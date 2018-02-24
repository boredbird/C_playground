#include <stdio.h>
int dys[]={31,28,31,30,31,30,31,31,
30,31,30,31}; //记录平年每月天数
void Display(void)         //全局外部函数定义
{   int m;
	for(m=0;m<12;m++)
	printf("%3d",dys[m]);
	printf("\n");
}
int DaysOfYear(void) 
{    int m,t=0;
	for(m=1;m<=12;m++)
		t=t+dys[m-1];
	return(t);	
}
