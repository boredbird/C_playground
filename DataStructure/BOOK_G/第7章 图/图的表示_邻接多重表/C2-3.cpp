// C2-3.cpp ����ͷ���ĵ�����Ļ�������(9��),��չ����(3��)

#include "C2-3.h"

void InitList(LinkList &L)
{   // �������������һ���յ����Ա�L
    L = NULL; // ָ��Ϊ��
}

void ClearList(LinkList &L)
{   // ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
    LinkList p;
    while (L) { // L����
        p = L; // pָ����Ԫ���
        L = L->next; // Lָ���2�����(����Ԫ���)
        free(p); // �ͷ���Ԫ���
    }
}

Status ListEmpty(LinkList L)
{   // ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
    if (L) {
        return FALSE;
    } else {
        return TRUE;
    }
}

int ListLength(LinkList L)
{   // ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ���
    int i = 0;
    LinkList p = L;
    while (p) { // pָ����(û����β)
        p = p->next; // pָ����һ�����
        i++;
    }
    return i;
}

Status GetElem(LinkList L, int i, ElemType &e)
{   // LΪ����ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
    int j = 1;
    LinkList p = L;
    if (i < 1) { // iֵ���Ϸ�
        return ERROR;
    }
    while (j < i && p) { // û����i��Ԫ�أ�Ҳû����β
        j++;
        p = p->next;
    }
    if (j == i) { // ���ڵ�i��Ԫ��
        e = p->data;
        return OK;
    } else {
        return ERROR;
    }
}

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{   // ��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����(����Ϊ1������Ϊ0)
    // �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
    //           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0
    int i = 0;
    LinkList p = L;
    while (p) {
        i++;
        if (compare(p->data, e)) { // �ҵ�����������Ԫ��
            return i;
        }
        p = p->next;
    }
    return 0;
}

Status ListInsert(LinkList &L, int i, ElemType e)
{   // �ڲ���ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
    int j = 1;
    LinkList p = L, s;
    
    if (i < 1 || i > ListLength(L) + 1) { // iֵ���Ϸ�
        return ERROR;
    }
    while (p && j < i - 1) { // Ѱ�ҵ�i-1�����
        p = p->next;
        j++;
    }
    s = (LinkList) malloc(sizeof(LNode)); // �����½��
    s->data = e;
    if (i == 1) {
        s->next = L;
        L = s;  // �ı�L
    } else {
        s->next = p->next;
        p->next = s;
    }
    return OK;
}

Status ListDelete(LinkList &L, int i, ElemType &e)
{   // �ڲ���ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
    int j = 1;
    LinkList p = L, q;
    if (i == 1) { // ɾ����1�����
        L = p->next; // L�ɵ�2����㿪ʼ
        e = p->data;
        free(p); // ɾ�����ͷŵ�1�����
    } else {
        while (p->next && j < i - 1) { // Ѱ�ҵ�i����㣬����pָ����ǰ��
            p = p->next;
            j++;
        }
        if (!p->next || j > i - 1) { // ɾ��λ�ò�����
            return ERROR;
        }
        q = p->next; // ɾ�����ͷŽ��
        p->next = q->next;
        e = q->data;
        free(q);
    }
    return OK;
}

void ListTraverse(LinkList L,void(*vi)(ElemType))
{   // ��ʼ���������Ա�L�Ѵ��ڡ�������������ζ�L��ÿ������Ԫ�ص��ú���vi()
    LinkList p = L;
    while (p) {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e, int(*compare)(ElemType,ElemType))
{   // ��ʼ���������Ա�L�Ѵ���
    // �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����
    //           ����OK���������ʧ�ܣ�pre_e�޶��壬����INFEASIBLE
    LinkList q, p = L; // pָ���һ�����
    while (p->next) { // p��ָ����к��
        q = p->next; // qΪp�ĺ��
        if (compare(q->data, cur_e) == 0) { // ������
            pre_e = p->data;
            return OK;
        }
        p = q; // p�����
    }
    return INFEASIBLE;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e, int(*compare)(ElemType,ElemType))
{   // ��ʼ���������Ա�L�Ѵ���
    // �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�
    //           ����OK���������ʧ�ܣ�next_e�޶��壬����INFEASIBLE
    LinkList p = L; // pָ���һ�����
    while (p->next) { // p��ָ����к��
        if (compare(p->data, cur_e) == 0) { // ������
            next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return INFEASIBLE;
}

// ����ͷ���ĵ��������չ����(3��)

void InsertAscend(LinkList &L, ElemType e, int(*compare)(ElemType,ElemType))
{   // ���ؼ��ַǽ���e�����L������compare()����ֵΪ���β�1�Ĺؼ���-�β�2�Ĺؼ���
    LinkList q = L;
    if (!L || compare(e, L->data) <= 0) { // ����ջ�e�Ĺؼ���С�ڵ����׽��Ĺؼ���
        ListInsert(L, 1, e); // ��e���ڱ�ͷ
    } else {
        while (q->next && compare(q->next->data, e) < 0) { // q����β�����q����һ���ؼ���<e�Ĺؼ���
            q = q->next;
        }
        ListInsert(q, 2, e); // ����q��ָ����(��q��Ϊͷָ��)
    }
}

LinkList Point(LinkList L, ElemType e, Status(*equal)(ElemType, ElemType), LinkList &p)
{   // ���ұ�L�����������Ľ�㡣���ҵ�������ָ��ý���ָ�룬pָ��ý���ǰ��(���ý����
    // ��Ԫ��㣬��p=NULL)�����L�������������Ľ�㣬�򷵻�NULL��p�޶��塣
    // ����equal()�����βεĹؼ�����ȣ�����OK�����򷵻�ERROR
    int i, j;
    i = LocateElem(L, e, equal);
    if (i) { // �ҵ�
        if (i == 1) { // ����Ԫ���
            p = NULL;
            return L;
        }
        p = L;
        for (j = 2; j < i; j++) {
            p = p->next;
        }
        return p->next;
    }
    return NULL; // û�ҵ�
}

Status DeleteElem(LinkList &L, ElemType &e, Status(*equal)(ElemType, ElemType))
{   // ɾ����L�����������Ľ�㣬������TRUE�����޴˽�㣬�򷵻�FALSE��
    // ����equal()�����βεĹؼ�����ȣ�����OK�����򷵻�ERROR
    LinkList p, q;
    q = Point(L, e, equal, p);
    if (q) { // �ҵ��˽�㣬��qָ��ý��
        if (p) { // �ý�㲻����Ԫ��㣬pָ����ǰ��
            ListDelete(p, 2, e); // ��p��Ϊͷָ��,ɾ����2�����
        } else { // �ý������Ԫ���
            ListDelete(L,1,e);
        }
        return TRUE;
    }
    return FALSE;
}
