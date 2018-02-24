//用递归方法将一个整数n转换成字符串。
#include <iostream>
#include <string>
using namespace std;
string convert(int n);
string numstring("");
void main()
{ 
	int number;
	cout<<"Input the number: ";
	cin>>number;
	cout<<"converted string is ";
	cout<<convert(number)<<endl;
}

string convert(int n)//递归函数
{
	if ((n/10==0)&&(n==0)) 
		return "";
	else
		numstring=convert(n/10).append(string(1,(n%10+48)));//将各位数转换为字符后创建字符串，加到最后
	return numstring;
}