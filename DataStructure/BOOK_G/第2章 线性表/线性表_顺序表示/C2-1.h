// C2-1.h ���Ա�Ķ�̬����˳��洢�ṹ
#ifndef C2_1_H
#define C2_1_H

#include "C1.h"

typedef int ElemType;     //�û�ָ����������

#define LIST_INIT_SIZE 10 // ���Ա�洢�ռ�ĳ�ʼ������
#define LIST_INCREMENT 2  // ���Ա�洢�ռ�ķ�������

struct SqList
{
    ElemType *elem;    // �洢�ռ��ַ
    int      length;   // ��ǰ����
    int      listsize; // ��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
};

// ˳���ʾ�����Ա�Ļ�������(12��)

void InitList(SqList &L);
// �������������һ���յ�˳�����Ա�L���㷨2.3

void DestroyList(SqList &L);
// ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������˳�����Ա�L

void ClearList(SqList &L);
// ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�

Status ListEmpty(SqList L);
// ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE

int ListLength(SqList L);
// ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ���

Status GetElem(SqList L, int i, ElemType &e);
// ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�������������e����L�е�i������Ԫ�ص�ֵ

int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));
// ��ʼ������˳�����Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����(����Ϊ1������Ϊ0)
// �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
//           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0���㷨2.6

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e);
// ��ʼ������˳�����Ա�L�Ѵ���
// �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����
//           �������ʧ�ܣ�pre_e�޶���

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e);
// ��ʼ������˳�����Ա�L�Ѵ���
// �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�
//           �������ʧ�ܣ�next_e�޶���

Status ListInsert(SqList &L, int i, ElemType e); 
// ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)+1
// �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1���㷨2.4

Status ListDelete(SqList &L, int i, ElemType &e); 
// ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)
// ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1���㷨2.5

void ListTraverse(SqList L, void(*vi)(ElemType&));
// ��ʼ������˳�����Ա�L�Ѵ���
// ������������ζ�L��ÿ������Ԫ�ص��ú���vi()
//           vi()���βμ�'&'��������ͨ������vi()�ı�Ԫ�ص�ֵ

#endif