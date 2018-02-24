// main7-1.cpp ����C7-1.cpp��������
#include "C1.h"
#include "C7-1.h"

void print(char *c)
{
    printf("%s  ", c);
}

bool LoopCommand(MGraph &g)
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
    MGraph g;
    //printf("��˳��ѡ������ͼ,������,����ͼ,������\n");
    CreateGraph(g);
    while (LoopCommand(g));
    DestroyGraph(g);
}


/*
void main()
{
    int i,j,k,n;
    MGraph g;
    VertexType v1,v2;
    printf("��˳��ѡ������ͼ,������,����ͼ,������\n");
    for(i=0;i<4;i++) // ��֤4�����
    {
        CreateGraph(g); // ����ͼg
        Display(g); // ���ͼg
        printf("�����¶��㣬�����붥���ֵ: ");
        scanf("%s",v1);
        InsertVex(g,v1);
        printf("�������¶����йصĻ���ߣ������뻡�����: ");
        scanf("%d",&n);
        for(k=0;k<n;k++)
        {
            printf("��������һ�����ֵ: ");
            scanf("%s",v2);
            if(g.kind<=1) // ����
            {
                printf("��������ͼ��������������һ����ķ���(0:��ͷ 1:��β): ");
                scanf("%d",&j);
                if(j) // v2�ǻ�β
                    InsertArc(g,v2,v1);
                else // v2�ǻ�ͷ
                    InsertArc(g,v1,v2);
            }
            else // ����
                InsertArc(g,v1,v2);
        }
        Display(g); // ���ͼg
        printf("ɾ�����㼰��صĻ���ߣ������붥���ֵ: ");
        scanf("%s",v1);
        DeleteVex(g,v1);
        Display(g); // ���ͼg
    }
    DestroyGraph(g); // ����ͼg
}
*/