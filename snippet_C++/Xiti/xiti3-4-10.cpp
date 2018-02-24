//编写程序，输入年月日信息，并输出这一天为这一年的第几天，注意闰年问题。

#include <iostream.h>
void main()
{ 
	int year,month,day;
	int num=0;
	int length;
	cout<<"Input year:";
	cin>>year;
	cout<<"Input month:";
	cin>>month;
	cout<<"Input day:";
	cin>>day;
	for (int i=1;i<month;i++)
	{
		if ((i==1)||(i==3)||(i==5)||(i==7)||(i==8)||(i==10)||(i==12))//大月31天
			length=31;
		else if ((i==4)||(i==6)||(i==9)||(i==11))//小月30天
			length=30;
		else if (((year%100==0)&&(year%4==0))||((year%100!=0)&&(year%4==0)))//闰年判断条件
			length=29;//闰年的二月29天
		else
			length=28;//非闰年的二月28天
		num+=length;
	}
	num+=day;
	cout<<year<<"年"<<month<<"月"<<day<<"日为这一年的第:"<<num<<"天."<<endl;
}
