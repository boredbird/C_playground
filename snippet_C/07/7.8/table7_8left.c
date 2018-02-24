/*定义无参宏*/
#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926           //无参宏定义1
#define FORMAT "%-4d%-4d\n"//无参宏定义2
#define OR ||			       //无参宏定义3
int main( )
{	int a,b,r;
	double s; 
	a=rand()%10;
	b=rand()%10;
	if(a OR b)
	{	printf(FORMAT,a,b);
		r=a>b?a:b;
		s=r*r*PI;
		printf("%g\n",s);
	}
    return 0;
}
