/*
* 
* 文件名称：Xiti10_4_3.cpp
* 摘 要：编写程序，完成两个文件的连接操作   
* 完成日期：2009.1
* 
*/

#include "iostream.h"
#include "fstream.h"
#define N 30
void main()
{
	int i=1;
	char a[N];
	fstream f1,f2;
	f1.open("From_Xiti_10_4_3.txt",ios::in|ios::out);			//以读写方式打开文件
	if(!f1)
	{
		cout<<"can't open this file.";
		return;
	}
	f2.open("To_Xiti_10_4_3.txt",ios::in|ios::out|ios::app);	//以读写方式打开文件，并使新的内容添加到文件的末尾
	if(!f2)
	{
		cout<<"can't open this file.";
		return;
	}

	while(!f1.eof())											//得到From_Xiti_10_4_3.txt中的数据并将添加到To_Xiti_10_4_3.txt的末尾，以实现文件的连接
	{
		f1.getline(a,sizeof(a));
		f2<<a<<'\n';
		i++;
	}
	cout<<"两个文件连接完成!\n结果被保存在To_Xiti_10_4_3.txt中"<<'\n';
	f1.close();													//关闭文件
	f2.close();
	
}