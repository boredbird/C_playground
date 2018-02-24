#include "stdio.h"
typedef int KeyType;     //重定义关键字类型为整型，也可以为其它类型
typedef struct 
{
   KeyType key;          //关键字域
   //InfoType otherinfo;  //其他的数据域
}LineList;               //线性查找表类型
//直接插入排序函数
void inerSort(LineList R[],int n)
{
    int i,j;
    for(i=2;i<=n;++i)
    if(R[i].key<R[i-1].key)
    {
         R[0].key=R[i].key;
         for(j=i-1;R[0].key<R[j].key;--j)
             R[j+1]= R[j];
         R[j+1]=R[0];
    }
}
main()
{
  LineList R[6];
  int i;
  printf("请输入5个整数:");
  for(i=1;i<=5;i++)
	  scanf("%d",&R[i].key);
  printf("直接插入排序后的结果:");
  inerSort(R,5);//调用直接插入排序函数
  for(i=1;i<=5;i++)
	  printf("%3d",R[i].key);
}
