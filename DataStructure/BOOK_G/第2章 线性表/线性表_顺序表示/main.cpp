// main2-1.cpp ����bo2-1.cpp��������
#include "C1.h"
#include "C2-1.h"

Status equal(ElemType c1, ElemType c2)
{   // �ж��Ƿ���ȵĺ���
    if (c1 == c2) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void print(ElemType &c)
{   // ��ӡ���͵ĺ���
    printf("%d ", c);
}

bool LoopCommand(SqList &sqList)
{
    char     command = 0;  // �������
    int      pos     = 1;  // λ�ñ���
    ElemType e       = 0;  // Ԫ�ر���
    ElemType ef      = 0;  // ��ѯԪ�ر���
    printf("\n");
    printf("1-��ʾ����Ϣ    2-����Ԫ��  3-ɾ��Ԫ��  4-��ձ�  5-��ѯԪ��ֵ\n");
    printf("6-��ѯԪ��λ��  7-�о�ǰ��  8-�оٺ��  0-�˳�\n");
    printf("\n��������Ҫִ�еĲ������ţ�");
    fflush(stdin);
    command = getchar();
    fflush(stdin);
    switch (command) {
        case '1':
            printf("\n��������%d, Ԫ�ظ�����%d\n", sqList.listsize, ListLength(sqList));
            printf("��Ԫ������Ϊ��");
            ListTraverse(sqList, print); //��������ӡ
            break;
        case '2':
            printf("\n������Ҫ�����Ԫ�أ�");
            scanf("%d", &e);
            printf("������Ҫ�����λ�ã�");
            scanf("%d", &pos);
            if (ListInsert(sqList, pos, e) != OK) {
                printf("����λ�ô���������1-%d֮�����\n", ListLength(sqList) + 1);
            }
            break;
        case '3':
            if (ListEmpty(sqList)) {
                printf("\n�ձ���Ԫ�ؿ�ɾ����\n");
                break;
            }
            printf("\n������Ҫɾ����Ԫ��λ�ã�");
            scanf("%d", &pos);
            if (ListDelete(sqList, pos, e) != OK) {
                printf("ɾ��λ�ô���������1-%d֮�����\n", ListLength(sqList));
            } else {
                printf("Ԫ��%d�ѱ�ɾ����\n", e);
            }
            break;
        case '4':
            ClearList(sqList);
            printf("\n������գ�\n");
            break;
        case '5':
            if (ListEmpty(sqList)) {
                printf("\n�ձ���Ԫ�ؿɲ�ѯ��\n");
                break;
            }
            printf("\n�������ѯԪ�ص�λ�ã�");
            scanf("%d", &pos);
            if (GetElem(sqList, pos, e) != OK) {
                printf("Ԫ��λ�ô���������1-%d֮�����\n", ListLength(sqList));
            } else {
                printf("���е�%dԪ����%d\n", pos, e);
            }
            break;
        case '6':
            printf("\n�������ѯԪ�ص�ֵ��");
            scanf("%d", &e);
            pos = LocateElem(sqList, e, equal);
            if (pos == 0) {
                printf("δ�ҵ�����������Ԫ�أ�\n");
            } else {
                printf("Ԫ��%d�Ǳ��е�%d��Ԫ��\n", e, pos);
            }
            break;
        case '7':
            printf("\n������ο�Ԫ�ص�ֵ��");
            scanf("%d", &e);
            if (PriorElem(sqList, e, ef) != OK) {
                printf("δ�ҵ�����������ǰ��Ԫ�أ�\n");
            } else {
                printf("Ԫ��%d��ǰ��Ԫ����%d\n", e, ef);
            }
            break;
        case '8':
            printf("\n������ο�Ԫ�ص�ֵ��");
            scanf("%d", &e);
            if (NextElem(sqList, e, ef) != OK) {
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
    SqList sqList;
    InitList(sqList);
    printf("���Ա��ѳ�ʼ��\n");

    while (LoopCommand(sqList));

    DestroyList(sqList);
}
