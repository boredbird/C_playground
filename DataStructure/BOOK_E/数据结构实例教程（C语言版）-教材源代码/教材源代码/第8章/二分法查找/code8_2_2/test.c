#include "stdio.h"
#define n 10
typedef struct
{
	int key;
	//InfoType otherinfo;
}NodeType;
int BinSearch(NodeType R[],int K) 
{
   int low=1,high=n,mid;
	while(low<=high)
	{
      mid=(low+high)/2;
	  if(R[mid].key==K) 
		return mid;
	  else if(R[mid].key>K)
		high=mid-1;
	  else
		low=mid+1;
	}
	return 0;
}

main()
{
    int result,i;
	NodeType SeqList[n];
	for(i=0;i<n;i++)
	   scanf("%d",&SeqList[i].key);
    result=BinSearch(SeqList,50);//查找K=50
	if(result==0)
		printf("查找失败!");
	else
		printf("查找成功!该数位置是:%d",result);
}

