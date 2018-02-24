#include<stdio.h>
int main()
{   int a,x;
    printf("%d\n",(x=a=3,6*a));
    printf("%d\n",x=(a=3,6*a));
    return 0;
}