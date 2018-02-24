#include<iostream.h>
int main()
{	int a=12345;
	double x=1234.56789;
	cout<<a<<endl;//默认左对齐
	cout.width(12); //宽度12，默认右对齐
	cout<<a<<endl;
	cout.fill('*');//星号填充
	cout.setf(ios::left,ios::adjustfield);//左对齐
	cout.width(12);
	cout<<a<<endl;
	cout.setf(ios::right,ios::adjustfield);//右对齐
	cout.width(12);
	cout.precision(7);//整数加小数共7位
	cout<<x<<endl;
	return 0;
}
