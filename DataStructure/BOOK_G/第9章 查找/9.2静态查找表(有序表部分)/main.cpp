#include "C9-2.H"

 void main()
 {
   char select;
   SSTable st;
   int i;
   KeyType s;
   ElemType r[N]={5,13,19,21,37,56,64,75,80,88,92}; /* ����Ԫ��(�Խ̿���p.219������Ϊ��) */
   Creat_Ord(&st,r,N); /* ��ȫ����������ǽ���̬���ұ�st */
   Traverse(st,print); /* ˳������ǽ���̬���ұ�st */
   do{
   printf("\n");
   printf("�����������ֵ�Ĺؼ���: ");
   scanf("%d",&s);
   i=Search_Bin(st,s); /* �۰��������� */
   if(i)
     printf("%d �ǵ�%d����¼�Ĺؼ���\n",st.elem[i].key,i);
   else
     printf("û�ҵ�\n");
   printf("���������...��'q'�˳�! \n");
   getchar();
   select = getchar();
   }
   while(select !='q');
   Destroy(&st);
 }