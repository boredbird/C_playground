#include<iostream.h>
void func(int x,int y=1,int z=0);//函数声明
int main()
{
		func(2,3,4);
		func(2,3);		//相当于func(2,3,0);
		func(2);		//相当于func(2,1,0);
		return 0;
}
void func(int x,int y,int z)//函数定义
{
		cout<<x<<" "<<y<<" "<<z<<endl;
}
