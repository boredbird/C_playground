/*程序10.4 一维数组可以看作行数为1的二维数组。*/
#include<stdio.h>
int main( )
{
		double d[5]={1,2,3,4,5};            //定义一维数组
		int i;
		printf("the array is:\n");
		for(i=0;i<5;i++)                   //按一维数组元素的访问方式
			printf("%f\t",d[i]); 
		printf("\n");
		printf("regrad array as a special two dementional array:\n");
		for(i=0;i<5;i++)                   //将一维数组看作只有1行的二维数组
			printf("%f\t",(&d)[0][i]);        //&d是二维数组指针
		printf("\n");    
		return 0;	
}
