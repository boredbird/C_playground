#include<stdio.h>
 void B(void);
void A(void)	  //全局外部函数定义
{	putchar('A');
	B( );
}
