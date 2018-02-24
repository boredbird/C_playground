#include "stdio.h"
#include "stdlib.h"
//二叉树的链式存储结构类型的定义
typedef struct node
{
	int key;
	struct node *lchild,*rchild;
}BTreeNode; 
void InsertBST(BTreeNode **T, int key)
{
	BTreeNode *s;
	if(*T ==NULL)
	{
		s=(BTreeNode *)malloc(sizeof(BTreeNode));
		s-> key = key;
		s->lchild=NULL;
		s->rchild=NULL;
		*T =s;//记录根
	}
	else if(key<(*T)->key)
	{
       InsertBST(&((*T)->lchild),key);
	}
	else
       InsertBST(&((*T)->rchild),key);
}
BTreeNode *CreateBST()
{
   int key;
   BTreeNode *root;
   root=NULL;
   scanf("%d",&key);
   while(key!=0)
   {
	    InsertBST(&root,key);
        scanf("%d",&key);
   }
   return root;
}
//二叉树的中序递归遍历
void inorder(BTreeNode *bt)
{
	if(bt!=NULL)
	{
		inorder(bt->lchild);
		printf("%ld,%d\n",bt->key);
		inorder(bt->rchild);
	}
}
main()
{
   BTreeNode *root;
   root=CreateBST();
   printf("排序后的结果:\n");
   inorder(root);
}
