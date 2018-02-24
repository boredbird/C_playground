/*程序5.9 从键盘上输入n(1≤n≤10)个整数作为数组a的元素值，
再读入一个待查找的整数x，在a数组中查找x，如果存在输出它的下标，否则提示："Not present!"。
*/
#include <stdio.h>
int main()
{
	int a[10],i=0,*p,n,x;                   
	do						//保证读入的n满足1≤n≤10
	{	printf("Please input n(1<=n<=10):\n");
		scanf("%d",&n);
	}while (n<1||n>10);
	printf("Please input %d elements:\n",n);
	for (p=a;p<a+n;p++)		//用移动指针的方法读入数组元素   
		scanf("%d",p);  
	printf("Please input x be searched:\n",n);
	scanf("%d",&x);
    p=a; 					//这条语句一定要有，使p回到数组开头
	while(i<n)				//循环条件为：如果未找到且未搜索完元素
	{
		if (x==*(p+i))			//如果查找成功，i的值正好是元素下标
			break;
		i++;                            
	}
    if(i<n)	                 
		printf("value=%d, index=%d\n",x,i);
	else
		printf("Not present!\n");
	return 0;
}
