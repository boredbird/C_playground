#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "C4-1.h"
  
int main()
{
    int i, j;                                                     
    char s, c[MAXSTRLEN + 1];
    Status k;
    SString t, s1, s2;

	printf("请输入串s1\n");
	while ( !( StrAssign (s1, gets(c) ) ) )
	{
		printf("串长超过MAXSTRLEN(=%d)，请重新输入！\n", MAXSTRLEN);     
		fflush(stdin);
	}

    printf("串长为%d \n输入串是否为空？(1:是 0:否)\n%d\n",StrLength(s1), StrEmpty(s1));
    StrCopy(s2, s1);
    printf("拷贝s1生成的串为: ");
    StrPrint(s2);
   
	printf("\n请输入串s2\n");
	while ( !(StrAssign ( s2, gets( c ) ) ) )
	{
		printf("串长超过MAXSTRLEN(%d)，请重新输入！\n", MAXSTRLEN);
		fflush(stdin);
	}
    i = StrCompare(s1, s2);
    if (i < 0)
    {
        s = '<';
    }
    else if (0 == i)
    {
        s = '=';
    }
    else
    {
        s = '>';
    }
    printf("比较结果：s1 %c s2\n",s);
    
    k = Concat(t, s1, s2);
    printf("\n串s1联接串s2得到的串t为: ");
    StrPrint(t);
	printf("\n");
    if (ERROR == k)
    {
        printf("串t有截断\n");
    }
    
    ClearString(s1);
    printf("清为空串后,串s1为: ");
    StrPrint(s1); 
    printf("串长为%d \n串是否为空？(1:是 0:否)\n%d\n\n", StrLength(s1), StrEmpty(s1));

    printf("求串t的子串,请输入子串的起始位置(pos)和子串长度(len)，两个数字之间以空格隔开:\n");
	while ( ( scanf("%d %d", &i, &j) ) != 2 || ERROR == ( SubString(s2, t, i, j) )  )
	{
		printf("输入错误，请检查之后重新输入！\n");
		fflush(stdin);
	}
	printf("子串s2为: ");
	StrPrint(s2);
	
	printf("从串t的第pos个字符起,删除len个字符，请输入pos和len，两个数字之间以空格隔开:\n");
	while ( (scanf("%d %d",&i, &j) ) != 2 || ERROR == ( StrDelete(t, i, j) ) )
	{
		printf("输入错误，请检查后重新输入！\n");
		fflush(stdin);
	} 
    printf("删除后的串t为: ");
    StrPrint(t);

    i = StrLength(s2) / 2;
    StrInsert(s2, i, t);
    printf("\n在串s2的第%d个字符之前插入串t后,串s2为:\n", i);
    StrPrint(s2);

    i = Index(s2, t, 1);
    printf("\ns2的第%d个字母起和t第一次匹配\n", i);                     
    SubString(t, s2, 1, 1);
    printf("此时串t为:");
    StrPrint(t);

    Concat(s1, t, t);
    printf("串s1为两个串t的连接,此时串s1为:");
    StrPrint(s1);
    printf("\n");

    Replace(s2, t, s1);
    printf("用串s1取代串s2中和串t相同的不重叠的串后,串s2为: ");
    StrPrint(s2);

    return 0;
 }
 