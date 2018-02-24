#include "C9-8.H"

 void main()
 { TrieTree t;   int i;   char s[MAX_KEY_LEN+1];   KeysType k;   Record *p;
   Record r[N]={{{"CAI"},1},{{"CAO"},2},{{"LI"},3},{{"LAN"},4},
{{"CHA"},5},{{"CHANG"},6}, {{"WEN"},7},{{"CHAO"},8},{{"YUN"},9},
{{"YANG"},10},{{"LONG"},11},{{"WANG"},12},{{"ZHAO"},13},{{"LIU"},14},
{{"WU"},15},{{"CHEN"},16}};
   InitDSTable(&t);
   for(i=0;i<N;i++)
   {
     r[i].key.num=strlen(r[i].key.ch)+1;
     r[i].key.ch[r[i].key.num]=Nil; /* 在关键字符串最后加结束符 */
     p=SearchTrie(t,r[i].key);
     if(!p)
       InsertTrie(&t,&r[i]);
   }
   printf("按关键字符串的顺序遍历Trie树(键树):\n");
   TraverseDSTable(t,pr);
   printf("\n请输入待查找记录的关键字符串: ");
   scanf("%s",s);
   k.num=strlen(s)+1;
   strcpy(k.ch,s);
   k.ch[k.num]=Nil; /* 在关键字符串最后加结束符 */
   p=SearchTrie(t,k);
   if(p)
     pr(p);
   else
     printf("没找到");
   printf("\n");
   DestroyDSTable(&t);
 }

