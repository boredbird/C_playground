#include "stdio.h"
#include "stdlib.h"
#define QueueSize 20
//广度优先遍历以邻接表表示的图G
typedef struct node //邻接表结点结构定义
{
	int adjvex;
	struct node *next;
}Anode;
typedef struct   //顶点数组元素结点结构定义
{
	char vertex;
	Anode *link;
}Vnode;
typedef struct
{
	Vnode adjlist[100];
	int vexnum,arcnum;
}Adjgraph;
int visited[10]={0};

Adjgraph creat()
{
  Anode *p;
  int i,s,d;
  Adjgraph ag;
  printf("请输入顶点和边的数量：");
  scanf("%d,%d",&ag.vexnum,&ag.arcnum);
  getchar();//吸收回车符
  for(i=0;i<ag.vexnum;i++)//输入顶点信息
  {
      printf("请输入点的值：");
	  scanf("%c",&ag.adjlist[i].vertex);
	  getchar();
      ag.adjlist[i].link=NULL;
  }
  for(i=0;i<ag.arcnum;i++)
  {
     printf("请输入边的序号：");
	 scanf("%d,%d",&s,&d);
	 //前插法
	 p=(Anode *)malloc(sizeof(Anode));
	 p->adjvex=d;
	 p->next=ag.adjlist[s].link;
     ag.adjlist[s].link=p;
     p=(Anode *)malloc(sizeof(Anode));
     p->adjvex=s;
	 p->next=ag.adjlist[d].link;
     ag.adjlist[d].link=p;
  }
  return ag;
}  
void dfs(Adjgraph *G,int i)
{
   Anode *p;
   printf("%c",G->adjlist[i].vertex);//访问顶点Vi
   visited[i]=1;//标记已被访问
   p=G->adjlist[i].link;
   while(p!=NULL)
   {
	   if(visited[p->adjvex]==0)//vj未曾访问过
		   dfs(G,p->adjvex);
	   p=p->next;//回溯
   }
}
void dfstraverse(Adjgraph *G)
{
  int i;
  for(i=0;i<G->vexnum;i++)
	  visited[i]=0;//初始化都未曾访问过
  for(i=0;i<G->vexnum;i++)
	  if(visited[i]==0)//未曾访问过
		  dfs(G,i);
}

main()
{
  Adjgraph ag,*g;
  ag=creat();
  g=&ag;
  dfstraverse(g);
  
}