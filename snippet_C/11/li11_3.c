//程序11.3从文件D:\poem.txt逐行读入文本，在显示器上输出。
#include<stdio.h>
#include<stdlib.h>
int main()
{ 
		char s[256];	                       //256是文件输入缓冲区的长度
		FILE *fp;                           //定义文件指针
		fp=fopen("D:\\poem.txt","r");           //以读的方式打开文件
		if(fp==NULL)		                   //相当于if(fp==0)，判断文件是否正常打开
		{	printf("cannot open file code.txt");
			exit(1);
		}
while((fgets(s,256,fp))!=NULL)         //读入一个字符串，返回值非空时
{			
	printf("%s",s);                   //输出该字符串
}		
		fclose(fp);                          //关闭文件
}

