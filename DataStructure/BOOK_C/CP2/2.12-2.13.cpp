#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;							//Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
typedef int ElemType;						//ElemType Ϊ�ɶ�����������ͣ�����Ϊint����

typedef struct DuLNode
{
	ElemType data;							//����������
	struct DuLNode *prior;
	struct DuLNode *next;					//����ָ����
}DuLNode,*DuLinkList;						//DuLinkListΪָ��ṹ��DuLNode��ָ������

Status InitDuList_L(DuLinkList &L){
	//����һ���յ�˫������L
	L=new DuLNode;							//�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
	L->next=NULL;							//ͷ����ָ�����ÿ�
	L->prior=NULL;
	return OK;
}

DuLNode *GetElemP_DuL(DuLinkList L,int i){
	//�ڴ�ͷ����˫������L�в��ҵ�i��Ԫ�أ����ؽ��ĵ�ַ
	int j;
	DuLNode *p;
	p=L->next;j=1;							//��ʼ����pָ���һ����㣬jΪ������
	while(j<i&&p){							//˳�������ɨ�裬ֱ��pָ���i��Ԫ�ػ�pΪ��
		p=p->next;++j;
	}
	if(!p || j>i)	return NULL;			//��i��Ԫ�ز�����
	return p;
}											//GetElemP_DuL

Status ListInsert_DuL(DuLinkList &L,int i,ElemType e){		//�㷨2.12 ˫������Ĳ���
	//�ڴ�ͷ����˫������L�е�i��λ��֮ǰ����Ԫ��e��i�ĺϷ�ֵΪ1<=i<=��+1
	DuLNode *s,*p;
	if(!(p=GetElemP_DuL(L,i)))				//��L��ȷ����i��Ԫ�ص�λ��ָ��p
		return ERROR;						//pΪNULLʱ����i��Ԫ�ز�����
	s=new DuLNode;							//�����½��s
	s->data=e;								//�����s������Ϊe
	s->prior=p->prior;						//�����s����L�У���Ҫ�޸�4��ָ����
	p->prior->next=s;
	s->next=p;
	p->prior=s;
	return OK;
}											//ListInsert_DuL

Status ListDelete_DuL(DuLinkList &L,int i,ElemType &e){		//�㷨2.13 ˫�������ɾ��
	//ɾ����ͷ����˫������L�е�i��λ��֮ǰ����Ԫ��e��i�ĺϷ�ֵΪ1<=i<=��
	DuLNode *p;
	if(!(p=GetElemP_DuL(L,i)))				//��L��ȷ����i��Ԫ�ص�λ��ָ��p
		return ERROR;						//pΪNULLʱ����i��Ԫ�ز�����
	e=p->data;								//���汻ɾ����������
	p->prior->next=p->next;					//�޸ı�ɾ����ǰ�����ĺ��ָ��
	p->next->prior=p->prior;				//�޸ı�ɾ���ĺ�̽���ǰ��ָ��
	delete p;								//�ͷű�ɾ���Ŀռ�
	return OK;
}											//ListDelete_DuL


void CreateDuList_L(DuLinkList &L,int n){
	//��λ������n��Ԫ�ص�ֵ����������ͷ����˫������L��ͬʱ����ǰ��ָ��
	DuLNode *r,*p;
	L=new DuLNode;
	L->next=NULL;								//�Ƚ���һ����ͷ���Ŀ�����
	r=L;
	cout<<"������"<<n<<"����\n";										//βָ��rָ��ͷ���
	for(int i=0;i<n;i++){
		p=new DuLNode;							//�����½��
		cin>>p->data;							//����Ԫ��ֵ
		p->next=NULL;r->next=p;					//���뵽��β
		r=p;									//rָ���µ�β���

		p->prior=L->prior;						//���뵽��ͷ
		L->prior=p;
	}
}												//CreateDuList_L

int main()
{
	int res,a,b,choose;
	DuLNode *L,*p;
	cout<<"1. ����˫������\n";
	cout<<"2. ��������\n";
	cout<<"3. ˫������Ĳ���\n";
	cout<<"4. ˫�������ɾ��\n";
	cout<<"5. �������\n";
	cout<<"0. �˳�\n\n";
	
	choose=-1;
	while(choose!=0)
	{
		cout<<"��ѡ��:";
		cin>>choose;
		switch(choose)
		{
		case 1:		//����һ��˫������
			if(InitDuList_L(L))
				cout<<"�ɹ�����˫������!\n";
			break;
		case 2:		//ʹ�ú�巨����˫������
			CreateDuList_L(L,10);
			break;
		case 3:		//˫������Ĳ���
			cout<<"�������������ֱ��������λ�ú���ֵ:";
			cin>>a>>b;
			if(ListInsert_DuL(L,a,b))
				cout<<"�ɹ���"<<a<<"λ�ò���"<<b<<endl;
			else
				cout<<"����ʧ��!\n";
			break;
		case 4:		//˫�������ɾ��
			cout<<"������һ��λ������ɾ��:";
			cin>>a;
			if(ListDelete_DuL(L,a,res))
				cout<<"ɾ���ɹ�!��ɾ��������"<<res<<endl;
			else
				cout<<"ɾ��ʧ��!\n";
			break;
		case 5:		//˫����������
			cout<<"���ڵ�������:\n";
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