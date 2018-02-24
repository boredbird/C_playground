 // C3-1.cpp 顺序栈（存储结构由C3-1.h定义）的基本操作

#include "C3-1.H"

Status InitStack(SqStack &S)
{	// 构造一个空栈S
	if(!(S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType)))) exit(OVERFLOW); // 存储分配失败
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack(SqStack &S)
{	// 销毁栈S，S不再存在
	free(S.base);
	S.base=NULL;
	S.top=NULL;
	S.stacksize=0;
	return OK;
}

Status StackEmpty(SqStack S)
{	// 若栈S为空栈，则返回TRUE，否则返回FALSE
	if(S.top==S.base) return TRUE; else return FALSE;
}


Status Push(SqStack &S,SElemType e)
{	// 插入元素e为新的栈顶元素
	if(S.top-S.base>=S.stacksize) // 栈满，追加存储空间
	{
		S.base=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) exit(OVERFLOW); // 存储分配失败
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*(S.top)++=e;
	return OK;
}

SElemType Pop(SqStack &S)
{	// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if(S.top==S.base) return ERROR;
    return *--S.top;
}

void conversion(int N) /* 算法3.1 */
 { /* 对于输入的任意一个非负10进制整数，打印输出与其等值的N进制数 */
   //使用到了InitStack(SqStack &S);Push(SqStack &S,SElemType e);StackEmpty(SqStack S);Pop(SqStack &S);等函数
   SqStack s;
   unsigned n; /* 非负整数 */
   SElemType e;
   InitStack(s); /* 初始化栈 */
   printf("将10进制整数n转换为 %d 进制数，请输入：n(>=0)=",N);
   scanf("%u",&n); /* 输入非负十进制整数n */
   while(n) /* 当n不等于0 */
   {
     Push(s,n%N); /* 入栈n除以N的余数(N进制的低位) */
     n=n/N;
   }
   printf("转换为 %d 进制的结果为 : ",N);
   while(!StackEmpty(s)) /* 当栈不空 */
   {
     e = Pop(s); /* 弹出栈顶元素且赋值给e */
	 if(e==10)
		 printf("A");
	 else if(e==11)
		 printf("B");
	 else if(e==12)
		 printf("C");
	 else if(e==13)
		 printf("D");
	 else if(e==14)
		 printf("E");
	 else if(e==15)
		 printf("F");
	 else   printf("%d",e); /* 输出e */
   }
   printf("\n");
   DestroyStack(s);
 }