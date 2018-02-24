#include "stdio.h"
#include "stdlib.h"
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
int count(Adjgraph ag)
{
  Anode *p;
  int sum=0,n,i;
  for(i=0;i<ag.vexnum;i++)
  {
      n=0;
	  p=ag.adjlist[i].link;
	  while(p!=NULL)
	  {
		  n++;
          p=p->next;   
	  }
	  if(n==2)
		  sum++;
  }
  return sum;
}
main()
{
  Adjgraph ag;
  int sum;
  ag=creat();
  sum=count(ag);
  printf("%d",sum);
}