#include<stdio.h>
int main()
{
    int i,n;
    n = 578;
    i = n%10;
    printf("%d",i);
    i = n/10%10;
    printf("%d",i);
    i = n/100;
    printf("%d\n",i);

    getchar();
    return 0;
}