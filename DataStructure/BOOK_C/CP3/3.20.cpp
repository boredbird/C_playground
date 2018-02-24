/***链队实现打印二项式系数表***/

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

Status InitQueue(LinkQueue &Q)
{
	Q.front = new QNode;
	if(Q.front == NULL)
	{
		return OVERFLOW;
	}
	Q.front->next = NULL;
	Q.rear = Q.front;
	return OK;
}

Status EnQueue(LinkQueue &Q,QElemType e)
{
	QNode *p = new QNode;
	if(p == NULL)
	{
		return OVERFLOW;
	}
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue &Q,QElemType &e)
{
	if(Q.front == Q.rear)
	{
		return ERROR;
	}
	QNode *p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p)
	{
		Q.rear = Q.front;
	}
	delete p;
	return OK;
}

//算法3.20　打印二项式系数表
void Yanghui(int n)
{
	LinkQueue q;
	InitQueue(q);		 //队列初始化
	EnQueue(q, 1);
	EnQueue(q, 1);		 //预先放入第1行的两个系数
	int s = 0, t; 		//计算下一行系数时用到的工作单元
	for (int i = 1; i <= n; i++)
	{ 		//逐行计算
		cout << endl; 		//换一行
		EnQueue(q, 0); 		//各行间插入一个0
		for (int j = 1; j <= i + 2; j++) {		 //处理第i行的i+2个系数（包括一个0）
			DeQueue(q, t);		 //一个系数出队
			EnQueue(q, s + t); 		//计算下一行系数，并进队
			s = t;
			if (j != i + 2)
				cout<<s<<' '; 	//打印一个系数，第i+2个是0
		}
	}
}

int main()
{
	Yanghui(7);
	return 0;
}
