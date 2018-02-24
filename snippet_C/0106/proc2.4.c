#include<stdio.h>
int main()
{
    char ch1,ch2;
    scanf("%c",&ch1);
    ch2 = ch1 + 32;
    printf("%c,%c\n",ch1,ch2);
    printf("%d,%d\n",ch1,ch2);
    ch1 = 102;
    ch2 = ch1 - 32;
    printf("%c,%c\n",ch1,ch2);
    printf("%d,%d\n",ch1,ch2);
    
    getchar();
    return 0;
}