#include "stdio.h"
typedef int KeyType;     //�ض���ؼ�������Ϊ���ͣ�Ҳ����Ϊ��������
typedef struct 
{
   KeyType key;          //�ؼ�����
   //InfoType otherinfo;  //������������
}LineList;               //���Բ��ұ�����
//����������
void QuickSort(LineList R[],int first,int end)
{  int i,j;
   LineList temp;
   i=first;j=end;temp=R[i];R[0]=R[i];     //��ʼ��
   while(i<j)
   {   while(i<j&&R[0].key<=R[j].key)  j--; //���Ҷ˿�ʼɨ��
       if(i<j){R[i]=R[j];i++;}
       while(i<j&&R[0].key>=R[i].key)   i++; //����˿�ʼɨ��
       if(i<j){R[j]=R[i];j--;}
   } 
   R[i]=R[0];
   if(first<i-1) QuickSort(R,first,i-1); //������������еݹ��������
   if(i+1<end)  QuickSort(R,i+1,end); //���Ҳ��������еݹ��������
} 


main()
{
  LineList R[6];
  int i;
  printf("������5������:");
  for(i=1;i<=5;i++)
	  scanf("%d",&R[i].key);
  printf("���������Ľ��:");
  QuickSort(R,1,5);//���ÿ���������
  for(i=1;i<=5;i++)
	  printf("%3d",R[i].key);
}
