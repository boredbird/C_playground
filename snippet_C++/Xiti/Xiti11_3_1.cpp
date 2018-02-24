/*
* 
* 文件名称：Xiti11_4_1.cpp
* 摘 要：编写程序，利用string类提供的成员函数来完成字符串的查找与替换	
* 完成日期：2009.1
* 
*/
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;


void main()
{

	cout<<"在字符串a中查找出字符串b，然后以字符串c替换"<<endl;
	string aa("");
	string bb("");
	string cc("");
	cout<<"输入字符串a"<<endl;
	cin>>aa;
	cout<<"输入字符串b"<<endl;
	cin>>bb;
	cout<<"输入字符串c"<<endl;
	cin>>cc;

	int npos=aa.find(bb);		//查找字符串b在a的位置
	int bb_length=bb.length();	//得到b的长度
	cout<<"字符串b的长度为："<<bb_length<<endl;
	aa.replace(npos,npos+bb_length-1,cc);	//在字符串a中查找出字符串b，然后以字符串c替换
	cout<<"替换之后的字符串a为：\n"<<aa<<endl;

}