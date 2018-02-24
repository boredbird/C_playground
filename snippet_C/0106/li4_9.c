/*程序4.9  从键盘上读入两个正整数，用辗转相除法求它们的最大公约数。
算法思想：
（1）将两个正整数分别作为被除数（dividend）和除数（divider）。
（2）被除数除以除数，得到余数（remainder）。
（3）若余数不为0，则除数转为被除数，余数转为除数，继续步骤②。
（4）若余数为0则结束循环，使余数为0的除数就是最大公约数。
*/
#include<stdio.h>
int main( )
{	
	int dividend,divider,remainder; 
    printf("Please input two integers:\n");
	scanf("%d%d",&dividend,&divider);      //读入被除数和除数
	if (dividend<=0||divider<=0)             //只要有一个为0
	{
		printf("Error input!\n");             //输出提示信息
		return 0 ;                         //结束程序
	}
	remainder=dividend%divider;            //求第一次的余数
	while (remainder)                      //当余数不为0时循环
	{  
		dividend=divider;                   //本次的除数作为下一次循环的被除数
	   divider=remainder;                  //本次的余数作为下一次循环的除数
	   remainder=dividend%divider ;         //求新的余数       
	}
	printf ("hcd: %d\n",divider);	            //输出最大公约数
	return 0;
}
