#include "stdio.h"
typedef int KeyType;     //�ض���ؼ�������Ϊ���ͣ�Ҳ����Ϊ��������
typedef struct 
{
   KeyType key;          //�ؼ�����
   //InfoType otherinfo;  //������������
}LineList;               //���Բ��ұ�����
//ֱ�Ӳ���������
void inerSort(LineList R[],int n)
{
    int i,j;
    for(i=2;i<=n;++i)
    if(R[i].key<R[i-1].key)
    {
         R[0].key=R[i].key;
         for(j=i-1;R[0].key<R[j].key;--j)
             R[j+1]= R[j];
         R[j+1]=R[0];
    }
}
main()
{
  LineList R[6];
  int i;
  printf("������5������:");
  for(i=1;i<=5;i++)
	  scanf("%d",&R[i].key);
  printf("ֱ�Ӳ��������Ľ��:");
  inerSort(R,5);//����ֱ�Ӳ���������
  for(i=1;i<=5;i++)
	  printf("%3d",R[i].key);
}
