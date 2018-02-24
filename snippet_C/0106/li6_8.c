/*
程序6.8 选择法排序函数的定义与调用。
第5章的程序5.12是主函数形式的选择法排序，
现在将排序部分独立定义为选择排序法函数Selection，
并在主函数中调用
*/
#include <stdio.h>
void Selection(int *pa,int n);//选择排序函数声明
int main()
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
	Selection(a,n);	   //选择排序函数调用	
    printf("The sorted array is:\n");
	for (i=0;i<n;i++)                     
		printf("%5d",a[i]);
	printf("\n");
	return 0;
}
void Selection(int *pa,int n) //选择排序函数定义
{
	int i,k,index,temp;
	for (k=0;k<n-1;k++)                  
	{
		index=k ;                       
		for(i=k+1;i<n;i++)               			  if (pa[i]<pa[index])            
		index=i;
		if (index!=k)                    
		{	
			temp=pa[index];              
			pa[index]=pa[k];
			pa[k]=temp;
		}
	}   
}
