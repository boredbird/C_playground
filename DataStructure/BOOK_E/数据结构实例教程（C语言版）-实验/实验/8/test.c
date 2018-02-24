//求二维数组元素在内存中的存储位置
//假设二维数组10行10列,下标从0开始
#include "stdio.h"
main()
{
  int loc_a00;//元素占用内存中一维数组首地址
  int num;//每个元素占用的存储单元数
  int loc_aij;
  int i,j;
  printf("请输入元素占用内存中一维数组首地址:");
  scanf("%d",&loc_a00);
  printf("请输入每个元素占用的存储单元数:");
  scanf("%d",&num);
  printf("请输入二维数组行号和列号:");
  scanf("%d,%d",&i,&j);
  loc_aij=loc_a00+(i*10+j)*num;//行优先
  printf("按照行优先二维数组a%d%d在内存中地址为:%d\n",i,j,loc_aij);
  loc_aij=loc_a00+(j*10+i)*num;//列优先
  printf("按照列优先二维数组a%d%d在内存中地址为:%d\n",i,j,loc_aij);
}