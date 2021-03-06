// main2-1.cpp 检验bo2-1.cpp的主程序
#include "C1.h"
#include "C2-1.h"

Status equal(ElemType c1, ElemType c2)
{   // 判断是否相等的函数
    if (c1 == c2) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void print(ElemType &c)
{   // 打印整型的函数
    printf("%d ", c);
}

bool LoopCommand(SqList &sqList)
{
    char     command = 0;  // 命令变量
    int      pos     = 1;  // 位置变量
    ElemType e       = 0;  // 元素变量
    ElemType ef      = 0;  // 查询元素变量
    printf("\n");
    printf("1-显示表信息    2-插入元素  3-删除元素  4-清空表  5-查询元素值\n");
    printf("6-查询元素位置  7-列举前驱  8-列举后继  0-退出\n");
    printf("\n请输入你要执行的操作代号：");
    fflush(stdin);
    command = getchar();
    fflush(stdin);
    switch (command) {
        case '1':
            printf("\n表容量：%d, 元素个数：%d\n", sqList.listsize, ListLength(sqList));
            printf("表元素依次为：");
            ListTraverse(sqList, print); //遍历表并打印
            break;
        case '2':
            printf("\n请输入要插入的元素：");
            scanf("%d", &e);
            printf("请输入要插入的位置：");
            scanf("%d", &pos);
            if (ListInsert(sqList, pos, e) != OK) {
                printf("插入位置错误，请输入1-%d之间的数\n", ListLength(sqList) + 1);
            }
            break;
        case '3':
            if (ListEmpty(sqList)) {
                printf("\n空表，无元素可删除！\n");
                break;
            }
            printf("\n请输入要删除的元素位置：");
            scanf("%d", &pos);
            if (ListDelete(sqList, pos, e) != OK) {
                printf("删除位置错误，请输入1-%d之间的数\n", ListLength(sqList));
            } else {
                printf("元素%d已被删除！\n", e);
            }
            break;
        case '4':
            ClearList(sqList);
            printf("\n表已清空！\n");
            break;
        case '5':
            if (ListEmpty(sqList)) {
                printf("\n空表，无元素可查询！\n");
                break;
            }
            printf("\n请输入查询元素的位置：");
            scanf("%d", &pos);
            if (GetElem(sqList, pos, e) != OK) {
                printf("元素位置错误，请输入1-%d之间的数\n", ListLength(sqList));
            } else {
                printf("表中第%d元素是%d\n", pos, e);
            }
            break;
        case '6':
            printf("\n请输入查询元素的值：");
            scanf("%d", &e);
            pos = LocateElem(sqList, e, equal);
            if (pos == 0) {
                printf("未找到符合条件的元素！\n");
            } else {
                printf("元素%d是表中第%d个元素\n", e, pos);
            }
            break;
        case '7':
            printf("\n请输入参考元素的值：");
            scanf("%d", &e);
            if (PriorElem(sqList, e, ef) != OK) {
                printf("未找到符合条件的前驱元素！\n");
            } else {
                printf("元素%d的前驱元素是%d\n", e, ef);
            }
            break;
        case '8':
            printf("\n请输入参考元素的值：");
            scanf("%d", &e);
            if (NextElem(sqList, e, ef) != OK) {
                printf("未找到符合条件的后继元素！\n");
            } else {
                printf("元素%d的后继元素是%d\n", e, ef);
            }
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
    // 初始化线性表
    SqList sqList;
    InitList(sqList);
    printf("线性表已初始化\n");

    while (LoopCommand(sqList));

    DestroyList(sqList);
}
