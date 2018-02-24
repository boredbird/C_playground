// C2-3.cpp 不带头结点的单链表的基本操作(9个),扩展操作(3个)

#include "C2-3.h"

void InitList(LinkList &L)
{   // 操作结果：构造一个空的线性表L
    L = NULL; // 指针为空
}

void ClearList(LinkList &L)
{   // 初始条件：线性表L已存在。操作结果：将L重置为空表
    LinkList p;
    while (L) { // L不空
        p = L; // p指向首元结点
        L = L->next; // L指向第2个结点(新首元结点)
        free(p); // 释放首元结点
    }
}

Status ListEmpty(LinkList L)
{   // 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE
    if (L) {
        return FALSE;
    } else {
        return TRUE;
    }
}

int ListLength(LinkList L)
{   // 初始条件：线性表L已存在。操作结果：返回L中数据元素个数
    int i = 0;
    LinkList p = L;
    while (p) { // p指向结点(没到表尾)
        p = p->next; // p指向下一个结点
        i++;
    }
    return i;
}

Status GetElem(LinkList L, int i, ElemType &e)
{   // L为不带头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
    int j = 1;
    LinkList p = L;
    if (i < 1) { // i值不合法
        return ERROR;
    }
    while (j < i && p) { // 没到第i个元素，也没到表尾
        j++;
        p = p->next;
    }
    if (j == i) { // 存在第i个元素
        e = p->data;
        return OK;
    } else {
        return ERROR;
    }
}

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{   // 初始条件：线性表L已存在，compare()是数据元素判定函数(满足为1，否则为0)
    // 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。
    //           若这样的数据元素不存在，则返回值为0
    int i = 0;
    LinkList p = L;
    while (p) {
        i++;
        if (compare(p->data, e)) { // 找到这样的数据元素
            return i;
        }
        p = p->next;
    }
    return 0;
}

Status ListInsert(LinkList &L, int i, ElemType e)
{   // 在不带头结点的单链线性表L中第i个位置之前插入元素e
    int j = 1;
    LinkList p = L, s;
    
    if (i < 1 || i > ListLength(L) + 1) { // i值不合法
        return ERROR;
    }
    while (p && j < i - 1) { // 寻找第i-1个结点
        p = p->next;
        j++;
    }
    s = (LinkList) malloc(sizeof(LNode)); // 生成新结点
    s->data = e;
    if (i == 1) {
        s->next = L;
        L = s;  // 改变L
    } else {
        s->next = p->next;
        p->next = s;
    }
    return OK;
}

Status ListDelete(LinkList &L, int i, ElemType &e)
{   // 在不带头结点的单链线性表L中，删除第i个元素，并由e返回其值
    int j = 1;
    LinkList p = L, q;
    if (i == 1) { // 删除第1个结点
        L = p->next; // L由第2个结点开始
        e = p->data;
        free(p); // 删除并释放第1个结点
    } else {
        while (p->next && j < i - 1) { // 寻找第i个结点，并令p指向其前趋
            p = p->next;
            j++;
        }
        if (!p->next || j > i - 1) { // 删除位置不合理
            return ERROR;
        }
        q = p->next; // 删除并释放结点
        p->next = q->next;
        e = q->data;
        free(q);
    }
    return OK;
}

void ListTraverse(LinkList L,void(*vi)(ElemType))
{   // 初始条件：线性表L已存在。操作结果：依次对L的每个数据元素调用函数vi()
    LinkList p = L;
    while (p) {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e, int(*compare)(ElemType,ElemType))
{   // 初始条件：线性表L已存在
    // 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，
    //           返回OK；否则操作失败，pre_e无定义，返回INFEASIBLE
    LinkList q, p = L; // p指向第一个结点
    while (p->next) { // p所指结点有后继
        q = p->next; // q为p的后继
        if (compare(q->data, cur_e) == 0) { // 如果相等
            pre_e = p->data;
            return OK;
        }
        p = q; // p向后移
    }
    return INFEASIBLE;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e, int(*compare)(ElemType,ElemType))
{   // 初始条件：线性表L已存在
    // 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，
    //           返回OK；否则操作失败，next_e无定义，返回INFEASIBLE
    LinkList p = L; // p指向第一个结点
    while (p->next) { // p所指结点有后继
        if (compare(p->data, cur_e) == 0) { // 如果相等
            next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return INFEASIBLE;
}

// 不带头结点的单链表的扩展操作(3个)

void InsertAscend(LinkList &L, ElemType e, int(*compare)(ElemType,ElemType))
{   // 按关键字非降序将e插入表L。函数compare()返回值为：形参1的关键字-形参2的关键字
    LinkList q = L;
    if (!L || compare(e, L->data) <= 0) { // 链表空或e的关键字小于等于首结点的关键字
        ListInsert(L, 1, e); // 将e插在表头
    } else {
        while (q->next && compare(q->next->data, e) < 0) { // q不是尾结点且q的下一结点关键字<e的关键字
            q = q->next;
        }
        ListInsert(q, 2, e); // 插在q所指结点后(将q作为头指针)
    }
}

LinkList Point(LinkList L, ElemType e, Status(*equal)(ElemType, ElemType), LinkList &p)
{   // 查找表L中满足条件的结点。如找到，返回指向该结点的指针，p指向该结点的前驱(若该结点是
    // 首元结点，则p=NULL)。如表L中无满足条件的结点，则返回NULL，p无定义。
    // 函数equal()的两形参的关键字相等，返回OK；否则返回ERROR
    int i, j;
    i = LocateElem(L, e, equal);
    if (i) { // 找到
        if (i == 1) { // 是首元结点
            p = NULL;
            return L;
        }
        p = L;
        for (j = 2; j < i; j++) {
            p = p->next;
        }
        return p->next;
    }
    return NULL; // 没找到
}

Status DeleteElem(LinkList &L, ElemType &e, Status(*equal)(ElemType, ElemType))
{   // 删除表L中满足条件的结点，并返回TRUE；如无此结点，则返回FALSE。
    // 函数equal()的两形参的关键字相等，返回OK；否则返回ERROR
    LinkList p, q;
    q = Point(L, e, equal, p);
    if (q) { // 找到此结点，且q指向该结点
        if (p) { // 该结点不是首元结点，p指向其前驱
            ListDelete(p, 2, e); // 将p作为头指针,删除第2个结点
        } else { // 该结点是首元结点
            ListDelete(L,1,e);
        }
        return TRUE;
    }
    return FALSE;
}
