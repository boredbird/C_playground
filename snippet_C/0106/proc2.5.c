#include<stdio.h>
int main()
{
    double d;
    float f1 = 3.14F,f2;
    int x;
    char ch;
    f2 = -90.5f;
    printf("Please input ch,x,d:\n");
    scanf("%c%d%lf",&ch,&x,&d);
    printf("d=%%8.2f:%8.2f\n",d);

    getchar();
    return 0;
}