#include<stdio.h>
#include <stdlib.h>
#define MAXNODE 20

typedef  char ElemType;   //Ĭ����������Ϊchar
//���Ա�ĵ�����洢�ṹ����
typedef struct BiNode{
   ElemType data;
   struct BiNode *lchild,*rchild;    //���Һ���ָ��
}BiNode;

void Visit(ElemType data)
{
	printf("%c",data);
}
void PreOrder(BiNode *bt) 
{
    if (bt == NULL)  return;              //�ݹ���õĽ�������
    else
	{
		Visit(bt->data);                  //���ʸ����bt��������
        PreOrder(bt->lchild);             //ǰ��ݹ����bt��������
        PreOrder(bt->rchild);             //ǰ��ݹ����bt��������  
    }
}

void InOrder (BiNode *bt)
{
     if (bt == NULL) return;                 //�ݹ���õĽ�������
     else 
	 {
         InOrder(bt->lchild);                //����ݹ����bt��������
         Visit(bt->data);                    //���ʸ����bt��������
         InOrder(bt->rchild);                //����ݹ����bt��������
    }
}

void PostOrder(BiNode *bt)
{ 
     if (bt == NULL) return;                //�ݹ���õĽ�������
     else 
	 {
         PostOrder(bt->lchild);             //����ݹ����bt��������
         PostOrder(bt->rchild);             //����ݹ����bt��������
         Visit(bt->data);                   //���ʸ����bt��������
    }
}

void LeverOrder(BiNode *bt)
{
	 int front,rear;
	 BiNode *Q[MAXNODE],*q;
     front = rear = 0;            //����ѭ�����У�
     if (bt == NULL) return;       //������Ϊ�գ��㷨����
     Q[rear] = bt;rear=(rear+1)%MAXNODE;             //��ָ�����
     while (front != rear)          //�����зǿ�ʱ
     {
          q = Q[front]; front=(front+1)%MAXNODE;        //����
          Visit(q->data);   
          if (q->lchild != NULL){Q[rear] = q->lchild;rear=(rear+1)%MAXNODE;}
          if (q->rchild != NULL){Q[rear] = q->rchild;rear=(rear+1)%MAXNODE;}
     }
}

BiNode *Creat()
{
	BiNode *bt;
    ElemType ch;
    scanf("%c",&ch);                           //�������������Ϣ������Ϊ�ַ�
    if (ch =='#') bt = NULL;                //����һ�ÿ���
    else
    {
        bt = (BiNode*)malloc(sizeof(BiNode));;
		bt->data = ch;  //����һ����㣬������Ϊch
        bt->lchild = Creat();        //�ݹ齨��������
        bt->rchild = Creat();        //�ݹ齨��������
    }
    return bt;
}

void Release(BiNode *bt)
{
    if (bt == NULL) return;                 //�ݹ���õĽ�������
    else
    {
        Release(bt->lchild);               //����ݹ����bt��������
        Release(bt->rchild);               //����ݹ����bt��������
        free(bt);                        //���ٸ����bt
    }
}

int main()
{
	BiNode *bt=Creat(); 	//����һ��������BT
	system("title ��5�� ���Ͷ�����-�������ı���");
	printf("ǰ�����:");
	PreOrder(bt);         //ǰ�����
	printf("\n�������:");
	InOrder(bt);       //�������
	printf("\n�������:");
	PostOrder(bt);      //�������
	printf("\n�������:");
	LeverOrder(bt);     //�������
	printf("\n");
	Release(bt);
}





