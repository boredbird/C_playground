/*
* 
* 文件名称：Xiti11_4_4.cpp
* 摘 要：编写程序，利用输入、输出迭代器，将一个文件中的内容添加到另一个文件的尾部   
* 完成日期：2009.1
* 
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>
using namespace std;

void main()
{
	typedef vector<string> string_vector;
	typedef istream_iterator<string> input;
	typedef ostream_iterator<string> output;
	typedef back_insert_iterator<string_vector> ins;
	string_vector vec;					//定义string类型容器对象vec
	ifstream from_file("file1.txt");
	if(from_file.fail())
	{
		cout<<"文件打开失败"<<endl;
		exit(0);
	}
	copy(input(from_file),input(),ins(vec));		//从file1.txt文件中提取元素插入到容器vec中
	cout<<"file1.txt文件的内容是："<<endl;
	copy(vec.begin(),vec.end(),output(cout," "));	//将容器vec中的元素插入到屏幕输出流
	cout<<endl;
	ofstream to_file("file2.txt",ios::app);			//使用ios::app方式实现一个文件中的内容添加到另一个文件的尾部 
	copy(vec.begin(),vec.end(),output(to_file," "));//将容器vec中的元素插入到file2.txt文件的尾部，分隔符为空格
	cout<<"文件的内容已成功插入到file2.txt文件的尾部!!!"<<endl;
}

