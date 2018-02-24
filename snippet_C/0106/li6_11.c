//程序6.11利用复合语句对数组元素求和。
#include <stdio.h>
#include <stdlib.h>
int main( )
{
	int a[10],i;          //主函数定义i
    for(i=0;i<10;i++)	   //主函数的i
  	   a[i]=rand()%10;   //调用随机函数赋值
{   //复合语句开始
	    int t=0,i;	        //复合语句定义t,i
        for( i=0;i<10;i++)  //复合语句的i
	       t=t+a[i] ;      //求数组元素的和
        printf("sum=%d\n",t);  //输出和数
  }    //复合语句结束，它的t和i的生命周期结束
    for(i=0;i<10;i++)    //主函数的i
	   printf("%d\t",a[i]);//输出数组的元素
	return 0;
}
