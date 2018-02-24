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
typedef struct
{
    char data[QueueSize];//char为数据类型，QueueSize为队列大小
    int front,rear;
}CirQueue;
//初始化为空队列
void InitQueue(CirQueue *q)
{
   q->front=0;
   q->rear=0;
}
//判断队列是否满
int QueueFull(CirQueue *q)
{
   if(q->front==(q->rear+1)%QueueSize) 
      return 1;
   else
	  return 0;
}
//判断队列是否空
int QueueEmpty(CirQueue *q)
{
   if(q->front==q->rear) 
      return 1;
   else 
	  return 0;
}
//进队操作
void EnQueue(CirQueue *q,char x)
{
   if(QueueFull(q)) 
    printf("overflow!"); //队满上溢
   q->data[q->rear]=x;
   q->rear=(q->rear+1)%QueueSize; 
}

//出队操作
char DeQueue(CirQueue *q)
{
    char x;
    if(QueueEmpty(q))
      printf("underflow!");//队空下溢
    x=q->data[q->front];
    q->front =(q->front +1)%QueueSize;
    return x;
}
//取队头元素操作
char QueueFront(CirQueue *q)
{
    char x;
    if(QueueEmpty(q))
       printf("underflow!");//队空下溢
    x=q->data[q->front];
    return x;
}
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

void bfs(Adjgraph *G,int k)
{
	int i;
	CirQueue Q;//队列章节中有循环队列的知识介绍
	Anode *p;
	InitQueue(&Q);
	printf("%c",G->adjlist[k].vertex);//访问顶点Vk
    visited[k]=1;//标记已被访问
    EnQueue(&Q,k);//将访问过的顶点入队
	while(!QueueEmpty(&Q))
	{
      i=DeQueue(&Q);
	  p=G->adjlist[i].link;//找Vi的第一个邻接点
	  while(p!=NULL)
	  {
		  if(visited[p->adjvex]==0)
		  {
              printf("%c",G->adjlist[p->adjvex].vertex);
              visited[p->adjvex]=1;//标记已被访问
              EnQueue(&Q,p->adjvex);
		  }
		  p=p->next;//找Vi的下一个邻接点
	  }
	}
}

main()
{
  Adjgraph ag,*g;
  ag=creat();
  g=&ag;
  bfs(g,0);
  
}