//求 1!+2!+…+50!。
#include <iostream.h>
void main()
{ 
	int sum1=1;//记录i!的结果
	int sum2=0;//记录i!累加的结果
	for (int i=1;i<=50;i++)
	{
		for (int j=1;j<=i;j++)	//计算i!
			sum1*=j;
		sum2+=sum1;
	}
	cout<<"1!+2!+…+50!="<<sum2<<endl; 
}
