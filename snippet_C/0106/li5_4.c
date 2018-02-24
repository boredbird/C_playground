/*程序5.4  设计程序验证d与&d的区别。*/
#include <stdio.h>
int main( )
{
	double d[5];
	printf("d=%x\n",d);          //d作为指针字面值常量，是第一个元素的地址
    printf("&d[0]=%x\n",&d[0]);  //输出第一个元素的地址
	printf("&d=%x\n",&d);       //d代表数组变量标识符，是数组空间的首地址
	printf("d+1=%x\n",d+1);      //以double为基类型的指针+1，向下移动8字节
    printf("&d+1=%x\n",&d+1);   //以double[5]为基类型的指针+1，向下移动40字节
	
	scanf("%d");
	return 0;
}
