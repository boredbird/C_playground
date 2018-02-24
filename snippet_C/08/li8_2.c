//程序8.2从键盘上输入3个学生记录，并在屏幕输出。

#include<stdio.h>
struct Student									//定义学生结构，嵌套结构的定义
{
		long unsigned id;						//学号
		double grades;							//成绩
}; 
typedef struct Student Student;					//定义学生类型的别名
int main( )
{
		int i;
		Student sa[3];
		printf("Enter 3 records:\n");
		for(i=0;i<3;i++)						//输入3个学生的各项信息
		{	
			scanf("%Lu%Lf",&sa[i].id,&sa[i].grades);
		}
		for(i=0;i<3;i++)						//输出3个学生的各项信息
		{
			printf("%Lu:%g\n",sa[i].id,sa[i].grades);
		}
		return 0;
}


