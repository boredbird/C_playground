#include <iostream.h>
class Complex
{
private:
	double r;								//表示复数的实部
	double i;								//表示复数的虚部
public:
	Complex(double x=0.0,double y=0.0)		//定义构造函数
	{	r=x;
		i=y;
	}
    Complex operator+(Complex &c);
    Complex operator-(Complex &c);
    Complex operator*(Complex &c);
    Complex operator/(Complex &c);
 	void print();
};

Complex Complex::operator +(Complex &c)
{
    Complex temp;
    temp.r=r+c.r;
    temp.i=i+c.i;
    return temp;
}

Complex Complex::operator -(Complex &c)
{
    Complex temp;
    temp.r=r-c.r;
    temp.i=i-c.i;
    return temp;
}

Complex Complex::operator *(Complex &c)
{
    Complex temp;
    temp.r=r*c.r-i*c.i;
    temp.i=i*c.r+r*c.i;
    return temp;
}

Complex Complex::operator /(Complex &c)
{
    Complex temp;
    temp.r=(r*c.r+i*c.i)/(c.r*c.r+c.i*c.i);
    temp.i=(i*c.r-r*c.i)/(c.r*c.r+c.i*c.i);
    return temp;
}

void Complex::print()
{	cout<<'('<<r<<','<<i<<')'<<endl;
}

void main()
{
    Complex c1(1.0,2.0),c2(3.0,4.0),c3=c1+c2,c4=c1-c2,c5=c1*c2,c6=c1/c2;
    c1.print();
    c2.print();
    c3.print();
    c4.print();
    c5.print();
    c6.print();
}

