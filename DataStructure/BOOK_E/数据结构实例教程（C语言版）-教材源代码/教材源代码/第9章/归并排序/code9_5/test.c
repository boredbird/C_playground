#include "stdio.h"
#define M  5
//两个有序序列合成一个有序序列
void Merge(int r[],int r1[],int s,int m,int t)
{   
	int i,j,k;
	i=s;j=m+1;k=s;
    while(i<=m&&j<=t)
    { 
		if(r[i]<=r[j]) r1[k++]=r[i++];
		else r1[k++]=r[j++];
    }
    if(i<=m)
		while(i<=m)  r1[k++]=r[i++];//收尾处理,前一个子序列
	if(j<=t)
		while(j<=t)  r1[k++]=r[j++];//后一个子序列
}

//二路归并算法
void MergeSort(int r[],int r1[],int r2[],int s,int t)  
{  
	if(s==t)  
		r1[s]=r[s];  
	else  
	{  
		int m;  
		m=(s+t)/2;  
		MergeSort(r,r2,r1,s,m);        //归并排序前半个子序列    
        MergeSort(r,r2,r1,m+1,t);      //归并排序后半个子序列  
        Merge(r2,r1,s,m,t);            //将两个已排序的子序列归并  
	}  
}   
main()
{
  int r[M],r1[M],r2[M];
  int i;
  printf("请输入5个整数:");
  for(i=0;i<M;i++)
	  scanf("%d",&r[i]);
  printf("归并排序后的结果:");
  MergeSort(r,r1,r2,0,M-1);//调用二路归并算法
  for(i=0;i<M;i++)
	  printf("%3d",r1[i]);
}
 
  

 
 