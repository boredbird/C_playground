#include<iostream.h>
int main()
{	
	int a=1234;
	cout.setf(ios::oct,ios::basefield); //八进制
	cout<<"oct:"<<a<<endl;
	cout.setf(ios::dec,ios::basefield); //十进制
	cout<<"dec:"<<a<<endl;
	cout.setf(ios::hex,ios::basefield); //十六进制
	cout<<"hex:"<<a<<endl;
	return 0;
}
