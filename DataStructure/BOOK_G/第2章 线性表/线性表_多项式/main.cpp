// main2-7.cpp 检验C2-7.cpp的主程序

#include "C1.h"
#include "C2-8.h"


bool LoopCommand(Polynomial &p)
{
    char command = '0';
    int  m;
    Polynomial q;
    printf("\n");
    printf("1-显示多项式   2-多项式相加   3-多项式相减\n");
    printf("4-多项式相乘   5-多项式取反   0-退出\n");
    printf("\n请输入你要执行的操作代号：");
    fflush(stdin);
    command = getchar();
    fflush(stdin);
    switch (command) {
        case '1':
            printf("\n多项式：\n");
            PrintPolyn(p);
            break;
        case '2':
            printf("请输入要相加的一元多项式的非零项的个数：");
            scanf("%d", &m);
            CreatPolyn(q, m);
            AddPolyn(p, q);
            printf("2个一元多项式相加的结果：\n");
            PrintPolyn(p);
            break;
        case '3':
            printf("请输入要相减的一元多项式的非零项的个数：");
            scanf("%d", &m);
            CreatPolyn(q, m);
            SubtractPolyn(p, q);
            printf("2个一元多项式相减的结果：\n");
            PrintPolyn(p);
            break;
        case '4':
            printf("请输入要相乘的一元多项式的非零项的个数：");
            scanf("%d", &m);
            CreatPolyn(q, m);
            MultiplyPolyn(p, q);
            printf("2个一元多项式相乘的结果：\n");
            PrintPolyn(p);
            break;
        case '5':
            Opposite(p);
            printf("多项式取反的结果：\n");
            PrintPolyn(p);
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
    int m;
    // 初始化多项式
    Polynomial p;
    printf("请输入一元多项式的非零项的个数：");
    scanf("%d", &m);
    CreatPolyn(p, m);

    while (LoopCommand(p));

    DestroyPolyn(p);

}
