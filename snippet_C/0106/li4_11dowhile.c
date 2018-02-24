/*程序4.11(方法2)： 按照格里高利公式求π的近似值，
直到最后一个累加项的绝对值小于1E-4。
*/
#include<stdio.h>
#include<math.h>  //含fabs原型
int main(void)
{   
	int sign,i=1;   //i初始化为1
	double item, pi,sum=0;  
	sign=1;               
	do   
	{   
       item=sign*1.0/(2*i-1); 
	   sum=sum+item;	   
       sign=-sign; 
	   i++;
	} while (fabs(item)>=1e-4);  
	pi=4*sum;       		  
	printf("pi=%f\n", pi);   
	return 0;
}  				   

