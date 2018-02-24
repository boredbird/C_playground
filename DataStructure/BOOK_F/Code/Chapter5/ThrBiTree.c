#include<stdio.h>
#include <stdlib.h>
#define MAXNODE 20

typedef  char ElemType;   //Ĭ����������Ϊchar
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
	scanf("%c",&ch);                     //�������������Ϣ������Ϊ�ַ�
	if (ch =='#') bt = NULL;          //����һ�ÿ���
	else
	{
		bt =(ThrNode*)malloc(sizeof(ThrNode));
		bt->data = ch;  //����һ����㣬������Ϊch
		bt->ltag=0;bt->rtag=0;        //��ÿ���������ұ�־��Ϊ0
        bt->lchild = Creat();          //�ݹ齨��������
        bt->rchild = Creat();          //�ݹ齨��������
    }
    return bt;
}
//��������������������������
void InThrBiTree(ThrNode*bt,ThrNode *pre)
{
     if (bt == NULL) return;	 
     ThrBiTree(bt->lchild, pre);
     if (bt->lchild == NULL)       //��bt����ָ����д���
	 {
		 bt->ltag = 1; 
		 bt->lchild = pre;         //����pre��ǰ������
	 }
	 if (bt->rchild == NULL) bt->rtag = 1;    //��bt����ָ����д���
	 if (pre!=NULL&&pre->rtag == 1) pre->rchild = bt;      //����pre�ĺ������
	 pre = bt;
	 ThrBiTree(bt->rchild, pre);
}

ThrNode * CreatInThrBiTree()
{
	ThrNode *bt=Creat();       //ǰ����������
	ThrBiTree(bt,NULL);            //������������������	
	return bt;
}

ThrNode *PreNode(ThrNode *p)
{
	ThrNode *q;
	if(p->ltag==1)q = p->lchild; //ltagΪ1������ֱ�ӵõ�ǰ�����
	else
	{
		q=p->lchild;  //ָ����p������
		while(q->rtag==0)q=q->rchild;//����p���������������½��
	}
	return q;
}

ThrNode *NextNode(ThrNode *p)
{
	ThrNode *q;
	if(p->rtag==1)q = p->rchild; //rtagΪ1������ֱ�ӵõ���̽��
	else
	{
		q=p->rchild;  //ָ����p���Һ���
		while(q->ltag==0)q=q->lchild;//����p���������������½��
	}
	return q;
}

int main()
{
	ThrNode *bt=CreatInThrBiTree();

	
}




