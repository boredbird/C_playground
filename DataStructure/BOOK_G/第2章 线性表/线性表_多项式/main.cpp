// main2-7.cpp ����C2-7.cpp��������

#include "C1.h"
#include "C2-8.h"


bool LoopCommand(Polynomial &p)
{
    char command = '0';
    int  m;
    Polynomial q;
    printf("\n");
    printf("1-��ʾ����ʽ   2-����ʽ���   3-����ʽ���\n");
    printf("4-����ʽ���   5-����ʽȡ��   0-�˳�\n");
    printf("\n��������Ҫִ�еĲ������ţ�");
    fflush(stdin);
    command = getchar();
    fflush(stdin);
    switch (command) {
        case '1':
            printf("\n����ʽ��\n");
            PrintPolyn(p);
            break;
        case '2':
            printf("������Ҫ��ӵ�һԪ����ʽ�ķ�����ĸ�����");
            scanf("%d", &m);
            CreatPolyn(q, m);
            AddPolyn(p, q);
            printf("2��һԪ����ʽ��ӵĽ����\n");
            PrintPolyn(p);
            break;
        case '3':
            printf("������Ҫ�����һԪ����ʽ�ķ�����ĸ�����");
            scanf("%d", &m);
            CreatPolyn(q, m);
            SubtractPolyn(p, q);
            printf("2��һԪ����ʽ����Ľ����\n");
            PrintPolyn(p);
            break;
        case '4':
            printf("������Ҫ��˵�һԪ����ʽ�ķ�����ĸ�����");
            scanf("%d", &m);
            CreatPolyn(q, m);
            MultiplyPolyn(p, q);
            printf("2��һԪ����ʽ��˵Ľ����\n");
            PrintPolyn(p);
            break;
        case '5':
            Opposite(p);
            printf("����ʽȡ���Ľ����\n");
            PrintPolyn(p);
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
    int m;
    // ��ʼ������ʽ
    Polynomial p;
    printf("������һԪ����ʽ�ķ�����ĸ�����");
    scanf("%d", &m);
    CreatPolyn(p, m);

    while (LoopCommand(p));

    DestroyPolyn(p);

}
