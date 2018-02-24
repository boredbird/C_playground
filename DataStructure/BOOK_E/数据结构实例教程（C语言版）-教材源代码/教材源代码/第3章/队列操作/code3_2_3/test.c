#include "stdio.h"
#include "stdlib.h"
typedef struct Queuenode//�����н�������
{	
  char data;
  struct  Queuenode *next;
}Linknode; 
typedef struct //��ͷβָ���װ��һ���������
{
	Linknode *front,*rear;
}LinkQueue;     

//��ʼ��Ϊ�ն���
void InitQueue(LinkQueue *Q)
{ 
  Q->front=Q->rear=NULL;
} 
//�ж϶����Ƿ�գ���
int QueueEmpty(LinkQueue *Q) 
{
  return Q->front==NULL&&Q->rear==NULL;
} 
//���Ӳ���
void EnQueue(LinkQueue *Q,char x) 
{  //��Ԫ��x����������β�� 
	Linknode *p=(Linknode *)malloc(sizeof(Linknode));//�����½�� 
	p->data=x;
	p->next=NULL; 
	if(QueueEmpty(Q)) 
		Q->front=Q->rear=p; //��x����ն��� 
	else
	{ //x����ǿն��е�β 
		Q->rear->next=p; //p������β
		Q->rear=p; //��βָ��ָ��p
	} 
} 
//���Ӳ�������
char DeQueue(LinkQueue *Q) 
{   
	char x;   
	Linknode *p; 
	if(QueueEmpty(Q)) 
		printf("Queue underflow");//���� 
	p=Q->front; //ָ���ͷ��� 
	x=p->data; //�����ͷ�������� 
	Q->front=p->next; //����ͷ��������ժ�� 
	if(Q->rear==p)//ԭ����ֻ��һ����㣬ɾȥ����б�գ���ʱ��ͷָ����Ϊ�� 
		Q->rear=NULL; 
	free(p); //�ͷű�ɾ��ͷ��� 
	return x; //����ԭ��ͷ����
} 
//ȡ��ͷԪ�ز���
char QueueFront(LinkQueue *Q) 
{  
	if(QueueEmpty(Q)) 
		printf("Queue if empty.");
	return Q->front->data;
} 

main()
{
   LinkQueue queue,*q;
   q=&queue;
   InitQueue(q);
   printf("ABC����!");
   EnQueue(q,'A');
   EnQueue(q,'B');
   EnQueue(q,'C');
   printf("��ͷԪ��Ϊ%c\n",QueueFront(q));
   printf("ִ��һ�γ���!");
   DeQueue(q);
   printf("��ͷԪ��Ϊ%c\n",QueueFront(q));
}
