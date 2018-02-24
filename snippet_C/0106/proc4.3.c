#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int a,b;
    srand(time(NULL));
    a=rand()%50;
    b=rand()%50;
    if(a>b)
    {
        printf("the larger number is a :%d\n",a);
        printf("a-b=%d\n",a-b);
    }
    else
    {
        printf("the larger number is b :%d\n",b);
        printf("b-a=%d\n",b-a);
    }
    if(a>b) printf("You are lucky!\n");
    return 0;
}