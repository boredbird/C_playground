//编写一个程序，要求分别输入5个学生的3科成绩，并输出平均成绩最高的学生的姓名及各科成绩。要求用结构体数组实现。
#include <iostream.h>
#include <string>
struct student
{	
	char name[20];		//姓名 
	float course1;		//第一科成绩	
	float course2;		//第二科成绩
	float course3;		//第三科成绩
	float average;		//平均成绩
};
struct student stu[5];

void main()
{	
	float temp=-100.0;
	int j,k=0;
	char c;
	for (int i=0;i<5;i++)
	{
		cout<<"Input NO."<<i+1<<" student's name: ";
		cin>>stu[i].name;
		cout<<"Input NO."<<i+1<<" student's three scores: ";
		cin>>stu[i].course1>>stu[i].course2>>stu[i].course3;//输入三科成绩
		stu[i].average=(stu[i].course1+stu[i].course2+stu[i].course3)/3;//求平均成绩
		if (temp<stu[i].average)
		{
			temp=stu[i].average;	//temp存放最高平均分
			k=i;					//k存放该同学的序号
		}
	}
	cout<<"The student is "<<stu[k].name<<", three scores are "<<stu[k].course1<<", "<<stu[k].course2<<" and  "<<stu[k].course3<<endl;	
}
