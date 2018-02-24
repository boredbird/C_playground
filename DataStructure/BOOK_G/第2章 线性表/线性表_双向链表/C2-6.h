// C2-6.h 线性表的双向链表存储结构

#ifndef C_2_6_H
#define C_2_6_H

#include "C1.h"

typedef int ElemType;

typedef struct DuLNode
{
    ElemType data;
    DuLNode  *prior;
    DuLNode  *next;
} DuLNode, *DuLinkList;


void InitList(DuLinkList &L);
// 产生空的双向循环链表L

void DestroyList(DuLinkList &L);
// 操作结果：销毁双向循环链表L

void ClearList(DuLinkList L); // 不改变L
// 初始条件：L已存在。操作结果：将L重置为空表

Status ListEmpty(DuLinkList L);
// 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE

int ListLength(DuLinkList L);
// 初始条件：L已存在。操作结果：返回L中数据元素个数

Status GetElem(DuLinkList L, int i, ElemType &e);
// 当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR

int LocateElem(DuLinkList L, ElemType e, Status(*compare)(ElemType, ElemType));
// 初始条件：L已存在，compare()是数据元素判定函数
// 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。
//           若这样的数据元素不存在，则返回值为0

Status PriorElem(DuLinkList L, ElemType cur_e, ElemType &pre_e);
// 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，
//           前驱，否则操作失败，pre_e无定义

Status NextElem(DuLinkList L, ElemType cur_e, ElemType &next_e);
// 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，
//           否则操作失败，next_e无定义

DuLinkList GetElemP(DuLinkList L, int i); // 另加
// 在双向链表L中返回第i个元素的地址。i为0，返回头结点的地址。若第i个元素不存在，
// 返回NULL(算法2.18、2.19要调用的函数)

Status ListInsert(DuLinkList L, int i, ElemType e);
// 在带头结点的双链循环线性表L中第i个位置之前插入元素e，i的合法值为1≤i≤表长+1
// 改进算法2.18，否则无法在第表长+1个结点之前插入元素

Status ListDelete(DuLinkList L, int i, ElemType &e); // 算法2.19
// 删除带头结点的双链循环线性表L的第i个元素，i的合法值为1≤i≤表长

void ListTraverse(DuLinkList L, void(*visit)(ElemType));
// 由双链循环线性表L的头结点出发，正序对每个数据元素调用函数visit()

void ListTraverseBack(DuLinkList L, void(*visit)(ElemType));
// 由双链循环线性表L的头结点出发，逆序对每个数据元素调用函数visit()。另加

#endif