//编写函数，完成指定二维数组（3*3）的转置，即行列对换。
#include <iostream.h>
#include <iomanip.h>
void main()
{	
	int i,j,temp,row=0,colum=0;
	int a[3][3];
	cout<<"输入一个3×3的整型矩阵："<<endl;
	for (i=0;i<=2;i++)				//从第0行~第2行
		for (j=0;j<=2;j++)			//从第0列~第2列
			cin>>a[i][j];			//输入矩阵元素
	
	for (i=0;i<=2;i++)
		for (j=0;j<=i;j++)
		{
			//将a[i][j]与a[j][i]的值互换
			temp=a[i][j];
			a[i][j]=a[j][i];		
			a[j][i]=temp;			
		}
	for (i=0;i<=2;i++)				
	{
		for (j=0;j<=2;j++)			
			cout<<setw(8)<<a[i][j];			//输入矩阵元素
		cout<<endl;
	}
}
