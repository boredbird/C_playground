/***循环队列基本操作***/

#include<iostream>
using namespace std;

#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int QElemType;
typedef int Status;

typedef struct{
	QElemType *base;//初始化时动态分配存储空间
	int front;//头指针
	int rear;//尾指针
}SqQueue;

//算法3.13　循环队列的初始化
Status InitQueue(SqQueue &Q)
{ // 构造一个空队列Q
	Q.base = new QElemType[MAXQSIZE];
	if(!Q.base)
	{
		return OVERFLOW;	// 存储分配失败
	}
	Q.front = 0;
	Q.rear = 0;
	return OK;
}

//算法3.14　求循环队列的长度
int QueueLength(SqQueue Q)
{// 返回Q的元素个数，即队列的长度
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

//算法3.15　循环队列的入队
Status EnQueue(SqQueue &Q,QElemType e)
{// 插入元素e为Q的新的队尾元素
	if((Q.rear+1)%MAXQSIZE == Q.front)
	{
		return ERROR;//尾指针在循环意义上加1后等于头指针，表明队满
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1)%MAXQSIZE;
	return OK;
}

//算法3.16　循环队列的出队
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
	cout<<"进循环队列的元素依次为："<<endl;
	if(InitQueue(Q)==OK)
		for(int j=1;j<=12;j++)
		{
			EnQueue(Q,j);
			cout<<j<<"  ";
		}
	cout<<endl<<"循环队列的长度为："<<endl<<QueueLength(Q);
	cout<<endl<<"依次出队的元素为："<<endl;
	while(DeQueue(Q,e) == OK)
	{
		cout<<e<<"  ";
	}
	return 0;
}
