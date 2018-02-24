#include<stdio.h>
#include <stdlib.h>

#define STACKSIZE 100         //ջ���������󳤶�
typedef int ElemType;         //ջ�Ĵ洢����
typedef struct  SqStack
{
	ElemType stack[STACKSIZE];   //ջ�洢�ռ�
	int top;          //ջ��λ��
	int stacksize;    //ջ����������󳤶�
}SqStack;             // ˳��ջ

//�����ջ������ɹ�������1�����ʧ�ܣ�����0
int InitStack(SqStack *S)
{
	S->top=-1;
	S->stacksize=STACKSIZE;
	return 1;
 }
// ����Ԫ��eΪ�µ�ջ��Ԫ�� ,����ɹ�������1�����ʧ�ܣ�����0
int Push (SqStack *S,ElemType e)
{ 
	if(S->top>=S->stacksize-1)return 0;  //ջ��	
	S->stack[++S->top]=e;  //�Ƚ�ջ��λ������һλ��Ȼ�����Ԫ��
	return 1;
}
//��ջ���գ���ɾ��ջ��Ԫ�أ���e������ֵ�����򷵻�NULL
ElemType Pop(SqStack *S)
{ 
	ElemType e;
	if(S->top<0)return NULL;  //ջ��		
	e=S->stack[S->top--];// ��ȡ��Ԫ��ֵ��ֵ��e��Ȼ��ջ��λ������һλ
	return e; 
 }
//��ջ���գ�����e����ջ��Ԫ�أ����򷵻�NULL
ElemType GetTop(SqStack S)
{
	ElemType e;
	if(S.top<0)return NULL;    //ջ��
	else
	{
		e=S.stack[S.top]; // ��ջ��Ԫ�ص�ֵ��ֵ��e
		return e;
	}	
 }
//��ջΪ��ջ���򷵻�1�����򷵻�0 
int StackEmpty(SqStack S)//ջ�ǿ�
{ 
	if(S.top<0)return 1;//ջ��
	else return 0;
}
//����ջ��Ԫ�ظ�������ջ�ĳ���
int StackLength(SqStack S)
{ 
	return S.top+1;
}


int main()
{
	int i,n;
	ElemType e;
	SqStack s;//����һ��ջ
	InitStack(&s);//��ʼ��ջ
	system("title ��3�� ˳��ջ-topָ��ջ��Ԫ�ص���һ��λ��");
	Push(&s,3);Push(&s,4);Push(&s,5);Push(&s,6); //���ν�3��4��5��6��ջ
	e=Pop(&s);printf("��ջ��Ԫ��Ϊ%d\n",e);     //��ջ����ӡջ��Ԫ��
	Push(&s,7); //7��ջ
	e=Pop(&s);  //��ջ
	Push(&s,8); //8��ջ
	n=StackLength(s); //��ȡջ�ĳ���
	printf("ջ��Ԫ�����γ�ջ:");
	for(i=0;i<n;i++) //ջ��Ԫ�����γ�ջ����ӡ
	{
		e=Pop(&s);
		printf("%3d",e);;
	}	
	printf("\n");
	
	return 0;
}






