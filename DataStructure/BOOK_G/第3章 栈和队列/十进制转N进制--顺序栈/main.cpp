// main.cpp ����C3-1.cpp��������

#include "C3-1.H"

 void main()
 {
	 char cache;
	 int N;
	 do{		
		 printf("������Ҫת���Ľ���(2,8,16)���ƾ���!");
		 scanf("%d",&N);
         conversion(N);
		 printf("�밴��������г���! �˳�����q ! \n");
		 getchar();
		 cache = getchar();
		 printf("\n");
		 }while(cache!='q');
 }