//程序13.3:C++风格
#include<iostream.h>
int main( )
{	
	char s[20];
	cout<<"Input a string: ";
	cin>>s;
	cout<<s<<endl;       //输出字符串ABC
	cout<<(void*)s<<endl; //输出字符串首地址
    cout<<&s<<endl;     //输出整个数组空间地址
	return 0;
}
