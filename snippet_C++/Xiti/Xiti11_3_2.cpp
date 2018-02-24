/*
* 
* 文件名称：Xiti 11_4_2.cpp
* 摘 要：编写程序，利用string类完成一个字符串的逆序输出
* 完成日期：2009.1
* 
*/

#include "iostream"
#include <string>
#include <vector>
#include <iterator>
using namespace std;

void main()
{
	cout<<"字符串的逆序输出"<<endl;
	string dd("");						//dd用来保存输入的字符串
	cout<<"输入字符串:"<<endl;
	cin>>dd;
	cout<<"逆序输出字符串：";
	for(int i=dd.length()-1;i>=0;i--)	//实现逆序输出字符串
	{
		cout<<dd.substr(i,1);
	}
	cout<<endl;
}