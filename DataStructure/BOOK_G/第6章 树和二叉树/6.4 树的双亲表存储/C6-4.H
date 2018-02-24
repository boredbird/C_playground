 /* c6-4.h 树的双亲表存储表示 */

#include "C6.H"

#ifndef C6_4_H
#define C6_4_H

#define ClearTree InitTree /* 二者操作相同 */
#define DestroyTree InitTree /* 二者操作相同 */

#define MAX_TREE_SIZE 100

 typedef struct
 {
   TElemType data;
   int parent; /* 双亲位置域 */
 } PTNode;

 typedef struct
 {
   PTNode nodes[MAX_TREE_SIZE];
   int n; /* 结点数 */
 } PTree;


//需要用到的单链队列－－队列的链式存储结构

 typedef struct
 {
   int num;
   TElemType name;
 }QElemType; /* 定义队列元素类型 */

 typedef struct QNode
 {
   QElemType data;
   struct QNode *next;
 }QNode,*QueuePtr;

 typedef struct
 {
   QueuePtr front,rear; /* 队头、队尾指针 */
 }LinkQueue;



extern void InitTree(PTree *T);
//初始化树T

extern void visit(TElemType c);
//打印程序

extern void CreateTree(PTree *T);
// 操作结果：构造树T 

extern Status TreeEmpty(PTree T);
// 初始条件：树T存在。操作结果：若T为空树，则返回TRUE，否则返回FALSE 

extern int TreeDepth(PTree T);
// 初始条件：树T存在。操作结果：返回T的深度 

extern TElemType Root(PTree T);
// 初始条件：树T存在。操作结果：返回T的根 

extern Status Assign(PTree *T,TElemType cur_e,TElemType value);
// 初始条件：树T存在，cur_e是树T中结点的值。操作结果：改cur_e为value 

extern TElemType Parent(PTree T,TElemType cur_e);
// 初始条件：树T存在，cur_e是T中某个结点 */
// 操作结果：若cur_e是T的非根结点，则返回它的双亲，否则函数值为＂空＂*/

extern TElemType LeftChild(PTree T,TElemType cur_e);
//初始条件：树T存在，cur_e是T中某个结点 
//操作结果：若cur_e是T的非叶子结点，则返回它的最左孩子，否则返回＂空＂

extern TElemType RightSibling(PTree T,TElemType cur_e);
// 初始条件：树T存在，cur_e是T中某个结点 
// 操作结果：若cur_e有右(下一个)兄弟，则返回它的右兄弟，否则返回＂空＂

extern void Print(PTree T);
//输出树T

extern Status InsertChild(PTree *T,TElemType p,int i,PTree c);
//初始条件：树T存在，p是T中某个结点，1≤i≤p所指结点的度+1，非空树c与T不相交 
// 操作结果：插入c为T中p结点的第i棵子树 

 extern void DeleteChild(PTree *T,TElemType p,int i);
// 初始条件：树T存在，p是T中某个结点，1≤i≤p所指结点的度
// 操作结果：删除T中结点p的第i棵子树

extern void TraverseTree(PTree T);
// 初始条件：二叉树T存在,Visit是对结点操作的应用函数
// 操作结果：层序遍历树T,对每个结点调用函数Visit一次且仅一次 

//-----------------------------------------------------
//需要用到的队列元素
extern void InitQueue(LinkQueue *Q);
//构造一个空队列Q 
 
extern Status QueueEmpty(LinkQueue Q);
//若Q为空队列，则返回TRUE，否则返回FALSE 

extern void DestroyQueue(LinkQueue *Q);
// 销毁队列Q(无论空否均可) 

extern void EnQueue(LinkQueue *Q,QElemType e);
//插入元素e为Q的新的队尾元素

extern Status DeQueue(LinkQueue *Q,QElemType *e);
// 若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR 

//-----------------------------------------------------

#endif