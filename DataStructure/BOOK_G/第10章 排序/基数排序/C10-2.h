
#ifndef C_10_2_H
#define C_10_2_H

#include "C1.h"

typedef int InfoType; // �������������������
typedef int KeyType; // ����RedType���͵Ĺؼ���Ϊ����
struct RedType // ��¼����
{
    KeyType  key;       // �ؼ�����
    InfoType otherinfo; // ����������
}; 
typedef char KeysType; // ����ؼ�������Ϊ�ַ���

#define MAX_NUM_OF_KEY 8 // �ؼ������������ֵ
#define RADIX 10 // �ؼ��ֻ�������ʱ��ʮ���������Ļ���
#define MAX_SPACE 1000
struct SLCell // ��̬����Ľ������
{
    KeysType keys[MAX_NUM_OF_KEY]; // �ؼ���
    InfoType otheritems;           // ����������
    int      next; 
}; 

struct SLList // ��̬��������
{
    SLCell r[MAX_SPACE]; // ��̬����Ŀ����ÿռ䣬r[0]Ϊͷ���
    int keynum; // ��¼�ĵ�ǰ�ؼ��ָ���
    int recnum; // ��̬����ĵ�ǰ����
}; 

typedef int ArrType[RADIX]; // ָ����������


void InitList(SLList &L, RedType D[], int n);
// ��ʼ����̬����L(������D�е����ݴ���L��)

void RadixSort(SLList &L);
// L�ǲ��þ�̬�����ʾ��˳�����L����������ʹ��L��Ϊ���ؼ���
// ��С���������̬����L.r[0]Ϊͷ��㡣

void Print(SLList L);
// ��������������̬����

void Sort(SLList L, int adr[]);
// ���adr[1..L.length]��adr[i]Ϊ��̬����L�ĵ�i����С��¼�����

void Rearrange(SLList &L, int adr[]);
// adr������̬����L��������򣬼�L.r[adr[i]]�ǵ�iС�ļ�¼��
// ���㷨��adr����L.r��ʹ������

#endif