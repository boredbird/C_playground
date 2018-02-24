//程序6.3 函数声明示例。
#include<stdio.h>
#include<stdlib.h>
void A(void);			       //函数A声明
void B(void); 			       //函数B声明
int main(void)
{	A();
	scanf("%d");

	return 0;
}
void A(void)			       //函数A定义
{	putchar('A');
		B();
}
void B(void)				//函数B定义
{	putchar('B');
		if(rand()%2==1)		//若随机数为1，则调用函数A，若为0，则B函数结束
		A();
}
