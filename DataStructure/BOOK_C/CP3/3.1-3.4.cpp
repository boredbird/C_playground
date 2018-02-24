/***˳��ջ��ʵ��***/

#include<iostream.h>
#include<stdlib.h>

//˳��ջ����
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE  100
typedef int Status;
typedef int SElemType;
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

//�㷨3.1��˳��ջ�ĳ�ʼ��
Status InitStack(SqStack &S)
{// ����һ����ջ S 
	S.base = new SElemType[MAXSIZE];	//Ϊ˳��ջ����һ���������ΪMAXSIZE������ռ�
	if(!S.base)
		exit (OVERFLOW);    	//�洢����ʧ��
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
//�㷨3.2��˳��ջ����ջ
Status Push(SqStack &S,SElemType &e)
{ // ����Ԫ��eΪ�µ�ջ��Ԫ��
	if(S.top-S.base==S.stacksize)
		return ERROR;	//ջ��
	*(S.top++) = e;	//Ԫ��eѹ��ջ����ջ��ָ���1
	return OK;
}
//�㷨3.3��˳��ջ�ĳ�ջ
Status Pop(SqStack &S,SElemType &e)
{// ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if(S.base == S.top)
		return ERROR;//ջ��
	e = *(--S.top); //ջ��ָ���1����ջ��Ԫ�ظ���e
	return OK;
}
//�㷨3.4��ȡ˳��ջ��ջ��Ԫ��
Status GetTop(SqStack S,SElemType &e)
{// ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if(S.top == S.base)
		return ERROR;
	e = *(S.top-1);//ջ��ָ���1����ջ��Ԫ�ظ���e
	return OK;
}

int main()
{
	SqStack s;
	SElemType e;
	SElemType t;
	cout<<"��ջԪ������Ϊ��"<<endl;
	if(InitStack(s)==OK)
		for(int j=1;j<=12;j++)
		{
			Push(s,j);
			cout<<j<<"  ";
		}
	cout<<endl<<"���ε�����ջ��Ԫ��Ϊ��"<<endl;
	while(GetTop(s,e) == OK)
	{
		cout<<e<<"  ";
		Pop(s,t);
	}
	return 0;
}
