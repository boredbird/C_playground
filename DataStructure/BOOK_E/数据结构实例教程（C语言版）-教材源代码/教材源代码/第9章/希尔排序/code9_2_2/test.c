#include "stdio.h"
typedef int KeyType;     //�ض���ؼ�������Ϊ���ͣ�Ҳ����Ϊ��������
typedef struct 
{
   KeyType key;          //�ؼ�����
   //InfoType otherinfo;  //������������
}LineList;               //���Բ��ұ�����
//ϣ��������
void shellSort(LineList R[],int n)
{
    int i,j,d;
    d=n/2;//��ʼ����Ϊ����һ��
    while(d>0)//ֱ��dΪ1
    {
        for(i=d+1;i<=n;++i)//��ÿ�����ֱ�Ӳ�������
        if(R[i].key<R[i-d].key)
        {  
            R[0].key=R[i].key;
            for(j=i-d;j>0&&R[0].key<R[j].key;j=j-d)
              R[j+d]=R[j];
            R[j+d]=R[0];
        }
        d=d/2;//��С����ֵ
	}
}

main()
{
  LineList R[6];
  int i;
  printf("������5������:");
  for(i=1;i<=5;i++)
	  scanf("%d",&R[i].key);
  printf("ϣ�������Ľ��:");
  shellSort(R,5);//����ϣ��������
  for(i=1;i<=5;i++)
	  printf("%3d",R[i].key);
}
