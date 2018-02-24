// C8-1.h 边界标识法可利用空间表的结点结构
// head和foot分别是可利用空间表中结点的第一个字和最后一个字(WORD)

#ifndef C_8_1_H
#define C_8_1_H

typedef struct WORD // 字类型
{
    union
    {
        WORD *llink;  // 头部域，指向前驱结点
        WORD *uplink;  // 底部域，指向本结点头部
    }; 
    int  tag;     // 块标志，0：空闲，1：占用，头部和尾部均有
    int  size;    // 头部域，块大小
    WORD *rlink;  // 头部域，指向后继结点
}WORD, head, foot, *Space;  // *Space：可利用空间指针类型

#define FootLoc(p) ((p)+((p)->size-1)) // 带参数的宏定义，指向p所指结点的底部(最后一个字)
#define MAX 1000 // 可利用空间的大小(以WORD的字节数为单位)
#define e   10   // 块的最小尺寸 - 1(以WORD的字节数为单位)



Space AllocBoundTag(Space &pav, int n); 
// 若可利用空间表pav中有不小于n的空闲块，则分配相应的存储块，并返回其首地址；否则返回NULL
// 若分配后可利用空间表不空，则pav指向表中刚分配过的结点的后继结点

void Reclaim(Space &pav, Space &p);
// 边界标识法的回收算法，将p所指的释放块回收到可利用空间表pav中

void Print(Space p);
// 输出p所指的可利用空间表

void PrintUser(Space p[]);
// 输出p数组所指的已分配空间


#endif