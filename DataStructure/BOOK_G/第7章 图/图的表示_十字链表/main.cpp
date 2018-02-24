// Main7-3.cpp 检验C7-3.cpp的主程序
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
    OLGraph g;
    printf("请顺序选择有向图,有向网,无向图,无向网\n");
    CreateGraph(g);
    while (LoopCommand(g));
    DestroyGraph(g);
}
