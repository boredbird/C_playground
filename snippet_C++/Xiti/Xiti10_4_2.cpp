/*
* 
* 文件名称：Xiti10_4_2.cpp
* 摘 要：
* 编写程序，统计一篇英文文章中英文单词的个数以及文章的总行数
* 其中要假定文章要用正常格式输入。即单词与单词之间要有空格。并且每一行的结尾要有回车。
* 完成日期：2009.1
* 
*/

#include "iostream.h"
#include "fstream.h"
void main()
{
	int word_number=1;						//单词个数
	int essay_line=1;						//行数
	int sign=-1;							//标志位，判断txt是否一个单词也没有。
	char a;
	fstream f;
	f.open("Xiti_10_4_2.txt",ios::in);		//打开文件
	if(!f)
	{
		cout<<"can't open this file.";
		return;
	}

	
	while(!f.eof())		//循环得到文件中的每个字符，并判断空格数和回车数，由此得出单词数和行数 			
	{
		f.get(a);
		if(a==' ')
		{
			word_number++;
			sign=1;
		}
		else if(a=='\n')
		{
			essay_line++;
			word_number++;
			sign=1;
		}
	}

	if(sign==-1)		//如果标志位是-1，则说明文件中单词数、行数均为0
	{
		essay_line=0;
		word_number=0;
	}

	cout<<"程序执行成功!\n"<<"这篇英文文章中单词的个数是:"<<word_number<<'\n'<<"文章的总行数为:"<<essay_line<<'\n';
	f.close();			//关闭文件
	
}