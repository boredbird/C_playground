// C10-1.cpp 常见排序算法

#include "C1.h"
#include "C10-1.h"

void Print(SqList L)
{
    int i; 
    for (i = 1; i <= L.length; i++) {
        printf("%d ", L.r[i].key); 
    }
    printf("\n"); 
}

void CreateList(SqList &L)
{
    // 生成一个乱序的线性表
    int key[10] = {34, -6, 89, 0, 267, -89, -3, 12, 67, 5};
    int info[10] = {0};
    int i;
    L.length = 0;
    for (i = 1; i <= 10; ++i)
    {
        L.r[i].key = key[i - 1];
        L.r[i].otherinfo = info[i - 1];
        L.length++;     
    } 
    
}


// 插入排序

void InsertSort(SqList &L)
{ 
    // 对顺序表L作直接插入排序。
    int i, j;
    for (i = 2; i <= L.length; ++i)
    {
        if (L.r[i].key < L.r[i - 1].key) // "<",需将L.r[i]插入有序子表
        {
            L.r[0] = L.r[i]; // 复制为哨兵
            for (j = i - 1; L.r[0].key < L.r[j].key; --j)
            {
                L.r[j + 1] = L.r[j]; // 记录后移
            }
            L.r[j + 1] = L.r[0]; // 插入到正确位置
        }
    }
}

void BInsertSort(SqList &L)
{ 
    // 对顺序表L作折半插入排序。
    int i, j, m, low, high;
    for (i = 2; i <= L.length; ++i)
    {
        L.r[0] = L.r[i]; // 将L.r[i]暂存到L.r[0]
        low = 1;
        high = i - 1;
        while (low <= high)
        {   
            // 在r[low..high]中折半查找有序插入的位置
            m = (low + high) / 2; // 折半
            if (L.r[0].key < L.r[m].key)
            {
                high = m - 1; // 插入点在低半区
            }
            else
            {
                low = m + 1; // 插入点在高半区
            }
        }
        for (j = i - 1; j >= high + 1; --j)
        {
            L.r[j + 1] = L.r[j]; // 记录后移
        }
        L.r[high + 1] = L.r[0]; // 插入
    }
}

void P2_InsertSort(SqList &L)
{ 
    // 2_路插入排序
    int i, j, first, final;
    RedType *d;
    d = (RedType*) malloc(L.length * sizeof(RedType)); // 生成L.length个记录的临时空间
    d[0] = L.r[1]; // 设L的第1个记录为d中排好序的记录(在位置[0])
    first = final = 0; // first、final分别指示d中排好序的记录的第1个和最后1个记录的位置
    for (i = 2; i <= L.length; ++i) // 依次将L的第2个～最后1个记录插入d中
    {
        if (L.r[i].key < d[first].key)
        { 
            // 待插记录小于d中最小值，插到d[first]之前(不需移动d数组的元素)
            first = (first - 1 + L.length) % L.length; // 设d为循环向量
            d[first] = L.r[i];
        }
        else if (L.r[i].key > d[final].key)
        { 
            // 待插记录大于d中最大值，插到d[final]之后(不需移动d数组的元素)
            final = final + 1;
            d[final] = L.r[i];
        }
        else
        { 
            // 待插记录大于d中最小值，小于d中最大值，插到d的中间(需要移动d数组的元素)
            j = final++; // 移动d的尾部元素以便按序插入记录
            while (L.r[i].key < d[j].key)
            {
                d[(j + 1) % L.length] = d[j];
                j = (j - 1 + L.length) % L.length;
            }
            d[(j + 1) % L.length] = L.r[i];
        }
    }
    for (i = 1; i <= L.length; i++) // 把d赋给L.r
    {
        L.r[i] = d[(i + first - 1) % L.length]; // 线性关系
    }
    free(d);
}

// 冒泡排序

void BubbleSort(SqList &L)
{ 
    int i,j;
    RedType t;
    Status change = TRUE;
    for( i = L.length; i > 1 && change; --i)
    {
        change = FALSE;
        for (j = 1; j < i; ++j)
        {
            if (L.r[j].key > L.r[j + 1].key)
            {
                t = L.r[j];
                L.r[j] = L.r[j + 1];
                L.r[j + 1] = t;
                change = TRUE;
            }
        }
    }
}

// 选择排序

int SelectMinKey(SqList L, int i)
{ 
    // 返回在L.r[i..L.length]中key最小的记录的序号
    KeyType min;
    int j, k;
    k = i; // 设第i个为最小
    min = L.r[i].key;
    for (j = i + 1; j <= L.length; j++)
    {
        if (L.r[j].key < min) // 找到更小的
        {
            k = j;
            min = L.r[j].key;
        }
    }
    return k;
}

void SelectSort(SqList &L)
{ 
    // 对顺序表L作简单选择排序。
    int i, j;
    RedType t;
    for (i = 1; i < L.length; ++i)
    { 
        //  选择第i小的记录，并交换到位
        j = SelectMinKey(L, i); // 在L.r[i..L.length]中选择key最小的记录
        if (i != j)
        { 
            // 与第i个记录交换
            t = L.r[i];
            L.r[i] = L.r[j];
            L.r[j] = t;
        }
    }
}


void TreeSort(SqList &L)
{ 
    // 树形选择排序
    int i, j, j1, k, k1, l, n = L.length;
    RedType *t;
    l = (int) ceil(log(n) / log(2)) + 1; // 完全二叉树的层数
    k = (int) pow(2, l) - 1; // l层完全二叉树的结点总数
    k1 = (int)pow(2, l - 1) - 1; // l-1层完全二叉树的结点总数
    t = (RedType*) malloc(k * sizeof(RedType)); // 二叉树采用顺序存储结构
    for (i = 1; i <= n; i++) // 将L.r赋给叶子结点
    {
        t[k1 + i - 1] = L.r[i];
    }
    for (i = k1 + n; i < k; i++) // 给多余的叶子的关键字赋无穷大
    {
        t[i].key = INT_MAX;
    }
    j1 = k1;
    j = k;
    while (j1)
    { 
        // 给非叶子结点赋值
        for (i = j1; i < j; i += 2)
        {
            if (t[i].key < t[i + 1].key)
            {
                t[(i + 1) / 2 - 1] = t[i];
            }
            else
            {
                t[(i + 1) / 2 - 1] = t[i + 1];
            }
        }
        j = j1;
        j1 = (j1 - 1) / 2;
    }
    for (i = 0; i < n; i++)
    {
        L.r[i + 1] = t[0]; // 将当前最小值赋给L.r[i]
        j1 = 0;
        for (j = 1; j < l; j++) // 沿树根找结点t[0]在叶子中的序号j1
        {
            if (t[2 * j1 + 1].key == t[j1].key)
            {
                j1 = 2 * j1 + 1;
            }
            else
            {
                j1 = 2 * j1 + 2;
            }
        }
        t[j1].key = INT_MAX;
        while (j1)
        {
            j1 = (j1 + 1) / 2 - 1; // 序号为j1的结点的双亲结点序号
            if (t[2 * j1 + 1].key <= t[2 * j1 + 2].key)
            {
                t[j1] = t[2 * j1 + 1];
            }
            else
            {
                t[j1] = t[2 * j1 + 2];
            }
        }
    }
    free(t);
}



// 希尔排序

void ShellInsert(SqList &L, int dk)
{ 
    // 对顺序表L作一趟希尔插入排序。本算法是和一趟直接插入排序相比，
    // 作了以下修改：
    // 1.前后记录位置的增量是dk，而不是1; 
    // 2.r[0]只是暂存单元，不是哨兵。当j <= 0时，插入位置已找到。
    int i, j; 
    for (i = dk + 1; i <= L.length; ++i) {
        if (L.r[i].key < L.r[i - dk].key) {
            // 需将L.r[i]插入有序增量子表
            L.r[0] = L.r[i]; // 暂存在L.r[0]
            for (j = i - dk; j > 0 && L.r[0].key < L.r[j].key; j -= dk) {
                L.r[j + dk] = L.r[j]; // 记录后移，查找插入位置
            }
            L.r[j + dk] = L.r[0]; // 插入
        }
    }
}


void ShellSort(SqList &L, int dlta[], int t)
{ 
    // 按增量序列dlta[0..t-1]对顺序表L作希尔排序
    int k; 
    for (k = 0; k < t; ++k) {
        ShellInsert(L, dlta[k]); // 一趟增量为dlta[k]的插入排序
        printf("第%d趟排序结果: ", k + 1); 
        Print(L); 
    }
}


// 快速排序
int Partition(SqList &L, int low, int high)
{ 
    // 交换顺序表L中子表r[low..high]的记录，枢轴记录到位，并返回其
    // 所在位置，此时在它之前(后)的记录均不大(小)于它。
    KeyType pivotkey; 
    L.r[0] = L.r[low]; // 用子表的第一个记录作枢轴记录
    pivotkey = L.r[low].key; // 枢轴记录关键字
    while (low < high) {
        // 从表的两端交替地向中间扫描
        while (low < high && L.r[high].key >= pivotkey) {
            --high; 
        }
        L.r[low] = L.r[high]; // 将比枢轴记录小的记录移到低端
        while (low < high && L.r[low].key <= pivotkey) {
            ++low; 
        }
        L.r[high] = L.r[low]; // 将比枢轴记录大的记录移到高端
    }
    L.r[low] = L.r[0]; // 枢轴记录到位
    return low; // 返回枢轴位置
}

// 快速排序的函数
void QSort(SqList &L, int low, int high)
{ 
    // 对顺序表L中的子序列L.r[low..high]作快速排序。
    int pivotloc; 
    if (low < high) {
        // 长度大于1
        pivotloc = Partition(L, low, high); // 将L.r[low..high]一分为二
        QSort(L, low, pivotloc - 1); // 对低子表递归排序，pivotloc是枢轴位置
        QSort(L, pivotloc + 1, high); // 对高子表递归排序
    }
}

void QuickSort(SqList &L)
{ 
    // 对顺序表L作快速排序。
    QSort(L, 1, L.length); 
}


// 堆排序

void HeapAdjust(HeapType &H, int s, int m) 
{ 
    // 已知H.r[s..m]中记录的关键字除H.r[s].key之外均满足堆的定义，本函数
    // 调整H.r[s]的关键字，使H.r[s..m]成为一个大顶堆(对其中记录的关键字而言)
    RedType rc; 
    int j; 
    rc = H.r[s]; 
    for (j = 2 * s; j <= m; j *= 2) {
        // 沿key较大的孩子结点向下筛选
        if (j < m && H.r[j].key < H.r[j + 1].key) {
            ++j; // j为key较大的记录的下标
        }
        if (!(rc.key < H.r[j].key)) {
            break; // rc应插入在位置s上
        }
        H.r[s] = H.r[j]; 
        s = j; 
    }
    H.r[s] = rc; // 插入
}

void HeapSort(HeapType &H)
{ 
    // 对顺序表H进行堆排序
    RedType t; 
    int i; 
    for (i = H.length / 2; i > 0; --i) { // 把H.r[1..H.length]建成大顶堆
        HeapAdjust(H, i, H.length); 
    }
    for (i = H.length; i > 1; --i) {
        // 将堆顶记录和当前未经排序子序列H.r[1..i]中最后一个记录相互交换
        t = H.r[1]; 
        H.r[1] = H.r[i]; 
        H.r[i] = t; 
        HeapAdjust(H, 1, i - 1); // 将H.r[1..i-1]重新调整为大顶堆
    }
}


// 归并排序

void Merge(RedType SR[], RedType TR[], int i, int m, int n)
{ 
    // 将有序的SR[i..m]和SR[m + 1..n]归并为有序的TR[i..n] 
    int j, k, l; 
    for (j = m + 1, k = i; i <= m && j <= n; ++k) { // 将SR中记录由小到大地并入TR
        if (SR[i].key <= SR[j].key) {
            TR[k] = SR[i++]; 
        } else {
            TR[k] = SR[j++]; 
        }
    }
    if (i <= m) {
        for (l = 0; l <= m - i; l++) {
            TR[k + l] = SR[i + l]; // 将剩余的SR[i..m]复制到TR
        }
    }
    if (j <= n) {
        for (l = 0; l <= n - j; l++) {
            TR[k + l] = SR[j + l]; // 将剩余的SR[j..n]复制到TR
        }
    }
}

void MSort(RedType SR[], RedType TR1[], int s, int t)
{ 
    // 将SR[s..t]归并排序为TR1[s..t]。
    int m; 
    RedType TR2[MAX_SIZE + 1]; 
    if (s == t) {
        TR1[s] = SR[s]; 
    } else {
        m = (s + t) / 2; // 将SR[s..t]平分为SR[s..m]和SR[m + 1..t]
        MSort(SR, TR2, s, m); // 递归地将SR[s..m]归并为有序的TR2[s..m]
        MSort(SR, TR2, m + 1, t); // 递归地将SR[m + 1..t]归并为有序的TR2[m + 1..t]
        Merge(TR2, TR1, s, m, t); // 将TR2[s..m]和TR2[m + 1..t]归并到TR1[s..t]
    }
}

void MergeSort(SqList &L)
{ 
    // 对顺序表L作归并排序。
    MSort(L.r, L.r, 1, L.length); 
}

