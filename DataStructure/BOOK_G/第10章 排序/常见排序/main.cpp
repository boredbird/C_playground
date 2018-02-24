// 0ain10-1.cpp ����C10-1.cpp��������
#include "C1.h"
#include "C10-1.h"

bool LoopCommand(SqList &sqList)
{
    char command = 0;  // �������
    int dlta[3] = {5, 3, 1};
    printf("\n");
    printf("a-ð������    b-ֱ�Ӳ�������  c-�۰��������  d-��·��������\n");
    printf("e-ϣ������    f-��ѡ������  g-����ѡ������  h-��������\n");
    printf("i-������      j-�鲢����      k-���������    l-��ӡ���Ա�       0-�˳�\n");
    printf("\n��������Ҫִ�еĲ������ţ�");
    fflush(stdin);
    command = getchar();
    fflush(stdin);
    switch (command) {
        case 'a':
            BubbleSort(sqList);
            break;
        case 'b':
            InsertSort(sqList);
            break;
        case 'c':
            BInsertSort(sqList);
            break;
        case 'd':
            P2_InsertSort(sqList);
            break;
        case 'e':
            ShellSort(sqList, dlta, 3);
            break;
        case 'f':
            SelectSort(sqList);
            break;
        case 'g':
            TreeSort(sqList);
            break;
        case 'h':
            QuickSort(sqList);
            break;
        case 'i':
            HeapSort(sqList);
            break;
        case 'j':
            MergeSort(sqList);
            break;
        case 'k':
            CreateList(sqList);
            break;
        case 'l':
            printf("��ǰ���Ա�Ϊ��");
            Print(sqList); // ��ӡ
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
    CreateList(sqList);
    printf("���Ա��ѳ�ʼ��\n");

    while (LoopCommand(sqList));
}
