//程序10.7 主函数中定义指针数组处理多个字符串，函数以指针的指针为形参输出所有字符串的值。

#include<stdio.h>
void Display(char** pa,int n)
{
		int i;
		for(i=0;i<n;i++)
			printf("%s  ",pa[i]);    //pa[i]可以写成*(pa+i);
		printf("\n");
}
int main( )
{
		char* a[]={"File","Edit","View","Run","Tools"};
		Display(a,5);                 //调用时，相当于执行了char **pa=a;
		return 0;
}
