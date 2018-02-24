//程序11.2 从文件D:\poem.txt读出文本，在显示器上输出。
#include<stdio.h>
#include<stdlib.h>
int main( )
{	
  		char ch;
		FILE *fp;                           //定义文件指针
		fp=fopen("D:\\poem.txt","r");           //以"读"的方式打开文件
		if(!fp)                              //相当于if(fp==0)，判断文件是否正常打开
		{
			printf("file cannot be opened");  
exit(1);
		}
        while((ch=fgetc(fp))!=EOF)	           //如果当前读入的字符不是文件结尾标志
		{
			putchar(ch);                      //输出该字符
		}
        fclose(fp);
		return 0;
}
