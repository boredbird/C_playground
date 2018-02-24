// main8-1.cpp 检验C8-1.cpp的主程序

#include "C1.h"
#include "C8-1.h"

Space v[MAX / e] = { NULL };  // 占用块指针数组(初始化为空)

bool LoopCommand(Space &pav)
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
            Print(pav);
            PrintUser(v);
            break;
        case '2':
            printf("请输入要申请的空间单元数：");
            scanf("%d", &m);
            printf("请输入申请空间的占用块数组编号：");
            scanf("%d", &i);
            v[i] = AllocBoundTag(pav, m);
            break;
        case '3':
            printf("请输入要删除的占用块数组编号：");
            scanf("%d", &i);
            Reclaim(pav, v[i]);
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
    Space pav, p;  // 空闲块指针
    printf("结构体WORD为%d个字节\n", sizeof(WORD)); 
    // 初始化空间
    p = new WORD[MAX + 2];  // 申请大小为MAX*sizeof(WORD)个字节的空间
    p->tag = 1;  // 设置低址边界，以防查找左邻块时出错
    pav = p + 1;  // 可利用空间表的表头
    pav->rlink = pav->llink = pav;  // 初始化可利用空间(一个整块)
    pav->tag = 0; 
    pav->size = MAX; 
    p = FootLoc(pav);  // p指向底部域
    p->uplink = pav; 
    p->tag = 0; 
    (p + 1)->tag = 1;  // 设置高址边界，以防查找右邻块时出错
    printf("初始化完毕\n\n"); 

    while (LoopCommand(pav));

    delete p;

}
