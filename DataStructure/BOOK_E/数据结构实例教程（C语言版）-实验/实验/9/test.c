//���ö����������Գɼ���������
#include "stdio.h"
#include "stdlib.h"
typedef struct node
{
	long id;
	int score;
	struct node *lchild,*rchild;
}stu;
//����ѧ����Ϣ
void insertbst(stu **p,long id,int score)
{
	stu *s;
	if(*p==NULL)
	{
		s=(stu *)malloc(sizeof(stu));
		s->id=id;
		s->score=score;
		s->lchild=NULL;
		s->rchild=NULL;
		*p=s;//��¼��
	}
	else if(score<(*p)->score)
	{
       insertbst(&((*p)->lchild),id,score);
	}
	else
       insertbst(&((*p)->rchild),id,score);
}
//��������������
stu *createbst()
{
   long id;
   int score;
   stu *root;
   root=NULL;
   printf("������ѧ�źͳɼ�:");
   scanf("%ld,%d",&id,&score);
   while(score!=0)
   {
	   insertbst(&root,id,score);
       printf("������ѧ�źͳɼ�:");
       scanf("%ld,%d",&id,&score);
   }
   printf("�������!\n");
   return root;
}
//������������ݹ����
void inorder(stu *bt)
{
	if(bt!=NULL)
	{
		inorder(bt->lchild);
		printf("%ld,%d\n",bt->id,bt->score);
		inorder(bt->rchild);
	}
}
main()
{
	stu *root;
	root=createbst();
    printf("�����Ľ��:\n");
	inorder(root);
}