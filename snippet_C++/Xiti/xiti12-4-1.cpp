//编写一个程序，采用异常处理的方法，对数组的下标错误进行显示。
#include <iostream.h>
void main()
{	int a[20],m;
	try								//在try语句块中包含要检查的函数
	{	
		for (int i=0;i<20;i++)
			a[i]=i;
		cout<<"现有一维数组a[20]，请输入要查询的下标:";
		cin>>m;
		if (m<0) 
			throw 3;
		else if (m>=20)
			throw 'a';
		else
			cout<<"a["<<m<<"]="<<a[m]<<endl;
	}
	catch(int) 							//用catch捕捉int类型的异常并进行处理
	{		
		cout << "数组下标不能小于零!";
	}
	catch(char)
	{		
		cout << "数组下标不能大于或等于20!";
	}
}
