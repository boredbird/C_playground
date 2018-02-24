/*程序5.8 调用随机函数产生10个1至100内的整数作为数组的元素，
  然后再逆置存放，输出初始序列和逆置以后的序列。
  方法二：采用移动指针法，设两个指针p和q分别指向第一个元素和最后一个元素，
  交换对应的*p和*q，然后p++同时q--，循环条件为p<q。
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main( )
{
	int a[10],temp,*p,*q;  
	srand(time(NULL));   
	for (p=a;p<a+10;p++) 
		*p=rand( )%100+1;
	printf("original array is:\n");
	for (p=a;p<a+10;p++)
		printf("%5d",*p);
	printf("\n");
for (p=a,q=a+9;p<q;p++,q--)
	{
		temp=*p;
		*p=*q;
		*q=temp;
	}	
   printf("reversed array is:\n");
	for (p=a;p<a+10;p++)
		printf("%5d",*p);
	printf("\n");
	return 0;
}
