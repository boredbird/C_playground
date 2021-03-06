// c2-2.h 线性表的单链表存储结构

#ifndef C_2_2_H
#define C_2_2_H

#include "C1.h"

typedef int ElemType;

struct LNode
{
    ElemType data;
    LNode    *next;
};

typedef LNode *LinkList; // 另一种定义LinkList的方法

void InitList(LinkList &L);
// 操作结果：构造一个空的线性表L

void DestroyList(LinkList &L);
// 初始条件：线性表L已存在。操作结果：销毁线性表L

void ClearList(LinkList L); // 不改变L
// 初始条件：线性表L已存在。操作结果：将L重置为空表

Status ListEmpty(LinkList L);
// 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE

int ListLength(LinkList L);
// 初始条件：线性表L已存在。操作结果：返回L中数据元素个数

Status GetElem(LinkList L, int i, ElemType &e); // 算法2.8
// L为带头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType));
// 初始条件: 线性表L已存在，compare()是数据元素判定函数(满足为1，否则为0)
// 操作结果: 返回L中第1个与e满足关系compare()的数据元素的位序。
//           若这样的数据元素不存在，则返回值为0

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e);
// 初始条件: 线性表L已存在
// 操作结果: 若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，
//           返回OK；否则操作失败，pre_e无定义，返回INFEASIBLE

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e);
// 初始条件：线性表L已存在
// 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，
//           返回OK;否则操作失败，next_e无定义，返回INFEASIBLE

Status ListInsert(LinkList L, int i, ElemType e); // 算法2.9；不改变L
// 在带头结点的单链线性表L中第i个位置之前插入元素e

Status ListDelete(LinkList L, int i, ElemType &e); // 算法2.10；不改变L
// 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值

void ListTraverse(LinkList L, void(*vi)(ElemType));
// vi的形参类型为ElemType，与bo2-1.cpp中相应函数的形参类型ElemType&不同
// 初始条件：线性表L已存在。操作结果：依次对L的每个数据元素调用函数vi()

#endif