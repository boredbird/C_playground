// c3-1.h 栈的顺序存储表示

#include "C1.H"

#ifndef C3_1_H
#define C3_1_H

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
extern Status ClearStack(SqStack &S);//把S置为空栈
extern Status StackEmpty(SqStack S);//若栈S为空栈，则返回TRUE，否则返回FALSE
extern int StackLength(SqStack S);// 返回S的元素个数，即栈的长度
extern Status GetTop(SqStack S,SElemType *e);//若栈不空，则返回S的栈顶元素；否则返回ERROR
extern void Push(SqStack &S,SElemType e);//插入元素e为新的栈顶元素
extern Status Pop(SqStack *S,SElemType *e);//若栈不空，则删除S的栈顶元素，返回其值；否则返回ERROR
extern Status StackTraverse(SqStack S);// 从栈底到栈顶依次对栈中每个元素进行访问
extern Status In(SElemType c);//判断c是否为7种运算符之一
extern char Precede(SElemType t1,SElemType t2);// 根据教科书表3.1，判断t1，t2两符号的优先关系 
extern SElemType Operate(SElemType a,SElemType theta,SElemType b); // 做四则运算a theta b，返回运算结果 
extern SElemType EvaluateExpression(); //算术表达式求值的算符优先算法。设OPTR和OPND分别为运算符栈和运算数栈

#endif