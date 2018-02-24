// c2-2.h 线性表的单链表存储结构

#include "C1.H"

#ifndef C3_2_H
#define C3_2_H

struct LNode
{
	SElemType data;
	LNode *next;
};

typedef LNode *LinkStack; 


extern Status InitStack(LinkStack &L);//构造一个空的线性表L
extern Status DestroyStack(LinkStack &L);//销毁线性表L
extern Status ClearStack(LinkStack L);//将L重置为空表
extern Status StackEmpty(LinkStack L);//若L为空表，则返回TRUE，否则返回FALSE
extern int    StackLength(LinkStack L);//返回L中数据元素个数
extern SElemType GetTop(LinkStack L);// 返回表头元素的值
extern Status Push(LinkStack L,SElemType e);//  在L的头部插入新的数据元素e,作为链表的第一个元素
extern SElemType Pop(LinkStack Le);//  删除L的第一个数据元素，并返回其值
extern Status StackTraverse(LinkStack L);
extern Status STraverse(LinkStack L);

#endif