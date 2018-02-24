#include<stdio.h>
void A(void)
{	extern void B(void);
	putchar('A');
	B( );
}
