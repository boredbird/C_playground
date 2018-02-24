#include <iostream.h>
#define PI 3.14159
class Circle
{
public:
	void input()
	{
		cout<<"请输入圆的半径：";
		cin>>r;
	}
	double cal()
	{
		return PI*r*r;
	}
	void output()
	{
		cout<<"圆的半径为："<<r<<"，面积为："<<cal()<<"。"<<endl;
	}
private:
	int r;
};
void main()
{
	Circle c;
	c.input();
	c.output();
} 
