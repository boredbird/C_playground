#include "stdio.h"
typedef int KeyType;     //�ض���ؼ�������Ϊ���ͣ�Ҳ����Ϊ��������
typedef struct 
{
   KeyType key;          //�ؼ�����
   //InfoType otherinfo;  //������������
}LineList;               //���Բ��ұ�����
//ֱ��ѡ��������
void selectSort(LineList R[],int n)
{  int i,j,index;
   for(i=1;i<n;++i)
   {  index=i;
      for(j=i+1;j<=n;++j)
       if(R[j].key<R[index].key)  index=j;
        if(index!=i)
        {R[0]=R[i];R[i]=R[index];R[index]=R[0];}
   } 
} 

main()
{
  LineList R[6];
  int i;
  printf("������5������:");
  for(i=1;i<=5;i++)
	  scanf("%d",&R[i].key);
  printf("ֱ��ѡ�������Ľ��:");
  selectSort(R,5);//����ֱ��ѡ��������
  for(i=1;i<=5;i++)
	  printf("%3d",R[i].key);
}
