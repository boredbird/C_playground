/*程序10.2 二维数组指针和首个行一维数组指针。*/
#include<stdio.h> 
int main()
{
		int a[4][3];
		printf("%x,%x\n",a,a[0]);	//测试二维数组指针针和首个行一维数组指针的值
		printf("%x,%x\n",a+1,a[0]+1);// 通过加1运算的结果验证它们的基类型不同
		return 0;
}
