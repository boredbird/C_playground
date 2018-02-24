#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a=rand()%10,b=rand()%10,c=rand()%10,d;
    printf("a=%d,b=%d,c=%d\n",a,b,c);
    printf("%d",c<(a+b));
    printf("%d",(d=c)>=(a+b));
    getchar();
    return 0;
}