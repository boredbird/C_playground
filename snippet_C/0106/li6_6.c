/*
程序6.6 求最大公约数函数的定义与调用。
第4章的程序4.9是求最大公约数程序的主函数形式，
现在将其求最大公约数部分独立定义为函数gcd，并在主函数中调用
*/

#include<stdio.h>
int gcd(int dividend,int divider);//求最大公约数函数声明
int main( )
{	
int m,n; 
	do                   
	{	
printf("Input m,n:\n");
		scanf("%d%d",&m,&n); 
	}while (m<=0||n<=0);    
printf("hcd: %d\n",gcd(m,n));//求最大公约数函数调用
	return 0;                 
}
int gcd(int dividend,int divider) //求最大公约数函数定义
{	int remainder; 
	remainder=dividend%divider;  
while (remainder)                      
{  
dividend=divider;                   
divider=remainder;                  
 remainder=dividend%divider ;               
}                
    return divider;      //循环终止时的除数
}  
