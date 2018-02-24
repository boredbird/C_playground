/*程序4.13 非固定行图形：打印一个n（3<=n<20）行等腰上三角形，
每行图形的字符依次为字符A，B，C┉。
*/

#include <stdio.h>
int main()
{	int i,j,n;           //增加变量n
    do
	{  printf("input lines:\n");
	   scanf("%d",&n);
	}while (n<3||n>20);  //保证n合适
	for (i=1;i<=n;i++)
	{	
		for (j=1;j<=(n-i);j++)
			printf("%2c",' '); 
		for (j=1;j<=2*i-1;j++)
			printf("%2c",i+64);
		printf("\n");
	}

	scanf("%d",&n);
	return 0;
}

