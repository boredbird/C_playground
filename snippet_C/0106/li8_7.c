//程序8.7 枚举类型的定义与使用例示。
#include<stdio.h>
enum Colors{red=1,green,blue};                 //定义颜色枚举类型
typedef enum Colors Colors;                    //为枚举类型起个别名
int  main( )
{
	int num;
	Colors col;                              //定义枚举类型变量
	printf("1=red,2=green,3=blue.\nPlease select:");//提示输入
	scanf("%d",&num);                       //输入一个整数
	col=(Colors)num;                         //为枚举变量赋值，需类型强制转换
	switch(col)                              //根据枚举变量的值控制输出
	{
	case  red:
		printf("red\n");break;                  //枚举值只能不能直接输出
	case  green:
		printf("green\n");break;                //枚举值通过与之写法一样的串输出
	case  blue:
		printf("blue\n");break;
	default:
		printf("??\n");
	}
	return 0;
}
