#include "stdio.h"
typedef int KeyType;     //重定义关键字类型为整型，也可以为其它类型
typedef struct 
{
   KeyType key;          //关键字域
   //InfoType otherinfo;  //其他的数据域
}LineList;               //线性查找表类型
//快速排序函数
void QuickSort(LineList R[],int first,int end)
{  int i,j;
   LineList temp;
   i=first;j=end;temp=R[i];R[0]=R[i];     //初始化
   while(i<j)
   {   while(i<j&&R[0].key<=R[j].key)  j--; //从右端开始扫描
       if(i<j){R[i]=R[j];i++;}
       while(i<j&&R[0].key>=R[i].key)   i++; //从左端开始扫描
       if(i<j){R[j]=R[i];j--;}
   } 
   R[i]=R[0];
   if(first<i-1) QuickSort(R,first,i-1); //对左侧分区域进行递归快速排序
   if(i+1<end)  QuickSort(R,i+1,end); //对右侧分区域进行递归快速排序
} 


main()
{
  LineList R[6];
  int i;
  printf("请输入5个整数:");
  for(i=1;i<=5;i++)
	  scanf("%d",&R[i].key);
  printf("快速排序后的结果:");
  QuickSort(R,1,5);//调用快速排序函数
  for(i=1;i<=5;i++)
	  printf("%3d",R[i].key);
}
