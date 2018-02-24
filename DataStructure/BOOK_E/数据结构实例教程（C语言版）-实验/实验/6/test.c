#include "stdio.h"
typedef struct
{
	char name[20];
	char sex;
}stu;
//frontָ��ͷԪ�أ�rearָ��βԪ����һ�����еĿռ�
//�����ͷ    
typedef struct
{
    stu data[10];
    int front,rear;
}Queue;
//���г�ʼ������
void initQue(Queue *q)
{
	q->front=0;
    q->rear=0;
}
//�ж϶����Ƿ�������
int isFull(Queue *q)
{
    if(q->front==(q->rear+1)%10) 
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
void enQue(Queue *q,stu x)
{
    if(isFull(q)) printf("overflow!");
    q->data[q->rear]=x;
    q->rear=(q->rear+1)%10; 
}
//���Ӳ�������
stu deleteQue(Queue *q)
{
    stu x;
    if(isEmpty(q))
       return;
    x=q->data[q->front];
    q->front =(q->front +1)%10;
	return x;
}
//ȡ��ͷԪ�ز���
stu getQue(Queue *q)
{
    stu x;
    if(isEmpty(q))
       return;
    x=q->data[q->front];
    return x;
}
//������
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
	printf("����������:\n");
	while(!isEmpty(&fdancers)&&!isEmpty(&mdancers))
	{
		p=deleteQue(&fdancers);//Ůʿ����
		printf("%s     ",p.name);
		p=deleteQue(&mdancers);//��ʿ����
		printf("%s     \n",p.name);
	}
	if(!isEmpty(&fdancers))
	{
		p=getQue(&fdancers);
		printf("��һ����Ů����%s����һ���õ������!",p.name);
	}
	if(!isEmpty(&mdancers))
	{
		p=getQue(&mdancers);
		printf("��һ����������%s����һ���õ�Ů���!",p.name);
	}

}
main()
{
    int i;
    stu dancers[9];
    printf("�����������������Ա�:\n");
	for(i=0;i<9;i++)
	{
        scanf("%s",dancers[i].name);
	    getchar();
		scanf("%c",&dancers[i].sex);   
	}
	dancestu(dancers,9);//���������Ժ���
}
