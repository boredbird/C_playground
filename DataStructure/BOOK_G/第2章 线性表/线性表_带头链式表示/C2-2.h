// c2-2.h ���Ա�ĵ�����洢�ṹ

#ifndef C_2_2_H
#define C_2_2_H

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
// ��ʼ���������Ա�L�Ѵ��ڡ�����������������Ա�L

void ClearList(LinkList L); // ���ı�L
// ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�

Status ListEmpty(LinkList L);
// ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE

int ListLength(LinkList L);
// ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ���

Status GetElem(LinkList L, int i, ElemType &e); // �㷨2.8
// LΪ��ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType));
// ��ʼ����: ���Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����(����Ϊ1������Ϊ0)
// �������: ����L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
//           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e);
// ��ʼ����: ���Ա�L�Ѵ���
// �������: ��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����
//           ����OK���������ʧ�ܣ�pre_e�޶��壬����INFEASIBLE

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e);
// ��ʼ���������Ա�L�Ѵ���
// �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�
//           ����OK;�������ʧ�ܣ�next_e�޶��壬����INFEASIBLE

Status ListInsert(LinkList L, int i, ElemType e); // �㷨2.9�����ı�L
// �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e

Status ListDelete(LinkList L, int i, ElemType &e); // �㷨2.10�����ı�L
// �ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ

void ListTraverse(LinkList L, void(*vi)(ElemType));
// vi���β�����ΪElemType����bo2-1.cpp����Ӧ�������β�����ElemType&��ͬ
// ��ʼ���������Ա�L�Ѵ��ڡ�������������ζ�L��ÿ������Ԫ�ص��ú���vi()

#endif