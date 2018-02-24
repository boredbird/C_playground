/*程序5.7 分别用移动下标的方法和移动指针的方法实现输出数组的所有元素。
方法1：移动下标
*/
#include <stdio.h>
int main( )
{
	int a[5]={1,2,3,4,5};     
	int i=0,*pa=a;           //pa=&a[0]
	while (i<5)
		printf("%5d",pa[i++]); //移动下标
	printf("\n");
	return 0;
}
