/*程序4.11（方法1)： 按照格里高利公式求前5001项的累加和作为π的近似值。
用for语句控制循环
*/
#include<stdio.h>
int main(void)
{   
	int sign,i;          //sign表示当前累加项的符号,i表示第几项
	double item, pi,sum=0; //item存当前累加项,sum存放累加和 
	sign=1;             // 第一项为正数,故符号变量赋值为1  
	for(i=1;i<=5001;i++)   //循环5001次
	{   
       item=sign*1.0/(2*i-1); //计算当前累加项,此处要乘1.0得实型结果
	   sum=sum+item;	  //累加当累加项 
       sign=-sign;   	  //改变符号
	}   
	pi=4*sum;       		  //求π
	printf("pi=%f\n", pi);    //输出π
	return 0;
}
