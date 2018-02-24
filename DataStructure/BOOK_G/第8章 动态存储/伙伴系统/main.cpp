// Main8-2.cpp ����C8-2.cpp��������

#include "C1.h"
#include "C8-2.h"

extern Space r;  // rΪ���ɿռ���׵�ַ��������C8-2.cpp
Space v[N] = { NULL };  // v����Ϊռ�ÿ���׵�ַ

bool LoopCommand(FreeList &a)
{
    char command = '0';
    int m, i;
    printf("\n");
    printf("1-����洢״̬   2-����ռ�   3-���տռ�   0-�˳�\n");
    printf("\n��������Ҫִ�еĲ������ţ�");
    fflush(stdin);
    command = getchar();
    fflush(stdin);
    switch (command) {
        case '1':
            printf("\n�洢״̬��\n");
            Print(a);
            PrintUser(v);
            break;
        case '2':
            printf("������Ҫ����Ŀռ䵥Ԫ����");
            scanf("%d", &m);
            printf("����������ռ��ռ�ÿ������ţ�");
            scanf("%d", &i);
            v[i] = AllocBuddy(a, m);
            break;
        case '3':
            printf("������Ҫɾ����ռ�ÿ������ţ�");
            scanf("%d", &i);
            Reclaim(a, v[i]);
            v[i] = NULL;
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
    int i; 
    FreeList a; 
    printf("%u���ռ������ܿռ��СΪ%u\n", M, int(pow(2, M))); 
    for (i = 0; i <= M; i++) // ��ʼ��a
    {
        a[i].nodesize = int(pow(2, i)); 
        a[i].first = NULL; 
    }
    r = a[M].first = new WORD_b[a[M].nodesize];  // ���������������һ�����
    r->llink = r->rlink = r;  // ��ʼ���ý��
    r->tag = 0; 
    r->kval = M; 
    printf("��ʼ�����\n\n"); 

    while (LoopCommand(a));

    delete r;

}
