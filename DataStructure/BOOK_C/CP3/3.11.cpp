/***������������еĸ������***/
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef char ElemType;
typedef struct LNode
{
	ElemType data; //����������
	LNode *next;  //����ָ����
}LNode,*LinkList;//ͷָ��

//��巨���������㷨
void CreateList_L(LinkList &L,int n)
{
	L = new LNode;
	L->next = NULL;
	LNode *p,*r;
	r= L;
	for(int i = 0;i < n;i ++)
	{
		p = new LNode;
		cin>>p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}

//�㷨3.11��������������еĸ������ĵݹ��㷨
void Print(LinkList p)
{
	if(p)
	{
		cout<<p->data<<" ";
		Print(p->next);
	}
}

int main()
{
	int n;
	LinkList L;
	//InitList(L);
	cout<<"������Ԫ�ظ�����"<<endl;
	cin>>n;
	cout<<"����������Ԫ��(�Կո���������س�����)��"<<endl;
	CreateList_L(L,n); //��巨���������㷨
	cout<<"�����е�Ԫ������Ϊ��"<<endl;
	Print(L->next);
    cout<<endl;
	return 0;
}
