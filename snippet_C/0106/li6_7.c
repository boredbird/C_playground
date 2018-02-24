#include<stdio.h>
#include<math.h>
int main( )
{
	double x,term=1,i=1,sum=0;
	int sign=1;
	scanf("%lf",&x);
	do
	{
		term=term*x/i;
		sum+=sign*term;		
        sign=-sign;
		i++;
	}while(fabs(term)>=1e-5);
	printf("sum=%.2f\n",sum);
	return 0;
}
