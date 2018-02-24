/*程序10.3 把二维数组当作一维数组输出。*/
#include<stdio.h> 
int main( )
{
		int i;
		int a[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
		for(i=0;i<12;i++)
		{
			printf("%d\t",a[0][i]);
			if((i+1)%3==0)		//一行输出3个数据后换行
				printf("\n");
		}
        return 0;
}

