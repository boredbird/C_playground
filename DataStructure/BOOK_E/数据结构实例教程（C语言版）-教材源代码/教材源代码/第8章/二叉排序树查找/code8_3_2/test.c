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
BTreeNode *SearchBST(BTreeNode *T,int key)
{
	if(T==NULL||key==T->key)
		return T;
	if(key<T->key)
		return SearchBST(T->lchild,key);
	else
        return SearchBST(T->rchild,key);
}
main()
{
   BTreeNode *root,*result;
   int key;
   root=CreateBST();
   printf("������Ҫ���ҵĹؼ���:\n");
   scanf("%d",&key);
   result=SearchBST(root,key);
   if(result!=NULL)
	   printf("���ҳɹ�!");
   else
       printf("����ʧ��!");

}