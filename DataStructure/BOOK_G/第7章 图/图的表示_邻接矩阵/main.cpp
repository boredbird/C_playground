// main7-1.cpp 检验C7-1.cpp的主程序
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
    printf("1-输出图  2-查找顶点  3-插入顶点  4-删除顶点  5-修改顶点\n");
    printf("6-增加弧  7-删除弧    8-DFS遍历   9-BFS遍历   0-退出\n");
    printf("\n请输入你要执行的操作代号：");
    fflush(stdin);
    command = getchar();
    fflush(stdin);
    switch (command) {
        case '1':
            printf("\n图的邻接矩阵：\n");
            Display(g);
            break;
        case '2':
            printf("请输入要查询的顶点值：");
            scanf("%s", v);
            m = LocateVex(g, v);
            if (m < 0) {
                printf("未查询到顶点%s\n", v);
            } else {
                printf("顶点%s在图中的位序为%d\n", v, m);
            }
            break;
        case '3':
            printf("请输入要插入的顶点值：");
            scanf("%s", v);
            InsertVex(g, v);
            break;
        case '4':
            printf("请输入要删除的顶点值：");
            scanf("%s", v);
            DeleteVex(g, v);
            break;
        case '5':
            printf("请输入要修改的顶点值和新值(以空格作为间隔)：");
            scanf("%s%s", v, w);
            PutVex(g, v, w);
            break;
        case '6':
            printf("请输入弧尾和弧头顶点值(以空格作为间隔)：");
            scanf("%s%s", v, w);
            InsertArc(g, v, w);
            break;
        case '7':
            printf("请输入待删除弧的弧尾和弧头(以空格作为间隔)：");
            scanf("%s%s", v, w);
            DeleteArc(g, v, w);
            break;
        case '8':
            printf("深度优先遍历：\n");
            DFSTraverse(g, print);
            putchar('\n');
            break;
        case '9':
            printf("广度优先遍历：\n");
            BFSTraverse(g, print);
            putchar('\n');
            break;
        case '0':
            return false;
        default:
            printf("操作代号不存在！\n");
            break;
    }

    return true;
}

void main()
{
    MGraph g;
    //printf("请顺序选择有向图,有向网,无向图,无向网\n");
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
    printf("请顺序选择有向图,有向网,无向图,无向网\n");
    for(i=0;i<4;i++) // 验证4种情况
    {
        CreateGraph(g); // 构造图g
        Display(g); // 输出图g
        printf("插入新顶点，请输入顶点的值: ");
        scanf("%s",v1);
        InsertVex(g,v1);
        printf("插入与新顶点有关的弧或边，请输入弧或边数: ");
        scanf("%d",&n);
        for(k=0;k<n;k++)
        {
            printf("请输入另一顶点的值: ");
            scanf("%s",v2);
            if(g.kind<=1) // 有向
            {
                printf("对于有向图或网，请输入另一顶点的方向(0:弧头 1:弧尾): ");
                scanf("%d",&j);
                if(j) // v2是弧尾
                    InsertArc(g,v2,v1);
                else // v2是弧头
                    InsertArc(g,v1,v2);
            }
            else // 无向
                InsertArc(g,v1,v2);
        }
        Display(g); // 输出图g
        printf("删除顶点及相关的弧或边，请输入顶点的值: ");
        scanf("%s",v1);
        DeleteVex(g,v1);
        Display(g); // 输出图g
    }
    DestroyGraph(g); // 销毁图g
}
*/