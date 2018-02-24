/*程序10.6  寻找矩阵中的马鞍点。一个矩阵中的元素，
若在它所在的行中最小，在它所在的列中最大，则称为马鞍点。
求一个n*m阶矩阵的所有马鞍点。
*/
#include<stdio.h>
#include<stdlib.h>                         //exit函数声明在该文件中
void MinMax(int* p,int n,int m);	            //求马鞍点，一级指针形参、行数、列数
int main( )
{
		int a[3][5]={{6,3,5,3,4},{4,3,4,3,4},{5,2,4,2,5}};	
		MinMax(a[0],3,5);					   //调用函数计算马鞍点,a[0]还可以是*a
   		return 0;                            //或&a[0][0]，初始化一级指针形参p
}                                           
void MinMax(int* pa,int n,int m)			   //求马鞍点
{
		int i,j,*min,*max;
		min=(int *)malloc(n*sizeof(int));		   //建立动态一维数组min，行数个元素
		max=(int *)malloc(m*sizeof(int));	       //建立动态一维数组max，列数个元素
		if(min==NULL||max==NULL)
		{
			printf("allocation failure");		   //错误提示：动态分配失败
			exit(1);						   //终止程序，控制权交给操作系统
		}
		for(i=0;i<n;i++)					   //将每行最小数据元素存入min
		{
			min[i]=pa[i*m];                   //min[i]的初值等于数组 i行0列元素
			for(j=1;j<m;j++)                 //列号从1列到m-1列循环
				if(pa[i*m+j]<min[i])          //比较i行j列元素是否小于min[i]
					min[i]=pa[i*m+j];        //如果小于min[i]，则赋值给min[i]
		}
		for(j=0;j<m;j++)					  //将每列最大数据元素存入max
		{
			max[j]=pa[0*m+j];               //max[j]的初值等于数组j列0行元素
		for(i=1;i<n;i++)                     //行号从1行到m-1行循环
			if(pa[i*m+j]>max[j])             //比较i行j列元素是否大于max[j]
				max[j]=pa[i*m+j];           //如果大于max[j]，则赋值给max[j]
		}
		for(i=0;i<n;i++)    			      //输出矩阵元素，马鞍点元素加小括号
		{
			for(j=0;j<m;j++) 
				if(min[i]==max[j])           //由等式min[i]==max[j]确定马鞍点,并输出
					printf("(%d)\t",pa[i*m+j]); //加小括号输出马鞍点元素
				else
					printf("%d\t",pa[i*m+j]);  //不是马鞍点的元素不加括号输出
			printf("\n");                     //换行
		}
		free(min);				          //释放动态数组空间
		free(max);
}
