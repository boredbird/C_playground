/*表7.9:带参宏替换后*/
#include <stdio.h>
#include <stdlib.h>
int main( )
{	int a,b,r;
	double s;
	a=rand()%(10);        //宏1替换
	b=rand()%(10);        //宏1替换
	if(a|| b)
	{  printf("%-4d%-4d\n",a,b);
	   r=((a)>(b)?(a):(b));  //宏3替换
	   s=(r)*(r)*3.1415926; //宏2替换
		printf("%g\n",s);
	}
    return 0;
}
