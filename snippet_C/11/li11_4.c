//程序11.4 从键盘输入一批学生记录，存储到文件D:\st.rec中
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
		char ch,num[20];
		Student s;                           //定义结构变量
		FILE *fp;                           //定义文件指针
		fp=fopen("D:\\st.rec","wb");            //以写入方式打开二进制文件
		if(!fp)                              //相当于if(fp==0)，判断文件是否正常打开
		{
			printf("file cannot be opened");
            exit(1);
  	 	}
		printf("Enter records:\n");
		do
		{
			printf("another(y/n)?");
			ch=getchar( );                    //输入字符y或n
			getchar();                       //跳过回车符
			if(ch=='n')                      //如果输入为n，则结束循环
				break;
			printf("id:    ");                //输入提示：输入学号
			gets(num);				      //按数字串读取1个学生的学号
			s.id=atol(num);		          //atol将数字串转化为长整型
			printf("name:  ");		          //输入提示：输入姓名
			gets(s.name);		              //从终端读取1个学生的姓名
			printf("grades:");		          //输入提示：输入成绩
			gets(num);				      //按数字串读取1个学生的成绩
			s.grades=atof(num);              //atof将数字串转化为双浮点型
			fwrite(&s,sizeof(s),1,fp);          //将当前这条记录s写入到文件中
		}while(1);                          //继续循环
        fclose(fp);
		return 0;
}
