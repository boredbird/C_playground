#include<iostream>
using namespace std;

typedef struct PNode{
	float coef;			//系数
	int expn;			//指数
	struct PNode *next;
}PNode,*Polynomial;

void CreatPolyn(Polynomial &P,int m)			//算法2.17 多项式的创建
{
	//输入m项的系数和指数，建立表示一个多项式的有序链表P
	PNode *q,*pre,*s;
	int i;
	P=new PNode;
	P->next=NULL;								//先建立一个带头结点的单链表
	for(i=1;i<=m;i++)							//依次输入m个非零项
	{
		s=new PNode;							//生成新结点
		cin>>s->coef>>s->expn;					//输入元素值
		pre=P;									//pre用于保存q的前驱，初值为头结点
		q=P->next;
		while(q && q->expn < s->expn)			//通过比较指数找到第一个大于输入项指数的项q
		{
			pre=q;
			q=q->next;
		}										//while
		s->next=q;								//将输入项s插入到q和其前驱结点pre之间
		pre->next=s;
	}											//for
}												//CreatPolyn

void AddPolyn(Polynomial &Pa,Polynomial &Pb)		//算法2.18 多项式的相加
{
	//多项式加法：Pa=Pa+Pb，利用两个多项式的结点构成“和多项式”
	PNode *r,*p1,*p2,*p3;
	float sum;
	p1=Pa->next;p2=Pb->next;					//p1和p2初值分别指向Pa和Pb的第一个结点
	p3=Pa;										//p3指向和多项式的当前结点，初值为Pa
	while(p1 && p2)								//p1和p2均非空
	{
		if(p1->expn == p2->expn)				//指数相等
		{
			sum=p1->coef+p2->coef;				//sum保存两项的系数和
			if(sum!=0)							//系数和不为0
			{
				p1->coef=sum;					//修改Pa当前结点p1的系数值为两项系数的和
				p3->next=p1;p3=p1;				//将修改后的Pa当前结点p1链在p3之后，p3指向p1
				p1=p1->next;					//p1指向后一项
				r=p2;p2=p2->next;delete r;		//删除Pb当前结点r
			}
			else								//系数和为0
			{
				r=p1;p1=p1->next;delete r;		//删除Pb当前结点p1
				r=p2;p2=p2->next;delete r;		//删除Pb当前结点p2
			}
		}
		else if(p1->expn < p2->expn)				//Pa当前结点p1的指数值小
		{
			p3->next=p1;						//将p1链在p3之后
			p3=p1;								//p3指向p1
			p1=p1->next;						//p1指向后一项
		}
		else									//Pa当前结点p2的指数值小
		{
			p3->next=p2;						//将p2链在p3之后
			p3=p2;								//p3指向p2
			p2=p2->next;						//p2指向后一项
		}
	}											//while
	p3->next=p1?p1:p2;							//插入非空多项式的剩余段
	delete Pb;									//释放Pb的头结点
}												//AddPolyn


int main()
{
	Polynomial Pa,Pb;
	PNode *p;
	int temp,i;
	
	//创建多项式Pa
	cout<<"请输入多项式Pa的项数：";
	cin>>temp;							//输入多项式Pa的个数
	cout<<"请输入多项式Pa的系数和指数，中间用一个空格隔开，一个项一行：\n";
	CreatPolyn(Pa,temp);						//调用函数，输入Pa每一项的系数和指数
	
	//创建多项式Pb
	cout<<"请输入多项式Pb的项数：";
	cin>>temp;							//输入多项式Pa的个数
	cout<<"请输入多项式Pb的系数和指数，中间用一个空格隔开，一个项一行：\n";
	CreatPolyn(Pb,temp);						//调用函数，输入Pa每一项的系数和指数
	
	AddPolyn(Pa,Pb);
	cout<<"多项式Pa和Pb相加后的结果是：\n";
	p=Pa->next;
	i=0;
	while(p)									//输出相加后的结果，每一项以x^n表示
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