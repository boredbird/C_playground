#include "stdio.h"
#include "math.h"
main()
{
   double a,b,c,t,x1,x2;
   scanf("%f,%f,%f",&a,&b,&c);
   t=b*b-4*a*c;
   if(t>=0)
   {
      x1=(-b+sqrt(t))/(2*a);
	  x2=(-b-sqrt(t))/(2*a);
	  printf("%f,%f",x1,x2);
   }
   else
	   printf("нч╦Ы");
}
