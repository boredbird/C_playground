//程序6.21  函数指针综合示例
#include <stdio.h>
int main( )
{	int a[5]={1,2,8,4,3};
		int Sum(int *,int);			        //求和函数Sum声明,一个指针参数一个值参
		int Max(int *);                    //寻找最大值函数Max声明，一个指针参数
		int (*pf)(int*,int)=Sum; 			//定义并初始化带形参表的函数指针变量pf
		int (*pq) ( );                      //定义不带形参的函数指针变量pq
		printf("Sum call:%d\n",Sum(a,5));    //输出Sum函数的调用结果
		printf("pf=Sum call:%d\n",pf(a,5));   //输出通过函数指针pf调用Sum的结果
		pq=Sum ;                        //为指针变量pq赋值Sum
		printf("pq=Sum call:%d\n",pq(a,5));	//输出通过函数指针pq调用Sum的结果
		printf("Max call:%d\n",Max(a));      //输出Max函数的调用结果
	//	pf=&Max ;                       //此句若在程序中则报警，形参表不匹配
	//	printf("pf=&Max call:%d\n",(*pf)(a));  //此句若在程序中则报错，实参太少
		pq=&Max;                        //可以将&Max赋给不带形参的函数指针pq 
   		printf("pq=&Max call:%d\n",(*pq)(a));  //输出通过函数指针pq调用Max的结果
		return 0;
}
int Sum(int *p,int n)                     //定义Sum函数求数组的前n个元素之和
{	int i,s=0;
		for (i=0;i<n;i++)
			s+=p[i];
		return s;
}
int Max(int *p)                     //定义Max函数找数组前5个元素的最大值
{	int m=p[0],i;
		for (i=1;i<5;i++)
			if (p[i]>m)  m=p[i];
		return m;
}
