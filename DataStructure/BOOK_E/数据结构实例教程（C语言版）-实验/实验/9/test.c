//利用二叉排序树对成绩进行排序
#include "stdio.h"
#include "stdlib.h"
typedef struct node
{
	long id;
	int score;
	struct node *lchild,*rchild;
}stu;
//插入学生信息
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
		*p=s;//记录根
	}
	else if(score<(*p)->score)
	{
       insertbst(&((*p)->lchild),id,score);
	}
	else
       insertbst(&((*p)->rchild),id,score);
}
//创建二叉排序树
stu *createbst()
{
   long id;
   int score;
   stu *root;
   root=NULL;
   printf("请输入学号和成绩:");
   scanf("%ld,%d",&id,&score);
   while(score!=0)
   {
	   insertbst(&root,id,score);
       printf("请输入学号和成绩:");
       scanf("%ld,%d",&id,&score);
   }
   printf("输入完成!\n");
   return root;
}
//二叉树的中序递归遍历
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
    printf("排序后的结果:\n");
	inorder(root);
}