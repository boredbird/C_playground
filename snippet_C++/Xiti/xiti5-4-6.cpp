//编写一个函数，统计并返回一行文字中所有字母、数字、空格及其他字符的个数，同时编写相应的主函数，在主函数中能接收用户输入的一行文本，然后调用上面定义的函数，并在主函数中输出各种字符的个数。
#include <iostream.h>
void main()
{ 
	char a[100];		//最多输入100个字符
	cout<<"Input the string："<<endl;
	cin.getline(a,100);
	int num[4]={0,0,0,0};//分别存储数字、空格、字母和其它字符的个数
	int i=0;
	while(a[i]!=0)//求字符串的长度
	{
		if ((a[i]>=48)&&(a[i]<=57))	//数字
			num[0]+=1;
		else if (a[i]==32)			//空格
			num[1]+=1;
		else if (((a[i]>=65)&&(a[i]<=90))||((a[i]>=97)&&(a[i]<=122)))//大小写字母
			num[2]+=1;
		else						//其它字符
			num[3]+=1;
		i++;
	}
	cout<<"The Statistic result is :"<<endl;//输出统计结果
	cout<<"number:"<<num[0]<<" blank:"<<num[1]<<" character:"<<num[2]<<" other:"<<num[3]<<endl;
}
