//编写一个程序，为选修3、4和5门课程的学生计算平均分，其中求平均分要用重载函数实现
#include <iostream.h>
float average(float a,float b,float c)//求三门课程平均分子函数
{
	return (a+b+c)/3;
}
float average(float a,float b,float c,float d)//求四门课程平均分子函数
{
	return (a+b+c+d)/4;
}
float average(float a,float b,float c,float d,float e)//求五门课程平均分子函数
{
	return (a+b+c+d+e)/5;
}
void main()
{ 
	int number;
	float s1,s2,s3,s4,s5;
	cout<<"The total of student's courses is ";
	cin>>number;
	if (number==3)
	{
		cout<<"Input three score of student:";
		cin>>s1>>s2>>s3;
		cout<<"The average is "<<average(s1,s2,s3)<<endl;
	}
	else if (number==4)
	{
		cout<<"Input four score of student:";
		cin>>s1>>s2>>s3>>s4;
		cout<<"The average is "<<average(s1,s2,s3,s4)<<endl;
	}
	else
	{
		cout<<"Input three score of student:";
		cin>>s1>>s2>>s3>>s4>>s5;
		cout<<"The average is "<<average(s1,s2,s3,s4,s5)<<endl;
	}
}
