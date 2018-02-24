//（3）编写程序输入一个华氏温度，将其转换为摄氏温度并输出。
#include <iostream.h>
void main()
{ 
	float C;			//变量C为摄氏温度
	float F; 			//变量F为华氏温度
 
	cout<<"请输入华氏温度(float类型):\n";
	cin>>F;				//输入华氏温度
	C=(F-32)*5/9;		//华氏温度转换为摄氏度
	cout<<"转换为摄氏温度为 "<<C<<endl;
}
