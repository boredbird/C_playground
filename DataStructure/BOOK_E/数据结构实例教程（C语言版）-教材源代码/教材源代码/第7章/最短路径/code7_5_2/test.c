#include "stdio.h"
#define Maxsize 10
//图的结构体
typedef struct
{
	int vexs[Maxsize]; //Maxsize为顶点数量
	int arcs[Maxsize][Maxsize];
	int vexnum,arcnum;
}mgraph;
int path[Maxsize][Maxsize];
//利用邻接矩阵创建图
void create_net(mgraph *g)
{
   int i,j,k,n;
   printf("请输入顶点数和边数:");
   scanf("%d,%d",&i,&j);
   g->vexnum=i;
   g->arcnum=j;
   for(i=1;i<=g->vexnum;i++)//输入顶点信息
   {
	   printf("第%d个顶点的信息:",i);
	   scanf("%d",&g->vexs[i]);
   }
   for(i=1;i<=g->vexnum;i++)//初始化矩阵
	   for(j=1;j<=g->vexnum;j++)
	     g->arcs[i][j]=999; //假设999就是矩阵中的∞
   for(k=1;k<=g->arcnum;k++)//输入边的信息和权值
   {
	   printf("输入第%d条边的起点和终点的编号:",k);
	   scanf("%d,%d",&i,&j);
	   printf("输入边<%d,%d>的权值",i,j);
	   scanf("%d",&n);
	   g->arcs[i][j]=n;
   }
}
//用递归实现遍历路径
void putpath(int i,int j)
{
	int k;
	k=path[i][j];
	if(k==-1)//没有中间点
	  return;
	putpath(i,k);
	printf("%d->",k);
	putpath(k,j);
}
//求最短路径
void minpath(mgraph *g)
{
   int d[5][5],i,j,k;
   for(i=1;i<=g->vexnum;i++)
	   for(j=1;j<=g->vexnum;j++)
	   {
		   d[i][j]=g->arcs[i][j];
		   path[i][j]=-1;
	   }
   for(k=1;k<=g->vexnum;k++)//以1、2....为中间点
	{
	   for(i=1;i<=g->vexnum;i++)
		   for(j=1;j<=g->vexnum;j++)
	        if((d[i][k]+d[k][j]<d[i][j])&&(i!=j)&&(i!=k)&&(j!=k))//递推
			{
               d[i][j]=d[i][k]+d[k][j];
				printf("%d",d[i][j]);
				path[i][j]=k;//记录最短路径经过的结点
			}
	}
	printf("\n输出最短路径:\n");
	for(i=1;i<=g->vexnum;i++)
	   for(j=1;j<=g->vexnum;j++)
	   {
		   if(i==j)
			continue;
		   printf("%d->",i);
		   putpath(i,j);
		   printf("%d",j);
		   printf("最短路径为:%d\n",d[i][j]);
	   }
}
main()
{
  mgraph net,*g;
  g=&net;
  create_net(g);
  minpath(g);
}
