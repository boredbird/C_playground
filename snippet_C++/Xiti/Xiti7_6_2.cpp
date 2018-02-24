#include<iostream.h>
#include<string.h>
class Person
{ protected:
	char *name;
	int age;
  public:
	Person();
	Person(char *sname,int sage);
	~Person();
	void show();
};
Person::Person()
{	name=new char[10];
	strcpy(name,"no name");
	age=0;
	cout<<"Person类的无参构造函数已经执行！"<<endl;
}
Person::Person(char *sname,int sage)
{	name=new char[strlen(sname)+1];
	strcpy(name,sname);
	age=sage;
	cout<<"Person类的有参构造函数已经执行！"<<endl;
}
Person::~Person()
{	delete[]name;
	cout<<"Person类的析构函数已经执行！"<<endl;
}
void Person::show()
{	cout<<"姓名："<<name<<"\t"<<"年龄："<<age<<"\t";
}

class Student:virtual public Person
{ protected:
	int no;
  public:
	Student();
	Student(char *sname,int sage,int sno);
	~Student();
	void show();
};
Student::Student()
{	no=0;
	cout<<"Student类的无参构造函数已经执行！"<<endl;
}
Student::Student(char *sname,int sage,int sno):Person(sname,sage)
{	no=sno;
	cout<<"Student类的有参构造函数已经执行！"<<endl;
}
Student::~Student()
{	cout<<"Student类的析构函数已经执行！"<<endl;
}
void Student::show()
{	Person::show();
	cout<<"学号："<<no<<endl;
}

class Teacher:virtual public Person
{ protected:
	char *title;
  public:
	Teacher();
	Teacher(char *sname,int sage,char *stitle);
	~Teacher();
	void show();
};
Teacher::Teacher()
{	title=new char[10];
	strcpy(title,"no title");
	cout<<"Teacher类的无参构造函数已经执行！"<<endl;
}
Teacher::Teacher(char *sname,int sage,char *stitle):Person(sname,sage)
{	title=new char[strlen(stitle)+1];
	strcpy(title,stitle);
	cout<<"Teacher类的有参构造函数已经执行！"<<endl;
}
Teacher::~Teacher()
{	delete[]title;
	cout<<"Teacher类的析构函数已经执行！"<<endl;
}
void Teacher::show()
{	Person::show();
	cout<<"职称："<<title<<endl;
}

class Teacher_Student:public Student,public Teacher
{
public:
	Teacher_Student(char *pname=" ",int page=0,int pno=0,char *ptitle=" ");
	void show();
};
Teacher_Student::Teacher_Student(char *pname,int page,int pno,char *ptitle):Student(pname,page,pno),Teacher(pname,page,ptitle),Person(pname,page)
{	}
void Teacher_Student::show()
{
	Student::show();
	cout<<"职称："<<title<<endl;
}
void main()
{	Person p1;
	p1.show();
	cout<<endl;
	Person p2("zhao",30);
	p2.show();
	cout<<endl<<endl;
	Student s1;
	s1.show();
	Student s2("qian",18,5001);
	s2.show();
	cout<<endl;
	Teacher t1;
	t1.show();
	Teacher t2("sun",50,"professor");
	t2.show();
	cout<<endl;
	Teacher_Student ts1;
	ts1.show();
	Teacher_Student ts2("li",35,8002,"lecturer");
	ts2.show();
}