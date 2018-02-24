// c2-6.h 带头结点的线性链表类型

#ifndef C_2_6_H
#define C_2_6_H

#include "C1.h"

typedef int ElemType; 


typedef struct LNode // 结点类型
{
    ElemType data;
    LNode    *next;
} *Link, *Position;

struct LinkList // 链表类型
{
    Link head; // 指向线性链表中的头结点
    Link tail; // 指向线性链表中的最后一个结点
    int  len; // 指示线性链表中数据元素的个数
};


// 具有实用意义的线性链表的24个基本操作


void MakeNode(Link &p, ElemType e);
// 分配由p指向的值为e的结点。若分配失败，则退出

void FreeNode(Link &p);
// 释放p所指结点

void InitList(LinkList &L);
// 构造一个空的线性链表L

void ClearList(LinkList &L);
// 将线性链表L重置为空表，并释放原链表的结点空间

void DestroyList(LinkList &L);
// 销毁线性链表L，L不再存在

void InsFirst(LinkList &L, Link h, Link s); // 形参增加L,因为需修改L
// h指向L的一个结点，把h当做头结点，将s所指结点插入在第一个结点之前

Status DelFirst(LinkList &L, Link h, Link &q); // 形参增加L,因为需修改L
// h指向L的一个结点，把h当做头结点，删除链表中的第一个结点并以q返回。
// 若链表为空(h指向尾结点)，q=NULL，返回FALSE

void Append(LinkList &L, Link s);
// 将指针s(s->data为第一个数据元素)所指(彼此以指针相链，以NULL结尾)的
// 一串结点链接在线性链表L的最后一个结点之后，并改变链表L的尾指针指向新的尾结点

Position PriorPos(LinkList L, Link p);
// 已知p指向线性链表L中的一个结点，返回p所指结点的直接前驱的位置。若无前驱，则返回NULL

Status Remove(LinkList &L, Link &q);
// 删除线性链表L中的尾结点并以q返回，改变链表L的尾指针指向新的尾结点

void InsBefore(LinkList &L, Link &p, Link s);
// 已知p指向线性链表L中的一个结点，将s所指结点插入在p所指结点之前，
// 并修改指针p指向新插入的结点

void InsAfter(LinkList &L, Link &p, Link s);
// 已知p指向线性链表L中的一个结点，将s所指结点插入在p所指结点之后，
// 并修改指针p指向新插入的结点

void SetCurElem(Link p, ElemType e);
// 已知p指向线性链表中的一个结点，用e更新p所指结点中数据元素的值

ElemType GetCurElem(Link p);
// 已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值

Status ListEmpty(LinkList L);
// 若线性链表L为空表，则返回TRUE，否则返回FALSE

int ListLength(LinkList L);
// 返回线性链表L中元素个数

Position GetHead(LinkList L);
// 返回线性链表L中头结点的位置

Position GetLast(LinkList L);
// 返回线性链表L中最后一个结点的位置

Position NextPos(Link p);
// 已知p指向线性链表L中的一个结点，返回p所指结点的直接后继的位置。若无后继，则返回NULL

Status LocatePos(LinkList L, int i, Link &p);
// 返回p指示线性链表L中第i个结点的位置，并返回OK，i值不合法时返回ERROR。i=0为头结点

Position LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType));
// 返回线性链表L中第1个与e满足函数compare()判定关系的元素的位置，
// 若不存在这样的元素，则返回NULL

void ListTraverse(LinkList L, void(*visit)(ElemType));
// 依次对L的每个数据元素调用函数visit()

void OrderInsert(LinkList &L, ElemType e, int (*comp)(ElemType, ElemType));
// 已知L为有序线性链表，将元素e按非降序插入在L中。(用于一元多项式)

Status LocateElem(LinkList L, ElemType e, Position &q, int (*compare)(ElemType, ElemType));
// 若升序链表L中存在与e满足判定函数compare()取值为0的元素，则q指示L中
// 第一个值为e的结点的位置，并返回TRUE；否则q指示第一个与e满足判定函数
// compare()取值>0的元素的前驱的位置。并返回FALSE。(用于一元多项式)

#endif