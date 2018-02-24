//编写一个程序，采用异常处理的方法，在指定文件不存在时显示出错信息，文件存在时显示文件的基本信息。
#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>
#include <stdio.h>
void main()
{	
	FILE *fp;	//定义文件指针fp
	try
	{
		//以读的方式打开文件exception.txt，并判断文件是否打开成功
		if ((fp=fopen("c:\\exception.txt","r"))==NULL)
			throw 1;//打开不成功
		else
			throw fp;//打开成功
		fclose(fp);//关闭原文件
	}
	catch (int)
	{
		cout<<"Can't find file!!"<<endl;
	}
	catch (FILE * Exceptionfile)//用catch捕捉FILE类型的异常并获取抛出的值
	{
		char ch;
		ch=fgetc(Exceptionfile);//读取文件的第一个字符
		while(ch!=EOF)
		{	cout<<ch;
			ch=fgetc(Exceptionfile);	//读取文件的下一个字符
		}
	}
}
