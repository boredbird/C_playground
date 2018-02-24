#include "stdio.h"
/*
main()
{
	int x;
	int *p;
	x=5;
	p=&x;
	printf("x=%d,*p=%d",x,*p);
}
*/
main()
{
	int a[5]={1,2,3,4,5};
	int *p;
	p=a;//不需要加&
	printf("a[2]=%d,*(p+2)=%d",p[2],*(p+2));
}