#include<stdio.h>
void A(void)
{	extern void B(void);
	printf("A");
	B();
}
