#ifndef C_10_1_H
#define C_10_1_H

#define MAX_SIZE 20 // һ������ʾ����С˳������󳤶�
typedef int KeyType; // ����ؼ�������Ϊ����
typedef int InfoType; // �������������������

struct RedType // ��¼����
{
    KeyType key; // �ؼ�����
    InfoType otherinfo; // ������������������������ж���
}; 

struct SqList // ˳�������
{
    RedType r[MAX_SIZE + 1]; // r[0]���û������ڱ���Ԫ
    int length; // ˳�����
}; 


void Print(SqList L);
// ��ӡ˳���

void CreateList(SqList &L);
// ����һ����������Ա�

void InsertSort(SqList &L);
// ��˳���L��ֱ�Ӳ�������
    
void BInsertSort(SqList &L);
// ��˳���L���۰��������

void P2_InsertSort(SqList &L);
// 2_·��������

void BubbleSort(SqList &L);
// ð������

void SelectSort(SqList &L);
// ��˳���L����ѡ������

void TreeSort(SqList &L);
// ����ѡ������

void ShellSort(SqList &L, int dlta[], int t);
// ����������dlta[0..t-1]��˳���L��ϣ������

void QuickSort(SqList &L);
// ��˳���L����������

typedef SqList HeapType; // �Ѳ���˳���洢��ʾ
void HeapSort(HeapType &H);
// ��˳���H���ж�����

void MergeSort(SqList &L);
// ��˳���L���鲢����

#endif