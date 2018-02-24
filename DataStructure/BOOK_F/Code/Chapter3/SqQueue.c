#include<stdio.h>
#include <stdlib.h>

#define QUEUESIZE 100         //队列的允许的最大长度

typedef struct Client
{
	int arrive;
	int treat;
}Client;
//typedef Client ElemType;     //队列的存储类型

typedef int ElemType;     //队列的存储类型
typedef struct  SqQueue
{
	ElemType  *data;      //队列存储空间的首地址
	int front;         //队头位置：指向当前队头元素
	int rear;    //队尾位置：指向当前队尾元素的下一位置
}SqQueue;             // 循环队列


//构造空队，如果成功，返回1，如果失败，返回0
int InitQueue(SqQueue *Q)
{
	Q->data=(ElemType *)malloc(QUEUESIZE*sizeof(SqQueue));
	if (Q->data==NULL)return 0; // 存储分配失败 
	Q->front=Q->rear=0;	
	return 1;
 }
// 插入元素e为Q的新的队尾元素 ,如果成功，返回1，如果失败，返回0
int EnQueue (SqQueue *Q,ElemType e)
{ 
    if ((Q->rear+1) % QUEUESIZE == Q->front) 
        return 0; //队列满
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1) % QUEUESIZE; //队尾后移一位
    return 1;
}
//若队列不空，则删除Q的队头元素，用e返回其值,并返回1；否则返回0
int DeQueue (SqQueue *Q,ElemType *e) 
{
	if (Q->front == Q->rear)  return 0; //队列为空
    *e = Q->data[Q->front];
    Q->front = (Q->front+1) % QUEUESIZE; //队头后移一位
    return 1;
}
//若栈不空，则用e返回队头元素,并返回1；否则返回0
int GetFront(SqQueue Q,ElemType *e)
{
	if (Q.front == Q.rear)  return 0; //队列为空
	*e=Q.data[Q.front];
    return  1;
 }
//若队列为空栈，则返回1，否则返回0 
int QueueEmpty(SqQueue Q)//栈非空
{ 
	if(Q.front == Q.rear)return 1; //队列为空
	else return 0;
}
//返回队列的元素个数，即队列的长度
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
	do//约定每轮循环，处理一位客户
	{  
		printf("客户模拟到达时间和需要办理业务的时间:(到达时间为0，则表示结束)");
		scanf("%d%d",&temp.arrive,&temp.treat);
		//下一位客户的到达时间在当前客户处理结束之前
		if(temp.arrive>0 && temp.arrive<=finish)
		{
			EnQueue(&Q,temp);// 暂存变量中的客户信息进队			
        }
		if(QueueEmpty(Q)==1&& temp.arrive>0)//等待队列为空，但还有客户
		{ 
			dwait+=temp.arrive-clock; //累计业务员总等待时间
			clock=temp.arrive;     //时钟推进到暂存变量中的客户的到达时间
			EnQueue(&Q,temp); //暂存变量中的客户信息进队
		}
		if(temp.arrive>0)
		{
			DeQueue(&Q,&curr);//出队一位客户信息
			count++; //累计客户人数
			wait+=clock-curr.arrive;  //累计到客户的总等待时间
			finish=clock+curr.treat;//设定业务办理结束时间
			clock=finish;   // 时钟推进到当前客户办理结束时间
		}
	}while(temp.arrive>0);
	printf("\t结果：\n\t业务员等待时间:%d\n",dwait);
	printf("\t客户平均等待时间:%.0f\n",(double)wait/count);
	printf("\t模拟总时间:%d\n",clock);
	printf("\t客户人数:%d\n",count);
	printf("\t总等待时间:%d\n",wait);
}
int main()
{
	system("title 第3章 模拟服务前台的排队现象问题");
	BankQueue();

}*/


int main()
{
	
	SqQueue q ;
	ElemType e;
	system("title 第3章 循环队列");
	InitQueue(&q); //初始化队列
	//依次将3，4，5，6进队
	EnQueue(&q,3);EnQueue(&q,4);EnQueue(&q,5);EnQueue(&q,6); 
	DeQueue(&q,&e);printf("出队的元素为:%d\n",e);  //出栈并打印队头元素
	EnQueue(&q,7); //7进队
	DeQueue(&q,&e); //出队
	EnQueue(&q,8); //8进队
	printf("队列中元素依次出栈:");
	while((DeQueue(&q,&e))!=NULL)//队中元素依次出队并打印
		printf("%3d",e);
	printf("\n");;
	return 0;


}






