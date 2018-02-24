#include "stdio.h"
#include "stdlib.h"
#define MaxSize 10
typedef struct node
{
	char data;
	struct node *lchild,*rchild;//左右孩子指针
}BTreeNode; //结点类型

BTreeNode *create()
{
	BTreeNode *s;
	BTreeNode *q[MaxSize];// MaxSize根据需要设定大小
	int i,j;
	char x;
	printf("i,x=");
	scanf("%d,%c",&i,&x);
	if(i==0)//空二叉树
		q[1]=NULL;
	while(i!=0&&x!='$')
	{
		s=(BTreeNode *)malloc(sizeof(BTreeNode));
		s->data=x;
		s->lchild=NULL;
		s->rchild=NULL;
		q[i]=s;
		if(i!=1)//非根结点，寻找双亲结点的地址
		{
			j=i/2;//j为双亲结点的地址
			if(i%2==0)//左孩子
				q[j]->lchild=s;
			else//右孩子
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
