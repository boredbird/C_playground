#include<iostream>
using namespace std;

typedef struct PNode{
	float coef;			//ϵ��
	int expn;			//ָ��
	struct PNode *next;
}PNode,*Polynomial;

void CreatPolyn(Polynomial &P,int m)			//�㷨2.17 ����ʽ�Ĵ���
{
	//����m���ϵ����ָ����������ʾһ������ʽ����������P
	PNode *q,*pre,*s;
	int i;
	P=new PNode;
	P->next=NULL;								//�Ƚ���һ����ͷ���ĵ�����
	for(i=1;i<=m;i++)							//��������m��������
	{
		s=new PNode;							//�����½��
		cin>>s->coef>>s->expn;					//����Ԫ��ֵ
		pre=P;									//pre���ڱ���q��ǰ������ֵΪͷ���
		q=P->next;
		while(q && q->expn < s->expn)			//ͨ���Ƚ�ָ���ҵ���һ������������ָ������q
		{
			pre=q;
			q=q->next;
		}										//while
		s->next=q;								//��������s���뵽q����ǰ�����pre֮��
		pre->next=s;
	}											//for
}												//CreatPolyn

void AddPolyn(Polynomial &Pa,Polynomial &Pb)		//�㷨2.18 ����ʽ�����
{
	//����ʽ�ӷ���Pa=Pa+Pb��������������ʽ�Ľ�㹹�ɡ��Ͷ���ʽ��
	PNode *r,*p1,*p2,*p3;
	float sum;
	p1=Pa->next;p2=Pb->next;					//p1��p2��ֵ�ֱ�ָ��Pa��Pb�ĵ�һ�����
	p3=Pa;										//p3ָ��Ͷ���ʽ�ĵ�ǰ��㣬��ֵΪPa
	while(p1 && p2)								//p1��p2���ǿ�
	{
		if(p1->expn == p2->expn)				//ָ�����
		{
			sum=p1->coef+p2->coef;				//sum���������ϵ����
			if(sum!=0)							//ϵ���Ͳ�Ϊ0
			{
				p1->coef=sum;					//�޸�Pa��ǰ���p1��ϵ��ֵΪ����ϵ���ĺ�
				p3->next=p1;p3=p1;				//���޸ĺ��Pa��ǰ���p1����p3֮��p3ָ��p1
				p1=p1->next;					//p1ָ���һ��
				r=p2;p2=p2->next;delete r;		//ɾ��Pb��ǰ���r
			}
			else								//ϵ����Ϊ0
			{
				r=p1;p1=p1->next;delete r;		//ɾ��Pb��ǰ���p1
				r=p2;p2=p2->next;delete r;		//ɾ��Pb��ǰ���p2
			}
		}
		else if(p1->expn < p2->expn)				//Pa��ǰ���p1��ָ��ֵС
		{
			p3->next=p1;						//��p1����p3֮��
			p3=p1;								//p3ָ��p1
			p1=p1->next;						//p1ָ���һ��
		}
		else									//Pa��ǰ���p2��ָ��ֵС
		{
			p3->next=p2;						//��p2����p3֮��
			p3=p2;								//p3ָ��p2
			p2=p2->next;						//p2ָ���һ��
		}
	}											//while
	p3->next=p1?p1:p2;							//����ǿն���ʽ��ʣ���
	delete Pb;									//�ͷ�Pb��ͷ���
}												//AddPolyn


int main()
{
	Polynomial Pa,Pb;
	PNode *p;
	int temp,i;
	
	//��������ʽPa
	cout<<"���������ʽPa��������";
	cin>>temp;							//�������ʽPa�ĸ���
	cout<<"���������ʽPa��ϵ����ָ�����м���һ���ո������һ����һ�У�\n";
	CreatPolyn(Pa,temp);						//���ú���������Paÿһ���ϵ����ָ��
	
	//��������ʽPb
	cout<<"���������ʽPb��������";
	cin>>temp;							//�������ʽPa�ĸ���
	cout<<"���������ʽPb��ϵ����ָ�����м���һ���ո������һ����һ�У�\n";
	CreatPolyn(Pb,temp);						//���ú���������Paÿһ���ϵ����ָ��
	
	AddPolyn(Pa,Pb);
	cout<<"����ʽPa��Pb��Ӻ�Ľ���ǣ�\n";
	p=Pa->next;
	i=0;
	while(p)									//�����Ӻ�Ľ����ÿһ����x^n��ʾ
	{
		if(i)
			cout<<" + ";
		cout<<"("<<p->coef<<") * x^"<<p->expn;
		p=p->next;
		i=1;
	}
	cout<<endl;
	return 0;
}