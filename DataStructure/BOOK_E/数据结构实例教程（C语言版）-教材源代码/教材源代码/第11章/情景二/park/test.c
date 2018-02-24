/*停车场管理系统*/
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<malloc.h>
/*------------------------------------------------------------------------------*/ 
#define Max 10
int getn()
{
	int n;
	printf("\n     欢迎光临万达停车场，");
	printf("本停车场管理实行24小时制，停车每分钟0.1元.\n\n");
	printf("===============================================================================\n");
	printf("\n请输入停车场可容纳的车(最多10辆):");
	scanf("%d",&n);
	fflush(stdin);
	do{
		if(n<1 || n>10)
		{
			printf("输入的车辆数不在要求范围内，请重新输入！");
			scanf("%d",&n);
			fflush(stdin);
		}
		else break;
	}while(n<1 || n>10);
	return n;
}

typedef struct time
{ 
	int hour; 
	int min; 
}Time; /*时间结点*/ 
typedef struct node
{ 
	char num[10];
	Time reach; 
	Time leave; 
}CarNode; /*车辆信息结点*/ 
typedef struct NODE
{ 
	CarNode *stack[Max+1];
	int top; 
}SeqStackCar; /*模拟车站*/
typedef struct car
{ 
	CarNode *data;
	struct car *next; 
}QueueNode; 
typedef struct Node
{ 
	QueueNode *head; 
	QueueNode *rear; 
}LinkQueueCar; /*模拟通道*/ 
void InitStack(SeqStackCar *,int n); /*声明栈*/
int InitQueue(LinkQueueCar *); /*声明便道*/
int Arrival(SeqStackCar *,LinkQueueCar *,int n); /*车辆进站*/
void Leave(SeqStackCar *,SeqStackCar *,LinkQueueCar *,int n); /*车辆出站*/
void List(SeqStackCar,LinkQueueCar); /*显示存车信息*/  

void InitStack(SeqStackCar *s,int n) /*初始化栈*/
{  
	int i; 
	s->top=0; 
	for(i=0;i<=n;i++)
		s->stack[s->top]=NULL; 
} 

int InitQueue(LinkQueueCar *Q) /*初始化便道*/ 
{ 
	Q->head=(QueueNode *)malloc(sizeof(QueueNode)); 
	if(Q->head!=NULL) 
	{ 
		Q->head->next=NULL; 
		Q->rear=Q->head; 
		return(1); 
	} 
	else return(-1); 
} 

void PRINT(CarNode *p) /*打印出站车的信息*/
{ 
	int A1,A2,B1,B2;
	int a,b,c; 
	printf("\n请输入离开的时间:/**:**/"); 
	scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
	fflush(stdin);
	do{
		if(p->leave.hour<p->reach.hour || (p->leave.hour==p->reach.hour && p->leave.min<p->reach.min))
		{
			printf("输入离开时间比进站时间早，请重新输入！\n");
			scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
			fflush(stdin);
		}
		if(p->leave.hour<0 || p->leave.hour>=24 || p->leave.min<0 || p->leave.min>=60)
		{
			printf("输入的时间格式有错，请重新输入!");
			scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
			fflush(stdin);
		}
		else break;
	}while(p->leave.hour<p->reach.hour || (p->leave.hour==p->reach.hour && p->leave.min<p->reach.min) || p->leave.hour<0 || p->leave.hour>=24 || p->leave.min<0 || p->leave.min>=60);
	printf("车场现在有一辆车离开，请便道里的第一辆车进入车场!\n");
	printf("出站的车的车牌号为:");
	puts(p->num);
	printf("\n");
	A1=p->reach.hour; 
	A2=p->reach.min; 
	B1=p->leave.hour; 
	B2=p->leave.min;
	a=(B1-A1)*60+B2-A2;
	if(a>=60)
	{
		b=a/60;
		c=a-60*b;
	}
	else
	{
		b=0;
		c=a;
	}
	printf("Welcome.");
	printf("\n            收        据\n");
	printf("================================== 车牌号: ");
	puts(p->num);
	printf("\n");
	printf("===================================================\n");
	printf("|进车场时刻 | 出车场时刻 | 停留时间 | 应付（元）|\n");
	printf("====================================================\n");
	printf("|   %d:%d",p->reach.hour,p->reach.min);
	printf("    |   %d:%d",p->leave.hour,p->leave.min);
	printf("    |   %d:%d",b,c);
	printf("  |      %2.1f",0.1*a);
	printf("    |\n");
	printf("-----------------------------------------------------\n");
	free(p);
} 

int Arrival(SeqStackCar *Enter,LinkQueueCar *W,int n) /*车辆到达*/
{  
	CarNode *p; 
	QueueNode *t; 
	int a,b;
	p=(CarNode *)malloc(sizeof(CarNode)); 
	flushall(); 
	printf("\n请输入车牌号(七位，例:陕A12345):\n");
	printf("请严格按照要求输入车牌号，否则系统会出错！\n");
	do{
		a=strlen("陕A12345");
		b=strlen(gets(p->num));
		fflush(stdin);
		if(a!=b)
		{
			printf("输入车牌号格式错误，请重新输入（七位）!\n");
			gets(p->num);
			fflush(stdin);
		}
		else break;
		if(a!=b)
			printf("输入车牌号格式错误，请重新输入（七位）!\n");
	}while(a!=b);
	if(Enter->top<n) /*车场未满，车进车场*/
	{ 
		Enter->top++; 
		printf("\n车辆在车场第%d位置.",Enter->top); 
		fflush(stdin);
		printf("\n请输入到达时间:/**:**/"); 
		scanf("%d:%d",&(p->reach.hour),&(p->reach.min));
		fflush(stdin);
		do{
			if(p->reach.hour<0 || p->reach.hour>=24 || p->reach.min<0 || p->reach.min>=60)
			{
				printf("输入的时间格式有错，请重新输入!");
				scanf("%d:%d",&(p->reach.hour),&(p->reach.min));
				fflush(stdin);
			}
			else
				break;
		}while(p->reach.hour<0 || p->reach.hour>=24 || p->reach.min<0 || p->reach.min>=60);
		Enter->stack[Enter->top]=p; 
		return(1); 
	} 
	else /*车场已满，车进便道*/ 
	{  
		printf("\n请该车在便道稍作等待!\n");
		t=(QueueNode *)malloc(sizeof(QueueNode)); 
		t->data=p; 
		t->next=NULL;  
		W->rear->next=t; 
		W->rear=t; 
		return(1); 
	} 
} 

void Leave(SeqStackCar *Enter,SeqStackCar *Temp,LinkQueueCar *W,int n)
{ /*车辆离开*/ 
	int room; 
	CarNode *p,*t; 
	QueueNode *q; 
	/*判断车场内是否有车*/ 
	if(Enter->top>0) /*有车*/  
	{  
		while(1) /*输入离开车辆的信息*/  
		{ 
			printf("\n请输入要离开的车在车场的位置/1--%d/：",Enter->top);
			scanf("%d",&room);
			fflush(stdin); 
			if(room>=1&&room<=Enter->top) break; 
		} 
		while(Enter->top>room) /*车辆离开*/ 
		{ 
			Temp->top++; 
			Temp->stack[Temp->top]=Enter->stack[Enter->top]; 
			Enter->stack[Enter->top]=NULL; 
			Enter->top--; 
		}  
		p=Enter->stack[Enter->top]; 
		Enter->stack[Enter->top]=NULL; 
		Enter->top--; 
		while(Temp->top>=1) 
		{ 
			Enter->top++; 
			Enter->stack[Enter->top]=Temp->stack[Temp->top]; 
			Temp->stack[Temp->top]=NULL; 
			Temp->top--; 
		} 
		PRINT(p);
		/*判断通道上是否有车及车站是否已满*/ 
		if((W->head!=W->rear)&&Enter->top<n) /*便道的车辆进入车场*/
		{
			q=W->head->next; 
			t=q->data; 
			Enter->top++; 
			printf("\n现在请便道上的车进入车场.该车的车牌号为:");
			puts(t->num);
			printf("\n该车进入车场第%d位置.",Enter->top);
			printf("\n请输入现在的时间(即该车进站的时间)/**:**/:");
			scanf("%d:%d",&(t->reach.hour),&(t->reach.min));
			fflush(stdin); 
			do{
				if(t->reach.hour<0 || t->reach.hour>=24 || t->reach.min<0 || t->reach.min>=60)
				{
					printf("输入的时间格式有错，请重新输入!");
					scanf("%d:%d",&(t->reach.hour),&(t->reach.min));
					fflush(stdin);
				}
				else
					break;
			}while(t->reach.hour<0 || t->reach.hour>=24 || t->reach.min<0 || t->reach.min>=60);
			W->head->next=q->next; 
			if(q==W->rear) W->rear=W->head; 
			Enter->stack[Enter->top]=t; 
			free(q); 
		} 
		else printf("\n目前便道里没有车.\n");
	} 
	else printf("\n目前车场里没有车，来车请直接进入车场!"); /*没车*/
} 

void List1(SeqStackCar *S) /*列表显示车场存车信息*/
{  
	int i; 
	if(S->top>0) /*判断车站内是否有车*/ 
	{ 
		printf("\n                                车场存车信息\n"); 
		printf("\n                        位置      到达时间       车牌号\n"); 
		for(i=1;i<=S->top;i++) 
		{ 
			printf("\n                          %d ",i); 
			printf("        %d:%d         ",S->stack[i]->reach.hour,S->stack[i]->reach.min); 
			puts(S->stack[i]->num); 
		} 
	} 
	else printf("\n目前车场里没有车");
} 

void List2(LinkQueueCar *W) /*列表显示便道信息*/ 
{  
	QueueNode *p; 
	p=W->head->next; 
	if(W->head!=W->rear) /*判断通道上是否有车*/ 
	{ 
		printf("\n目前正在等待车辆的号码为:");
		while(p!=NULL) 
		{ 
			puts(p->data->num);
			printf("     "); 
			p=p->next; 
		} 
	} 
	else printf("\n目前便道里没有车.");
} 
void List(SeqStackCar S,LinkQueueCar W) 
{ 
	int flag,tag; 
	flag=1; 
	while(flag) 
	{ 
		printf("\n1.车场\n2.便道\n3.返回\n"); 
		while(1) 
		{ printf("\n请选择 1|2|3:");  
		scanf("%d",&tag);
		fflush(stdin);
		do{
			if(tag<1||tag>3)
			{
				printf("输入有误，请按要求重新输入!");
				scanf("%d",&tag);
				fflush(stdin);
			}
			else
				break;
		}while(tag>3 && tag<1);
		break;
		} 
		switch(tag) 
		{ 
		case 1:List1(&S);break; /*列表显示车场信息*/ 
		case 2:List2(&W);break; /*列表显示便道信息*/ 
		case 3:flag=0;break;/*返回*/
		default: break; 
		} 
	} 
}

void main() 
{ 
	SeqStackCar Enter,Temp; 
	LinkQueueCar Wait;
	int ch;
	int n; 
	n=getn();
	InitStack(&Enter,n); /*初始化车场*/
	InitStack(&Temp,n); /*初始化让路的临时栈*/
	InitQueue(&Wait); /*初始化便道*/
	while(1) 
	{
		printf("             ***************************************************\n");	
		printf("               1. 车辆进站");
		printf(" 2. 车辆出站");
		printf(" 3. 存车信息");
		printf(" 4. 退出系统\n"); 
		printf("             ***************************************************\n");
		while(1) 
		{ printf("请选择： 1|2|3|4.\n");
		  scanf("%d",&ch);
		  fflush(stdin);
		  do{
			 if(ch>4 || ch<1)
			 {
				printf("输入有误，请重新输入!");
				scanf("%d",&ch);
				fflush(stdin);
			 }
			 else
				break;
		  }while(ch>4 || ch<1);
		  break;
		}
		switch(ch) 
		{  
		  case 1:Arrival(&Enter,&Wait,n);break; /*车辆进站*/
		  case 2:Leave(&Enter,&Temp,&Wait,n);break; /*车辆出站*/
		  case 3:List(Enter,Wait);break; /*存车信息*/
		  case 4:exit(0); /*退出系统*/
		  default:break;
		}  
	} 
}
