#include "stdio.h"

void sort(int R[],int n)
{
    int i,j;
    for (i=n-1;i>=1;i--)
       if (R[i-1]>R[i]) 
       {  
         R[n]=R[i-1];
         for (j=i;R[j]<R[n];j++)
             R[j-1]=R[j]; 
         R[j-1]=R[n];
       }
}
main()
{
	int a[6],i;
	printf("请输入5个整数:");
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	sort(a,5);
	printf("排序后的结果为:");
	for(i=0;i<5;i++)
		printf("%d",a[i]);

}
