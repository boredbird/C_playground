/*程序5.3  从键盘上输入n(1≤n≤10)个整数，首先输出这些元素，
再分别统计其中正数和负数的个数，并求出最大值与最小值。
*/
#include <stdio.h>
int main()
{
	int a[10],i,n;                         //定义数组，i控制下标，n控制元素个数
	int max,min;                      //存最大、最小元素值，类型与元素类型一致
	int positive=0,negative=0;              //存正数和负数的个数
	do                                 //保证读入的n满足1≤n≤10
	{	printf("Please input n(1<=n<=10):\n");
		scanf("%d",&n);
	}while (n<1||n>10);
	printf("Please input %d elements:\n",n);
	for (i=0;i<n;i++)                      //用for语句控制输入n个元素
		scanf("%d",&a[i]);                //注意取地址符的使用
	printf("The elements are:\n");
	for (i=0;i<n;i++)                      //用for语句控制输出n个元素
		printf("%5d",a[i]);
	printf("\n");
	for (i=0;i<n;i++)
		if(a[i]>0) positive++;              //统计正数个数
		else if (a[i]<0) negative++ ;         //统计负数个数，此处的if不能省略
	max=min=a[0] ;                      //假定第一个元素既是最大值又是最小值
	for (i=1;i<n; i++)                     //从第2个元素到第n个元素与最大最小值
	{   if (*(a+i)>max) max=*(a+i);        //变量作比较，及时根据条件修改这两个
		else                            //变量的值，此处的一对大括号可以省略
			if (*(a+i)<min) min=*(a+i);     //循环中对元素的访问用另一种形式表示
	}
	printf("positive=%d\n",positive);         //输出正数的个数
	printf("negative=%d\n",negative);        //输出负数的个数
	printf("max element=%d\n",max);        //输出最大元素值
	printf("min element=%d\n",min);        //输出最小元素值
	return 0;
}

