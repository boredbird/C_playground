//程序6.13 外部变量与局部变量的作用域示例。
#include<stdio.h>
int m=5;			            //定义并初始化外部变量m
void AB(void)
{	static int i=0;		        //静态局部变量i
  		int n=0,m=0;		        //自动局部变量n和m，其中m与外部变量同名
   		i++; m++; n++;           //运算局部变量，这里的m是局部变量而不是外部变量
    	printf("i=%d,n=%d,m=%d\n",i,n,m);   //输出3个局部变量的值
}
void NM(void)
{	 m++;			        //对外部变量m自增1
}
int main( )
{	AB();                   //第一次调用函数AB
   	    AB();                   //第二次调用函数AB
   		NM();                   //调用一次函数NM
    	printf("m=%d\n",m);	    //输出外部变量m的值
    	m*=10;                  //对外部变量m的值扩大10倍
   		printf("m=%d\n",m);	    //输出改变以后的外部变量m的值
		return 0;
}
