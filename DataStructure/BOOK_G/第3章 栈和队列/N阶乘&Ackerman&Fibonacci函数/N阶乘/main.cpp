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
	printf("����n��ֵ�� \n");
	scanf("%d",&n);
	b=a(n);
	printf("%d\n",b);
	printf("���������...'q'���˳�! \n");
	getchar();
	select=getchar();
	}while(select!='q');
}
