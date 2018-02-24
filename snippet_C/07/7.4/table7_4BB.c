#include<stdio.h>
#include<stdlib.h>
void B(void)
{	extern void A(void);
	printf("B");
	if(rand()%2==1)
		A();
}
