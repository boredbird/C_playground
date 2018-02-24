#include<stdio.h>
static void F(void);
void main(void)
{	F();
}
void F(void)
{	extern void A(void);
A();
}
