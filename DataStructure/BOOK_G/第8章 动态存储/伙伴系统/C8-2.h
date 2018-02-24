// C8-2.h ���ϵͳ�����ÿռ��Ľṹ
#ifndef C_8_2_H
#define C_8_2_H

#define M 10 // �����ÿռ�������1024�ֵ�2���ݴΣ��ӱ�ĸ���Ϊm+1
#define N 100 // ռ�ÿ���������ֵ

typedef struct WORD_b
{
    WORD_b *llink;  // ָ��ǰ�����
    int    tag;     // ���־��0�����У�1��ռ��
    int    kval;    // ���С��ֵΪ2���ݴ�k
    WORD_b *rlink;  // ͷ����ָ���̽��
} WORD_b, head, *Space;  // WORD_b���ڴ������ͣ����ĵ�һ����Ҳ��Ϊhead

typedef struct HeadNode
{
    int nodesize;  // ������Ŀ��п�Ĵ�С
    WORD_b *first;  // ������ı�ͷָ��
} FreeList[M + 1];  // ��ͷ��������


Space AllocBuddy(FreeList avail, int n); 
// avail[0..m]Ϊ�����ÿռ��nΪ��������������в�С��n�Ŀ��п飬
// �������Ӧ�Ĵ洢�飬���������׵�ַ�����򷵻�NULL���㷨8.2

Space buddy(Space p);
// ������ʼ��ַΪp�����СΪpow(2, p->kval)�Ŀ�Ļ���ַ

void Reclaim(FreeList pav, Space &p);
// ���ϵͳ�Ļ����㷨����p��ָ���ͷſ���յ������ÿռ��pav��

void Print(FreeList p);
// ���p�����п����ÿռ��

void PrintUser(Space p[]);
// ���p������ָ���ѷ���ռ�

#endif