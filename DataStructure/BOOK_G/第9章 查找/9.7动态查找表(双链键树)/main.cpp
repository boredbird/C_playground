#include "C9-7.H"

void main()
 {
   DLTree t;
   int i;
   char s[MAX_KEY_LEN+1];
   KeysType k;
   Record *p;
   Record r[N]={{{"CAI"},1},{{"CAO"},2},{{"LI"},3},{{"LAN"},4},{{"CHA"},5},{{"CHANG"},6},
                {{"WEN"},7},{{"CHAO"},8},{{"YUN"},9},{{"YANG"},10},{{"LONG"},11},
                {{"WANG"},12},{{"ZHAO"},13},{{"LIU"},14},{{"WU"},15},{{"CHEN"},16}};
   /* 数据元素(以教科书式9–24为例) */
   InitDSTable(&t);
   for(i=0;i<N;i++)
   {
     r[i].key.num=strlen(r[i].key.ch);
     p=SearchDLTree(t,r[i].key);
     if(!p) /* t中不存在关键字为r[i].key的项 */
       InsertDSTable(&t,&r[i]);
   }
   printf("按关键字符串的顺序遍历双链键树:\n");
   TraverseDSTable(t,print);
   printf("\n请输入待查找记录的关键字符串: ");
   scanf("%s",s);
   k.num=strlen(s);
   strcpy(k.ch,s);
   p=SearchDLTree(t,k);
   if(p)
     print(*p);
   else
     printf("没找到");
   printf("\n");
   DestroyDSTable(&t);
 }