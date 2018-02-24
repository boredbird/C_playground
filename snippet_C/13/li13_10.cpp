#include<iostream.h>
struct Vect	
{	
		double x1, x2;		
};
Vect operator+(Vect a,Vect b)	
{	
		Vect c;
		c.x1=a.x1+b.x1;
		c.x2=a.x2+b.x2;
		return(c);	
}
int main( )
{
		Vect x={6,5},y={4,3},z;
		z=x+y;						//相当于z=operator+(x,y);
		cout<<'('<<z.x1<<','<<z.x2<<')';
        return 0 ;
}
