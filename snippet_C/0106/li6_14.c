//程序6.14  动态空间资源"耗尽"实验。
#include<stdio.h>
#include<stdlib.h>
#define N 1000000                         //定义符号常量N
void f(void);		                        //函数原型声明
int main( )
{
	while(1)                             //连续调用函数f，直到动态存储空间资源
		f( );                             //"耗尽"，程序被迫停止
	return 0;
}
void f(void)                              //该函数调用了malloc而没有调用free
{
	double *p;                           //定义指针
	static int c=0;		                   //静态局部变量用来记录该函数调用次数
	c++;			 	                   //每调用一次，次数增1
	p=(double*)malloc(N*sizeof(double));    //每次申请N个double型元素的数组空间
	if(p==NULL)                        //NULL为符号常量,就是0
	{
		printf("allocation failure");	       //提示：动态分配失败
		exit(1);					       //终止程序，控制权交给操作系统
	}
	printf("c=%d\t",c);                    //输出本次是第几次调用
}
