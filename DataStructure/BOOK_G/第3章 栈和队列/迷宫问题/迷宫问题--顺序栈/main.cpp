//注意：此算法仅找到一条通路，这条通路无法确实是最近通路或者唯一通路。
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define stack_init_size 200
#define stack_increment 10
#define OVERFLOW 0
#define OK 1
#define ERROE 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef struct{
	int x;
	int y;
}PosType;

typedef struct {
	int ord;	
	PosType seat;	
	int di;			
}SElemType;

typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

int mg[20][20];



Status Push(SqStack &s,SElemType e){
	//压入栈
	if(s.top-s.base>=s.stacksize){
		s.base=(SElemType *)realloc(s.base,(s.stacksize+stack_increment) *sizeof(SElemType));
	if(!s.base)exit(OVERFLOW);
	s.top=s.base+s.stacksize;
	s.stacksize+=stack_increment;
	}
	*s.top++=e;
	return OK;
}


Status Pop(SqStack &s,SElemType &e){
	//出栈
	if(s.top==s.base)
		return ERROE;
	e=*--s.top;
	return OK;
}


Status StackEmpty(SqStack s){
	//是否空栈
	if (s.top==s.base)  
		return OK;
	return OVERFLOW;  
}

void Random(){
	//随时生成迷宫，墙壁和通道比例为1:2
	int i,j,k;
	srand(time(NULL));
	mg[1][0]=mg[1][1]=mg[18][19]=0;	//将入口、出口设置为"0"即可通过
	for(j=0;j<20;j++)
		mg[0][j]=mg[19][j]=1;		/*设置迷宫外围"不可走"，保证只有一个出口和入口*/
	for(i=2;i<19;i++)
		mg[i][0]=mg[i-1][19]=1;		/*设置迷宫外围"不可走"，保证只有一个出口和入口*/
	for(i=1;i<19;i++)
		for(j=1;j<19;j++){
			k=rand()%3;	//随机生成0、1、2三个数
			if(k)
				mg[i][j]=0;
			else{
				if((i==1&&j==1)||(i==18&&j==18))	/*因为距入口或出口一步的路是必经之路，故设该通道块为"0"加大迷宫能通行的概率*/
					mg[i][j]=0;
				else 
					mg[i][j]=1;
			}
		}		
}

Status InitStack(SqStack &s){
	//初始化空栈
	s.base =(SElemType *)malloc(stack_init_size * sizeof(SElemType));
	if(!s.base) return OVERFLOW;
	s.top=s.base;
	s.stacksize=stack_init_size;
	return OK;
}

Status Pass(PosType e){
	//当前块可否通过
	if (mg[e.x][e.y]==0)  //0时可以通过  
		return OK;		// 如果当前位置是可以通过，返回1
	return OVERFLOW;	// 其它情况返回0
}


Status FootPrint(PosType e){
	//留下通过的足迹
	mg[e.x][e.y]=3;//'3'为可以通过
	return OK;
}


PosType NextPos(PosType &e,int dir){//下一步
	PosType NEXTP;
	switch(dir){
	case 1:NEXTP.x=e.x;		//向下
		   NEXTP.y=e.y+1;
		   break;
	case 2:NEXTP.x=e.x+1;	//向右
		   NEXTP.y=e.y;
		   break;
    case 3:NEXTP.x=e.x;		//向上
		   NEXTP.y=e.y-1;
		   break;
	case 4:NEXTP.x=e.x-1;	//向左
		   NEXTP.y=e.y;
		   break;
	}
	return NEXTP;
}

Status MarkPrint(PosType e){ 
	//留下不能通过的足迹；‘2’为不能通过
	mg[e.x][e.y]=2;
	return OK;
}

Status MazePath(int mg,PosType start,PosType end,SqStack &s){
	//从入口(1,0)到出口(18,19)的通道存在，则求一条放入栈中，并返回TRUE，否则返回FALSE
	PosType curpos;
	InitStack(s);
	SElemType e; 
	int curstep;	
	curpos=start;	// 设定"当前位置"为"入口位置"
	curstep=1;		// 探索第一步
	do{ 
		if(Pass(curpos)){	// 当前位置可通过
			FootPrint(curpos);	// 留下足迹
			e.di =1;
            e.ord = curstep;
            e.seat= curpos;
			Push(s,e);	// 压栈，加入路径
			if(curpos.x==end.x&&curpos.y==end.y){
				printf("\n\n 可以到达终点!");
				return TRUE;
			}
			curpos=NextPos(curpos,1);	// 下一位置是当前位置的东邻
			curstep++;	 // 探索下一步
		}
		else{	// 当前位置不能通过
			if(!StackEmpty(s)){
				Pop(s,e);
				while(e.di==4&&!StackEmpty(s)){
					MarkPrint(e.seat);
					Pop(s,e);
				}
				if(e.di<4){
					e.di++;
					Push(s,e);	// 留下不能通过的标记，并退回一步
					curpos=NextPos(e.seat,e.di);	/* 当前位置设为新方向的相邻块*/
				}//if
			}//if
		}//else
	}while(!StackEmpty(s));
	printf("\n\n不能到达终点!\n");
	return FALSE;
}

//打印迷宫
void PrintMaze(){
		int i,j;
		printf("运行路径:\n\n");
		for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			if(mg[i][j]==0)printf("  ");
			else if(mg[i][j]==1) printf("■");		//迷宫的"墙"
			else if(mg[i][j]==2) printf("◇");      //不通的路
			else if(mg[i][j]==3)printf("○");		//通过的路径
		}			 
		printf("\n");
	}
		printf("\n");
}

void main(){
	char select;
	SqStack S;
	PosType start,end;
	start.x=1;start.y=0;	//起点坐标(1，0)	
	end.x=18;end.y=19;	//终点坐标(18,19)
	printf("\n==================迷宫游戏==================");
	printf("\n说明:■不能走的区域\t\n     ◇走不通的区域");
	printf("\n    '空格'代表未到过的区域");
	printf("\n     ○代表能通过的路径，指向终点");
	printf("\n============================================");
	do{
	Random();
	printf("\n\nTest:");
    MazePath(mg[20][20],start,end,S);
    PrintMaze();
    printf("任意键继续...'q':退出！");
	select=getchar();
	getchar();
	}
	while(select!='q');
	printf("\n程序退出!\n");
}
   
