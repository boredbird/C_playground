//编写一个函数，利用指针将一个字符串反向输出。编写相应的主函数对其进行调用，在主函数中完成原始数据的输入和结果输出。
#include <iostream.h>
void reverse(char *a, int n)//a为字符串首地址,n+1为字符串长度
{
	char temp;
	for(int k=0;k<((n+1)/2);k++)//a[k]和a[n-k]交换数据
	{
		temp=*(a+k);
		*(a+k)=*(a+n-k);
		*(a+n-k)=temp;
	}
}
void main()
{ 
	char a[100];		//最多输入100个字符
	cout<<"Input the string："<<endl;
	cin.getline(a,100);
	for (int i=0;a[i]!=0;)//求字符串的长度
		i++;
	reverse(a,i-1);
	cout<<"The reversed string is :";
	for(int j=0;j<=i-1;j++)//输出反向后的字符串
		cout<<*(a+j);
	cout<<endl;
}
