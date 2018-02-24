#include<stdio.h>
#include <stdlib.h>
#define MAXNODE 20

typedef  char ElemType;   //默认数据类型为char
typedef struct ThrNode
{ 
     ElemType data;
     struct ThrNode  *lchild, *rchild;
     int ltag, rtag;
}ThrNode;

ThrNode *Creat()
{
	ThrNode *bt;
	ElemType ch;
	scanf("%c",&ch);                     //输入结点的数据信息，假设为字符
	if (ch =='#') bt = NULL;          //建立一棵空树
	else
	{
		bt =(ThrNode*)malloc(sizeof(ThrNode));
		bt->data = ch;  //生成一个结点，数据域为ch
		bt->ltag=0;bt->rtag=0;        //将每个结点的左右标志置为0
        bt->lchild = Creat();          //递归建立左子树
        bt->rchild = Creat();          //递归建立右子树
    }
    return bt;
}
//遍历二叉链表，并建立中序线索
void InThrBiTree(ThrNode*bt,ThrNode *pre)
{
     if (bt == NULL) return;	 
     ThrBiTree(bt->lchild, pre);
     if (bt->lchild == NULL)       //对bt的左指针进行处理
	 {
		 bt->ltag = 1; 
		 bt->lchild = pre;         //设置pre的前驱线索
	 }
	 if (bt->rchild == NULL) bt->rtag = 1;    //对bt的右指针进行处理
	 if (pre!=NULL&&pre->rtag == 1) pre->rchild = bt;      //设置pre的后继线索
	 pre = bt;
	 ThrBiTree(bt->rchild, pre);
}

ThrNode * CreatInThrBiTree()
{
	ThrNode *bt=Creat();       //前序建立二叉树
	ThrBiTree(bt,NULL);            //创建中序线索二叉树	
	return bt;
}

ThrNode *PreNode(ThrNode *p)
{
	ThrNode *q;
	if(p->ltag==1)q = p->lchild; //ltag为1，可以直接得到前驱结点
	else
	{
		q=p->lchild;  //指向结点p的左孩子
		while(q->rtag==0)q=q->rchild;//查找p的左子树的最右下结点
	}
	return q;
}

ThrNode *NextNode(ThrNode *p)
{
	ThrNode *q;
	if(p->rtag==1)q = p->rchild; //rtag为1，可以直接得到后继结点
	else
	{
		q=p->rchild;  //指向结点p的右孩子
		while(q->ltag==0)q=q->lchild;//查找p的右子树的最左下结点
	}
	return q;
}

int main()
{
	ThrNode *bt=CreatInThrBiTree();

	
}




