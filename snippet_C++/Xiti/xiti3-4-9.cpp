//编写程序，用循环语句打印如下图案。
#include <iostream.h>
#include <math.h>
#include <iomanip.h>
void main()
{ 
	for (int i=1;i<=7;i++)
	{		
		cout<<setw(abs(4-i)+1)<<"@";//显示第一个@
		if ((i==1)||(i==7))			//第一行和最后一行仅显示一个@
		{
			cout<<endl;
			continue;
		}
		for (int m=abs(4-i)+2;m<=6-abs(4-i);m++)	//显示中间的*
			cout<<"*";
		cout<<"@"<<endl;			//中间几行显示第二个@
	}
}
