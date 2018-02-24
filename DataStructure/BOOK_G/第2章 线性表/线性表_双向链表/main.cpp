// main2-6.cpp ����C2-6.cpp��������

#include "C2-6.h"


Status equal(ElemType c1, ElemType c2)
{   // �ж��Ƿ���ȵĺ���
    if (c1 == c2) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void print(ElemType c)
{   // ��ӡ���͵ĺ���
    printf("%d ", c);
}

bool LoopCommand(DuLinkList &duLinkList)
{
    char      command = 0;  // �������
    int       pos     = 1;  // λ�ñ���
    ElemType  e       = 0;  // Ԫ�ر���
    ElemType  ef      = 0;  // ��ѯԪ��ָ��
    printf("\n");
    printf("1-��ʾ����Ϣ    2-����Ԫ��  3-��λ��ɾ��Ԫ��  4-��ձ�    5-��ѯԪ��ֵ\n");
    printf("6-��ѯԪ��λ��  7-�о�ǰ��  8-�оٺ��        0-�˳�\n");
    printf("\n��������Ҫִ�еĲ������ţ�");
    fflush(stdin);
    command = getchar();
    fflush(stdin);
    switch (command) {
        case '1':
            printf("\nԪ�ظ�����%d\n", ListLength(duLinkList));
            printf("��Ԫ������Ϊ��");
            ListTraverse(duLinkList, print); //��������ӡ
            break;
        case '2':
            printf("\n������Ҫ�����Ԫ�أ�");
            scanf("%d", &e);
            printf("������Ҫ�����λ�ã�");
            scanf("%d", &pos);
            if (ListInsert(duLinkList, pos, e) != OK) {
                printf("����λ�ô���������1-%d֮�����\n", ListLength(duLinkList) + 1);
            }
            break;
        case '3':
            if (ListEmpty(duLinkList)) {
                printf("\n�ձ���Ԫ�ؿ�ɾ����\n");
                break;
            }
            printf("\n������Ҫɾ����Ԫ��λ�ã�");
            scanf("%d", &pos);
            if (ListDelete(duLinkList, pos, e) != OK) {
                printf("ɾ��λ�ô���������1-%d֮�����\n", ListLength(duLinkList));
            } else {
                printf("Ԫ��%d�ѱ�ɾ����\n", e);
            }
            break;
        case '4':
            ClearList(duLinkList);
            printf("\n������գ�\n");
            break;
        case '5':
            if (ListEmpty(duLinkList)) {
                printf("\n�ձ���Ԫ�ؿɲ�ѯ��\n");
                break;
            }
            printf("\n�������ѯԪ�ص�λ�ã�");
            scanf("%d", &pos);
            if (GetElem(duLinkList, pos, e) != OK) {
                printf("Ԫ��λ�ô���������1-%d֮�����\n", ListLength(duLinkList));
            } else {
                printf("���е�%dԪ����%d\n", pos, e);
            }
            break;
        case '6':
            printf("\n�������ѯԪ�ص�ֵ��");
            scanf("%d", &e);
            pos = LocateElem(duLinkList, e, equal);
            if (pos == 0) {
                printf("δ�ҵ�����������Ԫ�أ�\n");
            } else {
                printf("Ԫ��%d�Ǳ��е�%d��Ԫ��\n", e, pos);
            }
            break;
        case '7':
            printf("\n������ο�Ԫ�ص�ֵ��");
            scanf("%d", &e);
            if (PriorElem(duLinkList, e, ef) != TRUE) {
                printf("δ�ҵ�����������ǰ��Ԫ�أ�\n");
            } else {
                printf("Ԫ��%d��ǰ��Ԫ����%d\n", e, ef);
            }
            break;
        case '8':
            printf("\n������ο�Ԫ�ص�ֵ��");
            scanf("%d", &e);
            if (NextElem(duLinkList, e, ef) != TRUE) {
                printf("δ�ҵ����������ĺ��Ԫ�أ�\n");
            } else {
                printf("Ԫ��%d�ĺ��Ԫ����%d\n", e, ef);
            }
            break;
        case '0':
            return false;
        default:
            printf("�������Ų����ڣ�\n");
            break;
    }

    return true;
}

void main()
{
    // ��ʼ�����Ա�
    DuLinkList duLinkList;
    InitList(duLinkList);
    printf("�����ѳ�ʼ��\n");

    while (LoopCommand(duLinkList));

    DestroyList(duLinkList);
}