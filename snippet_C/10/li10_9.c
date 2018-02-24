/*程序10.9 通过二级指针变量array申请了row行col列的动态二维数组空间，
二维数组的元素为0~99之间的随机数。最后以矩阵形式输出该动态二维数组。
*/
#include<stdio.h> 
#include<time.h> 
#include<stdlib.h>
int main( )
{	
int i,j,row,col;                   	//定义行、列数变量，从键盘输入更灵活
		int **array;                      	//定义二级指针变量，即指针的指针
		printf("Input row and col\n");
		scanf("%d%d",&row,&col);         	//输入矩阵的行数和列数
		array=(int **)malloc(row*sizeof(int *)); //申请一维指针数组，分量个数=行数
		for (i=0;i<row;i++)                    //利用每一个一级指针元素再申请动态
			array[i]=(int *)malloc(col*sizeof(int)); //一维数组空间，分量个数=列数
		srand(time(0));                       //生成随机种子
		for (i=0;i<row;i++)
			for (j=0;j<col;j++)
				array[i][j]=rand( )%100;	        //调用随机函数为二维数组的元素赋值
		printf("Matrix is:\n");
    	for (i=0;i<row;i++)                    //以矩阵形式输出二维数组
		{
			for (j=0;j<col;j++)
				printf("%6d",array[i][j]);
			printf("\n");
		}
		for (i=0;i<row;i++)                    //首先通过一维指针数组的每个指针元素
			free(array[i]);                     //释放动态二维数组的空间
		free(array);                           //再通过二级指针变量释放动态一维
		return 0;                             //指针数组空间
}
