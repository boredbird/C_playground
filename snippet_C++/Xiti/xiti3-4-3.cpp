//求解输入两个正整数的最大公约数和最小公倍数。

#include <iostream.h>
void main()
{ 
	int a,b;			//输入的两个正整数
	int min,max;		//最小值和最大值

	cout<<"请输入两个正整数(数字以空格隔开)"<<endl;
	cin>>a>>b;
	if (a>=b)//找出两个数中的最大值和最小值
	{
		min=b;
		max=a;
	}
	else
	{
		min=a;
		max=b;
	}
	//最大公约数一定不大于两个数中的最小值
	while (min>0)
	{
		if ((a%min==0)&&(b%min==0)) 
			break;
		else
			min--;
	}
	cout<<a<<"和"<<b<<"的最大公约数为"<<min<<endl;
	//最小公倍数一定不小于两个数中的最大值
	while ((max%a!=0)||(max%b!=0))
	{
		max++;
	}
	cout<<a<<"和"<<b<<"的最小公倍数为"<<max<<endl;
}
