//输出所有的"水仙花数"。
//"水仙花数"是指一个3位数，其各位数字的立方和等于该数本身。
#include <iostream.h>
void main()
{ 
	int N,M;
	int a[3];					//存储三位数的个十百位
	cout<<"水仙花数为:"<<endl;
	for (N=100;N<=999;N++)
	{
		M=N;
		for (int j=0;j<3;j++)	//提取数字的个十百位
		{
			a[j]=M%10;
			M/=10;
		}
		if (a[0]*a[0]*a[0]+a[1]*a[1]*a[1]+a[2]*a[2]*a[2]==N)
			cout<<N<<"  ";
	}
}
