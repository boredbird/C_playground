/***链队的基本操作***/

#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int QElemType;
typedef int Status;

typedef struct QNode{
	QElemType data;
	QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//算法3.17　链队的初始化
Status InitQueue(LinkQueue &Q)
{// 构造一个空队列Q
	Q.front = new QNode;
	if(Q.front == NULL)
	{
		return OVERFLOW;   // 存储分配失败
	}
	Q.front->next = NULL;
	Q.rear = Q.front;
	return OK;
}

//算法3.18　链队的入队
Status EnQueue(LinkQueue &Q,QElemType e)
{ // 插入元素e为Q的新的队尾元素
	QNode *p = new QNode;
	if(p == NULL)
	{
		return OVERFLOW;// 存储分配失败
	}
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;	// 修改队尾指针
	return OK;
}

//算法3.19　链队的出队
Status DeQueue(LinkQueue &Q,QElemType &e)
{//删除Q的队头元素，用e返回其值，并返回OK
	if(Q.front == Q.rear)
	{
		return ERROR;	//若队列空，则返回 ERROR
	}
	QNode *p = Q.front->next;//p指向队头元素
	e = p->data;//e保存队头元素的值
	Q.front->next = p->next;//修改头指针
	if(Q.rear == p)
	{
		Q.rear = Q.front;//最后一个元素被删，队尾指针指向头结点
	}
	delete p;
	return OK;
}

int main()
{
	LinkQueue Q;
	QElemType e;
	cout<<"进链队的元素依次为："<<endl;
	if(InitQueue(Q)==OK)
		for(int j=1;j<=12;j++)
		{
			EnQueue(Q,j);
			cout<<j<<"  ";
		}
	cout<<endl<<"依次出链队的元素为："<<endl;
	while(DeQueue(Q,e) == OK)
	{
		cout<<e<<"  ";
	}
	return 0;
}
