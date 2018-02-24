#include "stdio.h"
#include "string.h"
main()
{
	char ch,str[100];
	int i,n=0;
	printf("请输入一个字符串:");
	gets(str);
	printf("请输入要统计的字符:");
	ch=getchar();
	for(i=0;i<strlen(str)-1;i++)
		if(str[i]==ch)
			n++;
	printf("%c字符出现过%d次",ch,n);
}