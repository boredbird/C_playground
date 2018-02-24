#include<stdio.h>
int main()
{
    int a,b,c;
    a=b=c=7;
    c+=a++;
    printf("a=%d,c=%d\n",a,c);
    c%=++a;
    printf("a=%d,c=%d\n",a,c);
    c*=a--;
    printf("a=%d,c=%d\n",a,c);
    return 0;
}