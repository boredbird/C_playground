#include "C9-3.H"

 void main()
 {
	 char select;
   SSTable st;
   SOSTree t;
   Status i;
   KeyType s; /* 以教科书例9-1的数据为例 */
   ElemType r[N]={{'A',1},{'B',1},{'C',2},{'D',5},{'E',3},{'F',4},{'G',4},{'H',3},{'I',5}};
   Creat_Ord(&st,r,N); /* 由全局数组产生非降序静态查找表st */
   Traverse(st,print);
   CreateSOSTree(&t,st); /* 由有序表构造一棵次优查找树 */
   printf("\n请输入待查找的字符: ");
   scanf("%c",&s);
   i=Search_SOSTree(&t,s);
   if(i)
     printf("%c的权值是%d\n",s,t->data.weight);
   else
     printf("表中不存在此字符\n");
 }