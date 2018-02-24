#include <iostream.h>
class Shape		//抽象类Shape，表示形状
{
protected:
  double d;
public:
	void setShape(double i)
	{    d=i;
	}
	virtual void area()=0;
	virtual void volume()=0;

};

class Cylinder: public Shape	//圆柱体类
{
private:
	double height;
public:
	void setCylinder(double i,double j)
	{
		setShape(i);
		height=j;
	}
	void area()
	{	cout<<"圆柱体的表面积："<<2*3.14*d*height+2*3.14*d*d<<endl;
	}
	void volume()
	{	cout<<"圆柱体的体积："<<3.14*d*d*height<<endl;
	}
};

class Sphere:public Shape	//球体类
{
public :
	void setSphere(double i)
	{
		setShape(i);
	}
	void area()
	{
		cout<<"球体的表面积："<<4*3.14*d*d<<endl;
	}
	void volume()
	{
		cout<<"球体的体积："<<4/3*3.14*d*d*d<<endl;
	}
};

class Cube:public Shape		//正方体类
{
public:
	void setCube(double i)
	{
		setShape(i);
	}
	void area()
	{
		cout<<"正方体的表面积："<<d*d*6<<endl;
	}
	void volume()
	{
		cout<<"正方体的体积："<<d*d*d<<endl;
	}
};

void main()
{   Shape *p0;
	double p ;double q;double r;
	Cylinder cy1;
	Sphere sp1;
	Cube cu1;
    p0=&cy1;
	cout<<"分别输入圆柱体的半径和高："<<endl;
	cin>>p>>q;
    cy1.setCylinder(p,q);
	p0->area();
	p0->volume();

    p0=&sp1;
	cout<<endl<<"输入球体的半径："<<endl;
	cin>>r;
    sp1.setSphere(r);
	p0->area();
	p0->volume();

    p0=&cu1;
	cout<<endl<<"输入正方体的边长："<<endl;
	cin>>p;
	cu1.setCube(p);
	p0->area();
	p0->volume();
}
