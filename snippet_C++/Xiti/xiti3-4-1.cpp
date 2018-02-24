//编写程序，计算1到100中所有3的倍数的数的和。
#include <iostream.h>
void main()
{ 
	int sum=0;			//sum变量为3的倍数的和
	for(int i=1;i<=100;i++)
	{
		if (i%3==0)		//判断i是否是3的倍数
			sum+=i;
	}
	cout<<"1到100中所有3的倍数的数的和为:"<<sum<<endl;
}
