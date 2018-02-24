/*
程序8.3 用结构嵌套定义一个学生结构，从键盘上输入3个学生记录，并在屏幕输出。
问题分析：根据前面的描述，学生结构中嵌套了日期结构，应当先定义日期结构，再用日期结构变量作为学生结构的成员来使用。主函数中显然通过定义学生结构数组来存储3个学生的完整信息。
*/
#include<stdio.h>
struct Date				                   //定义日期结构
{
		int yr,mo,da;
};
typedef struct Date Date;                       //定义类型别名
struct Student			                       //定义学生结构，嵌套结构的定义
{
		long unsigned id;	                       //学号
		double grades;		                       //成绩
		Date dt;			                       //入学日期dt是结构类型Date型变量
}; 
typedef struct Student Student;                  //定义学生类型的别名
int main( )
{
		int i;
		Student sa[3];
		printf("Enter 3 records:\n");
		for(i=0;i<3;i++)                           //输入3个学生的各项信息
		{	
scanf("%Lu%Lf",&sa[i].id,&sa[i].grades);
			scanf("%d/%d/%d",&sa[i].dt.yr,&sa[i].dt.mo,&sa[i].dt.da);
		}
		for(i=0;i<3;i++)		                    //输出3个学生的各项信息
		{
			printf("%Lu:%g",sa[i].id,sa[i].grades);
			printf("(%d/%d/%d)\n",sa[i].dt.yr,sa[i].dt.mo,sa[i].dt.da);
		}
		return 0;
}	
