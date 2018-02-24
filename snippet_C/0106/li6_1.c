//程序6.1 对数组的元素累计求和。
#include<stdio.h>
int main( )	               //对数组元素累计求和
{	
int a[6]={10,11,12,13,14,15}, i,s=0;
		for(i=0;i<6;i++)		   //累计求和
			s=s+a[i];  		
		printf("sum=%d\n",s);
		
		scanf("%d");
        return 0;
}
