/*程序7.1:条件编译示例*/
#define DEBUG						//宏名DEBUG定义
#include<stdio.h>						//包含了printf原型
#include<stdlib.h>						//包含了rand原型
int main( )
{
		int a,b,r;
		double s;
		a=rand( )%10;
		b=rand( )%10;
		if (a && b)
		{
			#ifdef DEBUG 				//条件编译指令开始如果宏名DEBUG已定义
			printf("%-4d%-4d\n",a,b);		//测试语句
		    #endif 							//条件编译指令结束
		    r=((a)>(b)?(a):(b));
		    s=(r)*(r)*3.1415926;
		    printf("%g\n",s);
		}
}

