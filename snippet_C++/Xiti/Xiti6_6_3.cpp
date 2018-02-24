//设计一个点类Point，其中包含点的坐标x和y两个数据成员，并设计两个友元函数，分别计算两点间的水平距离和垂直距离。 
#include<iostream.h>
#include<math.h>
class Point
{	private:
		int x,y;
	public:
		Point(int a=0,int b=0)	//有参构造函数
		{	x=a;
			y=b;
		}
/*		void set(int a,int b)	//赋值函数
		{	x=a;
			y=b;
		}*/
		friend void distX(Point &p1,Point &p2) //友元函数，计算两点之间的水平距离
		{	cout<<"两点间的水平距离是："<<fabs(p1.x-p2.x)<<endl;
		}
		friend void distY(Point &p1,Point &p2) //友元函数，计算两点之间的垂直距离
		{	cout<<"两点间的垂直距离是："<<fabs(p1.y-p2.y)<<endl;
		}
};
void main()
{	Point d1(3,4),d2(15,10);
/*	Point d1,d2;
	int x,y;
	cout<<"输入第一个点的水平坐标和垂直坐标：";
	cin>>x>>y;
	d1.set(x,y);
	cout<<"输入第二个点的水平坐标和垂直坐标：";
	cin>>x>>y;
	d2.set(x,y);*/
	distX(d1,d2);
	distY(d1,d2);
}