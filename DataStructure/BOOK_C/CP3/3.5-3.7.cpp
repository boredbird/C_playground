//��ջ��ʵ��
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int SElemType;
typedef struct SNode{
	SElemType data;
	struct SNode *next;
}SNode,*LinkStack;

//�㷨3.5����ջ�ĳ�ʼ��
Status InitStack (LinkStack &S)
{
      // ����һ����ջ S��ջ��ָ���ÿ�
      S=NULL;
      return OK;
}

//�㷨3.6����ջ����ջ
Status Push(LinkStack &S , SElemType e)
{//��ջ������Ԫ��e
	SNode *p = new SNode;//�����½��p
	if(!p)
	{
		return OVERFLOW;
	}
	p->data = e;//���½����������Ϊe
	p->next = S;//���½��p����ջ��
	S = p;//�޸�ջ��ָ��
	return OK;
}

//�㷨3.7����ջ�ĳ�ջ
Status Pop (LinkStack &S,SElemType & e)
{// ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	SNode *p;
		if(!S)
			return ERROR;
		e = S->data;//��ջ��Ԫ�ظ���e
		p = S;
		S = S->next;//�޸�ջ��ָ��
		delete p;//�ͷ�ԭջ�����ռ�
		return OK;
}

int main()
{
	LinkStack s;
	SElemType e;
	cout<<"��ջԪ������Ϊ��"<<endl;
	if(InitStack(s)==OK)
		for(int j=1;j<=15;j++)
		{
			Push(s,j);
			cout<<j<<"  ";
		}
	cout<<endl<<"���ε�����ջ��Ԫ��Ϊ��"<<endl;
	while(Pop(s,e) == OK)
	{
		cout<<e<<"  ";
	}
	return 0;
}
