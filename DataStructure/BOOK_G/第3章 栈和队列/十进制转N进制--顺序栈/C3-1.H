// c3-1.h 栈的顺序存储表示

#include "C1.H"

#ifndef C3_1_H
#define C3_1_H

//#define N 16 /* 定义待转换的进制N(2～9) */

#define STACK_INIT_SIZE 10 // 存储空间初始分配量
#define STACKINCREMENT 2 // 存储空间分配增量

typedef int SElemType; 

struct SqStack
{
	SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
	SElemType *top; // 栈顶指针
	int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

extern Status InitStack(SqStack &S);//构造一个空栈S
extern Status DestroyStack(SqStack &S);//销毁栈S，S不再存在
extern Status StackEmpty(SqStack S);//若栈S为空栈，则返回TRUE，否则返回FALSE
extern Status Push(SqStack &S,SElemType e);//插入元素e为新的栈顶元素
extern SElemType Pop(SqStack &S);//若栈不空，则删除S的栈顶元素，返回其值；否则返回ERROR

extern void conversion(int N);//转换函数

#endif