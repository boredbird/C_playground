// C2-7.h 线性表的静态单链表存储结构

#ifndef C_2_7_H
#define C_2_7_H

#include "C1.h"

#define MAX_SIZE 100 // 链表的最大长度
typedef int ElemType;

typedef struct
{
    ElemType data;
    int      cur;
} Component, SLinkList[MAX_SIZE];

// 一个数组可生成若干静态链表的基本操作(14个)

#define DestroyList ClearList // DestroyList()和ClearList()的操作是一样的

int    Malloc(SLinkList L);
void   Free(SLinkList L, int k);
void   InitSpace(SLinkList L);
int    InitList(SLinkList L);
void   ClearList(SLinkList L, int n);
Status ListEmpty(SLinkList L, int n);
int    ListLength(SLinkList L, int n);
Status GetElem(SLinkList L, int n, int i, ElemType &e);
int    LocateElem(SLinkList L, int n, ElemType e);
Status PriorElem(SLinkList L, int n, ElemType cur_e, ElemType &pre_e);
Status NextElem(SLinkList L, int n, ElemType cur_e, ElemType &next_e);
Status ListInsert(SLinkList L, int n, int i, ElemType e);
Status ListDelete(SLinkList L, int n, int i, ElemType &e);
void   ListTraverse(SLinkList L, int n, void(*vi)(ElemType));

#endif