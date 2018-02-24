
// algo8 - 2.cpp ���ϵͳ��ʵ���㷨8.2�ĳ���
#include"c1.h"
#include"C8-2.h"

Space r;  // rΪ���ɿռ���׵�ַ��ȫ����

Space AllocBuddy(FreeList avail, int n)
{ 
    // avail[0..m]Ϊ�����ÿռ��nΪ��������������в�С��n�Ŀ��п飬
    // �������Ӧ�Ĵ洢�飬���������׵�ַ�����򷵻�NULL���㷨8.2
    int i, k; 
    Space pa, pi, pre, suc; 
    for (k = 0; k <= M; ++k) {  // ��С��������������Ҫ����ӱ����k
        if (avail[k].nodesize >= n + 1 && avail[k].first) {
            break;
        }
    }
    if (k > M) { // ����ʧ�ܣ�����NULL
        return NULL; 
    } else { // ���з���
        pa = avail[k].first;  // paָ��ɷ����ӱ�ĵ�һ�����
        pre = pa->llink;  // pre��suc�ֱ�ָ��pa��ָ����ǰ���ͺ��
        suc = pa->rlink; 
        if (pa == suc) { // �ɷ����ӱ�ֻ��1�����
            avail[k].first = NULL;  // �������ӱ��ɿձ�
        } else { // ���ӱ���ɾȥpa��ָ���(����ĵ�1�����)
            pre->rlink = suc; 
            suc->llink = pre; 
            avail[k].first = suc;  // ���ӱ��ͷָ��ָ��pa��ָ���ĺ��
        }
        for (i = 1; avail[k - i].nodesize >= n + 1; ++i) {
            // �Ӵ�С��ʣ��������Ӧ�ӱ�Լ�����͵�ַ(��ǰ��)�Ŀ���Ϊ�����
            pi = pa + int(pow(2, k - i));  // piָ���ٷָ�ĺ���(ʣ���)
            pi->rlink = pi;  // pi�Ǹ�����ĵ�1����㣬������ָ�붼ָ������
            pi->llink = pi; 
            pi->tag = 0;  // ���־Ϊ����
            pi->kval = k - i;  // ���С
            avail[k - i].first = pi;  // ��������
        }
        pa->tag = 1;  // ���ʣ��pa���Ƿ���飬������־Ϊռ��
        pa->kval = k - (--i);  // ���С
    }
    return pa;  // ���ط����ĵ�ַ
}

Space buddy(Space p)
{ 
    // ������ʼ��ַΪp�����СΪpow(2, p->kval)�Ŀ�Ļ���ַ
    if ((p - r) % (int) pow(2, p->kval + 1) == 0) { // pΪǰ��
        return p + (int) pow(2, p->kval);  // ���غ���ַ
    } else { // pΪ���
        return p - int(pow(2, p->kval));  // ����ǰ���ַ
    }
}

void Reclaim(FreeList pav, Space &p)
{ 
    // ���ϵͳ�Ļ����㷨����p��ָ���ͷſ���յ������ÿռ��pav��
    Space s; 
    s = buddy(p);  // �������ʼ��ַ
    while (s >= r && s < r + pav[M].nodesize && s->tag == 0 && s->kval == p->kval) // �鲢����
    { 
        // ������ʼ��ַ����Ч��Χ���һ�����в���p��ȴ󣬴�������ɾ���û�����
        if (s->rlink == s) { // �����Ͻ���һ�����
            pav[s->kval].first = NULL;  // �ô�����Ϊ��
        } else { // �����ϲ�ֹһ�����
            s->llink->rlink = s->rlink;  // ǰ���ĺ��Ϊ�ý��ĺ��
            s->rlink->llink = s->llink;  // ��̵�ǰ��Ϊ�ý���ǰ��
            if (pav[s->kval].first == s) { // s������ĵ�һ�����
                pav[s->kval].first = s->rlink;  // �޸ı�ͷָ����һ�����
            }
        } // �����޸Ľ��ͷ��
        if ((p - r) % (int) pow(2, p->kval + 1) == 0) { // pΪǰ��
            p->kval++;  // ���С�ӱ�
        } else { // pΪ���(sΪǰ��)
            s->kval = p->kval + 1;  // ���С�ӱ�
            p = s;  // pָ���¿��׵�ַ
        }
        s = buddy(p);  // ��һ���������ʼ��ַ
    } // ���½�p�嵽�����ÿռ����
    p->tag = 0;  // ����־Ϊ����
    if (pav[p->kval].first == NULL) { // �������
        pav[p->kval].first = p->llink = p->rlink = p;  // ����ָ�뼰��ͷ��ָ������
    } else { // �������գ����ڱ�ͷ
        p->rlink = pav[p->kval].first; 
        p->llink = p->rlink->llink; 
        p->rlink->llink = p; 
        p->llink->rlink = p; 
        pav[p->kval].first = p; 
    }
    p = NULL; 
}

void Print(FreeList p)
{ 
    // ���p�����п����ÿռ��
    int i; 
    Space h; 
    for (i = 0; i <= M; i++) {
        if (p[i].first) { // ��i�������ÿռ����
            h = p[i].first;  // hָ������ĵ�һ������ͷ����(�׵�ַ)
            do {
                printf("���С = %d �׵�ַ = %u ", (int) pow(2, h->kval), h);  // ��������Ϣ
                printf("���־ = %d(0:���� 1:ռ��)\n", h->tag); 
                h = h->rlink;  // ָ����һ������ͷ����(�׵�ַ)
            } while (h != p[i].first);  // û��ѭ������ı�β
        }
    }
}

void PrintUser(Space p[])
{ // ���p������ָ���ѷ���ռ�
    for (int i = 0; i < N; i++) {
        if (p[i]) { // ָ�벻Ϊ0(ָ��һ��ռ�ÿ�)
            printf("ռ�ÿ�%d���׵�ַ = %u ", i, p[i]);  // ��������Ϣ
            printf("��Ĵ�С = %d", (int) pow(2, p[i]->kval)); 
            printf(" ���־ = %d(0:���� 1:ռ��)\n", p[i]->tag); 
        }
    }
}
