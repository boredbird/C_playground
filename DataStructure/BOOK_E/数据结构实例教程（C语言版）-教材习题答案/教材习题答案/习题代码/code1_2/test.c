#include "stdio.h"
main()
{
	int f1=1,f2=2,f3,i;
	for(i=3;i<=20;i++)
	{
		f3=f1+f2;
		f1=f2;
		f2=f3;
	}
	printf("第20项的值为:%d",f3);
}