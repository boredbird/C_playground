#include "stdio.h"
int search(int a[],int low,int high,int key) 
{ 
    int mid; 
    while(low<=high) 
    { 
        mid=(low+high)/2; 
        if(a[mid]==key)   
			return mid; 
        if(a[mid]>key)   
			return search(a,low,mid-1,key);       
        else     
			return search(a,low+1,high,key);       
    } 
    return -1; 
} 
main()
{
	int a[10],i,result=0,key;
	printf("������10������:");
	for(i=0;i<10;i++)
      scanf("%d",&a[i]);
	printf("������Ҫ���ҵĹؼ���:");
	scanf("%d",&key);
	result=search(a,0,9,key);
	printf("λ����%d",result);
}

