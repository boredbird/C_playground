#include "stdio.h"
main()
{
  int a,b,c,t;
  printf("��������������:");
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
  printf("\n�����Ľ��Ϊ:");
  printf("%d %d %d",a,b,c);
}