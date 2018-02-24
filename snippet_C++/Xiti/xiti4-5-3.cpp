//编写一个函数。该函数读入一个整数，并判断这个整数是否为一个回文数字。例如4，44，434，4334，43534都是回文数字。
#include <iostream.h>
bool palindrome(int n)//判断n是否为回文的子函数
{
	int a[20];
	int m=n;
	int i=0;
	int temp,num;
	while (m>0)//将数字的各位反向放置在数组a中
	{
		a[i]=m%10;
		m=m/10;
		i++;
	}
	temp=i/2;//需要比较的次数
	num=--i;//数字的最高位存储在a[num]中
	for (int j=0;j<temp;j++)
	{
		if (a[j]!=a[num-j]) return false;//如果出现不相等的情况立即退出
	}
	return true;//若比较的各个位置都相等,则为回文
}
void main()
{ 
	int number;
	cout<<"Input the number:";
	cin>>number;
	if (palindrome(number))
		cout<<number<<" is a palindrome."<<endl;
	else
		cout<<number<<" is not a palindrome."<<endl;
}
