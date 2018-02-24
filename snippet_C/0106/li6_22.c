//程序6.22 定义递归函数求n!（n由键盘输入）。
//注意：每一层次的递归，其局部变量虽然同名，但是都有自己的空间，观察程序的输出结果。
#include<stdio.h>
long Fact(long n);
int main( )
{
		long n,c;
		scanf("%d",&n);                 //从键盘输入n
		if (n<0)  n=-n;                  //保证n>=0
		c=Fact(n);                      //调用递归函数求n!
		printf("%ld!=%ld\n",n,c);          //输出计算结果
		return 0;
}
long Fact(long n)                     //定义求阶阶乘的递归函数
{
		printf("n=%ld   &n=%x\n",n,&n);  //输出参数值和参数地址
		if(n==0||n==1)
			return(1);
		return(n*Fact(n-1)); 
}
