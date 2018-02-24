// Main8-2.cpp 检验C8-2.cpp的主程序

#include "C1.h"
#include "C8-2.h"

extern Space r;  // r为生成空间的首地址，定义于C8-2.cpp
Space v[N] = { NULL };  // v数组为占用块的首地址

bool LoopCommand(FreeList &a)
{
    char command = '0';
    int m, i;
    printf("\n");
    printf("1-输出存储状态   2-分配空间   3-回收空间   0-退出\n");
    printf("\n请输入你要执行的操作代号：");
    fflush(stdin);
    command = getchar();
    fflush(stdin);
    switch (command) {
        case '1':
            printf("\n存储状态：\n");
            Print(a);
            PrintUser(v);
            break;
        case '2':
            printf("请输入要申请的空间单元数：");
            scanf("%d", &m);
            printf("请输入申请空间的占用块数组编号：");
            scanf("%d", &i);
            v[i] = AllocBuddy(a, m);
            break;
        case '3':
            printf("请输入要删除的占用块数组编号：");
            scanf("%d", &i);
            Reclaim(a, v[i]);
            v[i] = NULL;
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
    int i; 
    FreeList a; 
    printf("%u条空间链，总空间大小为%u\n", M, int(pow(2, M))); 
    for (i = 0; i <= M; i++) // 初始化a
    {
        a[i].nodesize = int(pow(2, i)); 
        a[i].first = NULL; 
    }
    r = a[M].first = new WORD_b[a[M].nodesize];  // 在最大链表中生成一个结点
    r->llink = r->rlink = r;  // 初始化该结点
    r->tag = 0; 
    r->kval = M; 
    printf("初始化完毕\n\n"); 

    while (LoopCommand(a));

    delete r;

}
