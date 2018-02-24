/*程序6.17 约瑟夫环（Josephus）问题：n个人围坐一圈，
从某个人开始从1开始报数，沿顺时针方向数到m的人被淘汰。
然后再从1开始报数，数到m时再淘汰一人。重复上述过程，直到剩下1人为止。
剩下这个人是获胜者。
*/
#include <stdio.h>
#include <stdlib.h>
int main( )
{ 	int i,j,n,m,*pa;	
	printf("Input n and m:\n");
		scanf("%d%d",&n,&m);       //读入人数n和报数m
	pa=(int*)malloc(n*sizeof(int));	   //申请动态数组空间
	if(pa==NULL)                   //如果申请失败
	{	printf("allocation failure\n");    //输出提示信息
		exit(1);                     //结束程序的运行
	}
	for(i=0;i<n;i++)                 //pa[0]到pa[n-1]的值依次为1至n
 		pa[i]=i+1;
	i=0;		                      //从第一个人开始报数	
	while(n>1)					  //循环的条件是总人数超过1个
	{ 	i=(i+m-1)%n;               //计算被淘汰者的下标
	    printf("%-4d",pa[i]);		  //输出被淘汰者
		for(j=i+1;j<n;j++)			  //将被淘汰者从数组中删除
	      pa[j-1]=pa[j];
		n--;						  //人数减1
		if(i==n)					  //如果删除的是数组最后一个数据元素
			i=0;					  //则从头开始数
   	}
	printf("\nthe winner is:%d\n",pa[0]); //输出获胜者
	free(pa);                       //释放动态数组空间
	return 0;
}
