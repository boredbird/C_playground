//程序11.6  格式读写示例，从磁盘文件D:\st.txt读入数据，然后在显示器上输出。
#include<stdio.h>
#include<stdlib.h>                       //包含exit的原型
struct Student		                      //结构定义
{
		long unsigned id;                    //学号
		char name[20];		              //姓名
		double grades;			              //成绩
};
typedef struct Student Student;             //为类型定义别名Student
int main()
{
Student s;
		FILE *fp;
		fp=fopen("D:\\st.txt","r");             //以只读方式打开文本文件
		if(!fp)
		{
			printf("file cannot be opened");
            exit(1);
		}	
		fscanf(fp,"%Ld%s%Lf",&s.id,&s.name,&s.grades); //从文件中按格式读入一条记录
		while (!feof(fp))                     //若文件未结束
		{
			fprintf(stdout,"%Ld:%-10s %g\n",s.id,s.name,s.grades);  //输出记录
			fscanf(fp,"%Ld%s%Lf",&s.id,&s.name,&s.grades);   //读入下一记录
		}
		fclose(fp);                          //关闭文件
		return 0;
}
