/*程序9.3 按字符串的形式输入若干学生的记录的各个成员，
进行相应转换后存储，最后再输出各学生记录。
*/
#include<stdio.h>
#include<stdlib.h>	               //包含atof和atol的原型
struct Student		               //结构定义
{
		long unsigned id; 		        //学号
		char name[20];		        //姓名
		double grades;			        //成绩
};
typedef struct Student Student;
void Input(Student* pa,int n);		    //从键盘输入记录
void Output(const Student* pa,int n);  //在显示器输入记录
int main( )
{
		Student sa[3];
		printf("Enter 3 records:\n");	    //输入提示
		Input(sa,3);                   //第一实参为结构数组
		printf("Display 3 records:\n");	//输出提示
		Output(sa,3);
   		return 0;
}
void Input(Student* pa,int n)         //第一形参为结构指针，用来接受结构数组地址
{
		int i;
		char num[20];                 //定义一个字符数组用于输入
		for(i=0;i<n;i++)               //循环控制，依次输入n个元素的值
		{
			printf("id:    ");          //输入提示：输入学号
			gets(num);			    //按数字串读取第i+1个学生的学号
			pa[i].id=atol(num);		    //atol将数字串转化为长整型值赋给id成员
			printf("name:  ");		    //输入提示：输入姓名
			gets(pa[i].name);		    //从终端读取第i+1个学生的姓名
			printf("grades:");		    //输入提示：输入成绩
			gets(num);			    //按数字串读取第i+1个学生的成绩
			pa[i].grades=atof(num);     //atof将数字串转化为双浮点型
		}
}
void Output(const Student* pa,int n)
{	int i;
		for(i=0;i<n;i++)		        //输出结构数组每一个元素各个成员的值
			printf("%Ld: %-10s %g\n",(pa+i)->id,(pa+i)->name,(pa+i)->grades);
}
