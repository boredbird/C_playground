#include"stdio.h"
#include"stdlib.h"
#define QUEUESIZE 100  //���е��������󳤶�
typedef int ElemType;     //���еĴ洢����
typedef struct  SqQueue
{
	ElemType  *data;    //���д洢�ռ���׵�ַ
	int front;            //��ͷλ�ã�ָ��ǰ��ͷԪ��
	int rear;             //��βλ�ã�ָ��ǰ��βԪ�ص���һλ��
}SqQueue;               //ѭ������
//����նӣ�����ɹ�������1�����ʧ�ܣ�����0
int InitQueue(SqQueue *Q)
{
	Q->data=(ElemType *)malloc(QUEUESIZE*sizeof(SqQueue));
	if (Q->data==NULL)return 0; // �洢����ʧ�� 
	Q->front=Q->rear=0;	
	return 1;
 }

//���ض��е�Ԫ�ظ����������еĳ���
int QueueLength(SqQueue Q)
{ 
	return (Q.rear-Q.front+QUEUESIZE) % QUEUESIZE;
}

// ����Ԫ��eΪQ���µĶ�βԪ�� ,����ɹ�������1�����ʧ�ܣ�����0
int EnQueue (SqQueue *Q,ElemType e)
{ 
    if ((Q->rear+1) % QUEUESIZE == Q->front) return 0;  //������
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1) % QUEUESIZE;    //��β����һλ
    return 1;
}

//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������1�����򷵻�0
int DeQueue (SqQueue *Q,ElemType *e) 
{
	if (Q->front == Q->rear)  return 0;  //����Ϊ��
    *e = Q->data[Q->front];
    Q->front = (Q->front+1) % QUEUESIZE;  //��ͷ����һλ
    return 1;
}
//��ջ���գ�����e���ض�ͷԪ��,������1�����򷵻�0
int GetFront(SqQueue Q,ElemType *e)
{
	if (Q.front == Q.rear)  return 0; //����Ϊ��
	*e= Q.data[Q.front];
    return 1;
}


void YangHuiTriangle( )
{
	int j,n,N;
	ElemType x,temp;
	printf("������������");
	scanf("%d",&N);
	SqQueue Q;
	InitQueue (&Q);
	EnQueue (&Q,1);//��һ��Ԫ�����
	for(n=2;n<=N+1;n++) 
	{
		EnQueue (&Q,1);   //��n�еĵ�һ��Ԫ�����
				for(int i=1;i<=n-2;i++) //���ö��е�n-1��Ԫ�ز�����n�е��м�n-2��Ԫ�ز����
		{
			DeQueue (&Q,&temp);
			printf("%3d ",temp);     // ��ӡ��n-1�е�Ԫ��
			GetFront(Q,&x);
			temp=temp+x ;      //���ö��е�n-1��Ԫ�ز�����n��Ԫ��
			EnQueue (&Q,temp);
		}
		DeQueue (&Q,&x); 
		printf("%3d\n",x);    // ��ӡ��n-1�е����һ��Ԫ��
		EnQueue (&Q,1); // ��n�е����һ��Ԫ�����
	}
}
