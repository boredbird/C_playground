#include "stdio.h"
void sort(int a[],int n)
{
	int i,j,k,temp;
	for(i=0;i<=n/2-1;i++)
	{ 
      for(j=0;j<=n-2-i;j++)//�ϴ�������
	  {
        if(a[j]>a[j+1])
		{
           temp=a[j];
           a[j]=a[j+1];
           a[j+1]=temp;
		}
	  }
      for(k=j-1;k>=i+1;k--)
	  {   
        if(a[k]<a[k-1])
		{
           temp=a[k-1];
           a[k-1]=a[k];
           a[k]=temp;
		}
	  }
	}
}
main()
{
	int a[5],i;
	printf("������5������:");
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	sort(a,5);
	printf("ð���������Ϊ:\n");
	for(i=0;i<5;i++)
		printf("%d ",a[i]);

}

