//���ά����Ԫ�����ڴ��еĴ洢λ��
//�����ά����10��10��,�±��0��ʼ
#include "stdio.h"
main()
{
  int loc_a00;//Ԫ��ռ���ڴ���һά�����׵�ַ
  int num;//ÿ��Ԫ��ռ�õĴ洢��Ԫ��
  int loc_aij;
  int i,j;
  printf("������Ԫ��ռ���ڴ���һά�����׵�ַ:");
  scanf("%d",&loc_a00);
  printf("������ÿ��Ԫ��ռ�õĴ洢��Ԫ��:");
  scanf("%d",&num);
  printf("�������ά�����кź��к�:");
  scanf("%d,%d",&i,&j);
  loc_aij=loc_a00+(i*10+j)*num;//������
  printf("���������ȶ�ά����a%d%d���ڴ��е�ַΪ:%d\n",i,j,loc_aij);
  loc_aij=loc_a00+(j*10+i)*num;//������
  printf("���������ȶ�ά����a%d%d���ڴ��е�ַΪ:%d\n",i,j,loc_aij);
}