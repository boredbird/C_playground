#include<stdio.h>
int main()
{
    int m,n;
    n = 125;
    m = n;
    printf("The result is :\n");
    printf("%d,%d,%d\n",n,m,125);
    printf("%d,%d,%d\n",sizeof(n),sizeof(m),sizeof(125));
    printf("%x,%x\n",&n,&m);
    getchar();
    return 0;
}