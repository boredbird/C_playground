//编写程序，用户输入一些整数，该程序分别计算出所有奇数和所有偶数之和，并输出它们。
#include <iostream.h>
void main()
{ 
	int sum_odd=0;			//变量为所有奇数的和
	int sum_even=0;			//变量为所有偶数的和
	int b;					//变量为输入的数字
	int N;					//变量为数字个数
	cout<<"输入数字的总的个数为";
	cin>>N;
	cout<<"请输入数字(数字以空格隔开)"<<endl;
	for (int i=0;i<N;i++)
	{
		cin>>b;
		if (b%2==0)			//判断数字是否为偶数
			sum_even+=b;
		else
			sum_odd+=b;
	}
	cout<<"所有奇数的和为"<<sum_odd<<endl;
	cout<<"所有偶数的和为"<<sum_even<<endl;
}
