#include<stdio.h>
int main()
{
    char ch1,ch2,ch3,ch4,ch5,ch6;
    ch1 = 'N';
    ch2 = 78;
    ch3 = 0x4e;
    ch4 = 0116;
    ch5 = '\x4e';
    ch6 = '\116';
    printf("%c\t%c\t%c\t\n",ch1,ch2,ch3);
    printf("\a");
    printf("%c\t%c\t%c\t\n",ch4,ch5,ch6);
    printf("\a");
    
    getchar();
    return 0;
}