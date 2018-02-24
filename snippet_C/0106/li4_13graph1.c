/*程序4.13 固定行图形元素唯一的图形：
打印一个5行等腰上三角形，图形的符号为'*'号。
*/
#include <stdio.h>
int main()
{	
	int i,j;
    for (i=1;i<=5;i++)
	{	
	   for (j=1;j<=(5-i)+14;j++)  //+14使图形居中
		  printf("%2c",' ');      //打印前导空格
	   for (j=1;j<=2*i-1;j++)     //打印本行图形
			printf("%2c",'*');
	   printf("\n");             //换行
	}
	return 0;
}
