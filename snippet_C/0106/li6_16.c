//程序6.16 用筛选法求n以内的所有质数（n由键盘输入）。
#include <stdio.h>
#include <stdlib.h>
int main( )
{	int i,j,n;
	int *s;                           //定义指针s用来申请动态数组空间           
	do
	{	printf("Please input n:\n");
		scanf("%d",&n);
	}while (n<=0);                    //保证读入一个正整数n
	s=(int*)calloc(n+1,sizeof(int));       //用s申请大小为n+1的动态一维数组空间
	if(s==NULL)			            //如果申请失败
	{
		printf("allocation failure");		//提示：动态分配失败
        exit(1);						//终止程序，控制权交给操作系统
	}
	s[0]=s[1]=1;						//0和1不是质数，元素值修改为1
	for(i=2;i<=n;i++)				    //从2到n筛选
		if(s[i]==0)                   //i是质数，s[i]为筛眼
			for(j=2*i;j<n+1;j=j+i)      //所有s[i]的倍数都不是质数
				s[j]=1;              //元素s[i]的值修改为1
	for (i=0;i<=n;i++)                 //扫描所有的i
		if (!s[i])   printf("%5d",i);      //等效于if(s[i]= =0)，如果i是质数则输出
    printf("\n");
	free(s);							//释放动态数组空间
	return 0;
}
