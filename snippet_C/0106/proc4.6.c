#include<stdio.h>
int main()
{
    int n,i;
    double fac = 1;
    printf("Please input n:\n");
    scanf("%d",&n);
    if(n<0)
    {
        printf("Error input!\n");
    }
    else
    {
        for(i=1;i<=n;i++)
            fac*=i;

        printf("%d!=%c\n",n,fac);
    }
    return 0;
}