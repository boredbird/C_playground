/*ͣ��������ϵͳ*/
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<malloc.h>
/*------------------------------------------------------------------------------*/ 
#define Max 10
int getn()
{
	int n;
	printf("\n     ��ӭ�������ͣ������");
	printf("��ͣ��������ʵ��24Сʱ�ƣ�ͣ��ÿ����0.1Ԫ.\n\n");
	printf("===============================================================================\n");
	printf("\n������ͣ���������ɵĳ�(���10��):");
	scanf("%d",&n);
	fflush(stdin);
	do{
		if(n<1 || n>10)
		{
			printf("����ĳ���������Ҫ��Χ�ڣ����������룡");
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
}Time; /*ʱ����*/ 
typedef struct node
{ 
	char num[10];
	Time reach; 
	Time leave; 
}CarNode; /*������Ϣ���*/ 
typedef struct NODE
{ 
	CarNode *stack[Max+1];
	int top; 
}SeqStackCar; /*ģ�⳵վ*/
typedef struct car
{ 
	CarNode *data;
	struct car *next; 
}QueueNode; 
typedef struct Node
{ 
	QueueNode *head; 
	QueueNode *rear; 
}LinkQueueCar; /*ģ��ͨ��*/ 
void InitStack(SeqStackCar *,int n); /*����ջ*/
int InitQueue(LinkQueueCar *); /*�������*/
int Arrival(SeqStackCar *,LinkQueueCar *,int n); /*������վ*/
void Leave(SeqStackCar *,SeqStackCar *,LinkQueueCar *,int n); /*������վ*/
void List(SeqStackCar,LinkQueueCar); /*��ʾ�泵��Ϣ*/  

void InitStack(SeqStackCar *s,int n) /*��ʼ��ջ*/
{  
	int i; 
	s->top=0; 
	for(i=0;i<=n;i++)
		s->stack[s->top]=NULL; 
} 

int InitQueue(LinkQueueCar *Q) /*��ʼ�����*/ 
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

void PRINT(CarNode *p) /*��ӡ��վ������Ϣ*/
{ 
	int A1,A2,B1,B2;
	int a,b,c; 
	printf("\n�������뿪��ʱ��:/**:**/"); 
	scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
	fflush(stdin);
	do{
		if(p->leave.hour<p->reach.hour || (p->leave.hour==p->reach.hour && p->leave.min<p->reach.min))
		{
			printf("�����뿪ʱ��Ƚ�վʱ���磬���������룡\n");
			scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
			fflush(stdin);
		}
		if(p->leave.hour<0 || p->leave.hour>=24 || p->leave.min<0 || p->leave.min>=60)
		{
			printf("�����ʱ���ʽ�д�����������!");
			scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
			fflush(stdin);
		}
		else break;
	}while(p->leave.hour<p->reach.hour || (p->leave.hour==p->reach.hour && p->leave.min<p->reach.min) || p->leave.hour<0 || p->leave.hour>=24 || p->leave.min<0 || p->leave.min>=60);
	printf("����������һ�����뿪��������ĵ�һ�������복��!\n");
	printf("��վ�ĳ��ĳ��ƺ�Ϊ:");
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
	printf("\n            ��        ��\n");
	printf("================================== ���ƺ�: ");
	puts(p->num);
	printf("\n");
	printf("===================================================\n");
	printf("|������ʱ�� | ������ʱ�� | ͣ��ʱ�� | Ӧ����Ԫ��|\n");
	printf("====================================================\n");
	printf("|   %d:%d",p->reach.hour,p->reach.min);
	printf("    |   %d:%d",p->leave.hour,p->leave.min);
	printf("    |   %d:%d",b,c);
	printf("  |      %2.1f",0.1*a);
	printf("    |\n");
	printf("-----------------------------------------------------\n");
	free(p);
} 

int Arrival(SeqStackCar *Enter,LinkQueueCar *W,int n) /*��������*/
{  
	CarNode *p; 
	QueueNode *t; 
	int a,b;
	p=(CarNode *)malloc(sizeof(CarNode)); 
	flushall(); 
	printf("\n�����복�ƺ�(��λ����:��A12345):\n");
	printf("���ϸ���Ҫ�����복�ƺţ�����ϵͳ�����\n");
	do{
		a=strlen("��A12345");
		b=strlen(gets(p->num));
		fflush(stdin);
		if(a!=b)
		{
			printf("���복�ƺŸ�ʽ�������������루��λ��!\n");
			gets(p->num);
			fflush(stdin);
		}
		else break;
		if(a!=b)
			printf("���복�ƺŸ�ʽ�������������루��λ��!\n");
	}while(a!=b);
	if(Enter->top<n) /*����δ������������*/
	{ 
		Enter->top++; 
		printf("\n�����ڳ�����%dλ��.",Enter->top); 
		fflush(stdin);
		printf("\n�����뵽��ʱ��:/**:**/"); 
		scanf("%d:%d",&(p->reach.hour),&(p->reach.min));
		fflush(stdin);
		do{
			if(p->reach.hour<0 || p->reach.hour>=24 || p->reach.min<0 || p->reach.min>=60)
			{
				printf("�����ʱ���ʽ�д�����������!");
				scanf("%d:%d",&(p->reach.hour),&(p->reach.min));
				fflush(stdin);
			}
			else
				break;
		}while(p->reach.hour<0 || p->reach.hour>=24 || p->reach.min<0 || p->reach.min>=60);
		Enter->stack[Enter->top]=p; 
		return(1); 
	} 
	else /*�����������������*/ 
	{  
		printf("\n��ó��ڱ�������ȴ�!\n");
		t=(QueueNode *)malloc(sizeof(QueueNode)); 
		t->data=p; 
		t->next=NULL;  
		W->rear->next=t; 
		W->rear=t; 
		return(1); 
	} 
} 

void Leave(SeqStackCar *Enter,SeqStackCar *Temp,LinkQueueCar *W,int n)
{ /*�����뿪*/ 
	int room; 
	CarNode *p,*t; 
	QueueNode *q; 
	/*�жϳ������Ƿ��г�*/ 
	if(Enter->top>0) /*�г�*/  
	{  
		while(1) /*�����뿪��������Ϣ*/  
		{ 
			printf("\n������Ҫ�뿪�ĳ��ڳ�����λ��/1--%d/��",Enter->top);
			scanf("%d",&room);
			fflush(stdin); 
			if(room>=1&&room<=Enter->top) break; 
		} 
		while(Enter->top>room) /*�����뿪*/ 
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
		/*�ж�ͨ�����Ƿ��г�����վ�Ƿ�����*/ 
		if((W->head!=W->rear)&&Enter->top<n) /*����ĳ������복��*/
		{
			q=W->head->next; 
			t=q->data; 
			Enter->top++; 
			printf("\n���������ϵĳ����복��.�ó��ĳ��ƺ�Ϊ:");
			puts(t->num);
			printf("\n�ó����복����%dλ��.",Enter->top);
			printf("\n���������ڵ�ʱ��(���ó���վ��ʱ��)/**:**/:");
			scanf("%d:%d",&(t->reach.hour),&(t->reach.min));
			fflush(stdin); 
			do{
				if(t->reach.hour<0 || t->reach.hour>=24 || t->reach.min<0 || t->reach.min>=60)
				{
					printf("�����ʱ���ʽ�д�����������!");
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
		else printf("\nĿǰ�����û�г�.\n");
	} 
	else printf("\nĿǰ������û�г���������ֱ�ӽ��복��!"); /*û��*/
} 

void List1(SeqStackCar *S) /*�б���ʾ�����泵��Ϣ*/
{  
	int i; 
	if(S->top>0) /*�жϳ�վ���Ƿ��г�*/ 
	{ 
		printf("\n                                �����泵��Ϣ\n"); 
		printf("\n                        λ��      ����ʱ��       ���ƺ�\n"); 
		for(i=1;i<=S->top;i++) 
		{ 
			printf("\n                          %d ",i); 
			printf("        %d:%d         ",S->stack[i]->reach.hour,S->stack[i]->reach.min); 
			puts(S->stack[i]->num); 
		} 
	} 
	else printf("\nĿǰ������û�г�");
} 

void List2(LinkQueueCar *W) /*�б���ʾ�����Ϣ*/ 
{  
	QueueNode *p; 
	p=W->head->next; 
	if(W->head!=W->rear) /*�ж�ͨ�����Ƿ��г�*/ 
	{ 
		printf("\nĿǰ���ڵȴ������ĺ���Ϊ:");
		while(p!=NULL) 
		{ 
			puts(p->data->num);
			printf("     "); 
			p=p->next; 
		} 
	} 
	else printf("\nĿǰ�����û�г�.");
} 
void List(SeqStackCar S,LinkQueueCar W) 
{ 
	int flag,tag; 
	flag=1; 
	while(flag) 
	{ 
		printf("\n1.����\n2.���\n3.����\n"); 
		while(1) 
		{ printf("\n��ѡ�� 1|2|3:");  
		scanf("%d",&tag);
		fflush(stdin);
		do{
			if(tag<1||tag>3)
			{
				printf("���������밴Ҫ����������!");
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
		case 1:List1(&S);break; /*�б���ʾ������Ϣ*/ 
		case 2:List2(&W);break; /*�б���ʾ�����Ϣ*/ 
		case 3:flag=0;break;/*����*/
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
	InitStack(&Enter,n); /*��ʼ������*/
	InitStack(&Temp,n); /*��ʼ����·����ʱջ*/
	InitQueue(&Wait); /*��ʼ�����*/
	while(1) 
	{
		printf("             ***************************************************\n");	
		printf("               1. ������վ");
		printf(" 2. ������վ");
		printf(" 3. �泵��Ϣ");
		printf(" 4. �˳�ϵͳ\n"); 
		printf("             ***************************************************\n");
		while(1) 
		{ printf("��ѡ�� 1|2|3|4.\n");
		  scanf("%d",&ch);
		  fflush(stdin);
		  do{
			 if(ch>4 || ch<1)
			 {
				printf("������������������!");
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
		  case 1:Arrival(&Enter,&Wait,n);break; /*������վ*/
		  case 2:Leave(&Enter,&Temp,&Wait,n);break; /*������վ*/
		  case 3:List(Enter,Wait);break; /*�泵��Ϣ*/
		  case 4:exit(0); /*�˳�ϵͳ*/
		  default:break;
		}  
	} 
}
