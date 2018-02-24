/*程序5.11  整型数组a中有若干个元素，再读入一个待删除的整数x，
删除数组中第一个等于x的元素，如果x不是数组中的元素，则显示："can not delete x!"。
*/

#include <stdio.h>
int main( )
{
	int a[5]={23,45,34,12,56};            //初始化数组
	int i,j,x;
	printf("Please input x be deleted:\n");
	scanf("%d",&x);                    //读入待删除的x
	for (i=0;i<5&&a[i]!=x;i++) ;          //查找x是否存在，此处循环体为空语句
		if (i==5)                      //循环停止时如果i==5，则说明元素不存在
		{
			printf("can not delete x!\n");
		return 0;                      //if分支的最后一句为return，可省略对应else
	}
	for (j=i;j<5-1;j++)                  //此处的隐含条件是i<5&&a[i]= =x;
		a[j]=a[j+1];	                 //前移覆盖i下标的元素

    printf("The new array is:\n");
	for (i=0;i<4;i++)                    //输出删除以后的序列
		printf("%5d",a[i]);
	printf("\n");

	printf("%5d",a[4]);
	scanf("%d");
	return 0;
}