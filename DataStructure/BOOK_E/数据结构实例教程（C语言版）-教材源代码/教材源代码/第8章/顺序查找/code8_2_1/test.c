#include "stdio.h"
#define n 10
typedef struct
{
	int key;
	//InfoType otherinfo;
}NodeType;
int SeqSearch(NodeType R[],int K)
{
   int i;
   for(i=0;i<n;i++)
	   if(R[i].key==K)
		   return i;
   return -1;
}
main()
{
    int result,i;
	NodeType SeqList[n];
	for(i=0;i<n;i++)
	   scanf("%d",&SeqList[i].key);
    result=SeqSearch(SeqList,50);//查找K=50
	if(result==-1)
		printf("查找失败!");
	else
		printf("查找成功!该数位置是:%d",result);
}

