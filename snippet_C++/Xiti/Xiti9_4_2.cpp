#include<iostream.h>
template<class T>						//定义二分查找函数模板
int find(T data[],int length,T object)	//数组data 为有序数组，length 为数组长度，object 为待查找元素
{
	int max,min,mid;
	min=0;
	max=n-1;
	while(min<=max)
	{
		mid=(min+max)/2;
		if(object==data[mid])
			return mid;
		else if(object>data[mid])
			min=mid+1;
		else
			max=mid-1;
	}
	return -1;
}
int const n=5;
void main()
{
	int i;						//i为下标
	int f1,a[n],x1;				//int型测试所需数据
	int f2;						//char型测试所需数据
	char b[n];
	char x2;
	int f3;						//double型测试所需数据
	double c[n];
	double x3;
	cout<<"请输入"<<n<<"个依次增大的整数"<<endl;			//用int型进行测试
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"请输入一个要查找的整数:"<<endl;
	cin>>x1;
	f1=find(a,n,x1);										//函数模板实例化
	if(f1==-1)
		cout<<"查找"<<x1<<"失败"<<endl;
	else
		cout<<"查找"<<x1<<"成功"<<"下标为"<<f1<<endl;
	cout<<"请输入"<<n<<"个依次增大的字符"<<endl;			//用char型进行测试
	for(i=0;i<n;i++)
		cin>>b[i];
	cout<<"请输入一个要查找的字符:"<<endl;				
	cin>>x2;
	f2=find(b,n,x2);										//函数模板实例化
	if(f2==-1)
		cout<<"查找"<<x2<<"失败"<<endl;
	else
		cout<<"查找"<<x2<<"成功"<<"下标为"<<f2<<endl;
	cout<<"请输入"<<n<<"个依次增大的双精度浮点型数据"<<endl;//用double型进行测试
	for(i=0;i<n;i++)
		cin>>c[i];
	cout<<"请输入一个要查找的双精度浮点型数据:"<<endl;
	cin>>x3;
	f3=find(c,n,x3);										//函数模板实例化
	if(f3==-1)
		cout<<"查找"<<x3<<"失败"<<endl;
	else
		cout<<"查找"<<x3<<"成功"<<"下标为"<<f3<<endl;

}
