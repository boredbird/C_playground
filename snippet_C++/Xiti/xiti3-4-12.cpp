//鸡兔同笼问题。若鸡兔共有100只脚，利用循环计算鸡兔各几只。
#include <iostream.h>
void main()
{ 
	int rabbit,chicken;
	for (rabbit=100/4;rabbit>=0;rabbit--)//兔子最多有25只,最少没有
	{
		chicken=(100-rabbit*4)/2;
		cout<<"兔子有"<<rabbit<<"只,鸡有"<<chicken<<"只"<<endl;
	}
}
