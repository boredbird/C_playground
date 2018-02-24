#include "stdio.h"
typedef int KeyType;     //重定义关键字类型为整型，也可以为其它类型
typedef struct 
{
   KeyType key;          //关键字域
   //InfoType otherinfo;  //其他的数据域
}LineList;               //线性查找表类型
//直接选择排序函数
void selectSort(LineList R[],int n)
{  int i,j,index;
   for(i=1;i<n;++i)
   {  index=i;
      for(j=i+1;j<=n;++j)
       if(R[j].key<R[index].key)  index=j;
        if(index!=i)
        {R[0]=R[i];R[i]=R[index];R[index]=R[0];}
   } 
} 

main()
{
  LineList R[6];
  int i;
  printf("请输入5个整数:");
  for(i=1;i<=5;i++)
	  scanf("%d",&R[i].key);
  printf("直接选择排序后的结果:");
  selectSort(R,5);//调用直接选择排序函数
  for(i=1;i<=5;i++)
	  printf("%3d",R[i].key);
}
