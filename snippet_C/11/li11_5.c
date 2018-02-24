//程序11.5 从学生文件D:\st.rec中读取记录，在显示器上输出
#include<stdio.h>
#include<stdlib.h>                       //包含atof和atol的原型
struct Student		                      //结构定义
{
		long unsigned id;                    //学号
		char name[20];		              //姓名
		double grades;			              //成绩
};
typedef struct Student Student;              //为类型定义别名Student
int main()
{
		Student s;                           //定义一个结构变量
		FILE *fp;                           //定义文件指针
		fp=fopen("D:\\st.rec","rb");             //以读方式打开二进制文件
		if(!fp)                              //相当于if(fp==0)，判断文件是否正常打开
		{
		  printf("file cannot be opened");
exit(1);
		}
		while(fread(&s,sizeof(s),1,fp)==1)       //如果正确读入了一个数据块
			printf("%Ld:  %-10s %g\n",s.id,s.name,s.grades);   //在屏幕上显示记录信息 
  		fclose(fp);                           //关闭文件
		return 0;
}
