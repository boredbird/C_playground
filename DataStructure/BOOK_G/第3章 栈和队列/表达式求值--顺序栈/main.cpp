#include "C3-6.h"

 void main()
 {
   char select;
   do{
   printf("�������������ʽ,����Ҫ��(0-����)��ʾ\n");
   printf("%d\n",EvaluateExpression());
   printf("���������...��'q'�˳�! \n");
   select = getchar();
   getchar();
   }while(select!='q');
 }