// main8-1.cpp ����C8-1.cpp��������

#include "C1.h"
#include "C8-1.h"

Space v[MAX / e] = { NULL };  // ռ�ÿ�ָ������(��ʼ��Ϊ��)

bool LoopCommand(Space &pav)
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
            Print(pav);
            PrintUser(v);
            break;
        case '2':
            printf("������Ҫ����Ŀռ䵥Ԫ����");
            scanf("%d", &m);
            printf("����������ռ��ռ�ÿ������ţ�");
            scanf("%d", &i);
            v[i] = AllocBoundTag(pav, m);
            break;
        case '3':
            printf("������Ҫɾ����ռ�ÿ������ţ�");
            scanf("%d", &i);
            Reclaim(pav, v[i]);
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
    Space pav, p;  // ���п�ָ��
    printf("�ṹ��WORDΪ%d���ֽ�\n", sizeof(WORD)); 
    // ��ʼ���ռ�
    p = new WORD[MAX + 2];  // �����СΪMAX*sizeof(WORD)���ֽڵĿռ�
    p->tag = 1;  // ���õ�ַ�߽磬�Է��������ڿ�ʱ����
    pav = p + 1;  // �����ÿռ��ı�ͷ
    pav->rlink = pav->llink = pav;  // ��ʼ�������ÿռ�(һ������)
    pav->tag = 0; 
    pav->size = MAX; 
    p = FootLoc(pav);  // pָ��ײ���
    p->uplink = pav; 
    p->tag = 0; 
    (p + 1)->tag = 1;  // ���ø�ַ�߽磬�Է��������ڿ�ʱ����
    printf("��ʼ�����\n\n"); 

    while (LoopCommand(pav));

    delete p;

}
