//程序11.7  将文本文件D:\poem.txt中的小写字母改为大写字母。
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{	
        char ch;
		FILE *fp;
		fp=fopen("D:\\poem.txt","r+");           //以读写方式打开一个文本文件
		if(!fp)
		{
			printf("file cannot be opened"); 
            exit(1);
		}
		while((ch=fgetc(fp))!=EOF)		 
		{
			if(islower(ch))
			{
				ch=toupper(ch);
				fseek(fp,-1L,1);	//从当前位置向前移一个字节到刚才读取字符的位置
				fputc(ch,fp);      //改写文件内容
			}
		}
		fclose(fp);
		return 0;
}
