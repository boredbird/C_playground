//li11_8.c：文件拷贝，不带参数的main函数
#include<stdio.h>  
#include<stdlib.h>
int main( )
{ 
	char sFile[20],dFile[20];
	char ch; 
	FILE *infile,*outfile;
	printf("input source file name:\n");
gets(sFile);   //输入源文件名
printf("input destination file name:\n");
gets(dFile);   //输入目标文件名
	if((infile=fopen(sFile,"r"))==NULL)
	{
		printf("cannot open infile\n");	
		exit(0);
	}
	if((outfile=fopen(dFile,"w"))==NULL)
	{
		printf("cannot open outfile\n");
		exit(0);
	}
	while((ch=fgetc(infile))!=EOF) //核心操作
	{ 
		fputc(ch,outfile);	
	}
	fclose(infile);
	fclose(outfile);
	return 0;
}
