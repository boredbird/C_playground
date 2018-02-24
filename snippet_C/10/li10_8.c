//程序10.8 指针数组和二维数组。 
#include<stdio.h> 
int main()
{
	int i,j;
	int* p[4];										//指针数组
	int a[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};		//二维数组
    for (i=0;i<4;i++)
	    p[i]=a[i];		//指针数组的第i个元素指向二维数组的第i个行数组
	for(i=0;i<4;i++)	//用指针数组输出二维数组
	{
		for(j=0;j<3;j++)
			printf("%d\t",p[i][j]);	//p[i][j]=a[i][j]
		printf("\n");
	}
	return 0;
}
