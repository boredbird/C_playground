//程序6.12  定义函数fac求n! ，主函数调用该函数输出1！至7!并求阶乘之和。
#include <stdio.h>
double fac(int n)
{
		static double f=1.0;          //定义静态局部变量f，初始化为1
		f=f*n;                     //利用f的记忆功能，这里的f实际上就是n!
		return f;                    //返回n!
}
int main( )
{
		int i;                       //定义自动局部变量i用于控制循环，从1到7
		double t,sum=0.0;            //定义自动局部变量t和sum分别存i!以及和值
		for (i=1;i<=7;i++)            // 用i控制循环，从1到7
		{
			t=fac(i);                //t的结果就是i!
			sum+=t;                //阶乘累加
			printf("%10.0f",t);        //输出i!
		}
		printf("\nsum=%10.0f\n",sum);  //输出阶乘的和
		return 0;
}
