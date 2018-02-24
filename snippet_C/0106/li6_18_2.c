/*程序6.18:传值与传地址的区别----传地址
*/
#include<stdio.h>
void SwapByAddress(int*,int*);   //地址形参
int main()
{	int a=3,b=4;
	SwapByAddress (&a,&b);//实参为变量地址
	printf("a=%d,b=%d\n",a,b);
    return 0;
}
void SwapByAddress(int *px,int *py)
{	int tmp;    //交换两个指针变量所指向的值
	tmp=*px;	*px=*py; *py=tmp;
}
