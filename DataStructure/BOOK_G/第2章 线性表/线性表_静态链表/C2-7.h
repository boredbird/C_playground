// C2-7.h ���Ա�ľ�̬������洢�ṹ

#ifndef C_2_7_H
#define C_2_7_H

#include "C1.h"

#define MAX_SIZE 100 // �������󳤶�
typedef int ElemType;

typedef struct
{
    ElemType data;
    int      cur;
} Component, SLinkList[MAX_SIZE];

// һ��������������ɾ�̬����Ļ�������(14��)

#define DestroyList ClearList // DestroyList()��ClearList()�Ĳ�����һ����

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