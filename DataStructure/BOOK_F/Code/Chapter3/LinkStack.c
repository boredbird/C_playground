#include<stdio.h>
#include <stdlib.h>

typedef int ElemType;     //ջ�Ĵ洢����
typedef struct LNode  //��ջ���
{
	ElemType data;      //������
	struct Node  *next; //ָ����
}LNode;

typedef struct  LinkStack // ��ջ
{
	LNode *top;   //ջ��ָ��	
}LinkStack; 
           
//�����ջ
void InitStack(LinkStack *S)
{
	S->top=NULL;
}
// ����Ԫ��eΪ�µ�ջ��Ԫ�� ,����ɹ�������1�����ʧ�ܣ�����0
int Push (LinkStack *S,ElemType e)
{ 
	LNode *p;
	p=(LNode*)malloc(sizeof(LNode));
	if(p==NULL)return NULL;
	p->data=e;
	p->next=S->top;
	S->top=p;
	return 1;
}
//��ջ���գ���ɾ��ջ��Ԫ�أ���e������ֵ,������1�����򷵻�0
int Pop(LinkStack *S,ElemType *e)
{ 
	LinkStack *p;
	if(S->top==NULL)return 0;  //ջ��
	*e=S->top->data;
	p=S->top;
	S->top=S->top->next;
	free(p);
	return 1; 
 }
//��ջ���գ�����e����ջ��Ԫ��,������1�����򷵻�0
int GetTop(LinkStack S,ElemType *e)
{
	if(S.top==NULL)return 0;    //ջ��
	else
	{
		*e=S.top->data; // ��ջ��Ԫ�ص�ֵ��ֵ��e
		return 1;
	}	
 }
//��ջΪ��ջ���򷵻�1�����򷵻�0 
int StackEmpty(LinkStack S)//ջ�ǿ�
{ 
	if(S.top==NULL)return 1;//ջ��
	else return 0;
}



int main()
{
	int i,n;
	ElemType e;
	LinkStack s;//����һ��ջ
	InitStack(&s);//��ʼ��ջ
	system("title ��3�� ��ջ");
	Push(&s,3);Push(&s,4);Push(&s,5);Push(&s,6); //���ν�3��4��5��6��ջ
	Pop(&s,&e);printf("��ջ��Ԫ��Ϊ%d\n",e);     //��ջ����ӡջ��Ԫ��
	Push(&s,7); //7��ջ
	Pop(&s,&e);  //��ջ
	Push(&s,8); //8��ջ

	printf("ջ��Ԫ�����γ�ջ:");
	while(s.top!=NULL) //ջ��Ԫ�����γ�ջ����ӡ
	{
		Pop(&s,&e);
		printf("%3d",e);
	}	
	printf("\n");
	
	return 0;
}






