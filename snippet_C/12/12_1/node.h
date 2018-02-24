#ifndef _NODE                   //条件编译，可以避免重复包含的错误
#define _NODE
typedef int Type;                  //对应于不同的应用，int可以换作其它类型
struct node                       //结点类型就不需要作任何改变了
{
   	    Type data;                   //数据成员data属于Type类型
     	struct node *next;             //next是结点的指针域
};
const int size=sizeof(struct node);     //求链表的结点字节数，决定申请动态空间的大小
#endif
