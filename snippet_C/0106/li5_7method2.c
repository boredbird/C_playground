/*程序5.7 分别用移动下标的方法和移动指针的方法实现输出数组的所有元素。
方法2：移动指针
*/
#include <stdio.h>
int main( )
{
	int a[5]={1,2,3,4,5};
	int *pa=a;            //pa=&a[0]
	while (pa<a+5)
		printf("%5d",*pa++);  //移动指针
	printf("\n");
	return 0;
}
