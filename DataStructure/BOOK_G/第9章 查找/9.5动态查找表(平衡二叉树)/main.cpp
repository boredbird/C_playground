#include "C9-5.H"

 void main()
 {
   BSTree dt,p;
   Status k;
   int i;
   KeyType j;
   ElemType r[N]={{13,1},{24,2},{37,3},{90,4},{53,5}}; /* (�Խ̿���ͼ9.12Ϊ��) */
   InitDSTable(&dt); /* ��ʼ������ */
   for(i=0;i<N;i++)
     InsertAVL(&dt,r[i],&k); /* ��ƽ������� */
   PreOrderTraverse(dt,print); /* �������ƽ������� */
   printf("�������ƽ�������\n");
   TraverseDSTable(dt,print); /* ���ؼ���˳����������� */
   printf("\n����������ҵĹؼ���: ");
   scanf("%d",&j);
   p=SearchBST(dt,j); /* ���Ҹ����ؼ��ֵļ�¼ */
   if(p)
     print(p->data);
   else
     printf("���в����ڴ�ֵ");
   printf("\n");
   DestroyDSTable(&dt);
 }