/*宏替换后的等效代码*/
#include <stdio.h>
#include <stdlib.h>
int main( )
{	int a,b,r;
	double s;
	a=rand()%10;
	b=rand()%10;
	if(a || b)                     //宏替换
	{	printf("%-4d%-4d\n",a,b);  //宏替换
		r=a>b?a:b;
		s=r*r*3.1415926;         //宏替换
		printf("%g\n",s);
	}
    return 0;
}
