#include <stdio.h> 

#define COL 10 //一行输出10个 
long scan() 
{ //输入求fibonacci函数的第N项 
	int n; printf("Input the N = "); 
	scanf("%d",&n); return n;
} 

long fibonacci(int n) 
{ //fibonacci函数的递归函数 
	if (0==n||1==n) {
		//fibonacci函数递归的出口
		return 1; }
	else {
		return fibonacci(n-1)+fibonacci(n-2); //反复递归自身函数直到碰到出口处再返回就能计算出第n项的值 
	}
 } 
int main(void) 
{ 
	char select;
	int i,n; 
	do{
		n = scan(); 
	printf("Fibonacci数列的前%d项\n", n); 
	for (i=0; i<n;) //输出fibonacci函数前n项每项的值 
	{ 
		printf("%-10ld",fibonacci(i++)); //调用递归函数并且打印出返回值 
	if(i%COL==0) 
	{ //若对COL取余等于0就换行，也就是控制每行输出多少个， 
	  //而COL=10就是每行输出10个
		printf("\n"); 
	} 
	}
	printf(" \n任意键继续...'q'：退出！\n");
	getchar();
	select = getchar();
	}while(select!='q');
	printf("\n"); 
	return 0; 
} 
