
#ifndef C_10_2_H
#define C_10_2_H

#include "C1.h"

typedef int InfoType; // 定义其它数据项的类型
typedef int KeyType; // 定义RedType类型的关键字为整型
struct RedType // 记录类型
{
    KeyType  key;       // 关键字项
    InfoType otherinfo; // 其它数据项
}; 
typedef char KeysType; // 定义关键字类型为字符型

#define MAX_NUM_OF_KEY 8 // 关键字项数的最大值
#define RADIX 10 // 关键字基数，此时是十进制整数的基数
#define MAX_SPACE 1000
struct SLCell // 静态链表的结点类型
{
    KeysType keys[MAX_NUM_OF_KEY]; // 关键字
    InfoType otheritems;           // 其它数据项
    int      next; 
}; 

struct SLList // 静态链表类型
{
    SLCell r[MAX_SPACE]; // 静态链表的可利用空间，r[0]为头结点
    int keynum; // 记录的当前关键字个数
    int recnum; // 静态链表的当前长度
}; 

typedef int ArrType[RADIX]; // 指针数组类型


void InitList(SLList &L, RedType D[], int n);
// 初始化静态链表L(把数组D中的数据存于L中)

void RadixSort(SLList &L);
// L是采用静态链表表示的顺序表。对L作基数排序，使得L成为按关键字
// 自小到大的有序静态链表，L.r[0]为头结点。

void Print(SLList L);
// 按数组序号输出静态链表

void Sort(SLList L, int adr[]);
// 求得adr[1..L.length]，adr[i]为静态链表L的第i个最小记录的序号

void Rearrange(SLList &L, int adr[]);
// adr给出静态链表L的有序次序，即L.r[adr[i]]是第i小的记录。
// 本算法按adr重排L.r，使其有序。

#endif