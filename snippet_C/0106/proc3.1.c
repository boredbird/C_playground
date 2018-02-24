#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a=5,b=6,c=7;
    printf("%d\n",rand());
    printf("%d\n",a*(b+c)/2-2);
    printf("%d\n",a=b);
    b=rand()%10;
    printf("%d\n",b);
    printf("%d\n",c=a=b);

    printf("%d\n",b);
    printf("%d\n",a);
    printf("%d\n",c);
    getchar();
    return 0;
}