/*
程序11.1 从键盘输入一段文本，存储到文本文件D:\poem.txt中。
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{	
  		char ch;
		FILE *fp;                           //定义文件指针
		fp=fopen("D:\\poem.txt","w");          //以"写"的方式打开文件
		if(!fp)			                   //相当于if(fp==0)，判断文件是否正常打开
		{
			printf("file cannot be opened");	   
exit(1);
		}
		printf("Enter a text (to end with '#'):\n");   //输入提示。输入一段文本（以#结束）：
		ch=getchar();                        //读入第一个字符
		while(ch!='#')                       //条件判断，如果不是#就写字符入文件
		{
			fputc(ch,fp);                     //将刚读入的字符写入文件
			ch=getchar();                    //继续读下一个字符
		}
		fclose(fp);                           //关闭文件
		return 0;
}
