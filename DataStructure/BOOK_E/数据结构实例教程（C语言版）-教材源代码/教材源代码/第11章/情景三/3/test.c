#include "stdio.h"
#include "string.h"
#define Num 10
//旅游交通图结构体
typedef struct
{
	char citys[Num][8]; //存储城市名称，Num为交通图中所包含最多城市数量
	float time[Num][Num];//利用矩阵存储行驶每条道路花费的时间
	int citynum,roadnum;//城市数量和城市间道路的数量
}mgraph;
int path[Num][Num];
//利用邻接矩阵创建旅游交通图
void create_net(mgraph *g)
{
   int i,j,k;
   float t;
   printf("请输入城市数量和道路数量:");
   scanf("%d,%d",&g->citynum,&g->roadnum);
   getchar();
   for(i=1;i<=g->citynum;i++)//输入城市信息
   {
	   printf("第%d个城市信息:",i);
	   gets(g->citys[i]);
   }
   for(i=1;i<=g->citynum;i++)//初始化矩阵
	   for(j=1;j<=g->citynum;j++)
	     g->time[i][j]=999; //假设999就是矩阵中的∞
   for(k=1;k<=g->roadnum;k++)//输入边的信息和每条道路花费的时间
   {
	   printf("输入第%d条道路的起点和终点的编号:",k);
	   scanf("%d,%d",&i,&j);
	   printf("输入道路<%d,%d>行驶花费的时间:",i,j);
	   scanf("%f",&t);
	   g->time[i][j]=t;
	   g->time[j][i]=t;
   }
}
//打印旅游交通图信息
void pri_net(mgraph *g)
{
	int i,j;
	printf("城市信息:");
	printf("\n----------------------------------------------\n");
	for(i=1;i<=g->citynum;i++)
		printf("%-6d",i);
    printf("\n----------------------------------------------\n");
	for(i=1;i<=g->citynum;i++)
	    printf("%-6s",g->citys[i]);
	printf("\n----------------------------------------------\n");
	printf("\n行驶道路花费时间信息:\n");
	printf("   |");
    for(i=1;i<=g->citynum;i++)
		printf("%-6d",i);
	printf("\n----------------------------------------------\n");
    for(i=1;i<=g->citynum;i++)
	{
	   printf("%3d|",i);
	   for(j=1;j<=g->citynum;j++)
	     printf("%-6.1f",g->time[i][j]); 
	   printf("\n");
	}
}
//用递归实现遍历路径
void putpath(int i,int j,mgraph *g)
{
	int k;
	k=path[i][j];
	if(k==-1)//没有中间点
		return;
	putpath(i,k,g);
	printf("%s->",g->citys[k]);
	putpath(k,j,g);
}
//求最短路径
void minpath(mgraph *g)
{
    int i,j,k,c1=0,c2=0;
	float d[Num][Num];
	char city1[8],city2[8];
    for(i=1;i<=g->citynum;i++)
	   for(j=1;j<=g->citynum;j++)
	   {
		   d[i][j]=g->time[i][j];
		   path[i][j]=-1;
	   }
    for(k=1;k<=g->citynum;k++)//以1、2....为中间点
	{
	   for(i=1;i<=g->citynum;i++)
		   for(j=1;j<=g->citynum;j++)
	        if((d[i][k]+d[k][j]<d[i][j])&&(i!=j)&&(i!=k)&&(j!=k))//递推
			{
                d[i][j]=d[i][k]+d[k][j];
				path[i][j]=k;//记录最短路径经过的结点
			}
	}
	printf("请输入两个城市名称:\n");
	gets(city1);
	gets(city2);
	for(i=1;i<=g->citynum;i++)//按照城市名称查找对应的下标
	{
	   if(strcmp(g->citys[i],city1)==0)
		   c1=i;
       if(strcmp(g->citys[i],city2)==0)
		   c2=i;
	}
	printf("%d,%d\n",c1,c2);
	if(c1==0||c2==0)
		printf("其中一个城市不存在！\n");
	else
	{
	    printf("旅游最优路线为:");
		printf("%s->",g->citys[c1]);
	    putpath(c1,c2,g);
	    printf("%s\n",g->citys[c2]);
	    printf("行驶花费最短时间为:%-6.1f小时\n",d[c1][c2]);
	}
}

main()
{
    int choice;
	mgraph net,*g;
    g=&net;
  	printf("                       最短时间旅游路线查询系统\n\n");
	printf("**************************************************************************\n");
    printf(" 1.创建旅游交通图 2. 打印旅游交通图信息 3.查询最短时间旅游路线 4.退出系统\n");
    printf("**************************************************************************\n");
	while(1)
	{ printf("请输入选项:");
	  scanf("%d",&choice);
	  getchar();
	  switch(choice)
	  {
	    case 1:create_net(g);break;
		case 2:pri_net(g);break;
		case 3:minpath(g);break;
	  }
	  if(choice==4)
		  break;
	}
}
