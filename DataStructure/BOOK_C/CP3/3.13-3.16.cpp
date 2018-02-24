/***ѭ�����л�������***/

#include<iostream>
using namespace std;

#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int QElemType;
typedef int Status;

typedef struct{
	QElemType *base;//��ʼ��ʱ��̬����洢�ռ�
	int front;//ͷָ��
	int rear;//βָ��
}SqQueue;

//�㷨3.13��ѭ�����еĳ�ʼ��
Status InitQueue(SqQueue &Q)
{ // ����һ���ն���Q
	Q.base = new QElemType[MAXQSIZE];
	if(!Q.base)
	{
		return OVERFLOW;	// �洢����ʧ��
	}
	Q.front = 0;
	Q.rear = 0;
	return OK;
}

//�㷨3.14����ѭ�����еĳ���
int QueueLength(SqQueue Q)
{// ����Q��Ԫ�ظ����������еĳ���
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

//�㷨3.15��ѭ�����е����
Status EnQueue(SqQueue &Q,QElemType e)
{// ����Ԫ��eΪQ���µĶ�βԪ��
	if((Q.rear+1)%MAXQSIZE == Q.front)
	{
		return ERROR;//βָ����ѭ�������ϼ�1�����ͷָ�룬��������
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return OK;
}

//�㷨3.16��ѭ�����еĳ���
Status DeQueue(SqQueue &Q,QElemType &e)
{
	if(Q.rear == Q.front)
	{
		return ERROR;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front+1)%MAXQSIZE;
	return OK;
}

int main()
{
	SqQueue Q;
	QElemType e;
	cout<<"��ѭ�����е�Ԫ������Ϊ��"<<endl;
	if(InitQueue(Q)==OK)
		for(int j=1;j<=12;j++)
		{
			EnQueue(Q,j);
			cout<<j<<"  ";
		}
	cout<<endl<<"ѭ�����еĳ���Ϊ��"<<endl<<QueueLength(Q);
	cout<<endl<<"���γ��ӵ�Ԫ��Ϊ��"<<endl;
	while(DeQueue(Q,e) == OK)
	{
		cout<<e<<"  ";
	}
	return 0;
}
