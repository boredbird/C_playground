//编写程序求一元二次方程ax*x+bx+c=0的解。
#include <iostream.h>
#include <math.h>
void main()
{ 
	float a,b,c;//方程的系数
	float s1,s2;//解
	float temp;
	cout<<"Input a,b,c:"<<endl;
	cin>>a>>b>>c;
	if (a==0)
	{
		cout<<"不是一元二次方程!"<<endl;
	}else
	{
		temp=b*b-4*a*c;
		if (temp<0)						//无根的情况
			cout<<"无实根!"<<endl;
		else if (temp==0)				//只有一个实根的情况
		{
			s1=-b/(2*a);
			cout<<"方程有一个实根,为"<<s1<<endl;
		}
		else							//两个实根的情况
		{
			s1=(-b+sqrt(temp))/(2*a);
			s2=(-b-sqrt(temp))/(2*a);
			cout<<"方程有两个实根,为"<<s1<<"和"<<s2<<endl;
		}
	}
}
