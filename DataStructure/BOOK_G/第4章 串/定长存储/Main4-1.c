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

	printf("�����봮s1\n");
	while ( !( StrAssign (s1, gets(c) ) ) )
	{
		printf("��������MAXSTRLEN(=%d)�����������룡\n", MAXSTRLEN);     
		fflush(stdin);
	}

    printf("����Ϊ%d \n���봮�Ƿ�Ϊ�գ�(1:�� 0:��)\n%d\n",StrLength(s1), StrEmpty(s1));
    StrCopy(s2, s1);
    printf("����s1���ɵĴ�Ϊ: ");
    StrPrint(s2);
   
	printf("\n�����봮s2\n");
	while ( !(StrAssign ( s2, gets( c ) ) ) )
	{
		printf("��������MAXSTRLEN(%d)�����������룡\n", MAXSTRLEN);
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
    printf("�ȽϽ����s1 %c s2\n",s);
    
    k = Concat(t, s1, s2);
    printf("\n��s1���Ӵ�s2�õ��Ĵ�tΪ: ");
    StrPrint(t);
	printf("\n");
    if (ERROR == k)
    {
        printf("��t�нض�\n");
    }
    
    ClearString(s1);
    printf("��Ϊ�մ���,��s1Ϊ: ");
    StrPrint(s1); 
    printf("����Ϊ%d \n���Ƿ�Ϊ�գ�(1:�� 0:��)\n%d\n\n", StrLength(s1), StrEmpty(s1));

    printf("��t���Ӵ�,�������Ӵ�����ʼλ��(pos)���Ӵ�����(len)����������֮���Կո����:\n");
	while ( ( scanf("%d %d", &i, &j) ) != 2 || ERROR == ( SubString(s2, t, i, j) )  )
	{
		printf("�����������֮���������룡\n");
		fflush(stdin);
	}
	printf("�Ӵ�s2Ϊ: ");
	StrPrint(s2);
	
	printf("�Ӵ�t�ĵ�pos���ַ���,ɾ��len���ַ���������pos��len����������֮���Կո����:\n");
	while ( (scanf("%d %d",&i, &j) ) != 2 || ERROR == ( StrDelete(t, i, j) ) )
	{
		printf("�������������������룡\n");
		fflush(stdin);
	} 
    printf("ɾ����Ĵ�tΪ: ");
    StrPrint(t);

    i = StrLength(s2) / 2;
    StrInsert(s2, i, t);
    printf("\n�ڴ�s2�ĵ�%d���ַ�֮ǰ���봮t��,��s2Ϊ:\n", i);
    StrPrint(s2);

    i = Index(s2, t, 1);
    printf("\ns2�ĵ�%d����ĸ���t��һ��ƥ��\n", i);                     
    SubString(t, s2, 1, 1);
    printf("��ʱ��tΪ:");
    StrPrint(t);

    Concat(s1, t, t);
    printf("��s1Ϊ������t������,��ʱ��s1Ϊ:");
    StrPrint(s1);
    printf("\n");

    Replace(s2, t, s1);
    printf("�ô�s1ȡ����s2�кʹ�t��ͬ�Ĳ��ص��Ĵ���,��s2Ϊ: ");
    StrPrint(s2);

    return 0;
 }
 