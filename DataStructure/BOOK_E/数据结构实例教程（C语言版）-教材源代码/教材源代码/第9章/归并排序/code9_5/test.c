#include "stdio.h"
#define M  5
//�����������кϳ�һ����������
void Merge(int r[],int r1[],int s,int m,int t)
{   
	int i,j,k;
	i=s;j=m+1;k=s;
    while(i<=m&&j<=t)
    { 
		if(r[i]<=r[j]) r1[k++]=r[i++];
		else r1[k++]=r[j++];
    }
    if(i<=m)
		while(i<=m)  r1[k++]=r[i++];//��β����,ǰһ��������
	if(j<=t)
		while(j<=t)  r1[k++]=r[j++];//��һ��������
}

//��·�鲢�㷨
void MergeSort(int r[],int r1[],int r2[],int s,int t)  
{  
	if(s==t)  
		r1[s]=r[s];  
	else  
	{  
		int m;  
		m=(s+t)/2;  
		MergeSort(r,r2,r1,s,m);        //�鲢����ǰ���������    
        MergeSort(r,r2,r1,m+1,t);      //�鲢�������������  
        Merge(r2,r1,s,m,t);            //������������������й鲢  
	}  
}   
main()
{
  int r[M],r1[M],r2[M];
  int i;
  printf("������5������:");
  for(i=0;i<M;i++)
	  scanf("%d",&r[i]);
  printf("�鲢�����Ľ��:");
  MergeSort(r,r1,r2,0,M-1);//���ö�·�鲢�㷨
  for(i=0;i<M;i++)
	  printf("%3d",r1[i]);
}
 
  

 
 