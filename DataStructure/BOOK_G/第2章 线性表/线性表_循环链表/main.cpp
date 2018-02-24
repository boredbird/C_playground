// Main2-5.cpp ��ѭ������,����C2-5.cpp��������
#include"c2-5.h"

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

bool LoopCommand(LinkList &linkList)
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
            printf("\nԪ�ظ�����%d\n", ListLength(linkList));
            printf("��Ԫ������Ϊ��");
            ListTraverse(linkList, print); //��������ӡ
            break;
        case '2':
            printf("\n������Ҫ�����Ԫ�أ�");
            scanf("%d", &e);
            printf("������Ҫ�����λ�ã�");
            scanf("%d", &pos);
            if (ListInsert(linkList, pos, e) != OK) {
                printf("����λ�ô���������1-%d֮�����\n", ListLength(linkList) + 1);
            }
            break;
        case '3':
            if (ListEmpty(linkList)) {
                printf("\n�ձ���Ԫ�ؿ�ɾ����\n");
                break;
            }
            printf("\n������Ҫɾ����Ԫ��λ�ã�");
            scanf("%d", &pos);
            if (ListDelete(linkList, pos, e) != OK) {
                printf("ɾ��λ�ô���������1-%d֮�����\n", ListLength(linkList));
            } else {
                printf("Ԫ��%d�ѱ�ɾ����\n", e);
            }
            break;
        case '4':
            ClearList(linkList);
            printf("\n������գ�\n");
            break;
        case '5':
            if (ListEmpty(linkList)) {
                printf("\n�ձ���Ԫ�ؿɲ�ѯ��\n");
                break;
            }
            printf("\n�������ѯԪ�ص�λ�ã�");
            scanf("%d", &pos);
            if (GetElem(linkList, pos, e) != OK) {
                printf("Ԫ��λ�ô���������1-%d֮�����\n", ListLength(linkList));
            } else {
                printf("���е�%dԪ����%d\n", pos, e);
            }
            break;
        case '6':
            printf("\n�������ѯԪ�ص�ֵ��");
            scanf("%d", &e);
            pos = LocateElem(linkList, e, equal);
            if (pos == 0) {
                printf("δ�ҵ�����������Ԫ�أ�\n");
            } else {
                printf("Ԫ��%d�Ǳ��е�%d��Ԫ��\n", e, pos);
            }
            break;
        case '7':
            printf("\n������ο�Ԫ�ص�ֵ��");
            scanf("%d", &e);
            if (PriorElem(linkList, e, ef) != TRUE) {
                printf("δ�ҵ�����������ǰ��Ԫ�أ�\n");
            } else {
                printf("Ԫ��%d��ǰ��Ԫ����%d\n", e, ef);
            }
            break;
        case '8':
            printf("\n������ο�Ԫ�ص�ֵ��");
            scanf("%d", &e);
            if (NextElem(linkList, e, ef) != TRUE) {
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
    LinkList linkList;
    InitList(linkList);
    printf("�����ѳ�ʼ��\n");

    while (LoopCommand(linkList));

    DestroyList(linkList);
}