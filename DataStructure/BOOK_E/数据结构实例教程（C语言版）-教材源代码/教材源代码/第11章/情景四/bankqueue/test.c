#include "stdio.h"
#include "string.h"
//�����źŶ������Ͷ���
typedef struct
{
  char num[100][5];//�ŶӺ���4λ����\0��ռ1λ
  int front,rear;
}Queue;
Queue ordinary,vip;//������ͨ���к�vip��������ȫ�ֱ���
//���г�ʼ������
void initQue(Queue *q)
{
	q->front=0;
    q->rear=0;
}
//�ж϶����Ƿ�������
int isFull(Queue *q)
{
    if(q->front==(q->rear+1)%100) 
      return 1;
    else
	  return 0;
}
//�ж϶����Ƿ�գ���
int isEmpty(Queue *q)
{
    if(q->front==q->rear) 
       return 1;
    else 
	   return 0;
}
//���Ӳ���
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
//���Ӳ�������
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
//ȡ��ͷԪ�ز���
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
//����������ŶӺ���
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
//ȡ��ͨ�Ų������൱�ڽ��Ӳ���
void ordinary_getnum()
{
   char num[5];
   printf("��������ȡ����:");
   gets(num);
   enQue(&ordinary,num); 
   printf("��ǰ��ͨ�ŶӺ���:\n");
   pri(&ordinary);
}
//ȡvip�Ų������൱�ڽ��Ӳ���
void vip_getnum()
{
   char num[5];
   printf("��������ȡ����:");
   gets(num);
   enQue(&vip,num); 
   printf("��ǰvip�ŶӺ���:\n");
   pri(&vip);
}
//���ڴ�ȡ�������vip��������
void money_get()
{
   char num[5];
   if(isEmpty(&vip)==0)//vip���ǿ�
      strcpy(num,deleteQue(&vip));
   else if(isEmpty(&ordinary)==0)
      strcpy(num,deleteQue(&ordinary));
   else
      strcpy(num,"����!");
   printf("����%s��ʼ�����ڴ�ȡ��!\n",num);
   if(isEmpty(&vip)==0)
	  strcpy(num,getQue(&vip));
   else if(isEmpty(&ordinary)==0)
      strcpy(num,getQue(&ordinary));
   else
      strcpy(num,"����!");
   printf("�¸����ڴ�ȡ�����Ӧ��Ϊ:%s\n",num);
}
//������
main()
{
    int choice;
	initQue(&ordinary);//��ʼ��
    initQue(&vip);    //��ʼ��
	printf("**********************************************\n");
    printf(" 1.ȡ��ͨ�� 2.ȡVIP�� 3.���ڴ�ȡ�� 4.�˳�ϵͳ\n");
    printf("**********************************************\n");
	while(1)
	{ printf("������ѡ��:");
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