#include "C9-3.H"

 void main()
 {
	 char select;
   SSTable st;
   SOSTree t;
   Status i;
   KeyType s; /* �Խ̿�����9-1������Ϊ�� */
   ElemType r[N]={{'A',1},{'B',1},{'C',2},{'D',5},{'E',3},{'F',4},{'G',4},{'H',3},{'I',5}};
   Creat_Ord(&st,r,N); /* ��ȫ����������ǽ���̬���ұ�st */
   Traverse(st,print);
   CreateSOSTree(&t,st); /* ���������һ�ô��Ų����� */
   printf("\n����������ҵ��ַ�: ");
   scanf("%c",&s);
   i=Search_SOSTree(&t,s);
   if(i)
     printf("%c��Ȩֵ��%d\n",s,t->data.weight);
   else
     printf("���в����ڴ��ַ�\n");
 }