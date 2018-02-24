#include "stdio.h"
typedef struct 
{
      int data[10];
      int length;   
 }SeqList;
main()
{
	SeqList list;
	int i,t;
	for(i=0;i<10;i++)
		scanf("%d",&list.data[i]);
	list.length=10;
	for(i=0;i<list.length/2;i++)
    {
		t=list.data[i];
		list.data[i]=list.data[10-1-i];
        list.data[10-1-i]=t;
	}
	printf("逆序后的结构为:");
    for(i=0;i<10;i++)
		printf("%d ",list.data[i]);
}
