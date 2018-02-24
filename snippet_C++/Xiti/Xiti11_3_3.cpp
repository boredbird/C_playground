/*
* 
* 文件名称：Xiti 11_4_3.cpp
* 摘 要：编写程序，利用vector容器输入若干个string类数据元素，将其排序后输出
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
	cout<<"输入若干个string类数据元素，然后排序后输出"<<endl;
	vector <string> str_vector;
	string stradd("");

	//输入//////////////////////////////
	cout<<"向容器中添加字符串，以“0000”结束添加"<<endl;
	cin>>stradd;
	while (stradd.compare("0000")!=0)
	{
		str_vector.push_back(stradd);	//将字符串加入容器
		cin>>stradd;
	}

	//排序////////////////////////////
	int size=str_vector.size();			//得到容器长度
	int i,j;
	for(i=0;i<size;i++)					//冒泡排序
	{
		for(j=0;j<size-1-i;j++)
		{
			if(str_vector[j]>str_vector[j+1])
			{
				str_vector[j].swap(str_vector[j+1]);
			}
		}
	}
	//输出//////////////////////////
	for (i=0;i<size;i++)
	{
		cout<<str_vector[i]<<endl;
	}
}