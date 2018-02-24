//编写程序，提示用户输入三角形的三条边长，判断该三角形是否为直角三角形，若是输出结果以及三角形面积。
#include <iostream.h>

void main()
{ 
    float a,b,c,side1,side2,area; //side1和side2为两条直角边长度
    cout<<"please input length of three sides of the triangle: \n";     // 输出提示信息
    cin>>a>>b>>c;			// 输入三角形三边长度
	if ((a*a==b*b+c*c)||(c*c==a*a+b*b)||(b*b==a*a+c*c))//判断是否为直角三角形
	{
		if (a*a==b*b+c*c)//判断三边中哪两条边为直角边,并存储到side1和side2中
		{
			side1=b;
			side2=c;
		}else
		{
			if (c*c==a*a+b*b)
			{
				side1=a;
				side2=b;
			}else
			{
				side1=a;
				side2=c;			
			}
		}
		area=side1*side2/2;//计算直角三角形的面积
		cout<<"It is a right-angled triangle and the area is "<<area<<".\n";//输出判断结果及直角三角形面积
	}else
		cout<<"It is not a right-angled triangle.\n";
}
