#include<iostream>
using namespace std;

typedef struct LNode										//���嵥����
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void InitList_L(LinkList &L)								//����������
{
	L=new LNode;
	L->next=NULL;
}

void input(LinkList &L,int n)								//������������L����������
{
	int i;
	LinkList p,r;
	r=L;
	cout<<"������ñ��Ԫ�أ����ǵݼ���˳�򣩣�";
	for(i=0;i<n;i++)
	{
		p=new LNode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	}
}

void output(LinkList L)										//����������������ÿ��Ԫ��
{
	int i=0;
	LNode *p;
	p=L->next;
	while(p)
	{
		if(i)
			cout<<",";
		cout<<p->data;
		p=p->next;
		i=1;
	}
}

void MergeList_L(LinkList &LA,LinkList &LB,LinkList &LC)		//�㷨2.16 ��ʽ�����ĺϲ�
{
	//��֪������LA��LB��Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢LA��LB�õ��µĵ�����LC��LC��Ԫ��Ҳ��ֵ�ǵݼ�����
	LinkList pa,pb,pc;
	pa=LA->next;pb=LB->next;								//pa��pb�ĳ�ֵ�ֱ�ָ��������ĵ�һ�����
	LC=LA;													//��LA��ͷ�����ΪLC��ͷ���
	pc=LC;													//pc�ĳ�ֵָ��LC��ͷ���
	while(pa && pb)											//�������ǿ�
	{
		if(pa->data <= pb->data)							//����"ժȡ"������ֵ��С�Ľ����뵽LC������
		{
			pc->next=pa;									//��pa��ָ������ӵ�pc��ָ���֮��
			pc=pa;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;									//��pb��ָ������ӵ�pc��ָ���֮��
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb;										//����ǿձ��ʣ���
	delete LB;												//�ͷ�LB��ͷ���
}															//MergeList_L()

int main()
{
	LinkList La,Lb,Lc;
	int num_a,num_b;
	
	cout<<"������ǵݼ�������a�ĸ���n��";	
	cin>>num_a;	
	InitList_L(La);													//La��Ĵ���
	input(La,num_a);												//������������La����������
	
	cout<<"������ǵݼ�������b�ĸ���n��";	
	cin>>num_b;
	InitList_L(Lb);													//Lb��Ĵ���	
	input(Lb,num_b);												//������������La����������
	
	InitList_L(Lc);
	MergeList_L(La,Lb,Lc);											//��������La��Lb���кϲ�
	
	
	cout<<"�ǵݼ�������a��b�ϲ���ķǵݼ�������cΪ��\n";			//����ϲ���ĵ�����Lc
	output(Lc);
	cout<<endl;
	return 0;
}