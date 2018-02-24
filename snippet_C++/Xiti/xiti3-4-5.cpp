//输入4个字母，并反向显示这些字母。

#include <iostream.h>
void main()
{ 
	char a[4];		//输入4个字符
	
	cout<<"请输入4个字符："<<endl;
	for (int i=0;i<4;i++)
		cin>>a[i];
	cout<<"反向输出4个字符为:"<<endl;
	for (i=3;i>=0;i--)
		cout<<a[i];
	cout<<endl;

}
