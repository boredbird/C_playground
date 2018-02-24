/*
* 
* 文件名称：Xiti10_4_1.cpp
* 摘 要：  编写程序，打开指定的一个文本文件，并能在其中每一行的前面加上行号和一个空格符。 
* 完成日期：2009.1
* 
*/

#include "iostream.h"
#include "fstream.h"
void main()
{
	int i=1;
	char a[30];
	fstream f1,f2;
	f1.open("From_Xiti_10_4_1.txt",ios::in);	//以读方式打开文件From_Xiti_10_4_1.txt
	if(!f1)										//判断是否成功打开
	{
		cout<<"can't open this file.";
		return;
	}
	f2.open("To_Xiti_10_4_1.txt",ios::out);		//以写方式打开文件To_Xiti_10_4_1.txt
	if(!f2)										//判断是否成功打开
	{
		cout<<"can't open this file.";
		return;
	}
	while(!f1.eof())
	{
		f1.getline(a,sizeof(a));				//从From_Xiti_10_4_1.txt文件中读出一行数据到数组a[30]
		f2<<i<<" "<<a<<'\n';					//将其前面加上行号和一个空格符，之后再写入f2
		i++;
	}
	cout<<"程序执行成功!\nTo_Xiti_10_4_1.txt被保存在项目文件夹下"<<endl;
	f1.close();									//关闭文件					
	f2.close();
	
}