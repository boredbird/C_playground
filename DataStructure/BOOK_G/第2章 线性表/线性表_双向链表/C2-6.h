// C2-6.h ���Ա��˫������洢�ṹ

#ifndef C_2_6_H
#define C_2_6_H

#include "C1.h"

typedef int ElemType;

typedef struct DuLNode
{
    ElemType data;
    DuLNode  *prior;
    DuLNode  *next;
} DuLNode, *DuLinkList;


void InitList(DuLinkList &L);
// �����յ�˫��ѭ������L

void DestroyList(DuLinkList &L);
// �������������˫��ѭ������L

void ClearList(DuLinkList L); // ���ı�L
// ��ʼ������L�Ѵ��ڡ������������L����Ϊ�ձ�

Status ListEmpty(DuLinkList L);
// ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE

int ListLength(DuLinkList L);
// ��ʼ������L�Ѵ��ڡ��������������L������Ԫ�ظ���

Status GetElem(DuLinkList L, int i, ElemType &e);
// ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR

int LocateElem(DuLinkList L, ElemType e, Status(*compare)(ElemType, ElemType));
// ��ʼ������L�Ѵ��ڣ�compare()������Ԫ���ж�����
// �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
//           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0

Status PriorElem(DuLinkList L, ElemType cur_e, ElemType &pre_e);
// �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����
//           ǰ�����������ʧ�ܣ�pre_e�޶���

Status NextElem(DuLinkList L, ElemType cur_e, ElemType &next_e);
// �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�
//           �������ʧ�ܣ�next_e�޶���

DuLinkList GetElemP(DuLinkList L, int i); // ���
// ��˫������L�з��ص�i��Ԫ�صĵ�ַ��iΪ0������ͷ���ĵ�ַ������i��Ԫ�ز����ڣ�
// ����NULL(�㷨2.18��2.19Ҫ���õĺ���)

Status ListInsert(DuLinkList L, int i, ElemType e);
// �ڴ�ͷ����˫��ѭ�����Ա�L�е�i��λ��֮ǰ����Ԫ��e��i�ĺϷ�ֵΪ1��i�ܱ�+1
// �Ľ��㷨2.18�������޷��ڵڱ�+1�����֮ǰ����Ԫ��

Status ListDelete(DuLinkList L, int i, ElemType &e); // �㷨2.19
// ɾ����ͷ����˫��ѭ�����Ա�L�ĵ�i��Ԫ�أ�i�ĺϷ�ֵΪ1��i�ܱ�

void ListTraverse(DuLinkList L, void(*visit)(ElemType));
// ��˫��ѭ�����Ա�L��ͷ�������������ÿ������Ԫ�ص��ú���visit()

void ListTraverseBack(DuLinkList L, void(*visit)(ElemType));
// ��˫��ѭ�����Ա�L��ͷ�������������ÿ������Ԫ�ص��ú���visit()�����

#endif