#include "C9-1.H"

void main()
 {
	char select;
   ElemType r[N]={{179328,"�η���",85,89,98,100,93,80,47},
   {179325,"�º�",85,86,88,100,92,90,45},
	{179326,"½��",78,75,90,80,95,88,37},
	{179327,"��ƽ",82,80,78,98,84,96,40},
	{179324,"��С��",76,85,94,57,77,69,44}}; /* ���鲻���ؼ������� */
   SSTable st;
   int i;
   long s;
   for(i=0;i<N;i++) /* �����ܷ� */
     r[i].total=r[i].politics+r[i].Chinese+r[i].English+r[i].math+r[i].physics+
	 r[i].chemistry+r[i].biology;
   Creat_Seq(&st,r,N); /* ������r����˳��̬���ұ�st */
   printf("׼��֤��  ����  ���� ���� ���� ��ѧ ���� ��ѧ ���� �ܷ�\n");
   Traverse(st,print); /* ��˳�������̬���ұ�st */
   do{
   printf("������������˵Ŀ���: ");
   scanf("%ld",&s);
   i=Search_Seq(st,s); /* ˳����� */
   if(i)
     print(st.elem[i]);
   else
     printf("û�ҵ�\n");
   printf("���������...��'q'�˳�! \n");
   getchar();
   select = getchar();
   }
   while(select !='q');
   Destroy(&st);
 }