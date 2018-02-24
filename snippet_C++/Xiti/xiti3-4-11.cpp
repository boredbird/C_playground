//编写程序，由用户输入x值，计算函数值并输出y。函数如下所示：

#include <iostream.h>
void main()
{ 
	int x,y;
	cout<<"Input X(int):";
	cin>>x;
	if (x<0)		//x<0的情况
		y=x;
	else if (x>10)	//x>10的情况
		y=4*x*x*x-x*x;
	else			//其余的情况
		y=x*x;
	cout<<"函数结果y为:"<<y<<endl;
}
