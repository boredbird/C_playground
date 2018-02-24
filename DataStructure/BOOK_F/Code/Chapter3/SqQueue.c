#include<stdio.h>
#include <stdlib.h>

#define QUEUESIZE 100         //���е��������󳤶�

typedef struct Client
{
	int arrive;
	int treat;
}Client;
//typedef Client ElemType;     //���еĴ洢����

typedef int ElemType;     //���еĴ洢����
typedef struct  SqQueue
{
	ElemType  *data;      //���д洢�ռ���׵�ַ
	int front;         //��ͷλ�ã�ָ��ǰ��ͷԪ��
	int rear;    //��βλ�ã�ָ��ǰ��βԪ�ص���һλ��
}SqQueue;             // ѭ������


//����նӣ�����ɹ�������1�����ʧ�ܣ�����0
int InitQueue(SqQueue *Q)
{
	Q->data=(ElemType *)malloc(QUEUESIZE*sizeof(SqQueue));
	if (Q->data==NULL)return 0; // �洢����ʧ�� 
	Q->front=Q->rear=0;	
	return 1;
 }
// ����Ԫ��eΪQ���µĶ�βԪ�� ,����ɹ�������1�����ʧ�ܣ�����0
int EnQueue (SqQueue *Q,ElemType e)
{ 
    if ((Q->rear+1) % QUEUESIZE == Q->front) 
        return 0; //������
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1) % QUEUESIZE; //��β����һλ
    return 1;
}
//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ,������1�����򷵻�0
int DeQueue (SqQueue *Q,ElemType *e) 
{
	if (Q->front == Q->rear)  return 0; //����Ϊ��
    *e = Q->data[Q->front];
    Q->front = (Q->front+1) % QUEUESIZE; //��ͷ����һλ
    return 1;
}
//��ջ���գ�����e���ض�ͷԪ��,������1�����򷵻�0
int GetFront(SqQueue Q,ElemType *e)
{
	if (Q.front == Q.rear)  return 0; //����Ϊ��
	*e=Q.data[Q.front];
    return  1;
 }
//������Ϊ��ջ���򷵻�1�����򷵻�0 
int QueueEmpty(SqQueue Q)//ջ�ǿ�
{ 
	if(Q.front == Q.rear)return 1; //����Ϊ��
	else return 0;
}
//���ض��е�Ԫ�ظ����������еĳ���
int QueueLength(SqQueue Q)
{ 
	return (Q.rear-Q.front+QUEUESIZE) % QUEUESIZE;
}


/*void BankQueue()
{
	int dwait=0,clock=0,wait=0,count=0,finish=0;
	Client temp,curr;
	SqQueue Q;
	InitQueue(&Q);
	do//Լ��ÿ��ѭ��������һλ�ͻ�
	{  
		printf("�ͻ�ģ�⵽��ʱ�����Ҫ����ҵ���ʱ��:(����ʱ��Ϊ0�����ʾ����)");
		scanf("%d%d",&temp.arrive,&temp.treat);
		//��һλ�ͻ��ĵ���ʱ���ڵ�ǰ�ͻ��������֮ǰ
		if(temp.arrive>0 && temp.arrive<=finish)
		{
			EnQueue(&Q,temp);// �ݴ�����еĿͻ���Ϣ����			
        }
		if(QueueEmpty(Q)==1&& temp.arrive>0)//�ȴ�����Ϊ�գ������пͻ�
		{ 
			dwait+=temp.arrive-clock; //�ۼ�ҵ��Ա�ܵȴ�ʱ��
			clock=temp.arrive;     //ʱ���ƽ����ݴ�����еĿͻ��ĵ���ʱ��
			EnQueue(&Q,temp); //�ݴ�����еĿͻ���Ϣ����
		}
		if(temp.arrive>0)
		{
			DeQueue(&Q,&curr);//����һλ�ͻ���Ϣ
			count++; //�ۼƿͻ�����
			wait+=clock-curr.arrive;  //�ۼƵ��ͻ����ܵȴ�ʱ��
			finish=clock+curr.treat;//�趨ҵ��������ʱ��
			clock=finish;   // ʱ���ƽ�����ǰ�ͻ��������ʱ��
		}
	}while(temp.arrive>0);
	printf("\t�����\n\tҵ��Ա�ȴ�ʱ��:%d\n",dwait);
	printf("\t�ͻ�ƽ���ȴ�ʱ��:%.0f\n",(double)wait/count);
	printf("\tģ����ʱ��:%d\n",clock);
	printf("\t�ͻ�����:%d\n",count);
	printf("\t�ܵȴ�ʱ��:%d\n",wait);
}
int main()
{
	system("title ��3�� ģ�����ǰ̨���Ŷ���������");
	BankQueue();

}*/


int main()
{
	
	SqQueue q ;
	ElemType e;
	system("title ��3�� ѭ������");
	InitQueue(&q); //��ʼ������
	//���ν�3��4��5��6����
	EnQueue(&q,3);EnQueue(&q,4);EnQueue(&q,5);EnQueue(&q,6); 
	DeQueue(&q,&e);printf("���ӵ�Ԫ��Ϊ:%d\n",e);  //��ջ����ӡ��ͷԪ��
	EnQueue(&q,7); //7����
	DeQueue(&q,&e); //����
	EnQueue(&q,8); //8����
	printf("������Ԫ�����γ�ջ:");
	while((DeQueue(&q,&e))!=NULL)//����Ԫ�����γ��Ӳ���ӡ
		printf("%3d",e);
	printf("\n");;
	return 0;


}






