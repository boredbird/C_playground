/***����ʵ�ִ�ӡ����ʽϵ����***/

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

//�㷨3.20����ӡ����ʽϵ����
void Yanghui(int n)
{
	LinkQueue q;
	InitQueue(q);		 //���г�ʼ��
	EnQueue(q, 1);
	EnQueue(q, 1);		 //Ԥ�ȷ����1�е�����ϵ��
	int s = 0, t; 		//������һ��ϵ��ʱ�õ��Ĺ�����Ԫ
	for (int i = 1; i <= n; i++)
	{ 		//���м���
		cout << endl; 		//��һ��
		EnQueue(q, 0); 		//���м����һ��0
		for (int j = 1; j <= i + 2; j++) {		 //�����i�е�i+2��ϵ��������һ��0��
			DeQueue(q, t);		 //һ��ϵ������
			EnQueue(q, s + t); 		//������һ��ϵ����������
			s = t;
			if (j != i + 2)
				cout<<s<<' '; 	//��ӡһ��ϵ������i+2����0
		}
	}
}

int main()
{
	Yanghui(7);
	return 0;
}
