#include<stdio.h>
#include <stdlib.h>
#define MAXNODE 20

typedef  char ElemType;   //默认数据类型为char
//线性表的单链表存储结构描述
typedef struct BiNode{
   ElemType data;
   struct BiNode *lchild,*rchild;    //左右孩子指针
}BiNode;

void Visit(ElemType data)
{
	printf("%c",data);
}
void PreOrder(BiNode *bt) 
{
    if (bt == NULL)  return;              //递归调用的结束条件
    else
	{
		Visit(bt->data);                  //访问根结点bt的数据域
        PreOrder(bt->lchild);             //前序递归遍历bt的左子树
        PreOrder(bt->rchild);             //前序递归遍历bt的右子树  
    }
}

void InOrder (BiNode *bt)
{
     if (bt == NULL) return;                 //递归调用的结束条件
     else 
	 {
         InOrder(bt->lchild);                //中序递归遍历bt的左子树
         Visit(bt->data);                    //访问根结点bt的数据域
         InOrder(bt->rchild);                //中序递归遍历bt的右子树
    }
}

void PostOrder(BiNode *bt)
{ 
     if (bt == NULL) return;                //递归调用的结束条件
     else 
	 {
         PostOrder(bt->lchild);             //后序递归遍历bt的左子树
         PostOrder(bt->rchild);             //后序递归遍历bt的右子树
         Visit(bt->data);                   //访问根结点bt的数据域
    }
}

void LeverOrder(BiNode *bt)
{
	 int front,rear;
	 BiNode *Q[MAXNODE],*q;
     front = rear = 0;            //采用循环队列，
     if (bt == NULL) return;       //二叉树为空，算法结束
     Q[rear] = bt;rear=(rear+1)%MAXNODE;             //根指针入队
     while (front != rear)          //当队列非空时
     {
          q = Q[front]; front=(front+1)%MAXNODE;        //出队
          Visit(q->data);   
          if (q->lchild != NULL){Q[rear] = q->lchild;rear=(rear+1)%MAXNODE;}
          if (q->rchild != NULL){Q[rear] = q->rchild;rear=(rear+1)%MAXNODE;}
     }
}

BiNode *Creat()
{
	BiNode *bt;
    ElemType ch;
    scanf("%c",&ch);                           //输入结点的数据信息，假设为字符
    if (ch =='#') bt = NULL;                //建立一棵空树
    else
    {
        bt = (BiNode*)malloc(sizeof(BiNode));;
		bt->data = ch;  //生成一个结点，数据域为ch
        bt->lchild = Creat();        //递归建立左子树
        bt->rchild = Creat();        //递归建立右子树
    }
    return bt;
}

void Release(BiNode *bt)
{
    if (bt == NULL) return;                 //递归调用的结束条件
    else
    {
        Release(bt->lchild);               //后序递归遍历bt的左子树
        Release(bt->rchild);               //后序递归遍历bt的右子树
        free(bt);                        //销毁根结点bt
    }
}

int main()
{
	BiNode *bt=Creat(); 	//创建一个二叉树BT
	system("title 第5章 树和二叉树-二叉树的遍历");
	printf("前序遍历:");
	PreOrder(bt);         //前序遍历
	printf("\n中序遍历:");
	InOrder(bt);       //中序遍历
	printf("\n后序遍历:");
	PostOrder(bt);      //后序遍历
	printf("\n按层遍历:");
	LeverOrder(bt);     //按层遍历
	printf("\n");
	Release(bt);
}





