// Main7-3.cpp ����C7-3.cpp��������
#include "C1.h"
#include "C7-3.h"

void print(char *c)
{
    printf("%s  ", c);
}

bool LoopCommand(OLGraph &g)
{
    char command = '0';
    int  m;
    VertexType v, w;
    printf("\n");
    printf("1-���ͼ  2-���Ҷ���  3-���붥��  4-ɾ������  5-�޸Ķ���\n");
    printf("6-���ӻ�  7-ɾ����    8-DFS����   9-BFS����   0-�˳�\n");
    printf("\n��������Ҫִ�еĲ������ţ�");
    fflush(stdin);
    command = getchar();
    fflush(stdin);
    switch (command) {
        case '1':
            printf("\nͼ���ڽӾ���\n");
            Display(g);
            break;
        case '2':
            printf("������Ҫ��ѯ�Ķ���ֵ��");
            scanf("%s", v);
            m = LocateVex(g, v);
            if (m < 0) {
                printf("δ��ѯ������%s\n", v);
            } else {
                printf("����%s��ͼ�е�λ��Ϊ%d\n", v, m);
            }
            break;
        case '3':
            printf("������Ҫ����Ķ���ֵ��");
            scanf("%s", v);
            InsertVex(g, v);
            break;
        case '4':
            printf("������Ҫɾ���Ķ���ֵ��");
            scanf("%s", v);
            DeleteVex(g, v);
            break;
        case '5':
            printf("������Ҫ�޸ĵĶ���ֵ����ֵ(�Կո���Ϊ���)��");
            scanf("%s%s", v, w);
            PutVex(g, v, w);
            break;
        case '6':
            printf("�����뻡β�ͻ�ͷ����ֵ(�Կո���Ϊ���)��");
            scanf("%s%s", v, w);
            InsertArc(g, v, w);
            break;
        case '7':
            printf("�������ɾ�����Ļ�β�ͻ�ͷ(�Կո���Ϊ���)��");
            scanf("%s%s", v, w);
            DeleteArc(g, v, w);
            break;
        case '8':
            printf("������ȱ�����\n");
            DFSTraverse(g, print);
            putchar('\n');
            break;
        case '9':
            printf("������ȱ�����\n");
            BFSTraverse(g, print);
            putchar('\n');
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
    OLGraph g;
    printf("��˳��ѡ������ͼ,������,����ͼ,������\n");
    CreateGraph(g);
    while (LoopCommand(g));
    DestroyGraph(g);
}
