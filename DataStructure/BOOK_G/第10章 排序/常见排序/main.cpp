// 0ain10-1.cpp 检验C10-1.cpp的主程序
#include "C1.h"
#include "C10-1.h"

bool LoopCommand(SqList &sqList)
{
    char command = 0;  // 命令变量
    int dlta[3] = {5, 3, 1};
    printf("\n");
    printf("a-冒泡排序    b-直接插入排序  c-折半插入排序  d-二路插入排序\n");
    printf("e-希尔排序    f-简单选择排序  g-树形选择排序  h-快速排序\n");
    printf("i-堆排序      j-归并排序      k-生成乱序表    l-打印线性表       0-退出\n");
    printf("\n请输入你要执行的操作代号：");
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
            printf("当前线性表为：");
            Print(sqList); // 打印
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
    CreateList(sqList);
    printf("线性表已初始化\n");

    while (LoopCommand(sqList));
}
