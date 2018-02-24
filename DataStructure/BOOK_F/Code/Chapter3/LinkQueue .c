#include<stdio.h>
#include <stdlib.h>
typedef int ElemType;     //���еĴ洢����
typedef struct QNode// ���н������
{

	ElemType data;
	struct QNode  *next;
} QNode;
typedef struct      // ����������
{ 
    QNode *front;  // ��ͷָ��
    QNode *rear;   // ��βָ��
} LinkQueue;       



//����նӣ�����ɹ�������1�����ʧ�ܣ�����0
int InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear =(QNode *)malloc(sizeof(QNode));
	if (Q->front==NULL)return 0; //�洢����ʧ��
	Q->front->next = NULL;
	return 1;
}
// ����Ԫ��eΪQ���µĶ�βԪ�� ,����ɹ�������1�����ʧ�ܣ�����0
int EnQueue (LinkQueue *Q, ElemType e)
{
	QNode *p=(QNode *)malloc(sizeof(QNode));
	if (p==NULL)return 0;   //�洢����ʧ��
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;  //��p���뵽��β
	Q->rear = p;    //��βΪp
	return 1;
}

//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ�����򷵻�NULL
ElemType DeQueue (LinkQueue *Q) 
{
	QNode *p;
	ElemType e;
	if(Q->front==Q->rear)return 0;//����Ϊ��
	p=Q->front->next; //pָ���ͷ���
	e=p->data;
	Q->front->next=p->next; //front��next��ָ���ͷ�ĺ�һ���
	if (Q->rear==p)Q->rear = Q->front; //���������ֻ��һ����㣬��ɾ���󣬶���Ϊ��
	free (p);
	return e;
}
//��ջ���գ�����e���ض�ͷԪ�أ����򷵻�NULL
ElemType GetFront(LinkQueue Q)
{
	if (Q.front == Q.rear)  return NULL; //����Ϊ��
    return  Q.front->next->data;
}
//������Ϊ��ջ���򷵻�1�����򷵻�0 
int QueueEmpty(LinkQueue Q)//ջ�ǿ�
{ 
	if(Q.front == Q.rear)return 1; //����Ϊ��
	else return 0;
}



int main()
{
	LinkQueue q ;
	ElemType e;
	system("title ��3�� ������");

	InitQueue(&q);  //��ʼ������
	EnQueue(&q,3);EnQueue(&q,4);EnQueue(&q,5);EnQueue(&q,6); //���ν�3��4��5��6����
	e=DeQueue(&q);printf("���ӵ�Ԫ��Ϊ:%d\n",e); //��ջ����ӡ��ͷԪ��
	EnQueue(&q,7);//7����
	e=DeQueue(&q);//����
	EnQueue(&q,8);//8����
	printf("������Ԫ�����γ�ջ:");
	while((e=DeQueue(&q))!=NULL)//����Ԫ�����γ��Ӳ���ӡ
	{		
		printf("%3d",e);
	}
	printf("\n");;
	return 0;
}






