/*程序6.20  定义一个函数CalculateA，
求一维数组前n个元素的和、最大值、最小值，主函数调用其求解。
*/
#include <stdio.h>
int CalculateA(int *pa,int n,int *max,int *min)          //返回和，最后两个指针参数
{                                              //返回最大最小值
	int i,sum=0;
	*max=*min=pa[0];                            //第一个元素既最大也最小
	for (i=0;i<n;i++)                              //循环，对所有的元素求解
	{	sum+=pa[i];                              //当前元素累加到sum变量中
		if (pa[i]>*max) *max=pa[i];                 //如果比*max大，则赋值
		if (pa[i]<*min) *min=pa[i];                  //如果比*min小，则赋值
	}
	return sum;                                   //返回和
}	
int main( )
{	int a[]={12,23,340,56,6};                        //定义并初始化数组
	int sum,max,min;                              //定义存和、最大最小值的变量
	sum=CalculateA(a,5,&max,&min);                //调用函数求解
	printf("sum=%d\n",sum);                        //输出和
	printf("max=%d\n",max);                        //输出最大元素值
	printf("min=%d\n",min);                         //输出最小元素值
	return 0;
}
