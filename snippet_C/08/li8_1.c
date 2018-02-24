/*程序8.1:结构变量成员的引用示例*/
#include<stdio.h>
struct Student			        //表示学生信息的结构
{
    long unsigned id;          //学号
    float grades;		        //成绩
};

struct Date		            //表示日期的结构
{
		int yr,mo,da;
};

typedef struct Student Student;   //用typedef为类型定义别名
typedef struct Date Date;

int main( )
{
		Student st={2005065, 98.5};										
		Date dt={2005,8,16};
		st.grades=90.5f;			//修改成绩
		dt.yr=2008;				//修改年份
		printf("%Ld\n%g\n",st.id,st.grades);	  //输出学生的学号和分数
		printf("%d/%d/%d\n",dt.da,dt.mo,dt.yr);  //输出日期
        return 0;
}
