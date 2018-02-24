//程序10.1 将如下所示的矩阵存入二维数组，然后照原样输出，最后按转置形式输出
#include<stdio.h>
int main( )
{
		int a[4][3]={0};                 //定义二维数组并初始化
		int r,c;                         //定义两个控制变量，控制行号和列号
		for (r=0;r<4;r++)
			for (c=0;c<3;c++)
				a[r][c]=5*r+c;          //根据元素与行列号之间的规律计算并赋值
		printf("the original matrix is:\n");   //输出原始矩阵
    	for (r=0;r<4;r++)                //行号变化作为外层循环
		{
			for (c=0;c<3;c++)           //列号变化作为内层循环
				printf("%d\t",a[r][c]);    //输出元素
			printf("\n");                //一行结束后输出换行符
		}
   		printf("the transposed matrix is:\n");
		for(c=0;c<3;c++)		          //列号变化作为外层循环
		{
			for(r=0;r<4;r++)		      //行号变化作为内层循环
				printf("%d\t",a[r][c]);     //输出元素
			printf("\n");                 //一行结束后输出换行符
		}
		return 0;
}

