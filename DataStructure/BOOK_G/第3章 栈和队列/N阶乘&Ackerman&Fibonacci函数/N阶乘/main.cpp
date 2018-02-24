#include<stdio.h>

int a(int n)
{
	int b=1;
	if(n>=1)
	b=n*a(n-1);
	return b;
}

void main()
{
	int n,b;
	char select;
	do{
	printf("输入n的值： \n");
	scanf("%d",&n);
	b=a(n);
	printf("%d\n",b);
	printf("任意键继续...'q'：退出! \n");
	getchar();
	select=getchar();
	}while(select!='q');
}
