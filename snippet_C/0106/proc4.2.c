#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c,s,area;
    printf("Please input a,b,c:\n");
    scanf("%1f%1f%1f",&a,&b,&c);
    if(a>0&&b>0&&c>0&&a+b>c&&a+c>b&&b+c>a)
    {
        s=(a+b+c)/2;
        area=sqrt(s*(s-a)*(s-b)*(s-c));
        printf("area=%f\n",area);
    }
    else
        printf("Error input!\n");

    return 0;
}