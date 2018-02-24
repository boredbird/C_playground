/*表格8.1右侧:用结构指针作形参提高效率*/
#include<stdio.h>
struct Date				//定义日期类
{	int yr,mo,da;
};

typedef struct Date Date;    //定义日期类别名
void func(Date *result)    //定义函数指针形参
{	Date d={2006,1,1};
	*result=d;            //通过指针改变实参
}
int main( )
{	int y; 	Date x;
    func(&x);           //调用函数，实参为
                       //结构变量的地址
	y=x.yr;             //访问结构的成员
	printf("y=%d\n",y);   //输出年
	return 0;
}

