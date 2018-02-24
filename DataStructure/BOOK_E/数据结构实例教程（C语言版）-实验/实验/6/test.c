#include "stdio.h"
typedef struct
{
	char name[20];
	char sex;
}stu;
//front指向头元素，rear指向尾元素下一个空闲的空间
//定义队头    
typedef struct
{
    stu data[10];
    int front,rear;
}Queue;
//队列初始化
void initQue(Queue *q)
{
	q->front=0;
    q->rear=0;
}
//判断队列是否满
int isFull(Queue *q)
{
    if(q->front==(q->rear+1)%10) 
      return 1;
    else
	  return 0;
}
//判断队列是否空
int isEmpty(Queue *q)
{
    if(q->front==q->rear) 
       return 1;
    else 
	   return 0;
}
//进队操作
void enQue(Queue *q,stu x)
{
    if(isFull(q)) printf("overflow!");
    q->data[q->rear]=x;
    q->rear=(q->rear+1)%10; 
}
//出队操作
stu deleteQue(Queue *q)
{
    stu x;
    if(isEmpty(q))
       return;
    x=q->data[q->front];
    q->front =(q->front +1)%10;
	return x;
}
//取队头元素操作
stu getQue(Queue *q)
{
    stu x;
    if(isEmpty(q))
       return;
    x=q->data[q->front];
    return x;
}
//舞伴配对
void dancestu(stu dancer[],int num)
{
    int i;
	stu p;
	Queue mdancers,fdancers;
	initQue(&mdancers);
	initQue(&fdancers);
	for(i=0;i<num;i++)
	{
		p=dancer[i];
		if(p.sex=='f')
			enQue(&fdancers,p);
		else
            enQue(&mdancers,p);
	}
	printf("舞伴分配如下:\n");
	while(!isEmpty(&fdancers)&&!isEmpty(&mdancers))
	{
		p=deleteQue(&fdancers);//女士出队
		printf("%s     ",p.name);
		p=deleteQue(&mdancers);//男士出队
		printf("%s     \n",p.name);
	}
	if(!isEmpty(&fdancers))
	{
		p=getQue(&fdancers);
		printf("下一轮中女舞者%s将第一个得到男舞伴!",p.name);
	}
	if(!isEmpty(&mdancers))
	{
		p=getQue(&mdancers);
		printf("下一轮中男舞者%s将第一个得到女舞伴!",p.name);
	}

}
main()
{
    int i;
    stu dancers[9];
    printf("请输入舞者姓名和性别:\n");
	for(i=0;i<9;i++)
	{
        scanf("%s",dancers[i].name);
	    getchar();
		scanf("%c",&dancers[i].sex);   
	}
	dancestu(dancers,9);//调用舞伴配对函数
}
