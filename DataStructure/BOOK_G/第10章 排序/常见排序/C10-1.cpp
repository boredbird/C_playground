// C10-1.cpp ���������㷨

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
    // ����һ����������Ա�
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


// ��������

void InsertSort(SqList &L)
{ 
    // ��˳���L��ֱ�Ӳ�������
    int i, j;
    for (i = 2; i <= L.length; ++i)
    {
        if (L.r[i].key < L.r[i - 1].key) // "<",�轫L.r[i]���������ӱ�
        {
            L.r[0] = L.r[i]; // ����Ϊ�ڱ�
            for (j = i - 1; L.r[0].key < L.r[j].key; --j)
            {
                L.r[j + 1] = L.r[j]; // ��¼����
            }
            L.r[j + 1] = L.r[0]; // ���뵽��ȷλ��
        }
    }
}

void BInsertSort(SqList &L)
{ 
    // ��˳���L���۰��������
    int i, j, m, low, high;
    for (i = 2; i <= L.length; ++i)
    {
        L.r[0] = L.r[i]; // ��L.r[i]�ݴ浽L.r[0]
        low = 1;
        high = i - 1;
        while (low <= high)
        {   
            // ��r[low..high]���۰������������λ��
            m = (low + high) / 2; // �۰�
            if (L.r[0].key < L.r[m].key)
            {
                high = m - 1; // ������ڵͰ���
            }
            else
            {
                low = m + 1; // ������ڸ߰���
            }
        }
        for (j = i - 1; j >= high + 1; --j)
        {
            L.r[j + 1] = L.r[j]; // ��¼����
        }
        L.r[high + 1] = L.r[0]; // ����
    }
}

void P2_InsertSort(SqList &L)
{ 
    // 2_·��������
    int i, j, first, final;
    RedType *d;
    d = (RedType*) malloc(L.length * sizeof(RedType)); // ����L.length����¼����ʱ�ռ�
    d[0] = L.r[1]; // ��L�ĵ�1����¼Ϊd���ź���ļ�¼(��λ��[0])
    first = final = 0; // first��final�ֱ�ָʾd���ź���ļ�¼�ĵ�1�������1����¼��λ��
    for (i = 2; i <= L.length; ++i) // ���ν�L�ĵ�2�������1����¼����d��
    {
        if (L.r[i].key < d[first].key)
        { 
            // �����¼С��d����Сֵ���嵽d[first]֮ǰ(�����ƶ�d�����Ԫ��)
            first = (first - 1 + L.length) % L.length; // ��dΪѭ������
            d[first] = L.r[i];
        }
        else if (L.r[i].key > d[final].key)
        { 
            // �����¼����d�����ֵ���嵽d[final]֮��(�����ƶ�d�����Ԫ��)
            final = final + 1;
            d[final] = L.r[i];
        }
        else
        { 
            // �����¼����d����Сֵ��С��d�����ֵ���嵽d���м�(��Ҫ�ƶ�d�����Ԫ��)
            j = final++; // �ƶ�d��β��Ԫ���Ա㰴������¼
            while (L.r[i].key < d[j].key)
            {
                d[(j + 1) % L.length] = d[j];
                j = (j - 1 + L.length) % L.length;
            }
            d[(j + 1) % L.length] = L.r[i];
        }
    }
    for (i = 1; i <= L.length; i++) // ��d����L.r
    {
        L.r[i] = d[(i + first - 1) % L.length]; // ���Թ�ϵ
    }
    free(d);
}

// ð������

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

// ѡ������

int SelectMinKey(SqList L, int i)
{ 
    // ������L.r[i..L.length]��key��С�ļ�¼�����
    KeyType min;
    int j, k;
    k = i; // ���i��Ϊ��С
    min = L.r[i].key;
    for (j = i + 1; j <= L.length; j++)
    {
        if (L.r[j].key < min) // �ҵ���С��
        {
            k = j;
            min = L.r[j].key;
        }
    }
    return k;
}

void SelectSort(SqList &L)
{ 
    // ��˳���L����ѡ������
    int i, j;
    RedType t;
    for (i = 1; i < L.length; ++i)
    { 
        //  ѡ���iС�ļ�¼����������λ
        j = SelectMinKey(L, i); // ��L.r[i..L.length]��ѡ��key��С�ļ�¼
        if (i != j)
        { 
            // ���i����¼����
            t = L.r[i];
            L.r[i] = L.r[j];
            L.r[j] = t;
        }
    }
}


void TreeSort(SqList &L)
{ 
    // ����ѡ������
    int i, j, j1, k, k1, l, n = L.length;
    RedType *t;
    l = (int) ceil(log(n) / log(2)) + 1; // ��ȫ�������Ĳ���
    k = (int) pow(2, l) - 1; // l����ȫ�������Ľ������
    k1 = (int)pow(2, l - 1) - 1; // l-1����ȫ�������Ľ������
    t = (RedType*) malloc(k * sizeof(RedType)); // ����������˳��洢�ṹ
    for (i = 1; i <= n; i++) // ��L.r����Ҷ�ӽ��
    {
        t[k1 + i - 1] = L.r[i];
    }
    for (i = k1 + n; i < k; i++) // �������Ҷ�ӵĹؼ��ָ������
    {
        t[i].key = INT_MAX;
    }
    j1 = k1;
    j = k;
    while (j1)
    { 
        // ����Ҷ�ӽ�㸳ֵ
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
        L.r[i + 1] = t[0]; // ����ǰ��Сֵ����L.r[i]
        j1 = 0;
        for (j = 1; j < l; j++) // �������ҽ��t[0]��Ҷ���е����j1
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
            j1 = (j1 + 1) / 2 - 1; // ���Ϊj1�Ľ���˫�׽�����
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



// ϣ������

void ShellInsert(SqList &L, int dk)
{ 
    // ��˳���L��һ��ϣ���������򡣱��㷨�Ǻ�һ��ֱ�Ӳ���������ȣ�
    // ���������޸ģ�
    // 1.ǰ���¼λ�õ�������dk��������1; 
    // 2.r[0]ֻ���ݴ浥Ԫ�������ڱ�����j <= 0ʱ������λ�����ҵ���
    int i, j; 
    for (i = dk + 1; i <= L.length; ++i) {
        if (L.r[i].key < L.r[i - dk].key) {
            // �轫L.r[i]�������������ӱ�
            L.r[0] = L.r[i]; // �ݴ���L.r[0]
            for (j = i - dk; j > 0 && L.r[0].key < L.r[j].key; j -= dk) {
                L.r[j + dk] = L.r[j]; // ��¼���ƣ����Ҳ���λ��
            }
            L.r[j + dk] = L.r[0]; // ����
        }
    }
}


void ShellSort(SqList &L, int dlta[], int t)
{ 
    // ����������dlta[0..t-1]��˳���L��ϣ������
    int k; 
    for (k = 0; k < t; ++k) {
        ShellInsert(L, dlta[k]); // һ������Ϊdlta[k]�Ĳ�������
        printf("��%d��������: ", k + 1); 
        Print(L); 
    }
}


// ��������
int Partition(SqList &L, int low, int high)
{ 
    // ����˳���L���ӱ�r[low..high]�ļ�¼�������¼��λ����������
    // ����λ�ã���ʱ����֮ǰ(��)�ļ�¼������(С)������
    KeyType pivotkey; 
    L.r[0] = L.r[low]; // ���ӱ�ĵ�һ����¼�������¼
    pivotkey = L.r[low].key; // �����¼�ؼ���
    while (low < high) {
        // �ӱ�����˽�������м�ɨ��
        while (low < high && L.r[high].key >= pivotkey) {
            --high; 
        }
        L.r[low] = L.r[high]; // ���������¼С�ļ�¼�Ƶ��Ͷ�
        while (low < high && L.r[low].key <= pivotkey) {
            ++low; 
        }
        L.r[high] = L.r[low]; // ���������¼��ļ�¼�Ƶ��߶�
    }
    L.r[low] = L.r[0]; // �����¼��λ
    return low; // ��������λ��
}

// ��������ĺ���
void QSort(SqList &L, int low, int high)
{ 
    // ��˳���L�е�������L.r[low..high]����������
    int pivotloc; 
    if (low < high) {
        // ���ȴ���1
        pivotloc = Partition(L, low, high); // ��L.r[low..high]һ��Ϊ��
        QSort(L, low, pivotloc - 1); // �Ե��ӱ�ݹ�����pivotloc������λ��
        QSort(L, pivotloc + 1, high); // �Ը��ӱ�ݹ�����
    }
}

void QuickSort(SqList &L)
{ 
    // ��˳���L����������
    QSort(L, 1, L.length); 
}


// ������

void HeapAdjust(HeapType &H, int s, int m) 
{ 
    // ��֪H.r[s..m]�м�¼�Ĺؼ��ֳ�H.r[s].key֮�������ѵĶ��壬������
    // ����H.r[s]�Ĺؼ��֣�ʹH.r[s..m]��Ϊһ���󶥶�(�����м�¼�Ĺؼ��ֶ���)
    RedType rc; 
    int j; 
    rc = H.r[s]; 
    for (j = 2 * s; j <= m; j *= 2) {
        // ��key�ϴ�ĺ��ӽ������ɸѡ
        if (j < m && H.r[j].key < H.r[j + 1].key) {
            ++j; // jΪkey�ϴ�ļ�¼���±�
        }
        if (!(rc.key < H.r[j].key)) {
            break; // rcӦ������λ��s��
        }
        H.r[s] = H.r[j]; 
        s = j; 
    }
    H.r[s] = rc; // ����
}

void HeapSort(HeapType &H)
{ 
    // ��˳���H���ж�����
    RedType t; 
    int i; 
    for (i = H.length / 2; i > 0; --i) { // ��H.r[1..H.length]���ɴ󶥶�
        HeapAdjust(H, i, H.length); 
    }
    for (i = H.length; i > 1; --i) {
        // ���Ѷ���¼�͵�ǰδ������������H.r[1..i]�����һ����¼�໥����
        t = H.r[1]; 
        H.r[1] = H.r[i]; 
        H.r[i] = t; 
        HeapAdjust(H, 1, i - 1); // ��H.r[1..i-1]���µ���Ϊ�󶥶�
    }
}


// �鲢����

void Merge(RedType SR[], RedType TR[], int i, int m, int n)
{ 
    // �������SR[i..m]��SR[m + 1..n]�鲢Ϊ�����TR[i..n] 
    int j, k, l; 
    for (j = m + 1, k = i; i <= m && j <= n; ++k) { // ��SR�м�¼��С����ز���TR
        if (SR[i].key <= SR[j].key) {
            TR[k] = SR[i++]; 
        } else {
            TR[k] = SR[j++]; 
        }
    }
    if (i <= m) {
        for (l = 0; l <= m - i; l++) {
            TR[k + l] = SR[i + l]; // ��ʣ���SR[i..m]���Ƶ�TR
        }
    }
    if (j <= n) {
        for (l = 0; l <= n - j; l++) {
            TR[k + l] = SR[j + l]; // ��ʣ���SR[j..n]���Ƶ�TR
        }
    }
}

void MSort(RedType SR[], RedType TR1[], int s, int t)
{ 
    // ��SR[s..t]�鲢����ΪTR1[s..t]��
    int m; 
    RedType TR2[MAX_SIZE + 1]; 
    if (s == t) {
        TR1[s] = SR[s]; 
    } else {
        m = (s + t) / 2; // ��SR[s..t]ƽ��ΪSR[s..m]��SR[m + 1..t]
        MSort(SR, TR2, s, m); // �ݹ�ؽ�SR[s..m]�鲢Ϊ�����TR2[s..m]
        MSort(SR, TR2, m + 1, t); // �ݹ�ؽ�SR[m + 1..t]�鲢Ϊ�����TR2[m + 1..t]
        Merge(TR2, TR1, s, m, t); // ��TR2[s..m]��TR2[m + 1..t]�鲢��TR1[s..t]
    }
}

void MergeSort(SqList &L)
{ 
    // ��˳���L���鲢����
    MSort(L.r, L.r, 1, L.length); 
}

