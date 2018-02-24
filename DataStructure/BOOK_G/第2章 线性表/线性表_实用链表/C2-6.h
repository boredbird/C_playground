// c2-6.h ��ͷ����������������

#ifndef C_2_6_H
#define C_2_6_H

#include "C1.h"

typedef int ElemType; 


typedef struct LNode // �������
{
    ElemType data;
    LNode    *next;
} *Link, *Position;

struct LinkList // ��������
{
    Link head; // ָ�����������е�ͷ���
    Link tail; // ָ�����������е����һ�����
    int  len; // ָʾ��������������Ԫ�صĸ���
};


// ����ʵ����������������24����������


void MakeNode(Link &p, ElemType e);
// ������pָ���ֵΪe�Ľ�㡣������ʧ�ܣ����˳�

void FreeNode(Link &p);
// �ͷ�p��ָ���

void InitList(LinkList &L);
// ����һ���յ���������L

void ClearList(LinkList &L);
// ����������L����Ϊ�ձ����ͷ�ԭ����Ľ��ռ�

void DestroyList(LinkList &L);
// ������������L��L���ٴ���

void InsFirst(LinkList &L, Link h, Link s); // �β�����L,��Ϊ���޸�L
// hָ��L��һ����㣬��h����ͷ��㣬��s��ָ�������ڵ�һ�����֮ǰ

Status DelFirst(LinkList &L, Link h, Link &q); // �β�����L,��Ϊ���޸�L
// hָ��L��һ����㣬��h����ͷ��㣬ɾ�������еĵ�һ����㲢��q���ء�
// ������Ϊ��(hָ��β���)��q=NULL������FALSE

void Append(LinkList &L, Link s);
// ��ָ��s(s->dataΪ��һ������Ԫ��)��ָ(�˴���ָ����������NULL��β)��
// һ�������������������L�����һ�����֮�󣬲��ı�����L��βָ��ָ���µ�β���

Position PriorPos(LinkList L, Link p);
// ��֪pָ����������L�е�һ����㣬����p��ָ����ֱ��ǰ����λ�á�����ǰ�����򷵻�NULL

Status Remove(LinkList &L, Link &q);
// ɾ����������L�е�β��㲢��q���أ��ı�����L��βָ��ָ���µ�β���

void InsBefore(LinkList &L, Link &p, Link s);
// ��֪pָ����������L�е�һ����㣬��s��ָ��������p��ָ���֮ǰ��
// ���޸�ָ��pָ���²���Ľ��

void InsAfter(LinkList &L, Link &p, Link s);
// ��֪pָ����������L�е�һ����㣬��s��ָ��������p��ָ���֮��
// ���޸�ָ��pָ���²���Ľ��

void SetCurElem(Link p, ElemType e);
// ��֪pָ�����������е�һ����㣬��e����p��ָ���������Ԫ�ص�ֵ

ElemType GetCurElem(Link p);
// ��֪pָ�����������е�һ����㣬����p��ָ���������Ԫ�ص�ֵ

Status ListEmpty(LinkList L);
// ����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE

int ListLength(LinkList L);
// ������������L��Ԫ�ظ���

Position GetHead(LinkList L);
// ������������L��ͷ����λ��

Position GetLast(LinkList L);
// ������������L�����һ������λ��

Position NextPos(Link p);
// ��֪pָ����������L�е�һ����㣬����p��ָ����ֱ�Ӻ�̵�λ�á����޺�̣��򷵻�NULL

Status LocatePos(LinkList L, int i, Link &p);
// ����pָʾ��������L�е�i������λ�ã�������OK��iֵ���Ϸ�ʱ����ERROR��i=0Ϊͷ���

Position LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType));
// ������������L�е�1����e���㺯��compare()�ж���ϵ��Ԫ�ص�λ�ã�
// ��������������Ԫ�أ��򷵻�NULL

void ListTraverse(LinkList L, void(*visit)(ElemType));
// ���ζ�L��ÿ������Ԫ�ص��ú���visit()

void OrderInsert(LinkList &L, ElemType e, int (*comp)(ElemType, ElemType));
// ��֪LΪ��������������Ԫ��e���ǽ��������L�С�(����һԪ����ʽ)

Status LocateElem(LinkList L, ElemType e, Position &q, int (*compare)(ElemType, ElemType));
// ����������L�д�����e�����ж�����compare()ȡֵΪ0��Ԫ�أ���qָʾL��
// ��һ��ֵΪe�Ľ���λ�ã�������TRUE������qָʾ��һ����e�����ж�����
// compare()ȡֵ>0��Ԫ�ص�ǰ����λ�á�������FALSE��(����һԪ����ʽ)

#endif