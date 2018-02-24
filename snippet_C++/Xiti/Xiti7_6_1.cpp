#include <iostream>
#include <string>
using namespace std;
class Date		//定义日期类
{
private:
	int year;
	int month;
	int day;
public:
	Date(int y,int m,int d)		//有参构造函数
	{
		cout<<"调用Date构造函数"<<endl;
		year=y;
		month=m;
		day=d;
	}
	void show()					//显示函数
	{ 
		cout<<year<<"年"<<month<<"月"<<day<<"日"; 
	}
};
class Time		//定义时间类
{
private:
	int hour;
	int minute;
	int second;
public:
	Time(int h,int m,int s)		//有参构造函数
	{
		cout<<"调用Time构造函数"<<endl;
		hour=h;
		minute=m;
		second=s;
	}
	void show()					//显示函数
	{ 
		cout<<hour<<"点"<<minute<<"分"<<second<<"秒"<<endl; 
	}
};
class Schedule:public Date,public Time	//派生类
{
private:
	int number;
public:
	Schedule(int num,int a,int b,int c,int d,int e,int f):Date(a,b,c),Time(d,e,f) //派生类构造函数
	{
		cout<<"调用Schedule构造函数"<<endl;
		number=num;
	}
	void show()
	{
		cout<<"序号"<<number<<":";
		Date::show();
		Time::show();
	}
};
int main()
{
	Schedule obj(1,2008,8,8,0,0,0);
	obj.show();
	return 0;
}
