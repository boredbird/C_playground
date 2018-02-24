//编写程序计算10个正整数的平均值、方差以及标准方差。

#include <iostream.h>
#include <math.h>
#define number 10
void main()
{ 
	int a[number];			//输入的10个正整数
	int average,sum=0;		//平均值和总和
	int variance=0;			//方差
	int mvariance;			//均方差

	cout<<"请输入"<<number<<"个整数："<<endl;
	for (int i=0;i<number;i++)	//求总和
	{
		cin>>a[i];
		sum+=a[i];
	}
	i--;
	average=sum/number;			//求均值
	cout<<"average="<<average<<endl;
	while (i>=0)				//求方差
	{
		variance += abs(a[i]*a[i]-average*average);
		i--;
	}
	mvariance=variance/number;	//求均方差
	cout<<"variance="<<variance<<endl;
	cout<<"mvariance="<<mvariance<<endl;
}
