#include<stdio.h>
void F(void);
int main( )
{	F( );
    return 0;
}
void F(void)
{	extern void A(void);
A( );
}

