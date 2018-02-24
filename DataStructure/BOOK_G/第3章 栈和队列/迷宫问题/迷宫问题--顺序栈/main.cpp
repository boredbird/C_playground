//ע�⣺���㷨���ҵ�һ��ͨ·������ͨ·�޷�ȷʵ�����ͨ·����Ψһͨ·��
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
	//ѹ��ջ
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
	//��ջ
	if(s.top==s.base)
		return ERROE;
	e=*--s.top;
	return OK;
}


Status StackEmpty(SqStack s){
	//�Ƿ��ջ
	if (s.top==s.base)  
		return OK;
	return OVERFLOW;  
}

void Random(){
	//��ʱ�����Թ���ǽ�ں�ͨ������Ϊ1:2
	int i,j,k;
	srand(time(NULL));
	mg[1][0]=mg[1][1]=mg[18][19]=0;	//����ڡ���������Ϊ"0"����ͨ��
	for(j=0;j<20;j++)
		mg[0][j]=mg[19][j]=1;		/*�����Թ���Χ"������"����ֻ֤��һ�����ں����*/
	for(i=2;i<19;i++)
		mg[i][0]=mg[i-1][19]=1;		/*�����Թ���Χ"������"����ֻ֤��һ�����ں����*/
	for(i=1;i<19;i++)
		for(j=1;j<19;j++){
			k=rand()%3;	//�������0��1��2������
			if(k)
				mg[i][j]=0;
			else{
				if((i==1&&j==1)||(i==18&&j==18))	/*��Ϊ����ڻ����һ����·�Ǳؾ�֮·�������ͨ����Ϊ"0"�Ӵ��Թ���ͨ�еĸ���*/
					mg[i][j]=0;
				else 
					mg[i][j]=1;
			}
		}		
}

Status InitStack(SqStack &s){
	//��ʼ����ջ
	s.base =(SElemType *)malloc(stack_init_size * sizeof(SElemType));
	if(!s.base) return OVERFLOW;
	s.top=s.base;
	s.stacksize=stack_init_size;
	return OK;
}

Status Pass(PosType e){
	//��ǰ��ɷ�ͨ��
	if (mg[e.x][e.y]==0)  //0ʱ����ͨ��  
		return OK;		// �����ǰλ���ǿ���ͨ��������1
	return OVERFLOW;	// �����������0
}


Status FootPrint(PosType e){
	//����ͨ�����㼣
	mg[e.x][e.y]=3;//'3'Ϊ����ͨ��
	return OK;
}


PosType NextPos(PosType &e,int dir){//��һ��
	PosType NEXTP;
	switch(dir){
	case 1:NEXTP.x=e.x;		//����
		   NEXTP.y=e.y+1;
		   break;
	case 2:NEXTP.x=e.x+1;	//����
		   NEXTP.y=e.y;
		   break;
    case 3:NEXTP.x=e.x;		//����
		   NEXTP.y=e.y-1;
		   break;
	case 4:NEXTP.x=e.x-1;	//����
		   NEXTP.y=e.y;
		   break;
	}
	return NEXTP;
}

Status MarkPrint(PosType e){ 
	//���²���ͨ�����㼣����2��Ϊ����ͨ��
	mg[e.x][e.y]=2;
	return OK;
}

Status MazePath(int mg,PosType start,PosType end,SqStack &s){
	//�����(1,0)������(18,19)��ͨ�����ڣ�����һ������ջ�У�������TRUE�����򷵻�FALSE
	PosType curpos;
	InitStack(s);
	SElemType e; 
	int curstep;	
	curpos=start;	// �趨"��ǰλ��"Ϊ"���λ��"
	curstep=1;		// ̽����һ��
	do{ 
		if(Pass(curpos)){	// ��ǰλ�ÿ�ͨ��
			FootPrint(curpos);	// �����㼣
			e.di =1;
            e.ord = curstep;
            e.seat= curpos;
			Push(s,e);	// ѹջ������·��
			if(curpos.x==end.x&&curpos.y==end.y){
				printf("\n\n ���Ե����յ�!");
				return TRUE;
			}
			curpos=NextPos(curpos,1);	// ��һλ���ǵ�ǰλ�õĶ���
			curstep++;	 // ̽����һ��
		}
		else{	// ��ǰλ�ò���ͨ��
			if(!StackEmpty(s)){
				Pop(s,e);
				while(e.di==4&&!StackEmpty(s)){
					MarkPrint(e.seat);
					Pop(s,e);
				}
				if(e.di<4){
					e.di++;
					Push(s,e);	// ���²���ͨ���ı�ǣ����˻�һ��
					curpos=NextPos(e.seat,e.di);	/* ��ǰλ����Ϊ�·�������ڿ�*/
				}//if
			}//if
		}//else
	}while(!StackEmpty(s));
	printf("\n\n���ܵ����յ�!\n");
	return FALSE;
}

//��ӡ�Թ�
void PrintMaze(){
		int i,j;
		printf("����·��:\n\n");
		for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			if(mg[i][j]==0)printf("  ");
			else if(mg[i][j]==1) printf("��");		//�Թ���"ǽ"
			else if(mg[i][j]==2) printf("��");      //��ͨ��·
			else if(mg[i][j]==3)printf("��");		//ͨ����·��
		}			 
		printf("\n");
	}
		printf("\n");
}

void main(){
	char select;
	SqStack S;
	PosType start,end;
	start.x=1;start.y=0;	//�������(1��0)	
	end.x=18;end.y=19;	//�յ�����(18,19)
	printf("\n==================�Թ���Ϸ==================");
	printf("\n˵��:�������ߵ�����\t\n     ���߲�ͨ������");
	printf("\n    '�ո�'����δ����������");
	printf("\n     �������ͨ����·����ָ���յ�");
	printf("\n============================================");
	do{
	Random();
	printf("\n\nTest:");
    MazePath(mg[20][20],start,end,S);
    PrintMaze();
    printf("���������...'q':�˳���");
	select=getchar();
	getchar();
	}
	while(select!='q');
	printf("\n�����˳�!\n");
}
   
