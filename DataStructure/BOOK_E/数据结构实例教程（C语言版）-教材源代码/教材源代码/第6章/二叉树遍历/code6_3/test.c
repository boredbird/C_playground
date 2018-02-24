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
//先序遍历算法如下：
void preorder(BTreeNode *bt)
{
	if(bt!=NULL)
	{
		printf("%c ",bt->data);
		preorder(bt->lchild);		
		preorder(bt->rchild);
	}
}
//中序遍历算法如下：
void inorder(BTreeNode *bt)
{
	if(bt!=NULL)
	{
		inorder(bt->lchild);
		printf("%c ",bt->data);
		inorder(bt->rchild);
	}
}
//后序遍历算法如下：
void postorder(BTreeNode *bt)
{
	if(bt!=NULL)
	{
		postorder(bt->lchild);		
		postorder(bt->rchild);
		printf("%c ",bt->data);
	}
}
main()
{
  BTreeNode *bt;
  bt=create();
  printf("先序递归遍历结果：");
  preorder(bt);
  printf("\n中序递归遍历结果：");
  inorder(bt);
  printf("\n后序递归遍历结果：");
  postorder(bt);
}
