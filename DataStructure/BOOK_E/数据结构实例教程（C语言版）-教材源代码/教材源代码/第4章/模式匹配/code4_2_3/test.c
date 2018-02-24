#include "stdio.h"
#include "string.h"
#define MAXLEN 10
typedef struct 
{	char ch[MAXLEN];
	int len;
}SeqString;

int StrMatch(SeqString T,SeqString P)
{//找模式P在目标T中首次出现的位置，成功返回第1个有效位移，否则返回-1
    int i,j,k;
    int m=P.len;  //模式串长度 
    int n=T.len;  //目标串长度
    for(i=0;i<=n-m;i++)//0<=i<=n-m是合法的位移
	{   
      j=0;k=i;  
      while(j<m&&T.ch[k]==P.ch[j])//用while循环判定i是否为有效位移
	  {
       k++;j++;
	  }
      if(j==m) //既T[i..i+m-1]=P[0..m-1]
           return i;//i为有效位移，否则查找下一个位移
	}
    return -1;//找不到有效位移，匹配失败
}
main()
{
   SeqString t,p;
   int position;
   printf("请输入目标串:");
   gets(t.ch);
   t.len=strlen(t.ch);
   printf("请输入匹配串:");
   gets(p.ch);
   p.len=strlen(p.ch);
   position=StrMatch(t,p);
   if(position==-1)
       printf("查找失败!\n");
   else
       printf("查找成功,位置为%d\n",position);

}