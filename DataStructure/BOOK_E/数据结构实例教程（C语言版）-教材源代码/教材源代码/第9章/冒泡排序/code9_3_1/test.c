#include "stdio.h"
typedef int KeyType;     //重定义关键字类型为整型，也可以为其它类型
typedef struct 
{
   KeyType key;          //关键字域
   //InfoType otherinfo;  //其他的数据域
}LineList;               //线性查找表类型
//冒泡排序函数
void BubbleSort(LineList R[],int n)
{ int i,j;
   for(i=1;i<n;i++)               //i为比较趟数
     for(j=1;j<=n-i;j++)            //一趟交换排序
	    if(R[j].key>R[j+1].key)     //若逆序
       {R[0]=R[j];R[j]=R[j+1];R[j+1]=R[0];}//用R[0]最为中间变量实现交换
}

main()
{
  LineList R[6];
  int i;
  printf("请输入5个整数:");
  for(i=1;i<=5;i++)
	  scanf("%d",&R[i].key);
  printf("冒泡排序后的结果:");
  BubbleSort(R,5);//调用冒泡排序函数
  for(i=1;i<=5;i++)
	  printf("%3d",R[i].key);
}
