#include<stdio.h>
#include <stdlib.h>
#define NUM  10
#define STACKSIZE 100         //ջ���������󳤶�
#define STACKINCREMENT 20    //�洢�ռ��������
typedef int ElemType;     //ջ�Ĵ洢����
typedef struct  SqStack
{
	ElemType *base;   //ջ��ָ��
	int *top;         //ջ��ָ��
	int stacksize;    //ջ����������󳤶�
}SqStack;             // ˳��ջ

//�����ջ������ɹ�������1�����ʧ�ܣ�����0
int InitStack(SqStack *S)
{
	S->base=(ElemType *)malloc(STACKSIZE*sizeof(ElemType));
	if (S->base==NULL)return 0; // �洢����ʧ�� 
	S->top=S->base;
	S->stacksize=STACKSIZE;
	return 1;
 }
// ����Ԫ��eΪ�µ�ջ��Ԫ�� ,����ɹ�������1�����ʧ�ܣ�����0
int Push (SqStack *S,ElemType e)
{ 
	if(S->top-S->base>=S->stacksize) //ջ����׷�Ӵ洢�ռ�
	{
		S->base= (ElemType*) realloc (S->base, (S->stacksize+STACKINCREMENT)*sizeof (ElemType));
		if(S->base==NULL)return 0; //�洢����ʧ��
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*S->top++=e; // �Ȳ���Ԫ�أ�Ȼ��ջ��ָ������һλ
	return 1;
}
//��ջ���գ���ɾ��ջ��Ԫ�أ���e������ֵ��������1�����򷵻�0
int Pop(SqStack *S,ElemType *e)
{ 
	if(S->top==S->base)return 0;  //ջ��		
	*e=*--S->top;      // �Ƚ�ջ��ָ������һλ��Ȼ��ȡ��Ԫ��ֵ��ֵ��e
	return 1; 
 }

//��ջ���գ�����e����ջ��Ԫ�أ�������1�����򷵻�0
int GetTop(SqStack S,ElemType *e)
{
	if(S.top==S.base)return 0;    //ջ��
	else	{
		*e=*(S.top-1);               // ��ջ��Ԫ�ص�ֵ��ֵ��e
		return 1;
	}	
 }

//��ջΪ��ջ���򷵻�1�����򷵻�0 
int StackEmpty(SqStack S)//ջ�ǿ�
{ 
	if(S.top==S.base)return 1;//ջ��
	else return 0;
}
//����ջ��Ԫ�ظ�������ջ�ĳ���
int StackLength(SqStack S)
{ 
	return S.top-S.base;
}

void Conversion(int N,int r)
{
	SqStack S;            //����һ��˳��ջ
	ElemType x;
	InitStack (&S);
	while(N>0)
	{
		Push(&S,N%r);   //������ջ
		N=N/r;  	    //����Ϊ����������
	}
	while(StackEmpty(S)!=1)
	{ 
		Pop(&S,&x);      //���γ�ջ
		printf("%d",x); //�����ջ���
	}
}


void Conversion_1(int N,int r)
{  
    int  S[NUM],top;     	//����һ��˳��ջ
    int   x;
    top = 0;   		       //��ʼ��ջ
    while ( N>0 )
	{  
        S[top++] = N % r; //������ջ
        N = N / r ;   	 //����Ϊ����������
    }
    while (top>0)
	{ 
        x = S[--top];
        printf("%d",x);
    }
}

//����ƥ���㷨��expΪ�������У����ַ�����洢
//ƥ��ʧ�ܷ���0���ɹ�����1
int Matching(char exp[])
{
	int state = 1,i=0;
	SqStack S;//����һ��˳��ջ
	char ch; //�洢ջ��Ԫ��
	InitStack (&S);	//��ʼ��ջ
	while (exp[i]!='\0'&& state==1) //��exp[i]=='\0'��ʾ�������н���
	{
		switch (exp[i] )
		{
		case '(':
			Push(&S,exp[i]); i++; break;//�����Ž�ջ
		case ')':
			if(GetTop(S,&ch)!=0)
			{
				if(ch=='(')    //��������ƥ�䣬��ջ
				{
					Pop(&S,&ch);  i++;
				}
				else state=0;
			}
			else  state = 0;
			break;
		}
	}
	if (StackLength(S)==0&&state==1) return 1;
	else return 0;	
}
int In(char ch)
{
	return 1;
}
char Precede(char op1,char op2)
{
	return 0;
}
char Operate(char a,char op,char b)
{
	return 0;
}

int ExpEvaluation() //����һ�����������ʽ��������ֵ
{
	char ch;     //ch���ڱ������ı��ʽ���ַ�/
	char theta,a,b;//���������1��2������
	int v=0;//������
	SqStack OPTR,OPND; //��OPTR��OPND�ֱ�Ϊ�����ջ��������ջ
	InitStack (&OPTR);InitStack (&OPND);	//��ʼ��ջ
	Push(&OPTR,'#');
	printf("Please input an expression(Ending with #):");
	scanf("%c",&ch);
	GetTop(OPTR,&theta);
	while(ch!='#'||theta!='#') 
	{
		//In���������ж��ַ�ch�Ƿ����������
		//�����������1���ǲ���������0,�ú�����������в���
		if(In(ch)!=1)//�����������ջ
		{
			int temp;//������ֵ���ʱ����
			temp=ch-'0';//���ַ�ת��Ϊʮ������
			ch=getchar();
			//��ch�������������ĸ�λ���룬��ת��Ϊʮ������
			while(In(ch)!=1)//���������Ĳ�������λת��Ϊʮ������
			{
				temp=temp*10+ch-'0'; ch=getchar();
			}
			Push(&OPND,temp); //�����������ջ
		}
		else
		{
			//Precede���������ж�ջ��Ԫ�غͱ��ʽ��ǰԪ�ص����ȼ���
			//����'<'��'>'��'='���ú�����������в���
			GetTop(OPTR,&theta);
			switch(Precede (theta,ch))
			{
			case'<':   // ջ��Ԫ������Ȩ��,��ջ
				Push(&OPTR,ch); ch=getchar();break;
			case '=' : //����Ȩ��ȣ������Ų�������һ�ַ�
				Pop(&OPTR,&ch); ch=getchar(); break; 
           case '>' :  //ջ��Ԫ������Ȩ�ߣ���ջ������������ջ
              Pop(&OPTR,&theta); Pop(&OPND,&b); Pop(&OPND,&a);
			  // Operate��������a��b��Ϊ��һ������������theta��Ϊ�����
			  //���м��㣬���ؼ��������ú�����������в���
			  Push(&OPND,Operate(a, theta,b));
              break;
			}
		}
	}	
	while(Pop(&OPND,&ch)!=0)//��ջ��ȡ�����е������ַ���ת������Ӧ������
	{
		v=v*10+ch-'0'; 
	}
	return(v);
}


int main()
{
	int i,n;
	ElemType e;
	SqStack s;//����һ��ջ
	InitStack(&s);//��ʼ��ջ
	system("title ��3�� ˳��ջ-topָ��ջ��Ԫ�ص���һ��λ��");
	Push(&s,3);Push(&s,4);Push(&s,5);Push(&s,6); //���ν�3��4��5��6��ջ
	Pop(&s,&e);printf("��ջ��Ԫ��Ϊ%d\n",e);     //��ջ����ӡջ��Ԫ��
	Push(&s,7); //7��ջ
	Pop(&s,&e);  //��ջ
	Push(&s,8); //8��ջ
	n=StackLength(s); //��ȡջ�ĳ���
	printf("ջ��Ԫ�����γ�ջ:");
	for(i=0;i<n;i++) //ջ��Ԫ�����γ�ջ����ӡ
	{
		Pop(&s,&e);
		printf("%3d",e);;
	}	
	printf("\n");

	printf("\n%d\n",Matching("(()()(())"));
	
	return 0;
}






