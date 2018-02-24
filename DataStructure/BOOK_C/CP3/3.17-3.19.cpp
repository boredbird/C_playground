/***���ӵĻ�������***/

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

//�㷨3.17�����ӵĳ�ʼ��
Status InitQueue(LinkQueue &Q)
{// ����һ���ն���Q
	Q.front = new QNode;
	if(Q.front == NULL)
	{
		return OVERFLOW;   // �洢����ʧ��
	}
	Q.front->next = NULL;
	Q.rear = Q.front;
	return OK;
}

//�㷨3.18�����ӵ����
Status EnQueue(LinkQueue &Q,QElemType e)
{ // ����Ԫ��eΪQ���µĶ�βԪ��
	QNode *p = new QNode;
	if(p == NULL)
	{
		return OVERFLOW;// �洢����ʧ��
	}
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;	// �޸Ķ�βָ��
	return OK;
}

//�㷨3.19�����ӵĳ���
Status DeQueue(LinkQueue &Q,QElemType &e)
{//ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK
	if(Q.front == Q.rear)
	{
		return ERROR;	//�����пգ��򷵻� ERROR
	}
	QNode *p = Q.front->next;//pָ���ͷԪ��
	e = p->data;//e�����ͷԪ�ص�ֵ
	Q.front->next = p->next;//�޸�ͷָ��
	if(Q.rear == p)
	{
		Q.rear = Q.front;//���һ��Ԫ�ر�ɾ����βָ��ָ��ͷ���
	}
	delete p;
	return OK;
}

int main()
{
	LinkQueue Q;
	QElemType e;
	cout<<"�����ӵ�Ԫ������Ϊ��"<<endl;
	if(InitQueue(Q)==OK)
		for(int j=1;j<=12;j++)
		{
			EnQueue(Q,j);
			cout<<j<<"  ";
		}
	cout<<endl<<"���γ����ӵ�Ԫ��Ϊ��"<<endl;
	while(DeQueue(Q,e) == OK)
	{
		cout<<e<<"  ";
	}
	return 0;
}
