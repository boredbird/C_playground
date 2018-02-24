#include<stdio.h>
#include <stdlib.h>
typedef int ElemType;     //队列的存储类型
typedef struct QNode// 队列结点类型
{

	ElemType data;
	struct QNode  *next;
} QNode;
typedef struct      // 链队列类型
{ 
    QNode *front;  // 队头指针
    QNode *rear;   // 队尾指针
} LinkQueue;       



//构造空队，如果成功，返回1，如果失败，返回0
int InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear =(QNode *)malloc(sizeof(QNode));
	if (Q->front==NULL)return 0; //存储分配失败
	Q->front->next = NULL;
	return 1;
}
// 插入元素e为Q的新的队尾元素 ,如果成功，返回1，如果失败，返回0
int EnQueue (LinkQueue *Q, ElemType e)
{
	QNode *p=(QNode *)malloc(sizeof(QNode));
	if (p==NULL)return 0;   //存储分配失败
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;  //把p插入到队尾
	Q->rear = p;    //队尾为p
	return 1;
}

//若队列不空，则删除Q的队头元素，用e返回其值；否则返回NULL
ElemType DeQueue (LinkQueue *Q) 
{
	QNode *p;
	ElemType e;
	if(Q->front==Q->rear)return 0;//队列为空
	p=Q->front->next; //p指向队头结点
	e=p->data;
	Q->front->next=p->next; //front的next域指向队头的后一结点
	if (Q->rear==p)Q->rear = Q->front; //如果队列中只有一个结点，则删除后，队列为空
	free (p);
	return e;
}
//若栈不空，则用e返回队头元素；否则返回NULL
ElemType GetFront(LinkQueue Q)
{
	if (Q.front == Q.rear)  return NULL; //队列为空
    return  Q.front->next->data;
}
//若队列为空栈，则返回1，否则返回0 
int QueueEmpty(LinkQueue Q)//栈非空
{ 
	if(Q.front == Q.rear)return 1; //队列为空
	else return 0;
}



int main()
{
	LinkQueue q ;
	ElemType e;
	system("title 第3章 链队列");

	InitQueue(&q);  //初始化队列
	EnQueue(&q,3);EnQueue(&q,4);EnQueue(&q,5);EnQueue(&q,6); //依次将3，4，5，6进队
	e=DeQueue(&q);printf("出队的元素为:%d\n",e); //出栈并打印队头元素
	EnQueue(&q,7);//7进队
	e=DeQueue(&q);//出队
	EnQueue(&q,8);//8进队
	printf("队列中元素依次出栈:");
	while((e=DeQueue(&q))!=NULL)//队中元素依次出队并打印
	{		
		printf("%3d",e);
	}
	printf("\n");;
	return 0;
}






