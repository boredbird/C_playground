#include "stdio.h"
typedef int KeyType;     //�ض���ؼ�������Ϊ���ͣ�Ҳ����Ϊ��������
typedef struct 
{
   KeyType key;          //�ؼ�����
   //InfoType otherinfo;  //������������
}LineList;               //���Բ��ұ�����
//ɸѡ�㷨
void sift(LineList r[],int k,int m)
{//Ҫɸѡ���ı��Ϊk���������һ�����ı��Ϊm
	int i,j;
	LineList x;
	i=k;x=r[i];j=2*i;//��ɸѡ��¼�ݴ�x��
	while(j<=m)
	{  
		if((j<m)&&(r[j].key>r[j+1].key))
			j++;                  //���Һ�����С��Ϊr[j]
		if(x.key>r[j].key)
		{  
			r[i].key=r[j].key;
			i=j;    
			j*=2;   
		}
		else j=m+1;
	}
	r[i]=x; //��ɸѡ��¼�Ƶ���ȷλ��
} 
//�������㷨
void heapsort(LineList r[],int n)//��r[1]��r[n]���ж�����
{  int i;
   LineList x;
   for(i=n/2;i>=1;i--)//������
      sift(r,i,n);
   for(i=n;i>=2;i--)//����n-1�˶�����
   {  x=r[1];
      r[1]=r[i];
      r[i]=x;
      sift(r,1,i-1);
   }
}

main()
{
  LineList R[6];
  int i;
  printf("������5������:");
  for(i=1;i<=5;i++)
	  scanf("%d",&R[i].key);
  printf("�������Ľ��:");
  heapsort(R,5);//���ö�������
  for(i=5;i>=1;i--)
	  printf("%3d",R[i].key);
}
