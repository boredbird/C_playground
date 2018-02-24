//程序6.2 将打印18个"*"组成星形线定义为一个返回值和形参列表都为空的函数，主函数调用它。
#include<stdio.h>
void Star(void)			   //画星形线。函数没有返回值，形参列表也为空
{	int i;
		for(i=1;i<=18;i++)	
			printf("*");		   //18个"*"组成星形线
		printf("\n");
 	   return ;                  //返回值类型为void，return后不带表达式，此句可省略
}
int main()
{		Star( );			       //单独的函数调用语句，实参表为空，但必须保留括号
		printf("I love C language!\n");
		Star( );

		scanf("%d");
    	return 0;
}
