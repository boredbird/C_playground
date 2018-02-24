// C2-5.h ѭ��������洢�ṹ

#ifndef C_2_5_H
#define C_2_5_H

#include "C1.h"

typedef int ElemType;

struct LNode
{
    ElemType data;
    LNode    *next;
};

typedef LNode *LinkList; // ��һ�ֶ���LinkList�ķ���

void InitList(LinkList &L);
// �������������һ���յ����Ա�L

void DestroyList(LinkList &L);
// ����������������Ա�L

void ClearList(LinkList &L); // �ı�L
// ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�

Status ListEmpty(LinkList L);
// ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE

int ListLength(LinkList L);
// ��ʼ������L�Ѵ��ڡ��������������L������Ԫ�ظ���

Status GetElem(LinkList L, int i, ElemType &e);
// ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType));
// ��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����
// �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
//           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e);
// ��ʼ���������Ա�L�Ѵ���
// �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����
//           �������ʧ�ܣ�pre_e�޶���

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e);
// ��ʼ���������Ա�L�Ѵ���
// �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�
//           �������ʧ�ܣ�next_e�޶���

Status ListInsert(LinkList L, int i, ElemType e); // �ı�L
// ��L�ĵ�i��λ��֮ǰ����Ԫ��e

Status ListDelete(LinkList L, int i, ElemType &e); // �ı�L
// ɾ��L�ĵ�i��Ԫ�أ�����e������ֵ

void ListTraverse(LinkList L, void(*vi)(ElemType));
// ��ʼ������L�Ѵ��ڡ�������������ζ�L��ÿ������Ԫ�ص��ú���vi()


#endif