// ��ʽ����������֤����
#include "C1.h"
#include "C10-2.h"

#define N 10
void main()
{
    RedType d[N]={{278,1},{109,2},{63,3},{930,4},{589,5},{184,6},{505,7},{269,8},{8,9},{83,10}};
    SLList l;
    int *adr;
    InitList(l,d,N);
    printf("����ǰ(next��û��ֵ):\n");
    Print(l);
    RadixSort(l);
    printf("�����(��̬����):\n");
    Print(l);
    adr=(int*)malloc((l.recnum)*sizeof(int));
    Sort(l,adr);
    Rearrange(l,adr);
    printf("�����(���ż�¼):\n");
    Print(l);
}
