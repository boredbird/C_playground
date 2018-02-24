#include "stdio.h"
main()
{
	int a,b,t;
    scanf("%d,%d",&a,&b);
    t=a; 
    a=b; 
    b=t;
	printf("a=%d,b=%d",a,b);
}

