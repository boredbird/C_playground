// C3-2.h �������У������е���ʽ�洢�ṹ

#ifndef C3_2_H
#define C3_2_H

#include "C1.h"

typedef int QElemType;  // �û�ָ���Ķ���Ԫ������

typedef struct QNode
{
    QElemType data;
    QNode     *next;
} *QueuePtr;

struct LinkQueue
{
    QueuePtr front; // ��ͷָ��
    QueuePtr rear;  // ��βָ��
};


// �����еĻ�������(9��)

void InitQueue(LinkQueue &Q);
// ����һ���ն���Q

void DestroyQueue(LinkQueue &Q);
// ���ٶ���Q(���ۿշ����)

void ClearQueue(LinkQueue &Q);
// ��Q��Ϊ�ն���

Status QueueEmpty(LinkQueue Q);
// ��QΪ�ն��У��򷵻�TRUE�����򷵻�FALSE

int QueueLength(LinkQueue Q);
// ����еĳ���

Status GetHead(LinkQueue Q, QElemType &e);
// �����в��գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR

void EnQueue(LinkQueue &Q, QElemType e);
// ����Ԫ��eΪQ���µĶ�βԪ��

Status DeQueue(LinkQueue &Q, QElemType &e);
// �����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR

void QueueTraverse(LinkQueue Q, void(*vi)(QElemType));
// �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���vi()

#endif