#include "stdio.h"
main()
{
	int i,j,a[4][4],sum=0;
	for(i=0;i<4;i++)
	  for(j=0;j<4;j++)
		  scanf("%d",&a[i][j]);
    for(i=0;i<4;i++)
	{
		sum=sum+a[i][i];
		sum=sum+a[i][3-i];
	}
    printf("\n½á¹ûÎª£º%d",sum);
}