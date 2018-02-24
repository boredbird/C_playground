/* 程序5.8 调用随机函数产生10个1至100内的整数作为数组的元素，
   然后再逆置存放，输出初始序列和逆置以后的序列。
   方法1：采用移动下标法，因为这种方法无需要移动指针，
    故直接使用数组而不设指针变量，在交换时，用i和j分别指示待交换的两个元素的下标，
	i从0开始递增，j从9开始递减，循环条件为i<j。
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main( )
{
	int a[10],temp,i,j;     
	srand(time(NULL));  
	for (i=0;i<10;i++)    
		a[i]=rand( )%100+1;
	printf("original array is:\n");
	for (i=0;i<10;i++)   
		printf("%5d",a[i]);
	printf("\n");
	for (i=0,j=9;i<j;i++,j--) 
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}	
    printf("reversed array is:\n");
	for (i=0;i<10;i++)
		printf("%5d",a[i]);
	printf("\n");
	return 0;
}
