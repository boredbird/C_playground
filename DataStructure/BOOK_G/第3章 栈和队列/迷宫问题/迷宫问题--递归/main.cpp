#include<string.h>
#include<ctype.h>
#include<malloc.h> // malloc()等
#include<limits.h> // INT_MAX等
#include<stdio.h> // EOF(=^Z或F6),NULL
#include<stdlib.h> // atoi()
#include<io.h> // eof()
#include<math.h> // floor(),ceil(),abs()
#include<time.h>
#include<process.h> // exit()
#include<iostream.h> // cout,cin

 #define MAXLENGTH 25 /* 设迷宫的最大行列为25 */
 typedef int MazeType[MAXLENGTH][MAXLENGTH]; /* 迷宫数组类型[行][列] */

typedef struct
 {
   int xx; /* 行值 */
   int yy; /* 列值 */
 }PosType; /* 迷宫坐标位置类型 */

 /* 全局变量 */
 //MazeType m; /* 迷宫数组 */
 int x=20,y=20; /* 迷宫的行数，列数 */
 int Mark=0;
 PosType begin,end; /* 迷宫的入口坐标,出口坐标 */

 int mg[20][20];

void Print()
 { /* 输出迷宫的解(mg数组) */
   int i,j;
   for(i=0;i<x;i++)
   {
     for(j=0;j<y;j++)
		    if(i==1&&j==0||i==1&&j==1) printf("○");
			else if(mg[i][j]==1) printf("■");		//迷宫的"墙"
			else if(mg[i][j]==0) printf("◇");      //不通的路
			else if(mg[i][j]==-1)printf("◇");		
			else printf("○");		//通过的路径
     printf("\n");
   }
   Mark = 1;
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
			k=rand()%3;	//随机生成0、1、2三个数(1和2随机出现的概率比0出现的概率多一倍)
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

 void Try(PosType cur,int curstep)
 { /* 由当前位置cur、当前步骤curstep试探下一点 */
   int i;
   PosType next; /* 下一个位置 */
   PosType direc[4]={{0,1},{1,0},{0,-1},{-1,0}}; /* {行增量,列增量},移动方向,依次为东南西北 */
   for(i=0;i<=3;i++) /* 依次试探东南西北四个方向 */
   {
     next.xx=cur.xx+direc[i].xx; /* 根据移动方向，给下一位置赋值 */
     next.yy=cur.yy+direc[i].yy;
     if(mg[next.xx][next.yy]==0) /* 下一个位置是通路 */
     {
       mg[next.xx][next.yy]=++curstep; /* 将下一个位置设为足迹 */
       if(next.xx!=end.xx||next.yy!=end.yy) /* 没到终点 */
         Try(next,curstep); /* 由下一个位置继续试探(降阶递归调用，离终点更近) */
       else /* 到终点 */
       {
         Print(); /* 输出结果(出口，不再递归调用) */
         printf("\n");
       }
       mg[next.xx][next.yy]=-1; /* 恢复为通路，以便在另一个方向试探另一条路 */
       curstep--; /* 足迹也减1 */
     }
   }
 }

 void main()
 {
   char select;
	printf("\n==================迷宫游戏==================");
	printf("\n说明:■不能走的区域\t\n     ◇走不通的区域");
	printf("\n     ○代表能通过的路径，指向终点");
	printf("\n============================================");
    printf("\n 此迷宫从入口到出口的路径如下:\n");
	begin.xx=1;begin.yy=0;	//起点坐标(1，0)	
	end.xx=18;end.yy=19;	//终点坐标(18,19)
   do{
	   Mark=0;
	   Random();
	   Try(begin,0); /* 由第1步入口试探起 */
       if(!Mark)printf("\n该随机生成的迷宫无解!!!\n");
	   printf("\n按任意键继续...'q':退出! \n");
       select = getchar();
	   getchar();
   }while(select!='q');
 }
