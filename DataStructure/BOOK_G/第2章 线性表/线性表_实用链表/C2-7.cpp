// C2-7.cpp ����ʽ�Ļ����������㷨2.22��2.23��(8��)
#include"c2-6.h"
#include"c2-7.h"

void OrderInsertMerge(LinkList &l, ElemType e, int(* compare)(Term, Term))
{   // �������ж�����compare()��Լ������ֵΪe�Ľ������ϲ�����������L���ʵ�λ��
    Position q, s;
    if (LocateElem(l, e, q, compare)) { // L�д��ڸ�ָ����
        q->data.coef += e.coef; // �ı䵱ǰ���ϵ����ֵ
        if (!q->data.coef) { // ϵ��Ϊ0
            // ɾ������ʽL�е�ǰ���
            s = PriorPos(l, q); // sΪ��ǰ����ǰ��
            if (!s) { // q��ǰ��
                s=l.head;
            }
            DelFirst(l, s, q);
            FreeNode(q);
        }
    } else { // ���ɸ�ָ�����������
        MakeNode(s, e); // ���ɽ��
        InsFirst(l, q, s);
    }
}

int cmp(Term a, Term b) // CreatPolyn()��ʵ��
{   // ��a��ָ��ֵ<��=��>b��ָ��ֵ���ֱ𷵻�-1��0��+1
    if (a.expn == b.expn) {
        return 0;
    } else {
        return (a.expn - b.expn) / abs(a.expn - b.expn);
    }
}

void CreatPolyn(Polynomial &p, int m) // �㷨2.22
{   // ����m���ϵ����ָ����������ʾһԪ����ʽ����������P
    Position q, s;
    Term e;
    int i;
    InitList(p);
    printf("����������%d��ϵ����ָ���ÿո�������\n", m);
    for (i = 1; i <= m; ++i) {
        // ��������m��������(�ɰ�����˳��)
        scanf("%f%d", &e.coef, &e.expn);
        fflush(stdin);
        if (!LocateElem(p, e, q, cmp)) { // ��ǰ�����в����ڸ�ָ���cmp��ʵ��
            MakeNode(s, e); // ���ɽ�㲢��������
            InsFirst(p, q, s);
        }
    }
}

void PrintPolyn(Polynomial p)
{   // ��ӡ���һԪ����ʽP
    Link q;
    q = p.head->next; // qָ���1�����
    printf("   ϵ��   ָ��\n");
    while (q) {
        printf("%8.2f   %-d\n", q->data.coef, q->data.expn);
        q = q->next;
    }
}

void AddPolyn(Polynomial &pa, Polynomial &pb) // �㷨2.23
{   // ����ʽ�ӷ���pa=pa+pb��������һԪ����ʽpb
    Position ha, hb, qa, qb;
    Term a, b;
    ha = GetHead(pa);
    hb = GetHead(pb); // ha��hb�ֱ�ָ��pa��pb��ͷ���
    qa = NextPos(ha);
    qb = NextPos(hb); // qa��qb�ֱ�ָ��pa��pb�е�ǰ���(��Ϊ��1�����)
    while (!ListEmpty(pa) && !ListEmpty(pb) && qa) {
        // pa��pb���ǿ���haûָ��β���(qa!=0)
        a = GetCurElem(qa);
        b = GetCurElem(qb); // a��bΪ�����е�ǰ�Ƚ�Ԫ��
        switch (cmp(a, b)) {
            case -1:
                ha = qa; // ����ʽpa�е�ǰ����ָ��ֵС
                qa = NextPos(ha); // ha��qa�������1�����
                break;
            case 0: 
                qa->data.coef += qb->data.coef; // ���ߵ�ָ��ֵ��ȣ��޸�pa��ǰ����ϵ��ֵ
                if (qa->data.coef == 0) { // ɾ������ʽpa�е�ǰ���
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
                DelFirst(pb, hb, qb); // ����ʽpb�е�ǰ����ָ��ֵС
                InsFirst(pa, ha, qb);
                ha = ha->next;
                qb = NextPos(hb);
        }
    }
    if (!ListEmpty(pb)) {
        pb.tail = hb;
        Append(pa, qb); // ����pb��ʣ����
    }
    DestroyPolyn(pb); // ����pb
}

void AddPolyn1(Polynomial &pa,Polynomial &pb)
{   // ��һ�ֶ���ʽ�ӷ����㷨��pa=pa+pb��������һԪ����ʽpb
    Position qb;
    Term b;
    qb = GetHead(pb); // qbָ��pb��ͷ���
    qb = qb->next; // qbָ��pb�ĵ�1�����
    while (qb) {
        b = GetCurElem(qb);
        OrderInsertMerge(pa, b, cmp);
        qb = qb->next;
    }
    DestroyPolyn(pb); // ����pb
}

void Opposite(Polynomial p)
{   // һԪ����ʽpϵ��ȡ��
    Position q;
    q = p.head;
    while (q->next) {
        q = q->next;
        q->data.coef *= -1;
    }
}

void SubtractPolyn(Polynomial &pa, Polynomial &pb)
{   // ����ʽ������pa=pa-pb��������һԪ����ʽpb
    Opposite(pb);
    AddPolyn(pa, pb);
}

void MultiplyPolyn(Polynomial &pa, Polynomial &pb)
{   // ����ʽ�˷���pa=pa��pb��������һԪ����ʽpb
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
    DestroyPolyn(pb); // ����pb
    ClearList(pa); // ��pa����Ϊ�ձ�
    pa.head = pc.head;
    pa.tail = pc.tail;
    pa.len  = pc.len;
}
