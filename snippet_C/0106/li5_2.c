/*程序5.2 编程定义并初始化一维数组，
显示一维整型数组所有元素的值及对应地址，
并对数组的所有元素求和。
*/
#include<stdio.h>
int main( )
{
		int a[5]={10,15,20,25,30};	     //初始化
		int i,sum=0;                    //定义循环控制变量i及求和变量sum
		for (i=0;i<5;i++)
			printf("%x,",a+i);			  //输出语句①，显示数组元素地址方法一
		printf("\n");
		for (i=0;i<5;i++)                
			printf("%x,",&a[i]);			  //输出语句②，显示数组元素地址方法二
		printf("\n");
    	for (i=0;i<5;i++)           	 
			printf("%d,",*(a+i));		  //输出语句③，显示数组元素值的方法一
        printf("\n");
		for (i=0;i<5;i++)           	  
			printf("%d,",a[i]);	          //输出语句④，显示数组元素值的方法二
		printf("\n");
		for (i=0;i<5;i++)           	 
			sum+=a[i];		          //数组元素求和
		printf("sum of array is: %d\n",sum); //输出和

		scanf("%d");
		return 0;
}

