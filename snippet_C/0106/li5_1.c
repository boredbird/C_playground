/*测试程序5.1  首先测试变量x、m和n的地址：
*/
	#include <stdio.h>
int main()
{  
       int n,m;							
	   double x;							
	   printf("%x,%x,%x\n",&x,&m,&n);	//输出变量n、m和x的地址

/* 此处为后增加的测试语句
		*(double*)0x13ff70=3.1415;			//相当于x=3.1415;
		*(int*)0x13ff7c=5;					//相当于n=5; 
		*(int*)0x13ff78=*(int*)0x13ff7c;		//相当于m=n;
		printf("n=%d,m=%d,x=%f\n",n,m,x);	//输出变量n、m和x的值，检验结果

*/

	   return 0;
} 
