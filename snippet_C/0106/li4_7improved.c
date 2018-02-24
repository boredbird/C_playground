/*程序4.7 从键盘输入一个正整数m，判断m是否为质数，输出判断结果。
  改进版:用do~while语句使得读入的m一定是正整数,改进原来读入的m不是正整数时直接给出错误提示
*/

#include<stdio.h>
#include<math.h>					
int main(  )
{
	int m,i,k,prime=1;				
	do
	{	
		printf("Please input a data>0:\n");
		scanf("%d",&m);                 
	} while (m<=0);    //保证读入的m一定大于0
	if (m==1)	
		prime=0;			
	k=(int)sqrt(m);	i=2;
	while(prime&&i<=k) 
		if (m%i++==0)  		    
			prime=0; 
	 if (prime)                      
		printf("%d is a prime\n",m);
	else 
		printf("%d is not a prime\n",m);
	return 0;
}
