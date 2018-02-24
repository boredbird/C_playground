/*
 程序6.5  调用primeInt 函数以每行5个质数的格式输出100到200之间的所有质数。
 */
#include<stdio.h>
#include<math.h>

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

int main( )
{	
int i,count=0;					
		for (i=101;i<200;i=i+2)    //用i作为循环控制变量，从101开始，步长为2
		  if (primeInt(i))        //对每一个i，调用primeInt函数判断它是否为质数
		  {
			printf("%5d",i);      //如果是质数，输出该质数i
			count++ ;           //质数个数加1
			if (count%5==0 )     //每输出5个质数换一行
printf("\n");
		  }
	    printf("\n");
	    return 0;
}
