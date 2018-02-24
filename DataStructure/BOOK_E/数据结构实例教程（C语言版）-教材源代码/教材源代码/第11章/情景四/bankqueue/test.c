#include "stdio.h"
#include "string.h"
//银行排号队列类型定义
typedef struct
{
  char num[100][5];//排队号码4位，‘\0’占1位
  int front,rear;
}Queue;
Queue ordinary,vip;//定义普通队列和vip队列两个全局变量
//队列初始化
void initQue(Queue *q)
{
	q->front=0;
    q->rear=0;
}
//判断队列是否满
int isFull(Queue *q)
{
    if(q->front==(q->rear+1)%100) 
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
void enQue(Queue *q,char num[])
{
    if(isFull(q)) 
		printf("overflow!");
	else
	{
      strcpy(q->num[q->rear],num);
      q->rear=(q->rear+1)%100;
	}
}
//出队操作
char* deleteQue(Queue *q)
{
    char num[5],*p;
    if(isEmpty(q))
	{
      return NULL;   
	}
	else
	{
      strcpy(num,q->num[q->front]);
      q->front =(q->front+1)%100;
	  p=num;
	  return p;
	}
}
//取队头元素操作
char* getQue(Queue *q)
{
    char num[5],*p;
    if(isEmpty(q))
    {
      return NULL; 
	}
	else
	{
      strcpy(num,q->num[q->front]);
	  p=num;
	  return p;
  	}
}
//输出队列中排队号码
void pri(Queue *q)
{
	int i;
	printf("-------------------------\n");
	for(i=q->front;i<q->rear;i++)
	{
		printf("%s ",q->num[i]);
	}
	printf("\n-------------------------\n");
}
//取普通号操作，相当于进队操作
void ordinary_getnum()
{
   char num[5];
   printf("请输入所取号码:");
   gets(num);
   enQue(&ordinary,num); 
   printf("当前普通排队号码:\n");
   pri(&ordinary);
}
//取vip号操作，相当于进队操作
void vip_getnum()
{
   char num[5];
   printf("请输入所取号码:");
   gets(num);
   enQue(&vip,num); 
   printf("当前vip排队号码:\n");
   pri(&vip);
}
//窗口存取款操作，vip队列优先
void money_get()
{
   char num[5];
   if(isEmpty(&vip)==0)//vip不是空
      strcpy(num,deleteQue(&vip));
   else if(isEmpty(&ordinary)==0)
      strcpy(num,deleteQue(&ordinary));
   else
      strcpy(num,"无人!");
   printf("号码%s开始到窗口存取款!\n",num);
   if(isEmpty(&vip)==0)
	  strcpy(num,getQue(&vip));
   else if(isEmpty(&ordinary)==0)
      strcpy(num,getQue(&ordinary));
   else
      strcpy(num,"无人!");
   printf("下个窗口存取款号码应该为:%s\n",num);
}
//主程序
main()
{
    int choice;
	initQue(&ordinary);//初始化
    initQue(&vip);    //初始化
	printf("**********************************************\n");
    printf(" 1.取普通号 2.取VIP号 3.窗口存取款 4.退出系统\n");
    printf("**********************************************\n");
	while(1)
	{ printf("请输入选项:");
	  scanf("%d",&choice);
	  getchar();
	  switch(choice)
	  {
	    case 1:ordinary_getnum();break;
		case 2:vip_getnum();break;
		case 3:money_get();break;
	  }
	  if(choice==4)
		  break;
	}
}