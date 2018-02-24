#include<iostream>
using namespace std;

typedef struct LNode
{
	int data;							//����������
	struct LNode *next;						//����ָ����
}LNode,*List;							//LinkListΪָ��ṹ��LNode��ָ������


void InitList(List &L)						//��������
{
	L=new LNode;
	L->next=NULL;
}

void ListInput(List &L,int n)				//�������ݵ�����
{
	int i;
	LNode *p,*r;
	cout<<"������"<<n<<"������\n";
	r=L;
	for(i=0;i<n;i++)
	{
		p=new LNode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	}
}

bool LocateElem(List L,int e)				//�ж�List����û��e���Ԫ��
{
	LNode *p;
	p=L->next;
	while(p!=NULL)
	{
		if(p->data==e)
			return true;
		p=p->next;
	}
	return false;
}

void ListInsert(List &L,int e)				//��e���뵽List��
{
	LNode *p;
	p=new LNode;
	p->data=e;
	p->next=L->next;
	L->next=p;
}

void ListOutput(List L)						//���List
{
	LNode *p;
	p=L->next;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

void unionList(List &LA,List LB)					//�㷨2.14 ���Ա�ĺϲ�������
{
	//�����������Ա�LB�е�����LA�е�����Ԫ�ز��뵽LA��
	int e;
	LNode *p;
	p=LB->next;
	while(p!=NULL)
	{
		e=p->data;
		if(!LocateElem(LA,e))						//LA�в����ں�e��ͬ������Ԫ�أ������֮
			ListInsert(LA,e);
		p=p->next;
	}
}													//unionList

int main()
{
	List LA,LB;
	int n,m;
	InitList(LA);
	InitList(LB);

	cout<<"���������Ա�LA��Ԫ�ظ�����";
	cin>>n;
	ListInput(LA,n);
	cout<<"���������Ա�LB��Ԫ�ظ�����";
	cin>>m;
	ListInput(LB,m);
	
	unionList(LA,LB);

	cout<<"LA��LB�ϲ���ļ���Ϊ��\n";
	ListOutput(LA);
	return 0;
}