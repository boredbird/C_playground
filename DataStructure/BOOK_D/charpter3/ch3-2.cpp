#include"stdio.h"
#include"stdlib.h"
#define MAXSIZE 20                       //����������
typedef struct 
{
	int stack[MAXSIZE];
	int  lefttop;  		//��ջջ��λ��ָʾ��
	int  righttop;  	//��ջջ��λ��ָʾ��
  } dupsqstack;

//�������������ڽӿռ�Ŀ�ջ��ָ��Sָ��ÿռ�
int initDupStack(dupsqstack *s)
{
	s=(dupsqstack*)malloc(sizeof(dupsqstack));
	if (s==NULL) return 0;
	s->lefttop= -1;
	s->righttop=MAXSIZE;
	return 1;
};

//������Ԫ��xѹ����ջ��status='L'������ջ��status='R'��
int pushDupStack(dupsqstack *s,char status,int x)
{
	if(s->lefttop+1==s->righttop) return 0; //ջ��
	if(status='L')  s->stack[++s->lefttop]=x; //��ջ��ջ
    else if(status='R')  s->stack[--s->righttop]=x;  //��ջ��ջ
	else return 0; 						//��������
	return 1;
};
//����ջ��status='L'������ջ��status='R'���˳�ջ��Ԫ��
int  popDupStack(dupsqstack *s,char status)
{
	if(status=='L')
	{
		if (s->lefttop<0)
			return 0;  				//��ջΪ��
		else return (s->stack[s->lefttop--]);   		//��ջ��ջ
	}
	else if(status=='R')
	{
		if (s->righttop>MAXSIZE-1)
			return 0;  				//��ջΪ��
		else return (s->stack[s->righttop++]);  	//��ջ��ջ
	}
	else  return 0;  				//��������
};

void main()
{
dupsqstack *s;
int initDupStack(dupsqstack *s);
int pushDupStack(dupsqstack *s,char status,int x);
int popDupStack(dupsqstack *s,char status);
}