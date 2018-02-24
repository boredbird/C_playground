//copy.c：文件拷贝，带参数的main函数
#include<stdio.h>  
#include<stdlib.h>
int main(int argc,char **argv)
{ 
	
char ch; 
FILE *infile,*outfile;
if(argc!=3)
{	  printf("wrong parameters\n");
    exit(0);
}	
if((infile=fopen(argv[1],"r"))==NULL)
{
	 printf("cannot open infile\n");	
	 exit(0);
}	
if((outfile=fopen(argv[2],"w"))==NULL)
{
	 printf("cannot open outfile\n");
	 exit(0);
	}
	while((ch=fgetc(infile))!=EOF)
	{ 
		fputc(ch,outfile);	
	}
	fclose(infile);
	fclose(outfile); 
	return 0;
}
