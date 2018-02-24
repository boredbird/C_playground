#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class Date		//定义一个日期类
{
private:
	int year;
	int month;
	int day;
public:
	Date()					//无参构造函数定义
	{	}
	Date(int y,int m,int d)	//有参构造函数定义
	{	year=y;
		month=m;
		day=d;
		cout<<"Date类有参构造函数被执行!"<<endl;
	}
	Date(const Date &p)		//拷贝构造函数定义
	{	year=p.year;
		month=p.month;
		day=p.day;
		cout<<"Date类拷贝构造函数被执行!"<<endl;
	}
	int Getyear()
	{	return year;
	}
	int Getmonth()
	{	return month;
	}
	int Getday()
	{	return day;
	}
};

class Student		//定义一个学生类
{
private:
	int number;
	char name[20];
	Date birth;
public:
	Student();
	Student(int n,char *m,Date d);
	Student(const Student &s);
    ~Student();
	void setnumber(int n);
	void setname(char *s);
	void setbirth(Date d);
	void printstudent();
};
Student::Student()//无参构造函数定义
{	}
Student::Student(int n,char *m,Date d):birth(d)//有参构造函数定义
{	number=n;
	strcpy(name,m);
	cout<<"Student类有参构造函数被执行!"<<endl;
}
Student::Student(const Student &s):birth(s.birth)//拷贝构造函数定义
{	number=s.number;
	strcpy(name,s.name);
    cout<<"Student类拷贝构造函数被执行!"<<endl;	
}
Student::~Student()//析构函数定义
{	}
void Student::setnumber(int n)
{
	number=n;
}

void Student::setname(char *s)
{
	strcpy(name,s);
}
void Student::setbirth(Date d)
{
	birth=d;
}
void Student::printstudent()//输出全部学生的信息
{
	cout<<"学生学号"<<setw(15)<<"学生姓名"<<setw(15)<<"出生日期"<<endl;
	cout<<number<<setw(15)<<name<<setw(15)<<birth.Getyear()<<"-"<<birth.Getmonth()<<"-"<<birth.Getday()<<endl;
}
int main()
{   int setnumber;	//用于设定学生人数
    int q;
	int xnumber;	//定义学号
	char xname[20];	//定义姓名
	int xyear,xmouth,xday;//定义年,月,日
    Student student[100];//定义一个Student对象数组,调用Student类中的无参构造函数,但是会先调用子对象birth的无参构造函数
	
    cout<<"请输入学生人数(小于100): ";
	cin>>setnumber;
    cout<<endl;

	for(q=0;q<setnumber;q++)
	{	cout<<"学生学号: ";
		cin>>xnumber;
	
		cout<<"学生姓名: ";
		cin>>xname;

		cout<<"出生日期"<<endl;
		cout<<"年: ";
		cin>>xyear;
		cout<<"月: ";
		cin>>xmouth;
		cout<<"日: ";
		cin>>xday;
		cout<<endl;

		Date xdate(xyear,xmouth,xday);		//调用Date类有参构造函数
		Student temp(xnumber,xname,xdate);	//调用Student类的有参构造函数,但会先执行Date类的拷贝构造函数
		Student stu(temp);					//调用Student类的拷贝构造函数,但先执行Date类的拷贝构造函数
		student[q]=stu;
	}

	for(q=0;q<setnumber;q++)
	{	student[q].printstudent();//输出学生信息
	}

	Student stu;
	cout<<"学生学号: ";
	cin>>xnumber;	
	cout<<"学生姓名: ";
	cin>>xname;
	cout<<"出生日期"<<endl;
	cout<<"年: ";
	cin>>xyear;
	cout<<"月: ";
	cin>>xmouth;
	cout<<"日: ";
	cin>>xday;
	cout<<endl;
	Date date1(xyear,xmouth,xday);
	stu.setnumber(xnumber);
	stu.setname(xname);
	stu.setbirth(date1);//调用Date类的拷贝构造函数
	stu.printstudent();
	return 0;
}