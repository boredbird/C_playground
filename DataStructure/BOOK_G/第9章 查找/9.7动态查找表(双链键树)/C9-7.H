#include "C9.H"

#ifndef C9_7_H
#define C9_7_H

#define N 16 /* 数据元素个数 */
#define Nil ' ' /* 定义结束符为空格(与教科书不同) */

 typedef struct
 {
   int ord;
 }Others; /* 记录的其它部分 */

//////////////////////////////////////////////////
 #define MAX_KEY_LEN 16 /* 关键字的最大长度 */

 typedef struct
 {
   char ch[MAX_KEY_LEN]; /* 关键字 */
   int num; /* 关键字长度 */
 }KeysType; /* 关键字类型 */

 typedef struct
 {
   KeysType key; /* 关键字 */
   Others others; /* 其它部分(由主程定义) */
 }Record; /* 记录类型 */

 typedef enum{LEAF,BRANCH}NodeKind; /* 结点种类：{叶子,分支} */
 typedef struct DLTNode /* 双链树类型 */
 {
   char symbol;
   struct DLTNode *next; /* 指向兄弟结点的指针 */
   NodeKind kind;
   union
   {
     Record *infoptr; /* 叶子结点的记录指针 */
     struct DLTNode *first; /* 分支结点的孩子链指针 */
   }a;
 }DLTNode,*DLTree;

 ///////////////////////////////////////顺序栈数据结构
 #define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
 #define STACK_INCREMENT 2 /* 存储空间分配增量 */

  typedef struct
 {
   char ch;
   DLTree p;
 }SElemType; /* 定义栈元素类型 */

 typedef struct SqStack
 {
   SElemType *base; /* 在栈构造之前和销毁之后，base的值为NULL */
   SElemType *top; /* 栈顶指针 */
   int stacksize; /* 当前已分配的存储空间，以元素为单位 */
 }SqStack; /* 顺序栈 */
 ///////////////////////////////////////顺序栈数据结构

extern  void InitDSTable(DLTree *DT);
extern void DestroyDSTable(DLTree *DT);
extern Record *SearchDLTree(DLTree T,KeysType K);
extern void InsertDSTable(DLTree *DT,Record *r);
extern void TraverseDSTable(DLTree DT,void(*Vi)(Record));
extern  void print(Record e);

 ///////////////////////////////////////顺序栈函数
extern  void InitStack(SqStack *S);//构造一个空栈S
extern  void DestroyStack(SqStack *S);//销毁栈S，S不再存在
extern  void ClearStack(SqStack *S);//把S置为空栈
extern  Status StackEmpty(SqStack S);//若栈S为空栈，则返回TRUE，否则返回FALSE
extern  int StackLength(SqStack S);// 返回S的元素个数，即栈的长度
extern  Status GetTop(SqStack S,SElemType *e);//若栈不空，则返回S的栈顶元素；否则返回ERROR
extern  void Push(SqStack *S,SElemType e);//插入元素e为新的栈顶元素
extern  Status Pop(SqStack *S,SElemType *e);//若栈不空，则删除S的栈顶元素，返回其值；否则返回ERROR
extern  void StackTraverse(SqStack S,void(*visit)(SElemType));// 从栈底到栈顶依次对栈中每个元素进行访问


#endif