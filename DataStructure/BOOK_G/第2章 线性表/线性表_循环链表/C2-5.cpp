// C2-5.cpp ����βָ��ĵ�ѭ�������12����������

#include "C2-5.h"

void InitList(LinkList &L)
{   // �������������һ���յ����Ա�L
    L = (LinkList) malloc(sizeof(LNode)); // ����ͷ��㣬��ʹLָ���ͷ���
    if (!L) { // �洢����ʧ��
        exit(OVERFLOW);
    }
    L->next = L; // ָ����ָ��ͷ���
}

void DestroyList(LinkList &L)
{   // ����������������Ա�L
    LinkList q, p = L->next; // pָ���һ�����
    while (p != L) { // û����β
        q = p->next;
        free(p);
        p = q;
    }
    free(L);
    L = NULL;
}

void ClearList(LinkList &L) // �ı�L
{   // ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
    LinkList p, q;
    p = L->next; // pָ���һ�����
    while (p != L) { // û����β
        q = p->next;
        free(p);
        p = q;
    }
    L->next = L; // ͷ���ָ����ָ������
}

Status ListEmpty(LinkList L)
{   // ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
    if(L->next == L) { // ��
        return TRUE;
    } else {
        return FALSE;
    }
}

int ListLength(LinkList L)
{   // ��ʼ������L�Ѵ��ڡ��������������L������Ԫ�ظ���
    int i = 0;
    LinkList p = L->next; // pָ���һ�����
    while (p != L) { // û����β
        i++;
        p = p->next;
    }
    return i;
}

Status GetElem(LinkList L, int i, ElemType &e)
{   // ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
    int j = 1; // ��ʼ����jΪ������
    LinkList p = L->next; // pָ���һ�����
    if (i <= 0 || i > ListLength(L)) { // ��i��Ԫ�ز�����
        return ERROR;
    }
    while (j < i) { // ˳ָ�������ң�ֱ��pָ���i��Ԫ��
        p = p->next;
        j++;
    }
    e = p->data; // ȡ��i��Ԫ��
    return OK;
}

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{   // ��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����
    // �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
    //           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0
    int i = 0;
    LinkList p = L->next; // pָ���һ�����
    while (p != L) {
        i++;
        if (compare(p->data, e)) { // �����ϵ
            return i;
        }
        p = p->next;
    }
    return 0;
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e)
{   // ��ʼ���������Ա�L�Ѵ���
    // �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����
    //           �������ʧ�ܣ�pre_e�޶���
    LinkList q, p = L->next; // pָ���һ�����
    q = p->next;
    while (q != L) { // pû����β
        if (q->data == cur_e) {
            pre_e = p->data;
            return TRUE;
        }
        p = q;
        q = q->next;
    }
    return FALSE; // ����ʧ��
}

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e)
{   // ��ʼ���������Ա�L�Ѵ���
    // �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�
    //           �������ʧ�ܣ�next_e�޶���
    LinkList p = L->next; // pָ���һ�����
    while (p != L && p->next != L) { // pû����β
        if (p->data == cur_e) {
            next_e = p->next->data;
            return TRUE;
        }
        p = p->next;
    }
    return FALSE; // ����ʧ��
}

Status ListInsert(LinkList L, int i, ElemType e) // �ı�L
{   // ��L�ĵ�i��λ��֮ǰ����Ԫ��e
    LinkList p = L, s; // pָ��ͷ���
    int j = 0;
    if (i <= 0 || i > ListLength(L) + 1) { // λ��i���Ϸ�
        return ERROR;
    }
    while (j < i - 1) { // Ѱ�ҵ�i-1�����
        p = p->next;
        j++;
    }
    s = (LinkList) malloc(sizeof(LNode)); // �����½��
    s->data = e; // ����L��
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList L, int i, ElemType &e) // �ı�L
{   // ɾ��L�ĵ�i��Ԫ�أ�����e������ֵ
    LinkList p = L, q; // pָ��ͷ���
    int j = 0;
    if (i <= 0 || i > ListLength(L)) { // ��i��Ԫ�ز�����
        return ERROR;
    }
    while (j < i - 1) { // Ѱ�ҵ�i-1�����
        p = p->next;
        j++;
    }
    q = p->next; // qָ���ɾ�����
    p->next = q->next;
    e = q->data;
    free(q); // �ͷŴ�ɾ�����
    return OK;
}

void ListTraverse(LinkList L, void(*vi)(ElemType))
{   // ��ʼ������L�Ѵ��ڡ�������������ζ�L��ÿ������Ԫ�ص��ú���vi()
    LinkList p = L->next;  // pָ���һ�����
    while (p != L) { // p��ָ��ͷ���
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}