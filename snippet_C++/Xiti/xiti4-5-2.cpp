//求a!+b!+c!的值，其中求n!要用一个函数实现，通过主函数输入a、b和c的值，并在主函数中输出计算的结果。
#include <iostream.h>
int factorial(int n)//求两点距离的子函数
{
	int sum=1;
	for (int i=1;i<=n;i++)
		sum*=i;
	return sum;
}
void main()
{ 
	int a,b,c;
	cout<<"Input a,b,c:";
	cin>>a>>b>>c;
	cout<<"a!+b!+c!="<<factorial(a)+factorial(b)+factorial(c)<<endl;
}
