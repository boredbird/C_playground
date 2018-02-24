#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;		//Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
typedef int ElemType;	 //ElemType Ϊ�ɶ�����������ͣ�����Ϊint����

typedef struct LNode
{
	ElemType data;							//����������
	struct LNode *next;						//����ָ����
}LNode,*LinkList;							//LinkListΪָ��ṹ��LNode��ָ������


Status InitList_L(LinkList &L){				//�㷨2.5 ������ĳ�ʼ��
	//����һ���յĵ�����L
	L=new LNode;							//�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
	L->next=NULL;							//ͷ����ָ�����ÿ�
	return OK;
}

Status GetElem_L(LinkList L,int i,ElemType &e){		//�㷨2.6 ����Ų���
	//�ڴ�ͷ���ĵ�����L�в��ҵ�i��Ԫ��
	int j;
	LNode *p;
	p=L->next;j=1;							//��ʼ����pָ���һ����㣬jΪ������
	while(j<i&&p){							//˳�������ɨ�裬ֱ��pָ���i��Ԫ�ػ�pΪ��
		p=p->next;++j;
	}
	if(!p || j>i)	return ERROR;			//��i��Ԫ�ز�����
	e=p->data;								//ȡ��i��Ԫ��
	return OK;
}											//GetElem_L

LNode *LocateElem_L(LinkList L,ElemType e){			//�㷨2.7 ��ֵ����
	//�ڴ�ͷ���ĵ�����L�в���ֵΪe��Ԫ��
	LNode *p;
	p=L->next;
	while(p&&p->data!=e)
		p=p->next;							//Ѱ�����������Ľ��
	return p;								//����L�е�ֵΪe������Ԫ�ص�λ�ã�����ʧ�ܷ���NULL
}											//LocateElem_L

Status ListInsert_L(LinkList &L,int i,ElemType &e){		//�㷨2.8 ������Ĳ���
	//�ڴ�ͷ���ĵ�����L�е�i��λ��֮ǰ����Ԫ��e
	int j;
	LNode *p,*s;
	p=L;j=0;
	while(p && j<i-1){p=p->next;++j;}		//Ѱ�ҵ�i-1�����
	if(!p||j>i-1)	return ERROR;			//i���ڱ�+1����С��1
	s=new LNode;							//�����½��s
	s->data=e;								//�����s����������Ϊe
	s->next=p->next;						//�����s����L��
	p->next=s;
	return OK;
}											//ListInsert_L

Status ListDelete_L(LinkList &L,int i,ElemType &e){		//�㷨2.9 �������ɾ��
	//�ڴ�ͷ���ĵ�����L�У�ɾ����i��λ�ã�����e����ֵ
	LNode *p,*q;
	int j;
	p=L;j=0;
	while(p->next && j<i-1){p=p->next;++j;}		//Ѱ�ҵ�i-1�����
	if(!(p->next) || j>i-1)		return ERROR;	//i���ڱ�+1����С��1
	q=p->next;									//��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ�
	p->next=q->next;							//�ı�ɾ�����ǰ������ָ����
	e=q->data;									//����ɾ������������
	delete q;									//�ͷ�ɾ�����Ŀռ�
	return OK;
}												//ListDelete_L

void CreateList_F(LinkList &L,int n){				//�㷨2.10 ǰ�巨����������
	//��λ������n��Ԫ�ص�ֵ��������ͷ���ĵ�����L
	LNode *p;
	L=new LNode;
	L->next=NULL;								//�Ƚ���һ����ͷ���Ŀ�����
	cout<<"������ "<<n<<" ����:\n";
	for(int i=n;i>0;--i){
		p=new LNode;							//�����½��
		cin>>p->data;							//����Ԫ��ֵ
		p->next=L->next;L->next=p;				//���뵽��ͷ
	}
}												//CreateList_F

void CreateList_L(LinkList &L,int n){				//�㷨2.11 ��巨����������
	//��λ������n��Ԫ�ص�ֵ��������ͷ���ĵ�����L
	LNode *r,*p;
	L=new LNode;
	L->next=NULL;								//�Ƚ���һ����ͷ���Ŀ�����
	r=L;										//βָ��rָ��ͷ���
	cout<<"������ "<<n<<" ����:\n";
	for(int i=0;i<n;i++){
		p=new LNode;							//�����½��
		cin>>p->data;							//����Ԫ��ֵ
		p->next=NULL;r->next=p;					//���뵽��β
		r=p;									//rָ���µ�β���
	}
}												//CreateList_L

int main()
{
	int res,a,b,choose;
	LNode *L,*p;
	cout<<"1. ��������\n";
	cout<<"2. ��������\n";
	cout<<"3. ��λ�ò���\n";
	cout<<"4. ��ֵ����\n";
	cout<<"5. ����Ĳ���\n";
	cout<<"6. �����ɾ��\n";
	cout<<"7. �������\n";
	cout<<"0. �˳�\n\n";
	
	choose=-1;
	while(choose!=0)
	{
		cout<<"��ѡ��:";
		cin>>choose;
		switch(choose)
		{
		case 1:					//����һ��������
			if(InitList_L(L))
				cout<<"�ɹ���������!\n\n";
			break;
		case 2:					//ʹ�ú�巨����������
			CreateList_L(L,10);
			cout<<"�ɹ���������!\n\n";
			break;
		case 3:					//������İ���Ų���
			cout<<"������һ��λ����������:";
			cin>>a;
			if(GetElem_L(L,a,res))
				cout<<"���ҳɹ�!��"<<a<<"�����ǣ�"<<res<<"\n\n";
			else
				cout<<"����ʧ��\n\n";	
			break;
		case 4:					//������İ�ֵ����
			cout<<"������һ����ֵ��������:";
			cin>>b;
			if(LocateElem_L(L,b)!=NULL)
				cout<<"���ҳɹ�\n\n";
			else
				cout<<"����ʧ��! "<<b<<" û���ҵ�\n\n";
			break;
		case 5:					//������Ĳ���
			cout<<"�������������ֱ��������λ�ú���ֵ:";
			cin>>a>>b;
			if(ListInsert_L(L,a,b))
   				cout<<"�ɹ���"<<b<<"���ڵ�"<<a<<"��λ��\n\n";
			else
				cout<<"����ʧ��!\n\n";
			break;
		case 6:					//�������ɾ��
			cout<<"������һ��λ������ɾ��:";
			cin>>a;
			if(ListDelete_L(L,a,res))
				cout<<"ɾ���ɹ�!��ɾ�������ǣ�"<<res<<"\n\n";
			else
				cout<<"ɾ��ʧ��!\n\n";	
			break;
		case 7:					//����������
			cout<<"��������������ֱ���:\n";
			p=L->next;
			while(p)
			{
				cout<<p->data<<" ";
				p=p->next;
			}
			cout<<endl;
			break;
		}
	}
	return 0;
}
