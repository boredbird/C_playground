/*
程序6.4 判断质数函数的定义与调用。第4章的程序4.7是判断质数程序的主函数形式，
现在将其判断质数部分独立定义为判断质数函数primeInt，并在主函数中调用
*/

#include<stdio.h>
#include<math.h>
int primeInt(int m); //判断质数函数声明
int main( )
{	int m;				
	scanf("%d",&m);             
	if (primeInt(m))   //判断质数函数调用
         printf("%d is a prime\n",m);
	else             
		printf("%d is not a prime\n",m);
	return 0;
}
int primeInt(int m)         //判断质数函数定义 
{	int i,k,prime=1 ;        //函数内定义3个变量
	if (m==1)		         //形参若为1		 
		prime=0 ;         //形参若为1，非质数
	k=(int)sqrt(m);		   	             
	for (i=2; prime &&i<=k;i++)             
		if (m%i==0)  	 //m被某除数整除			   
			prime=0 ;      //则不是质数      
	return prime ;          //用return语句返回
}                        //函数体结束      
