//编写一个函数。该函数读入一个整数，然后将这个整数上每个位的数字按照相反的顺序输出。
//例如输入的整数为12345，输出结果为54321。
#include <iostream.h>
void reverse(int n)//反向显示整数n
{
	int a[20];//存储n的各位，最多20位
	int m=n;
	int i=0;
	while (m>0)//提取n的各位
	{
		a[i]=m%10;
		m=m/10;
		i++;
	}
	cout<<"reversed number is ";
	for (int j=0;j<=i-1;j++)//反向输出各位
		cout<<a[j];
	cout<<endl;
}
void main()
{ 
	int number;
	cout<<"Input the number: ";
	cin>>number;
	reverse(number);
}
