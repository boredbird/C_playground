#include "stdio.h"
void sort(int *p,int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1;j++)
			if(p[j]>p[j+1])
			{
				t=p[j];p[j]=p[j+1];p[j+1]=t;
			}
}
main()
{
	int a[10],i;
	printf("请输入10个整数:");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	sort(a,10);
    for(i=0;i<10;i++)
		printf("%d ",a[i]);
}