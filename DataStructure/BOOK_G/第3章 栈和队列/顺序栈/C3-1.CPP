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

Status ClearStack(SqStack &S)
{	// 把S置为空栈
	S.top=S.base;
	return OK;
}

Status StackEmpty(SqStack S)
{	// 若栈S为空栈，则返回TRUE，否则返回FALSE
	if(S.top==S.base) return TRUE; else return FALSE;
}

int StackLength(SqStack S)
{	// 返回S的元素个数，即栈的长度
	return S.top-S.base;
}

Status GetTop(SqStack S,SElemType &e)
{	// 若栈不空，则用e获取栈顶元素，并返回OK；否则返回ERROR
	if(S.top==S.base)
		return ERROR;
	e = *(S.top-1);
	return OK;
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

Status StackTraverse(SqStack S)
{	// 从栈底到栈顶依次对栈中每个元素进行访问
	while(S.top>S.base) printf("%c",*S.base++);
	printf("\n");
	return OK;
}