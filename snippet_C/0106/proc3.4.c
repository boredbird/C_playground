#include<stdio.h>
int main(void)
{
    int i=5,j=6,k;
    i++;++j;
    printf("i=%d,j=%d\n",i,j);
    i--;--j;
    printf("i=%d,j=%d\n",i,j);
    k=(i++)+(++j);
    printf("i=%d,j=%d,k=%d\n",i,j,k);
    k=(i--)+(--j);
    printf("i=%d,j=%d,k=%d\n",i,j,k);

    // getchar();
    return 0;
}