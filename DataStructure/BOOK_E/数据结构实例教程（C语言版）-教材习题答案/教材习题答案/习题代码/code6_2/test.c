#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 100
#define DATATYPE2 char
typedef struct node
{    DATATYPE2 data;
     struct node * lchild,* rchild;
}BTLINK;
BTLINK *createbt()
{   BTLINK *q[MAXSIZE];
BTLINK *s;
	char n;
int i,j;
printf("输入二叉树各结点的编号和值：\n");
	scanf("%d,%c",&i,&n);
	while(i!=0 && n!= '$')
	{	s=(BTLINK *)malloc(sizeof(BTLINK));
		s->data=n;
		s->lchild=NULL;
		s->rchild=NULL;
		q[i]=s;
		if(i!=1)
		{	j=i/2;
			if(i%2==0)
				q[j]->lchild=s;
			else
				q[j]->rchild=s;
		}
		printf("输入二叉树各结点的编号和值：\n");
		scanf("%d,%c",&i,&n);
	}
	return(q[1]);
}
BTLINK *search(BTLINK *bt,char x)
{	BTLINK *temp;
	if(bt==NULL)
		return NULL;
	if(x==bt->data)
		return bt;
	temp=search(bt->lchild,x);
	if(temp!=NULL)
		return temp;
	else
		return search(bt->rchild,x);
}
BTLINK *parent(BTLINK *bt,BTLINK *q)
{	BTLINK *p;
	if(bt==NULL)
		return NULL;
	if(bt->lchild==q||bt->rchild==q)
		return bt;
	p=parent(bt->lchild,q);
	if(p!=NULL)
		return p;
	else
		return parent(bt->rchild,q);
}
main()
{	BTLINK *bt,*temp,*p;
	char x;
	bt=createbt();
	printf("输入要查找双亲结点的数据：");
	scanf("%c",&x);
	temp=search(bt,x);
	if(temp==NULL)
		printf("无此结点！");
	else if(temp==bt)
			printf("无双亲结点，是根结点！");
	else
	{	p=parent(bt,temp);
		printf("双亲结点为：%c",p->data);
	}
}	
