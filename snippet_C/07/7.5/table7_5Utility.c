#include<stdio.h>
extern int dys[];  //声明	
void Display(void) 
{   int m;
	for(m=1;m<=12;m++)
	printf("%3d",dys[m-1]);
	printf("\n");
}
int DaysOfYear(void) 
{	int m,t=0;
	for(m=1;m<=12;m++)
		t=t+dys[m-1];
	return(t);	
}
