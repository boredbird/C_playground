/*表8.1第一种方法:返回结构类型*/
#include<stdio.h>
struct Date			   //定义日期类
{	int yr,mo,da;
};

typedef struct Date Date;   //定义日期类别名

Date func(void)          //定义值返回的函数
{	
Date d={2006,1,1};
	return(d);           //返回结构值
}
int main( )
{	int y;    Date x;
    x= func( ) ;          //调用值返回的函数
	y=x.yr;             //访问结构的成员
	printf("y=%d\n",y);   //输出年
	return 0;
}
