/*程序6.23：数制转换问题。将一个十进制正整数n转为指定的B（B>1）进制数。
方法2-------递归实现
*/
#include <stdio.h>
void MultiBase(int n,int B);
int main( )                //主函数相同
{
	int n,B;
	do
	{	scanf("%d%d",&n,&B);
	}while (n<0||B<=1);
	printf("change result:\n");
    MultiBase(n,B);      //调用函数数制转换
	printf("\n");
	return 0;
}
void MultiBase(int n,int B)  //递归法数制转换
{
	int m; 
	if(n)		           //n!=0则递归调用
    {
	   MultiBase(n/B,B);  //递归时第1参数变
	   m=n%B;         //求本层的余数
	   if(m<10)         //余数<10原样输出
	   	  printf("%d",m);
	   else             //余数>=10输出字符
		  printf("%c",m+55); 			
	}	
}
