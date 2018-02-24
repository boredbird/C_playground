#include "C9-6.H"

void main()
 {
   Record r[N]={{24,"1"},{45,"2"},{53,"3"},{12,"4"},{37,"5"},{50,"6"},{61,"7"},{90,"8"},
                {100,"9"},{70,"10"},{3,"11"},{30,"12"},{26,"13"},{85,"14"},{3,"15"},
		{7,"16"}}; 
   BTree t;
   Result s;
   int i;
   InitDSTable(&t);
   for(i=0;i<N;i++)
   {
     s=SearchBTree(t,r[i].key);
     if(!s.tag)
       InsertBTree(&t,&r[i],s.pt,s.i);
   }
   printf("按关键字的顺序遍历B_树:\n");
   TraverseDSTable(t,print);
   printf("\n请输入待查找记录的关键字: ");
   scanf("%d",&i);
   s=SearchBTree(t,i);
   if(s.tag)
     print(*(s.pt),s.i);
   else
     printf("没找到");
   printf("\n");
   DestroyDSTable(&t);
 }