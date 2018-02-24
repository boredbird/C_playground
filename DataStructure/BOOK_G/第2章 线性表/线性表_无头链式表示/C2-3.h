// C2-3.h ���Ա���ͷ���ĵ�����洢�ṹ

#ifndef C_2_3_H
#define C_2_3_H

#include "C1.h"

typedef int ElemType;

struct LNode
{
    ElemType data;
    LNode    *next;
};

typedef LNode *LinkList; // ��һ�ֶ���LinkList�ķ���

#define DestroyList ClearList // DestroyList()��ClearList()�Ĳ�����һ����

void InitList(LinkList &L);
// �������������һ���յ����Ա�L

void ClearList(LinkList &L);
// ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�

Status ListEmpty(LinkList L);
// ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE

int ListLength(LinkList L);
// ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ���

Status GetElem(LinkList L, int i, ElemType &e);
// LΪ����ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType));
// ��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����(����Ϊ1������Ϊ0)
// �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
//           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0

Status ListInsert(LinkList &L, int i, ElemType e);
// �ڲ���ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e

Status ListDelete(LinkList &L, int i, ElemType &e);
// �ڲ���ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ

void ListTraverse(LinkList L,void(*vi)(ElemType));
// ��ʼ���������Ա�L�Ѵ��ڡ�������������ζ�L��ÿ������Ԫ�ص��ú���vi()

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e);
// ��ʼ���������Ա�L�Ѵ���
// �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����
//           ����OK���������ʧ�ܣ�pre_e�޶��壬����INFEASIBLE

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e);
// ��ʼ���������Ա�L�Ѵ���
// �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�
//           ����OK���������ʧ�ܣ�next_e�޶��壬����INFEASIBLE


// ����ͷ���ĵ��������չ����(3��)

void InsertAscend(LinkList &L, ElemType e, int(*compare)(ElemType,ElemType));
// ���ؼ��ַǽ���e�����L������compare()����ֵΪ���β�1�Ĺؼ���-�β�2�Ĺؼ���

LinkList Point(LinkList L, ElemType e, Status(*equal)(ElemType, ElemType), LinkList &p);
// ���ұ�L�����������Ľ�㡣���ҵ�������ָ��ý���ָ�룬pָ��ý���ǰ��(���ý����
// ��Ԫ��㣬��p=NULL)�����L�������������Ľ�㣬�򷵻�NULL��p�޶��塣
// ����equal()�����βεĹؼ�����ȣ�����OK�����򷵻�ERROR

Status DeleteElem(LinkList &L, ElemType &e, Status(*equal)(ElemType, ElemType));
// ɾ����L�����������Ľ�㣬������TRUE�����޴˽�㣬�򷵻�FALSE��
// ����equal()�����βεĹؼ�����ȣ�����OK�����򷵻�ERROR

#endif