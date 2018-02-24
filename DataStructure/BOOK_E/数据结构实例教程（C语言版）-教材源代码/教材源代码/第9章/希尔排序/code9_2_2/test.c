#include "stdio.h"
typedef int KeyType;     //重定义关键字类型为整型，也可以为其它类型
typedef struct 
{
   KeyType key;          //关键字域
   //InfoType otherinfo;  //其他的数据域
}LineList;               //线性查找表类型
//希尔排序函数
void shellSort(LineList R[],int n)
{
    int i,j,d;
    d=n/2;//初始步长为表长的一半
    while(d>0)//直到d为1
    {
        for(i=d+1;i<=n;++i)//对每组进行直接插入排序
        if(R[i].key<R[i-d].key)
        {  
            R[0].key=R[i].key;
            for(j=i-d;j>0&&R[0].key<R[j].key;j=j-d)
              R[j+d]=R[j];
            R[j+d]=R[0];
        }
        d=d/2;//缩小步长值
	}
}

main()
{
  LineList R[6];
  int i;
  printf("请输入5个整数:");
  for(i=1;i<=5;i++)
	  scanf("%d",&R[i].key);
  printf("希尔排序后的结果:");
  shellSort(R,5);//调用希尔排序函数
  for(i=1;i<=5;i++)
	  printf("%3d",R[i].key);
}
