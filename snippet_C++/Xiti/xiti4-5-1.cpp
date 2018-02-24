//编写一个函数，计算直角坐标系中点a(x0,y0)到点b(x1,y1)的距离。
#include <iostream.h>
#include <math.h>
float length(float x0,float y0,float x1,float y1)//求两点距离的子函数
{
	return sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));;
}
void main()
{ 
	float x0,x1,y0,y1;
	cout<<"Input x and y of a point:";
	cin>>x0>>y0;
	cout<<"Input x and y of b point:";
	cin>>x1>>y1;
	cout<<"The length from a to b is "<<length(x0,y0,x1,y1)<<endl;
}
