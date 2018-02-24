#include "stdio.h"
#include "stdlib.h"
#define QueueSize 20
//������ȱ������ڽӱ��ʾ��ͼG
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
int visited[10]={0};
typedef struct
{
    char data[QueueSize];//charΪ�������ͣ�QueueSizeΪ���д�С
    int front,rear;
}CirQueue;
//��ʼ��Ϊ�ն���
void InitQueue(CirQueue *q)
{
   q->front=0;
   q->rear=0;
}
//�ж϶����Ƿ�������
int QueueFull(CirQueue *q)
{
   if(q->front==(q->rear+1)%QueueSize) 
      return 1;
   else
	  return 0;
}
//�ж϶����Ƿ�գ���
int QueueEmpty(CirQueue *q)
{
   if(q->front==q->rear) 
      return 1;
   else 
	  return 0;
}
//���Ӳ���
void EnQueue(CirQueue *q,char x)
{
   if(QueueFull(q)) 
    printf("overflow!"); //��������
   q->data[q->rear]=x;
   q->rear=(q->rear+1)%QueueSize; 
}

//���Ӳ�������
char DeQueue(CirQueue *q)
{
    char x;
    if(QueueEmpty(q))
      printf("underflow!");//�ӿ�����
    x=q->data[q->front];
    q->front =(q->front +1)%QueueSize;
    return x;
}
//ȡ��ͷԪ�ز���
char QueueFront(CirQueue *q)
{
    char x;
    if(QueueEmpty(q))
       printf("underflow!");//�ӿ�����
    x=q->data[q->front];
    return x;
}
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

void bfs(Adjgraph *G,int k)
{
	int i;
	CirQueue Q;//�����½�����ѭ�����е�֪ʶ����
	Anode *p;
	InitQueue(&Q);
	printf("%c",G->adjlist[k].vertex);//���ʶ���Vk
    visited[k]=1;//����ѱ�����
    EnQueue(&Q,k);//�����ʹ��Ķ������
	while(!QueueEmpty(&Q))
	{
      i=DeQueue(&Q);
	  p=G->adjlist[i].link;//��Vi�ĵ�һ���ڽӵ�
	  while(p!=NULL)
	  {
		  if(visited[p->adjvex]==0)
		  {
              printf("%c",G->adjlist[p->adjvex].vertex);
              visited[p->adjvex]=1;//����ѱ�����
              EnQueue(&Q,p->adjvex);
		  }
		  p=p->next;//��Vi����һ���ڽӵ�
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