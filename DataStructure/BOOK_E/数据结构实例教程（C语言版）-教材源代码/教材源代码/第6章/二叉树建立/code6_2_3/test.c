#include "stdio.h"
#include "stdlib.h"
#define MaxSize 10
typedef struct node
{
	char data;
	struct node *lchild,*rchild;//���Һ���ָ��
}BTreeNode; //�������

BTreeNode *create()
{
	BTreeNode *s;
	BTreeNode *q[MaxSize];// MaxSize������Ҫ�趨��С
	int i,j;
	char x;
	printf("i,x=");
	scanf("%d,%c",&i,&x);
	if(i==0)//�ն�����
		q[1]=NULL;
	while(i!=0&&x!='$')
	{
		s=(BTreeNode *)malloc(sizeof(BTreeNode));
		s->data=x;
		s->lchild=NULL;
		s->rchild=NULL;
		q[i]=s;
		if(i!=1)//�Ǹ���㣬Ѱ��˫�׽��ĵ�ַ
		{
			j=i/2;//jΪ˫�׽��ĵ�ַ
			if(i%2==0)//����
				q[j]->lchild=s;
			else//�Һ���
				q[j]->rchild=s;
		}
     printf("i,x=");
	    scanf("%d,%c",&i,&x);
	}
	return q[1];
}
main()
{
  BTreeNode *bt;
  bt=create();
  
}
