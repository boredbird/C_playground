// c3-1.h 栈的顺序存储表示

#include "C1.H"

#ifndef C3_1_H
#define C3_1_H

#define STACK_INIT_SIZE 10 // 存储空间初始分配量
#define STACKINCREMENT 2 // 存储空间分配增量

typedef char SElemType; 

struct SqStack
{
	SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
	SElemType *top; // 栈顶指针
	int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

extern Status InitStack(SqStack &S);//构造一个空栈S
extern Status DestroyStack(SqStack &S);//销毁栈S，S不再存在
extern Status ClearStack(SqStack &S);//把S置为空栈
extern Status StackEmpty(SqStack S);//若栈S为空栈，则返回TRUE，否则返回FALSE
extern int StackLength(SqStack S);// 返回S的元素个数，即栈的长度
extern SElemType GetTop(SqStack S);//若栈不空，则返回S的栈顶元素；否则返回ERROR
extern SElemType Push(SqStack &S,SElemType e);//插入元素e为新的栈顶元素
extern SElemType Pop(SqStack &S);//若栈不空，则删除S的栈顶元素，返回其值；否则返回ERROR
extern Status StackTraverse(SqStack S);// 从栈底到栈顶依次对栈中每个元素进行访问

#endif