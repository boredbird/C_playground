// C3-2.cpp ������(�洢�ṹ��C3-2.h����)�Ļ�������(9��)

#include "C3-2.h"

void InitQueue(LinkQueue &Q)
{ 
    // �������������һ���ն���Q
    if (!(Q.front = Q.rear = (QueuePtr) malloc(sizeof(QNode)))) {
        exit(OVERFLOW);
    }
    Q.front->next = NULL;
}

void DestroyQueue(LinkQueue &Q)
{ 
    // ������������ٶ���Q(���ۿշ����)
    while (Q.front) {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
}

void ClearQueue(LinkQueue &Q)
{ 
    // �����������Q��Ϊ�ն���
    QueuePtr p, q;
    Q.rear = Q.front;
    p = Q.front->next;
    Q.front->next = NULL;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
}

Status QueueEmpty(LinkQueue Q)
{ 
    // �����������QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE
    if (Q.front->next == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int QueueLength(LinkQueue Q)
{ 
    // �������������еĳ���
    int i = 0;
    QueuePtr p;
    p = Q.front;
    while (Q.rear != p) {
        i++;
        p = p->next;
    }
    return i;
}

Status GetHead(LinkQueue Q, QElemType &e)
{ 
    // ��������������в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
    QueuePtr p;
    if (Q.front == Q.rear) {
        return ERROR;
    }
    p = Q.front->next;
    e = p->data;
    return OK;
}

void EnQueue(LinkQueue &Q, QElemType e)
{ 
    // �������������Ԫ��eΪQ���µĶ�βԪ��
    QueuePtr p;
    if (!(p = (QueuePtr) malloc(sizeof(QNode)))) { // �洢����ʧ��
        exit(OVERFLOW);
    }
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

Status DeQueue(LinkQueue &Q, QElemType &e)
{ 
    // ��������������в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
    QueuePtr p;
    if (Q.front == Q.rear) {
        return ERROR;
    }
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) {
        Q.rear = Q.front;
    }
    free(p);
    return OK;
}

void QueueTraverse(LinkQueue Q, void(*vi)(QElemType))
{ 
    // ����������Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi()
    QueuePtr p;
    p = Q.front->next;
    while (p) {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}