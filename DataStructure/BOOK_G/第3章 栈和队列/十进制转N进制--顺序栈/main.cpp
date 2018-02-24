// main.cpp 检验C3-1.cpp的主程序

#include "C3-1.H"

 void main()
 {
	 char cache;
	 int N;
	 do{		
		 printf("输入您要转换的进制(2,8,16)进制均可!");
		 scanf("%d",&N);
         conversion(N);
		 printf("请按任意键运行程序! 退出输入q ! \n");
		 getchar();
		 cache = getchar();
		 printf("\n");
		 }while(cache!='q');
 }