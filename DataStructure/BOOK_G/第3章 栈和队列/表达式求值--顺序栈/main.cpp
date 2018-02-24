#include "C3-6.h"

 void main()
 {
   char select;
   do{
   printf("请输入算术表达式,负数要用(0-正数)表示\n");
   printf("%d\n",EvaluateExpression());
   printf("任意键继续...；'q'退出! \n");
   select = getchar();
   getchar();
   }while(select!='q');
 }