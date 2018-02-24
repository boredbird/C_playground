#include<stdio.h>
extern int dys[];	//记录平常年每月天数
extern void Display(void);    //输出每月天数
extern int DaysOfYear(void);  //计算年总天数
int main()
{	Display();
	printf("%d\n",DaysOfYear());
	return 0;
	
}
