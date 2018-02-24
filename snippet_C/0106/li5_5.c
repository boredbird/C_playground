//程序5.6 同一段空间，可以用作不同类型的数组空间示例。
#include <stdio.h>
int main( )
{
	double d[2];                //定义长度为2的双浮点型数组d
	int *pi=(int*)d;             //通过强制类型转换将double地址赋值给整型指针
	// int *pi= (int)d[0];
	printf("d=%x\n",d); 
	printf("pi=%x\n",pi); 
	printf("d+1=%x\n",d+1); 
	printf("pi+1=%x\n",pi+1); 

    d[0]=2.125;                //通过双浮点型指针d访问双浮点型数组空间
	d[1]=3.625;			      
	printf("%g\t%g\n",d[0],d[1]);  //输出两个双浮点数组元素的值
	pi[0]=17;                  //通过整型指针访问整型数组空间，长度为2的双浮
	pi[1]=29;	                  //点型数组空间可以用做长度为4的整型数组空间
	printf("%d\t%d\n",pi[0],pi[1]) ; //输出前两个整型元素 
	printf("%g\t%g\n",d[0],d[1]);   //输出两个双浮点数组元素的值
	
	scanf("%d");
	return 0;
}

