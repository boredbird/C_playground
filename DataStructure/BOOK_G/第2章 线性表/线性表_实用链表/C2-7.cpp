// C2-7.cpp 多项式的基本操作及算法2.22、2.23等(8个)
#include"c2-6.h"
#include"c2-7.h"

void OrderInsertMerge(LinkList &l, ElemType e, int(* compare)(Term, Term))
{   // 按有序判定函数compare()的约定，将值为e的结点插入或合并到升序链表L的适当位置
    Position q, s;
    if (LocateElem(l, e, q, compare)) { // L中存在该指数项
        q->data.coef += e.coef; // 改变当前结点系数的值
        if (!q->data.coef) { // 系数为0
            // 删除多项式L中当前结点
            s = PriorPos(l, q); // s为当前结点的前驱
            if (!s) { // q无前驱
                s=l.head;
            }
            DelFirst(l, s, q);
            FreeNode(q);
        }
    } else { // 生成该指数项并插入链表
        MakeNode(s, e); // 生成结点
        InsFirst(l, q, s);
    }
}

int cmp(Term a, Term b) // CreatPolyn()的实参
{   // 依a的指数值<、=或>b的指数值，分别返回-1、0或+1
    if (a.expn == b.expn) {
        return 0;
    } else {
        return (a.expn - b.expn) / abs(a.expn - b.expn);
    }
}

void CreatPolyn(Polynomial &p, int m) // 算法2.22
{   // 输入m项的系数和指数，建立表示一元多项式的有序链表P
    Position q, s;
    Term e;
    int i;
    InitList(p);
    printf("请依次输入%d个系数和指数用空格符间隔：\n", m);
    for (i = 1; i <= m; ++i) {
        // 依次输入m个非零项(可按任意顺序)
        scanf("%f%d", &e.coef, &e.expn);
        fflush(stdin);
        if (!LocateElem(p, e, q, cmp)) { // 当前链表中不存在该指数项，cmp是实参
            MakeNode(s, e); // 生成结点并插入链表
            InsFirst(p, q, s);
        }
    }
}

void PrintPolyn(Polynomial p)
{   // 打印输出一元多项式P
    Link q;
    q = p.head->next; // q指向第1个结点
    printf("   系数   指数\n");
    while (q) {
        printf("%8.2f   %-d\n", q->data.coef, q->data.expn);
        q = q->next;
    }
}

void AddPolyn(Polynomial &pa, Polynomial &pb) // 算法2.23
{   // 多项式加法：pa=pa+pb，并销毁一元多项式pb
    Position ha, hb, qa, qb;
    Term a, b;
    ha = GetHead(pa);
    hb = GetHead(pb); // ha和hb分别指向pa和pb的头结点
    qa = NextPos(ha);
    qb = NextPos(hb); // qa和qb分别指向pa和pb中当前结点(现为第1个结点)
    while (!ListEmpty(pa) && !ListEmpty(pb) && qa) {
        // pa和pb均非空且ha没指向尾结点(qa!=0)
        a = GetCurElem(qa);
        b = GetCurElem(qb); // a和b为两表中当前比较元素
        switch (cmp(a, b)) {
            case -1:
                ha = qa; // 多项式pa中当前结点的指数值小
                qa = NextPos(ha); // ha和qa均向后移1个结点
                break;
            case 0: 
                qa->data.coef += qb->data.coef; // 两者的指数值相等，修改pa当前结点的系数值
                if (qa->data.coef == 0) { // 删除多项式pa中当前结点
                    DelFirst(pa, ha, qa);
                    FreeNode(qa);
                } else {
                    ha = qa;
                }
                DelFirst(pb, hb, qb);
                FreeNode(qb);
                qb = NextPos(hb);
                qa = NextPos(ha);
                break;
            case 1: 
                DelFirst(pb, hb, qb); // 多项式pb中当前结点的指数值小
                InsFirst(pa, ha, qb);
                ha = ha->next;
                qb = NextPos(hb);
        }
    }
    if (!ListEmpty(pb)) {
        pb.tail = hb;
        Append(pa, qb); // 链接pb中剩余结点
    }
    DestroyPolyn(pb); // 销毁pb
}

void AddPolyn1(Polynomial &pa,Polynomial &pb)
{   // 另一种多项式加法的算法：pa=pa+pb，并销毁一元多项式pb
    Position qb;
    Term b;
    qb = GetHead(pb); // qb指向pb的头结点
    qb = qb->next; // qb指向pb的第1个结点
    while (qb) {
        b = GetCurElem(qb);
        OrderInsertMerge(pa, b, cmp);
        qb = qb->next;
    }
    DestroyPolyn(pb); // 销毁pb
}

void Opposite(Polynomial p)
{   // 一元多项式p系数取反
    Position q;
    q = p.head;
    while (q->next) {
        q = q->next;
        q->data.coef *= -1;
    }
}

void SubtractPolyn(Polynomial &pa, Polynomial &pb)
{   // 多项式减法：pa=pa-pb，并销毁一元多项式pb
    Opposite(pb);
    AddPolyn(pa, pb);
}

void MultiplyPolyn(Polynomial &pa, Polynomial &pb)
{   // 多项式乘法：pa=pa×pb，并销毁一元多项式pb
    Polynomial pc;
    Position qa, qb;
    Term a, b, c;
    InitList(pc);
    qa = GetHead(pa);
    qa = qa->next;
    while (qa) {
        a  = GetCurElem(qa);
        qb = GetHead(pb);
        qb = qb->next;
        while (qb) {
            b = GetCurElem(qb);
            c.coef = a.coef * b.coef;
            c.expn = a.expn + b.expn;
            OrderInsertMerge(pc, c, cmp);
            qb = qb->next;
        }
        qa = qa->next;
    }
    DestroyPolyn(pb); // 销毁pb
    ClearList(pa); // 将pa重置为空表
    pa.head = pc.head;
    pa.tail = pc.tail;
    pa.len  = pc.len;
}
