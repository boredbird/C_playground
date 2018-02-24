#ifndef C_10_1_H
#define C_10_1_H

#define MAX_SIZE 20 // 一个用作示例的小顺序表的最大长度
typedef int KeyType; // 定义关键字类型为整型
typedef int InfoType; // 定义其它数据项的类型

struct RedType // 记录类型
{
    KeyType key; // 关键字项
    InfoType otherinfo; // 其它数据项，具体类型在主程中定义
}; 

struct SqList // 顺序表类型
{
    RedType r[MAX_SIZE + 1]; // r[0]闲置或用作哨兵单元
    int length; // 顺序表长度
}; 


void Print(SqList L);
// 打印顺序表

void CreateList(SqList &L);
// 生成一个乱序的线性表

void InsertSort(SqList &L);
// 对顺序表L作直接插入排序。
    
void BInsertSort(SqList &L);
// 对顺序表L作折半插入排序。

void P2_InsertSort(SqList &L);
// 2_路插入排序。

void BubbleSort(SqList &L);
// 冒泡排序。

void SelectSort(SqList &L);
// 对顺序表L作简单选择排序。

void TreeSort(SqList &L);
// 树形选择排序。

void ShellSort(SqList &L, int dlta[], int t);
// 按增量序列dlta[0..t-1]对顺序表L作希尔排序。

void QuickSort(SqList &L);
// 对顺序表L作快速排序。

typedef SqList HeapType; // 堆采用顺序表存储表示
void HeapSort(HeapType &H);
// 对顺序表H进行堆排序。

void MergeSort(SqList &L);
// 对顺序表L作归并排序。

#endif