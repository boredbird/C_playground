//编写程序输入一个十进制表示的正整数，将其转化为二进制表示并输出结果。
#include <iostream.h>
void main()
{ 
	int a;			//变量C为摄氏温度
	int b[20]; 	//数组存储转换后的二进制数
	int i;

	i=0;
	cout<<"请输入一个十进制的数字:\n";
	cin>>a;			//输入十进制数
	while (a>0)		//转换过程
	{
		b[i]=a%2;
		i++;
		a=(int)(a/2);
	}
	i--;
	cout<<"转换的二进制数为： ";	
	while (i>=0)	//输出二进制结果
	{
		cout<<b[i];
		i--;
	}
	cout<<endl;
}
