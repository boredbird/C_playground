#include "C9.H"

#ifndef C9_9_H
#define C9_9_H

 //////对两个数值型关键字的比较约定为如下的宏定义 
 #define EQ(a,b) ((a)==(b))
 #define LT(a,b) ((a)<(b))
 #define LQ(a,b) ((a)<=(b))
 //////对两个数值型关键字的比较约定为如下的宏定义

 #define SUCCESS 1
 #define UNSUCCESS 0
 #define DUPLICATE -1

 #define NULL_KEY 0 /* 0为无记录标志 */
 #define N 10 /* 数据元素个数 */
 typedef int KeyType; /* 设关键字域为整型 */
 typedef struct
 {
   KeyType key;
   int ord;
 }ElemType; /* 数据元素类型 */

 ///开放定址哈希表的存储结构 

 typedef struct
 {
   ElemType *elem; /* 数据元素存储基址，动态分配数组 */
   int count; /* 当前数据元素个数 */
   int sizeindex; /* hashsize[sizeindex]为当前容量 */
 }HashTable;
 ///开放定址哈希表的存储结构 


#endif