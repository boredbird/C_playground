#include <stdio.h> 

#define COL 10 //һ�����10�� 
long scan() 
{ //������fibonacci�����ĵ�N�� 
	int n; printf("Input the N = "); 
	scanf("%d",&n); return n;
} 

long fibonacci(int n) 
{ //fibonacci�����ĵݹ麯�� 
	if (0==n||1==n) {
		//fibonacci�����ݹ�ĳ���
		return 1; }
	else {
		return fibonacci(n-1)+fibonacci(n-2); //�����ݹ�������ֱ���������ڴ��ٷ��ؾ��ܼ������n���ֵ 
	}
 } 
int main(void) 
{ 
	char select;
	int i,n; 
	do{
		n = scan(); 
	printf("Fibonacci���е�ǰ%d��\n", n); 
	for (i=0; i<n;) //���fibonacci����ǰn��ÿ���ֵ 
	{ 
		printf("%-10ld",fibonacci(i++)); //���õݹ麯�����Ҵ�ӡ������ֵ 
	if(i%COL==0) 
	{ //����COLȡ�����0�ͻ��У�Ҳ���ǿ���ÿ��������ٸ��� 
	  //��COL=10����ÿ�����10��
		printf("\n"); 
	} 
	}
	printf(" \n���������...'q'���˳���\n");
	getchar();
	select = getchar();
	}while(select!='q');
	printf("\n"); 
	return 0; 
} 
