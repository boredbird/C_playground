#include "C9-2.H"

 void main()
 {
   char select;
   SSTable st;
   int i;
   KeyType s;
   ElemType r[N]={5,13,19,21,37,56,64,75,80,88,92}; /* 数据元素(以教科书p.219的数据为例) */
   Creat_Ord(&st,r,N); /* 由全局数组产生非降序静态查找表st */
   Traverse(st,print); /* 顺序输出非降序静态查找表st */
   do{
   printf("\n");
   printf("请输入待查找值的关键字: ");
   scanf("%d",&s);
   i=Search_Bin(st,s); /* 折半查找有序表 */
   if(i)
     printf("%d 是第%d个记录的关键字\n",st.elem[i].key,i);
   else
     printf("没找到\n");
   printf("任意键继续...；'q'退出! \n");
   getchar();
   select = getchar();
   }
   while(select !='q');
   Destroy(&st);
 }