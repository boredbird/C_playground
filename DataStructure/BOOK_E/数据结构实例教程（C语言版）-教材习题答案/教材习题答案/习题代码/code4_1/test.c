#include "stdio.h"
#include "string.h"
main()
{
	char ch,str[100];
	int i,n=0;
	printf("������һ���ַ���:");
	gets(str);
	printf("������Ҫͳ�Ƶ��ַ�:");
	ch=getchar();
	for(i=0;i<strlen(str)-1;i++)
		if(str[i]==ch)
			n++;
	printf("%c�ַ����ֹ�%d��",ch,n);
}