#include "stdio.h"
#include "stdlib.h"
typedef struct node //�ڽӱ���ṹ����
{
	int adjvex;
	struct node *next;
}Anode;
typedef struct   //��������Ԫ�ؽ��ṹ����
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
  printf("�����붥��ͱߵ�������");
  scanf("%d,%d",&ag.vexnum,&ag.arcnum);
  getchar();//���ջس���
  for(i=0;i<ag.vexnum;i++)//���붥����Ϣ
  {
      printf("��������ֵ��");
	  scanf("%c",&ag.adjlist[i].vertex);
	  getchar();
      ag.adjlist[i].link=NULL;
  }
  for(i=0;i<ag.arcnum;i++)
  {
     printf("������ߵ���ţ�");
	 scanf("%d,%d",&s,&d);
	 //ǰ�巨
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