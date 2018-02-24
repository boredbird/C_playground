#include"stdio.h"
#include"stdlib.h"
#define QUEUESIZE 100  //队列的允许的最大长度
typedef int ElemType;     //队列的存储类型
typedef struct  SqQueue
{
	ElemType  *data;    //队列存储空间的首地址
	int front;            //队头位置：指向当前队头元素
	int rear;             //队尾位置：指向当前队尾元素的下一位置
}SqQueue;               //循环队列
//构造空队，如果成功，返回1，如果失败，返回0
int InitQueue(SqQueue *Q)
{
	Q->data=(ElemType *)malloc(QUEUESIZE*sizeof(SqQueue));
	if (Q->data==NULL)return 0; // 存储分配失败 
	Q->front=Q->rear=0;	
	return 1;
 }

//返回队列的元素个数，即队列的长度
int QueueLength(SqQueue Q)
{ 
	return (Q.rear-Q.front+QUEUESIZE) % QUEUESIZE;
}

// 插入元素e为Q的新的队尾元素 ,如果成功，返回1，如果失败，返回0
int EnQueue (SqQueue *Q,ElemType e)
{ 
    if ((Q->rear+1) % QUEUESIZE == Q->front) return 0;  //队列满
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1) % QUEUESIZE;    //队尾后移一位
    return 1;
}

//若队列不空，则删除Q的队头元素，用e返回其值，并返回1；否则返回0
int DeQueue (SqQueue *Q,ElemType *e) 
{
	if (Q->front == Q->rear)  return 0;  //队列为空
    *e = Q->data[Q->front];
    Q->front = (Q->front+1) % QUEUESIZE;  //队头后移一位
    return 1;
}
//若栈不空，则用e返回队头元素,并返回1；否则返回0
int GetFront(SqQueue Q,ElemType *e)
{
	if (Q.front == Q.rear)  return 0; //队列为空
	*e= Q.data[Q.front];
    return 1;
}


void YangHuiTriangle( )
{
	int j,n,N;
	ElemType x,temp;
	printf("请输入行数：");
	scanf("%d",&N);
	SqQueue Q;
	InitQueue (&Q);
	EnQueue (&Q,1);//第一行元素入队
	for(n=2;n<=N+1;n++) 
	{
		EnQueue (&Q,1);   //第n行的第一个元素入队
				for(int i=1;i<=n-2;i++) //利用队中第n-1行元素产生第n行的中间n-2个元素并入队
		{
			DeQueue (&Q,&temp);
			printf("%3d ",temp);     // 打印第n-1行的元素
			GetFront(Q,&x);
			temp=temp+x ;      //利用队中第n-1行元素产生第n行元素
			EnQueue (&Q,temp);
		}
		DeQueue (&Q,&x); 
		printf("%3d\n",x);    // 打印第n-1行的最后一个元素
		EnQueue (&Q,1); // 第n行的最后一个元素入队
	}
}
