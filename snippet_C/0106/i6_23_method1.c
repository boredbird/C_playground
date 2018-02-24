/*程序6.23：数制转换问题。将一个十进制正整数n转为指定的B（B>1）进制数。
方法1-------非递归实现
*/
#include <stdio.h>
void MultiBase(int n,int B);
int main( )              //主函数相同
{
	int n,B;
    do
	{  scanf("%d%d",&n,&B);
	} while (n<0||B<=1);  //保证读入n，B合法
    printf("change result:\n");
    MultiBase(n,B);      //调用函数数制转换
	printf("\n");
	return 0;
}
void MultiBase(int n,int B)  //非递归法数制转换
{
	int m,i=0,a[32]; 
	while(n)			
    {
		a[i++]=n%B;	   //余数作数组元素
		n=n/B;		   //被除数降一阶
	}
	while(i>0)		   //逆序输出数组元素
    {	m=a[--i];
		if(m<10)        //余数<10原样输出
		  printf("%d",m);
		else            //余数>=10输出字符
		  printf("%c",m+55);  
	}	
}
