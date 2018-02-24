#include "stdio.h"
main()
{
  int a,b,c,t;
  printf("请输入三个整数:");
  scanf("%d,%d,%d",&a,&b,&c);
  if(a>b)
  {
	  t=a;a=b;b=t;
  }
  if(a>c)
  {
	  t=a;a=c;c=t;
  }
  if(b>c)
  {
	  t=b;b=c;c=t;
  }
  printf("\n排序后的结果为:");
  printf("%d %d %d",a,b,c);
}