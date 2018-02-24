// C3-1.h 栈的顺序存储表示
#ifndef C_3_1_H
#define C_3_1_H

#include "C1.h"

#define STACK_INIT_SIZE 10 // 存储空间初始分配量
#define STACK_INCREMENT 2 // 存储空间分配增量
typedef int SElemType; // 栈元素类型

struct SqStack
{
    SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
    SElemType *top; // 栈顶指针
    int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

void InitStack(SqStack &S);
void DestroyStack(SqStack &S);
void ClearStack(SqStack &S);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status GetTop(SqStack S, SElemType &e);
void Push(SqStack &S, SElemType e);
Status Pop(SqStack &S, SElemType &e);
void StackTraverse(SqStack S, void(*visit)(SElemType));

#endif