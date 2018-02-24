// C2-3.h 线性表不带头结点的单链表存储结构

#ifndef C_2_3_H
#define C_2_3_H

#include "C1.h"

typedef int ElemType;

struct LNode
{
    ElemType data;
    LNode    *next;
};

typedef LNode *LinkList; // 另一种定义LinkList的方法

#define DestroyList ClearList // DestroyList()和ClearList()的操作是一样的

void InitList(LinkList &L);
// 操作结果：构造一个空的线性表L

void ClearList(LinkList &L);
// 初始条件：线性表L已存在。操作结果：将L重置为空表

Status ListEmpty(LinkList L);
// 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE

int ListLength(LinkList L);
// 初始条件：线性表L已存在。操作结果：返回L中数据元素个数

Status GetElem(LinkList L, int i, ElemType &e);
// L为不带头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType));
// 初始条件：线性表L已存在，compare()是数据元素判定函数(满足为1，否则为0)
// 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。
//           若这样的数据元素不存在，则返回值为0

Status ListInsert(LinkList &L, int i, ElemType e);
// 在不带头结点的单链线性表L中第i个位置之前插入元素e

Status ListDelete(LinkList &L, int i, ElemType &e);
// 在不带头结点的单链线性表L中，删除第i个元素，并由e返回其值

void ListTraverse(LinkList L,void(*vi)(ElemType));
// 初始条件：线性表L已存在。操作结果：依次对L的每个数据元素调用函数vi()

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e);
// 初始条件：线性表L已存在
// 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，
//           返回OK；否则操作失败，pre_e无定义，返回INFEASIBLE

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e);
// 初始条件：线性表L已存在
// 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，
//           返回OK；否则操作失败，next_e无定义，返回INFEASIBLE


// 不带头结点的单链表的扩展操作(3个)

void InsertAscend(LinkList &L, ElemType e, int(*compare)(ElemType,ElemType));
// 按关键字非降序将e插入表L。函数compare()返回值为：形参1的关键字-形参2的关键字

LinkList Point(LinkList L, ElemType e, Status(*equal)(ElemType, ElemType), LinkList &p);
// 查找表L中满足条件的结点。如找到，返回指向该结点的指针，p指向该结点的前驱(若该结点是
// 首元结点，则p=NULL)。如表L中无满足条件的结点，则返回NULL，p无定义。
// 函数equal()的两形参的关键字相等，返回OK；否则返回ERROR

Status DeleteElem(LinkList &L, ElemType &e, Status(*equal)(ElemType, ElemType));
// 删除表L中满足条件的结点，并返回TRUE；如无此结点，则返回FALSE。
// 函数equal()的两形参的关键字相等，返回OK；否则返回ERROR

#endif