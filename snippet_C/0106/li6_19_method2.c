/*程序6.19  用折半查找方法在元素从小到大排列的有序数组中寻找特定的元素是否存在。分别用两种方法实现：
方法1，若找到此元素，则返回其在数组中的下标，这是值返回；
方法2，若找到此元素，则返回其所在的地址，这是地址返回。
这是方法2------地址返回
*/
#include <stdio.h>
int* BiSearch(int* pa,int n,int item); //返回地址
int main( )
{
	int a[10]={1,3,34,45,56,67,78,89,90,99};
	int x,*pos;
	printf("Input x be searched:\n");
	scanf("%d",&x);
	pos=BiSearch(a,10,x);
	if (pos!=NULL)
		printf("pos=%d\n",pos-a);
	else
		printf("Not found!\n");
	return 0;
}
int* BiSearch(int* pa,int n,int item) //返回地址
{
	int low=0,high=n-1,mid;		 //（1）
	while(low<=high)				
	{
		mid=(low+high)/2;		 //（2）
		if(item==pa[mid])		 //（3）
			return(&pa[mid]);  //返回地址
		else
			if(item<pa[mid])
				high=mid-1;		
			else
				low=mid+1;		
	}
	return NULL;				 //（4）
}
