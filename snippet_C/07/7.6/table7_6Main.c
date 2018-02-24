#include<stdio.h>
static int dys[]={31,28,31,30,31,30,31,31, 30,
31,30,31}; 
extern void Display(void);  
int main(  )
{	int m,t=0; 
	Display();
	for(m=0;m<12;m++)
		t=t+dys[m];
	printf("%d\n",t);	   
    return 0;
}
