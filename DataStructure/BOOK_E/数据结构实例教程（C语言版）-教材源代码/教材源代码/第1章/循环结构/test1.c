#include "stdio.h"
/*
main()
{
	int i,sum=0;
	i=3;
	while(i<=99)
	{
      sum=sum+i;
	  i=i+3;
	}
	printf("sum=%d",sum);
}
*/
main()
{
    int i,sum=0;
	for(i=3;i<=99;i=i+3)
	  sum=sum+i;
	printf("sum=%d",sum);
}