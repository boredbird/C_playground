#include "stdio.h"
#include "stdlib.h"
//����������ʽ�洢�ṹ���͵Ķ���
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
		*T =s;//��¼��
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
//������������ݹ����
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
   printf("�����Ľ��:\n");
   inorder(root);
}
