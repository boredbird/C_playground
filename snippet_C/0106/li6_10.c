/*程序6.10  自动局部变量的生存周期和作用域示例*/
#include<stdio.h>
void AB(void);                            //函数原型声明
void NM(void) ;                           //函数原型声明
int main( )
{
		int x,y;
		printf("main:&x=%x,&y=%x\n",&x,&y);	//调用之前，输出主函数的局部变量地址
		AB();                               //调用函数AB
		NM();                               //调用函数NM
		printf("main:&x=%x,&y=%x\n",&x,&y);	//调用之后，输出主函数的局部变量地址
    	return 0;
}
void AB(void)
{
		int a,b;
		printf("AB:  &a=%x,&b=%x\n",&a,&b);	//输出被调函数AB的自动局部变量地址
}
void NM(void)
{
		int n,m;
		printf("NM:  &n=%x,&m=%x\n",&n,&m);	//输出被调函数NM的自动局部变量地址
}
