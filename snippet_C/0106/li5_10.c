/*例5.10：从键盘上输入n(1≤n≤10)个整数，首先输出这些元素，
再用选择法排序，最后输出排序后的元素。
*/
#include <stdio.h>
int main()
{
	int a[10],n,index,i,k,temp;                         //定义数组，i控制下标，n控制元素个数
	
	do                                 //保证读入的n满足1≤n≤10
	{	printf("Please input n(1<=n<=10):\n");
		scanf("%d",&n);
	}while (n<1||n>10);

	printf("Please input %d elements:\n",n);
	for (i=0;i<n;i++)                      //用for语句控制输入n个元素
		scanf("%d",&a[i]);                //注意取地址符的使用

	printf("The original array is:\n");
	for (i=0;i<n;i++)                      //用for语句控制输出n个初始元素
		printf("%5d",a[i]);
	printf("\n");

	for (k=0;k<n-1;k++)                //k控制排序的趟数
	{
		index=k;                       //本趟最小位置存于index,开始时为k
		for (i=k+1;i<n;i++)            //通过内层循环找出本趟真正的最小元素,
			if(a[i]<a[index])          //将下标赋给index
				index=i;
		if (index!=k)                  //如果本趟最小元素没有到位
		{
			temp=a[index];             //则通过交换使本趟最小元素到k下标处
			a[index]=a[k];
			a[k]=temp;
		}
	}
            
    printf("The sorted array is:\n");
	for (i=0;i<n;i++)                  //用for语句控制输出n个排好序的元素
		printf("%5d",a[i]);
	printf("\n");

	return 0;
}
