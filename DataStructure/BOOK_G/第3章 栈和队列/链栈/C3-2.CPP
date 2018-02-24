// C3-2.cpp 单链表线性表(存储结构由C3-2.h定义)的扩展操作

#include "C3-2.H"

Status Push(LinkStack L,SElemType e)
{	// 线性表L已存在，在L的头部插入新的数据元素e,作为链表的第一个元素
	LinkStack s;
	s=(LinkStack)malloc(sizeof(LNode)); // 生成新结点
	s->data=e; // 给结点赋值
	s->next=L->next; // 插在栈顶
	L->next=s;
	return OK;
}

SElemType Pop(LinkStack L)
{	// 线性表L已存在，删除L的栈顶元素，并返回其值
	LinkStack p=L->next;
	SElemType e;
	if(p)
	{
		e=p->data;
		L->next=p->next;
		free(p);
		return e;
	}
	else
		return ERROR;
}

SElemType GetTop(LinkStack L)
{	// 返回表头元素的值
	LinkStack p=L->next;
		SElemType e;
	if(!p) // 空表
		return ERROR;
	else // 非空表
		e=p->data;
	return e;
}

//////////////////////////////////////
Status StackTraverse(LinkStack S)
{	// 从栈底到栈顶依次对栈中每个元进行访问。
	SElemType e;
	LinkStack temp,p=S;
	InitStack(temp);	// 初始化temp栈
	while(p->next)
	{
		e=GetTop(p);
		Push(temp,e);
		p=p->next;
	}
	STraverse(temp);
	return OK;
}

///////////////////////////////////////////////////////

Status InitStack(LinkStack &L)
{	// 操作结果：构造一个空的线性表L
	L=(LinkStack)malloc(sizeof(LNode)); // 产生头结点,并使L指向此头结点
	if(!L) // 存储分配失败
		exit(OVERFLOW);
	L->next=NULL; // 指针域为空
	return OK;
}

Status DestroyStack(LinkStack &L)
{	// 初始条件：线性表L已存在。操作结果：销毁线性表L
	LinkStack q;
	while(L)
	{
		q=L->next;
		free(L);
		L=q;
	}
	return OK;
}

Status DestroyStack(LinkStack L) // 不改变L
{	// 初始条件：线性表L已存在。操作结果：将L重置为空表
	LinkStack p,q;
	p=L->next; // p指向第一个结点
	while(p) // 没到表尾
	{
		q=p->next;
		free(p);
		p=q;
	}
	L->next=NULL; // 头结点指针域为空
	return OK;
}

Status StackEmpty(LinkStack L)
{	// 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE
	if(L->next) // 非空
		return FALSE;
	else
		return TRUE;
}

int StackLength(LinkStack L)
{	// 初始条件：线性表L已存在。操作结果：返回L中数据元素个数
	int i=0;
	LinkStack p=L->next; // p指向第一个结点
	while(p) // 没到表尾
	{
		i++;
		p=p->next;
	}
	return i;
}

Status STraverse(LinkStack L)
{	// 初始条件：线性表L已存在
	// 操作结果:依次对L的每个数据元素进行输出
	LinkStack p=L->next;
	while(p)
	{
		printf("%d",p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}

Status ClearStack(LinkStack L) // 不改变L
{	// 初始条件：线性表L已存在。操作结果：将L重置为空表
	LinkStack p,q;
	p=L->next; // p指向第一个结点
	while(p) // 没到表尾
	{
		q=p->next;
		free(p);
		p=q;
	}
	L->next=NULL; // 头结点指针域为空
	return OK;
}
