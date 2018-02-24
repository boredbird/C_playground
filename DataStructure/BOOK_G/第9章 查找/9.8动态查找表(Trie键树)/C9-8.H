#include "C9.H"

#ifndef C9_8_H
#define C9_8_H

 #define N 16 /* 数据元素个数 */
 #define LENGTH 27 /* 结点的最大度+1(大写英文字母) */

 typedef struct
 {
   int ord;
 }Others; /* 记录的其它部分 */

 #define Nil ' ' /* 定义结束符为空格(与教科书不同) */

////////////////////////////////// Trie键树类型 */
 #define MAX_KEY_LEN 16 /* 关键字的最大长度，同c9-4.h */
 typedef struct
 {
   char ch[MAX_KEY_LEN]; /* 关键字 */
   int num; /* 关键字长度 */
 }KeysType; /* 关键字类型，同c9-4.h */

 typedef struct
 {
   KeysType key; /* 关键字 */
   Others others; /* 其它部分(由主程定义) */
 }Record; /* 记录类型，同c9-4.h */

 typedef enum{LEAF,BRANCH}NodeKind; /* 结点种类：{叶子,分支}，同c9-4.h */

 typedef struct TrieNode /* Trie键树类型 */
 {
   NodeKind kind;
   union
   {
     struct /* 叶子结点 */
     {
       KeysType K;
       Record *infoptr;
     }lf;
     struct /* 分支结点 */
     {
       struct TrieNode *ptr[LENGTH]; /* LENGTH为结点的最大度+1，在主程定义 */
     /*  int num; 改 */
     }bh;
   }a;
 }TrieNode,*TrieTree;
////////////////////////////////// Trie键树类型 */

 ///对两个字符串型关键字的比较约定为如下的宏定义 
#define EQ(a,b) (!strcmp((a),(b)))
#define LT(a,b) (strcmp((a),(b))<0)
#define LQ(a,b) (strcmp((a),(b))<=0)

extern  void InitDSTable(TrieTree *T);
extern void DestroyDSTable(TrieTree *T);
extern int ord(char c);
extern Record *SearchTrie(TrieTree T,KeysType K);
extern void InsertTrie(TrieTree *T,Record *r);
extern void TraverseDSTable(TrieTree T,void(*Vi)(Record*));
extern  void pr(Record *r);




#endif