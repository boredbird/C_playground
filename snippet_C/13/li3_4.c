//程序13.4:C风格
#include<stdio.h>
int main( )
{	
    int m,n;
	char a[10],b[10];
	printf("Input two integers:");
	scanf("%d%d",&m,&n);
	printf("%d\n%d\n",m,n);
	printf("Input two strings:");
	scanf("%s%s",a,b);
	printf("%s\n%s\n",a,b);
    return 0;
}
