#include "stdio.h"
typedef int KeyType;     //重定义关键字类型为整型，也可以为其它类型
typedef struct 
{
   KeyType key;          //关键字域
   //InfoType otherinfo;  //其他的数据域
}LineList;               //线性查找表类型
//筛选算法
void sift(LineList r[],int k,int m)
{//要筛选结点的编号为k，堆中最后一个结点的编号为m
	int i,j;
	LineList x;
	i=k;x=r[i];j=2*i;//将筛选记录暂存x中
	while(j<=m)
	{  
		if((j<m)&&(r[j].key>r[j+1].key))
			j++;                  //左右孩子中小的为r[j]
		if(x.key>r[j].key)
		{  
			r[i].key=r[j].key;
			i=j;    
			j*=2;   
		}
		else j=m+1;
	}
	r[i]=x; //将筛选记录移到正确位置
} 
//堆排序算法
void heapsort(LineList r[],int n)//对r[1]到r[n]进行堆排序
{  int i;
   LineList x;
   for(i=n/2;i>=1;i--)//初建堆
      sift(r,i,n);
   for(i=n;i>=2;i--)//进行n-1趟堆排序
   {  x=r[1];
      r[1]=r[i];
      r[i]=x;
      sift(r,1,i-1);
   }
}

main()
{
  LineList R[6];
  int i;
  printf("请输入5个整数:");
  for(i=1;i<=5;i++)
	  scanf("%d",&R[i].key);
  printf("堆排序后的结果:");
  heapsort(R,5);//调用堆排序函数
  for(i=5;i>=1;i--)
	  printf("%3d",R[i].key);
}
