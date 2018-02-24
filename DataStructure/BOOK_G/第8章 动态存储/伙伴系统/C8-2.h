// C8-2.h 伙伴系统可利用空间表的结构
#ifndef C_8_2_H
#define C_8_2_H

#define M 10 // 可利用空间总容量1024字的2的幂次，子表的个数为m+1
#define N 100 // 占用块个数的最大值

typedef struct WORD_b
{
    WORD_b *llink;  // 指向前驱结点
    int    tag;     // 块标志，0：空闲，1：占用
    int    kval;    // 块大小，值为2的幂次k
    WORD_b *rlink;  // 头部域，指向后继结点
} WORD_b, head, *Space;  // WORD_b：内存字类型，结点的第一个字也称为head

typedef struct HeadNode
{
    int nodesize;  // 该链表的空闲块的大小
    WORD_b *first;  // 该链表的表头指针
} FreeList[M + 1];  // 表头向量类型


Space AllocBuddy(FreeList avail, int n); 
// avail[0..m]为可利用空间表，n为申请分配量，若有不小于n的空闲块，
// 则分配相应的存储块，并返回其首地址；否则返回NULL。算法8.2

Space buddy(Space p);
// 返回起始地址为p，块大小为pow(2, p->kval)的块的伙伴地址

void Reclaim(FreeList pav, Space &p);
// 伙伴系统的回收算法。将p所指的释放块回收到可利用空间表pav中

void Print(FreeList p);
// 输出p中所有可利用空间表

void PrintUser(Space p[]);
// 输出p数组所指的已分配空间

#endif