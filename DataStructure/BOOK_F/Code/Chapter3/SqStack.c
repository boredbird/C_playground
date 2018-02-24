#include<stdio.h>
#include <stdlib.h>
#define NUM  10
#define STACKSIZE 100         //栈的允许的最大长度
#define STACKINCREMENT 20    //存储空间分配增量
typedef int ElemType;     //栈的存储类型
typedef struct  SqStack
{
	ElemType *base;   //栈底指针
	int *top;         //栈底指针
	int stacksize;    //栈表的允许的最大长度
}SqStack;             // 顺序栈

//构造空栈，如果成功，返回1，如果失败，返回0
int InitStack(SqStack *S)
{
	S->base=(ElemType *)malloc(STACKSIZE*sizeof(ElemType));
	if (S->base==NULL)return 0; // 存储分配失败 
	S->top=S->base;
	S->stacksize=STACKSIZE;
	return 1;
 }
// 插入元素e为新的栈顶元素 ,如果成功，返回1，如果失败，返回0
int Push (SqStack *S,ElemType e)
{ 
	if(S->top-S->base>=S->stacksize) //栈满，追加存储空间
	{
		S->base= (ElemType*) realloc (S->base, (S->stacksize+STACKINCREMENT)*sizeof (ElemType));
		if(S->base==NULL)return 0; //存储分配失败
		S->top=S->base+S->stacksize;
		S->stacksize+=STACKINCREMENT;
	}
	*S->top++=e; // 先插入元素，然后将栈顶指针上移一位
	return 1;
}
//若栈不空，则删除栈顶元素，用e返回其值，并返回1；否则返回0
int Pop(SqStack *S,ElemType *e)
{ 
	if(S->top==S->base)return 0;  //栈空		
	*e=*--S->top;      // 先将栈顶指针下移一位，然后取出元素值赋值给e
	return 1; 
 }

//若栈不空，则用e返回栈顶元素，并返回1；否则返回0
int GetTop(SqStack S,ElemType *e)
{
	if(S.top==S.base)return 0;    //栈空
	else	{
		*e=*(S.top-1);               // 将栈顶元素的值赋值给e
		return 1;
	}	
 }

//若栈为空栈，则返回1，否则返回0 
int StackEmpty(SqStack S)//栈非空
{ 
	if(S.top==S.base)return 1;//栈空
	else return 0;
}
//返回栈的元素个数，即栈的长度
int StackLength(SqStack S)
{ 
	return S.top-S.base;
}

void Conversion(int N,int r)
{
	SqStack S;            //定义一个顺序栈
	ElemType x;
	InitStack (&S);
	while(N>0)
	{
		Push(&S,N%r);   //余数入栈
		N=N/r;  	    //商作为被除数继续
	}
	while(StackEmpty(S)!=1)
	{ 
		Pop(&S,&x);      //依次出栈
		printf("%d",x); //输出出栈结果
	}
}


void Conversion_1(int N,int r)
{  
    int  S[NUM],top;     	//定义一个顺序栈
    int   x;
    top = 0;   		       //初始化栈
    while ( N>0 )
	{  
        S[top++] = N % r; //余数入栈
        N = N / r ;   	 //商作为被除数继续
    }
    while (top>0)
	{ 
        x = S[--top];
        printf("%d",x);
    }
}

//括号匹配算法，exp为括号序列，用字符数组存储
//匹配失败返回0，成功返回1
int Matching(char exp[])
{
	int state = 1,i=0;
	SqStack S;//定义一个顺序栈
	char ch; //存储栈顶元素
	InitStack (&S);	//初始化栈
	while (exp[i]!='\0'&& state==1) //当exp[i]=='\0'表示括号序列结束
	{
		switch (exp[i] )
		{
		case '(':
			Push(&S,exp[i]); i++; break;//左括号进栈
		case ')':
			if(GetTop(S,&ch)!=0)
			{
				if(ch=='(')    //左右括号匹配，出栈
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

int ExpEvaluation() //读入一个简单算术表达式并计算其值
{
	char ch;     //ch用于保存读入的表达式的字符/
	char theta,a,b;//运算符、第1、2操作数
	int v=0;//计算结果
	SqStack OPTR,OPND; //设OPTR和OPND分别为运算符栈和运算数栈
	InitStack (&OPTR);InitStack (&OPND);	//初始化栈
	Push(&OPTR,'#');
	printf("Please input an expression(Ending with #):");
	scanf("%c",&ch);
	GetTop(OPTR,&theta);
	while(ch!='#'||theta!='#') 
	{
		//In（）用于判断字符ch是否是运算符，
		//是运算符返回1，是操作数返回0,该函数请读者自行补充
		if(In(ch)!=1)//不是运算符进栈
		{
			int temp;//存放数字的临时变量
			temp=ch-'0';//将字符转换为十进制数
			ch=getchar();
			//用ch逐个读入操作数的各位数码，并转化为十进制数
			while(In(ch)!=1)//将逐个读入的操作数各位转化为十进制数
			{
				temp=temp*10+ch-'0'; ch=getchar();
			}
			Push(&OPND,temp); //不是运算符进栈
		}
		else
		{
			//Precede（）用于判断栈顶元素和表达式当前元素的优先级，
			//返回'<'、'>'、'='，该函数请读者自行补充
			GetTop(OPTR,&theta);
			switch(Precede (theta,ch))
			{
			case'<':   // 栈顶元素优先权低,进栈
				Push(&OPTR,ch); ch=getchar();break;
			case '=' : //优先权相等，脱括号并接收下一字符
				Pop(&OPTR,&ch); ch=getchar(); break; 
           case '>' :  //栈顶元素优先权高，退栈并将运算结果进栈
              Pop(&OPTR,&theta); Pop(&OPND,&b); Pop(&OPND,&a);
			  // Operate（）将以a、b做为第一、二操作数，theta做为运算符
			  //进行计算，返回计算结果，该函数请读者自行补充
			  Push(&OPND,Operate(a, theta,b));
              break;
			}
		}
	}	
	while(Pop(&OPND,&ch)!=0)//从栈中取出所有的数字字符，转换做对应的整数
	{
		v=v*10+ch-'0'; 
	}
	return(v);
}


int main()
{
	int i,n;
	ElemType e;
	SqStack s;//声明一个栈
	InitStack(&s);//初始化栈
	system("title 第3章 顺序栈-top指向栈顶元素的下一个位置");
	Push(&s,3);Push(&s,4);Push(&s,5);Push(&s,6); //依次将3，4，5，6进栈
	Pop(&s,&e);printf("出栈的元素为%d\n",e);     //出栈并打印栈顶元素
	Push(&s,7); //7进栈
	Pop(&s,&e);  //出栈
	Push(&s,8); //8进栈
	n=StackLength(s); //获取栈的长度
	printf("栈中元素依次出栈:");
	for(i=0;i<n;i++) //栈中元素依次出栈并打印
	{
		Pop(&s,&e);
		printf("%3d",e);;
	}	
	printf("\n");

	printf("\n%d\n",Matching("(()()(())"));
	
	return 0;
}






