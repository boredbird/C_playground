/*程序5.6:用一级指针访问一维数组*/
#include<stdio.h>
int main( )
{
	int a[5]={10,15,20,25,30};	//数组初始化
	int i,*p=a;					//整型指针变量初始化等于a	
	p[0]=-p[0];					//修改数组首元素的值，即a[0]=-10;
	p[1]=p[2]+p[3];				//修改数组第2个元素的值，即a[1]=a[2]+a[3];
	printf("print out address and value of each element by using pointer:\n");
	for (i=0;i<5;i++)           //利用指针输出数组每个元素的地址及元素值
		printf("&a[%d]=%x,  a[%d]=%d\n",i,p+i,i,*(p+i));   
	printf("print out address and value of each element by using array:\n");
	for (i=0;i<5;i++)           //利用一维数组输出数组每个元素的地址及元素值
		printf("&a[%d]=%x,  a[%d]=%d\n",i,&a[i],i,a[i]); 

	scanf("%d");
	return 0;	
}
