#include "stdio.h"
typedef int KeyType;     //�ض���ؼ�������Ϊ���ͣ�Ҳ����Ϊ��������
typedef struct 
{
   KeyType key;          //�ؼ�����
   //InfoType otherinfo;  //������������
}LineList;               //���Բ��ұ�����
//ð��������
void BubbleSort(LineList R[],int n)
{ int i,j;
   for(i=1;i<n;i++)               //iΪ�Ƚ�����
     for(j=1;j<=n-i;j++)            //һ�˽�������
	    if(R[j].key>R[j+1].key)     //������
       {R[0]=R[j];R[j]=R[j+1];R[j+1]=R[0];}//��R[0]��Ϊ�м����ʵ�ֽ���
}

main()
{
  LineList R[6];
  int i;
  printf("������5������:");
  for(i=1;i<=5;i++)
	  scanf("%d",&R[i].key);
  printf("ð�������Ľ��:");
  BubbleSort(R,5);//����ð��������
  for(i=1;i<=5;i++)
	  printf("%3d",R[i].key);
}
