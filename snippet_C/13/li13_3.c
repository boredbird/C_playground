//程序13.3:C风格串处理
#include<stdio.h>
int main( )
{	
	char s[20];
    printf("Input a string: ");
	scanf("%s",s);
	printf("%s\n",s);  
	printf("%x\n",s);  
    printf("%x\n",&s); 
	return 0;
}
