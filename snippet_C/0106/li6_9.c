/*
程序6.9 冒泡法排序函数的定义。方法1
*/
#include <stdio.h>
void Bubble (int *pa,int n);//冒泡法排序函数声明
int main()  //补充的主函数代码,与程序6.4类似
{	
	int a[10],n,i;               
	do                                  
	{	
		printf("Input n(1<=n<=10):\n");
		scanf("%d",&n);
	}while (n<1||n>10); 
	printf("Input %d elements:\n",n);
	for (i=0;i<n;i++)                      
		scanf("%d",&a[i]);                
	printf("The original array is:\n");
	for (i=0;i<n;i++)                      
		printf("%5d",a[i]);
	printf("\n");
	Bubble (a,n);	   //冒泡排序函数调用	
    printf("The sorted array is:\n");
	for (i=0;i<n;i++)                     
		printf("%5d",a[i]);
	printf("\n");
	return 0;
}
void Bubble (int *pa,int n)
{ 
		int i,j,temp,noswap;
		for(i=0;i<n-1;i++)	
		{
			noswap=1;		 //每轮扫描有无交换的标志，1表示无交换，0表示有交换
			for(j=n-1;j>i;j--)	 //从数组最后一个元素向前扫描，直到i指向的元素
				if(pa[j]<pa[j-1])
				{            //交换
					temp=pa[j-1];		
					pa[j-1]=pa[j];	
					pa[j]=temp;	
					noswap=0;//修改发生交换的标记
				}
			if(noswap==1)    //如果某一轮扫描未发生交换，算法终止，返回调用函数
				return;
		}
}

