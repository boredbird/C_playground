#include "stdio.h"
#include "stdlib.h"
typedef struct node
{
  char data;
  struct node *lchild;
  struct node *rchild;
}BTreeNode,*BiTree;
void PrintBiTree(BiTree root,int n)
{
  int i;
  if(root==NULL) return;
  PrintBiTree(root->rchild,n+1);
  for(i=0;i<n;i++) printf("    ");
  if(n>=0)
  {
    printf("---");
    printf("%c\n",root->data);
  }
  PrintBiTree(root->lchild,n+1);
}
void CreateBiTree(BiTree *bt)
{
  char ch;
  ch=getchar();
  if(ch==',')
    *bt=NULL;
  else
     {
      *bt=(BiTree)malloc(sizeof(BTreeNode));
      (*bt)->data=ch;
      CreateBiTree(&((*bt)->lchild));
      CreateBiTree(&((*bt)->rchild));
     }
}
void PreOrder(BiTree root)
{
  if(root!=NULL)
  {
    printf(" %c",root->data);
    PreOrder(root->lchild);
    PreOrder(root->rchild);
  }
}
void InOrder(BiTree root)
{
  if(root!=NULL)
  {
    InOrder(root->lchild);
    printf(" %c",root->data);
    InOrder(root->rchild);
 }
}
void PostOrder(BiTree root)
{
  if(root!=NULL)
  {
    PostOrder(root->lchild);  
    PostOrder(root->rchild);
    printf(" %c",root->data);
 }
}
int datanum(BiTree t)       
{int n1,n2,n=0;
 if(t==NULL) return 0;
  else
   if(t->lchild==NULL&&t->rchild==NULL) n=1;
  n1=datanum(t->lchild);
  n2=datanum(t->rchild);
  return(n1+n2+n);
}
void main()
{
  BiTree R;
  printf("\n请输入数据串:");
  R=(BiTree)malloc(sizeof(BTreeNode));
  CreateBiTree(&R);
  printf("\n\n 树的图形 :\n\n");
  PrintBiTree(R,0);
  getchar();
  printf("\n 先序结果: ");
  PreOrder(R);
  printf("\n 中序结果: ");
  InOrder(R);
  printf("\n 后序结果: ");
  PostOrder(R);
  printf("\n\n度为1的结果数量: ");
  printf("%d",datanum(R));
  getchar();
} 
