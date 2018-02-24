/*表7.9带参数的宏*/
#include <stdio.h>
#include <stdlib.h>
#define RANDOM(num) rand()%(num)	
#define S(r) (r)*(r)*3.1415926	
#define MAX(a,b) ((a)>(b)?(a):(b))		
int main(  )
{	int a,b,r;
	double s;
	a=RANDOM(10);
	b=RANDOM(10);
	if(a||b)
	{	printf("%-4d%-4d\n",a,b);
		r=MAX(a,b);
		s=S(r);
		printf("%g\n",s);
	}
    return 0;
}
