// 链式基数排序验证函数
#include "C1.h"
#include "C10-2.h"

#define N 10
void main()
{
    RedType d[N]={{278,1},{109,2},{63,3},{930,4},{589,5},{184,6},{505,7},{269,8},{8,9},{83,10}};
    SLList l;
    int *adr;
    InitList(l,d,N);
    printf("排序前(next域还没赋值):\n");
    Print(l);
    RadixSort(l);
    printf("排序后(静态链表):\n");
    Print(l);
    adr=(int*)malloc((l.recnum)*sizeof(int));
    Sort(l,adr);
    Rearrange(l,adr);
    printf("排序后(重排记录):\n");
    Print(l);
}
