/*程序6.18:传值与传地址的区别----传值
*/
#include<stdio.h>
void SwapByVlaue(int,int);   //值形参
int main()
{	int a=3,b=4;
	SwapByVlaue (a,b);   //实参为两个int变量
	printf("a=%d,b=%d\n",a,b);
    return 0;
}
void SwapByVlaue (int x,int y)
{	int tmp;           //交换两个值参变量的值
	tmp=x;	x=y; y=tmp; 
}
