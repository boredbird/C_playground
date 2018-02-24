//编写一个程序，要求当输入一个数字月份时，程序输出该月的英文名称。例如输入5时，程序输出"May"，要求用指针数组实现。
#include <iostream.h>
#include <string>
void main()
{	
	//定义指针数组
	char *month[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	int n;
	cout<<"Input the month(1-12)：";
	cin>>n;
	while ((n>12)||(n<1))
	{
		cout<<"Input the month(1-12):";
		cin>>n;
	}
	cout<<"The month is "<<*(month+n-1)<<endl;	
}
