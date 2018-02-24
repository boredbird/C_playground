//程序10.10  编写程序complex.c，将所有的命令行参数（不包括命令本身）在屏幕的同一行输出。
#include <stdio.h>
int main(int argc,char **argv)
{
		int i;
		for (i=1;i<argc;i++)
			printf("%8s",argv[i]);
		printf("\n");
		return 0;
}
