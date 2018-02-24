#include<stdio.h>
#include<stdlib.h>
 void A(void);
void B(void)			       
{	putchar('B');
	if(rand( )%2==1)	        
	  A( );
}
