//输入三个数字，数字可以为整形或浮点型，分别编写函数来求解三个数字的最大值、最小值和平均值，要求在主函数中完成数字的输入和计算结果的输出。
#include <iostream.h>
#include <iomanip.h>
float fmax,fmin,faverage;
int max,min,average;
void calculate(float fa,float fb,float fc)		//浮点型处理函数
{
	fmax=fa>=fb?fa:fb;
	fmax=fmax>=fc?fmax:fc;
	fmin=fa<=fb?fa:fb;
	fmin=fmin<=fc?fmin:fc;
	faverage=(fa+fb+fc)/3;
}
void calculate(int a,int b,int c)				//整型处理函数
{
	max=a>=b?a:b;
	max=max>=c?max:c;
	min=a<=b?a:b;
	min=min<=c?min:c;
	average=(a+b+c)/3;
}
void main()
{ 
	int s1,s2,s3;
	float f1,f2,f3;
	int type;
	cout<<"Input the type: float(1) or int(0):";
	cin>>type;

	while ((type!=0)&&(type!=1))		//输入类型错误时再次输入
	{
		cout<<"Please input 1 or 0:";
		cin>>type;
	}
	cout<<"Input three numbers:";

	if (type==1)		//浮点型数据
	{
		cin>>f1>>f2>>f3;
		calculate(f1,f2,f3);
		cout<<setw(8)<<"max"<<setw(8)<<"min"<<setw(12)<<"average"<<endl;
		cout<<setw(8)<<fmax<<setw(8)<<fmin<<setw(12)<<faverage<<endl;
	}
	else				//整型数据
	{
		cin>>s1>>s2>>s3;
		calculate(s1,s2,s3);
		cout<<setw(5)<<"max"<<setw(8)<<"min"<<setw(8)<<"average"<<endl;
		cout<<setw(5)<<max<<setw(8)<<min<<setw(8)<<average<<endl;
	}
}
