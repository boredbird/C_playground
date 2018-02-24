/*程序10.5 将给定矩阵按转置形式输出。*/
#include<stdio.h>
void Display(int (*pa)[3],int row)	     //矩阵转置输出的函数
{ 
		int r,c;
		for(c=0;c<3;c++)		         //输出不同列的元素
		{
			for(r=0;r<row;r++)	         //输出不同行的元素
				printf("%d\t",pa[r][c]);
			printf("\n");                //换行
		}
}
int main()
{	int a[4][3]={{0,1,2},{5,6,7},{10,11,12},{15,16,17}};
		Display(a,4);                   //调用时用二维数组名a初始化行指针变量pa
		return 0;
}
