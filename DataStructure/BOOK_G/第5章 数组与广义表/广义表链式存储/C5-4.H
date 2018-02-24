#ifndef text5_5_H
#define text5_6_H

#define MAXSTRLEN   255                     /* 用户可在255以内定义最大串长（1个字节）*/                                   

typedef char AtomType ;
typedef AtomType SString[MAXSTRLEN+1];      /* 0号单元存放串的长度*/

typedef enum
{
    OK    = 1,
    ERROR = 0
}Status;

struct GLNode
{
    enum  ElemTag tag;                      /* 公共部分,用于区分原子结点和表结点*/
    union                                   /* 原子结点和表结点的联合部分*/
    {
        AtomType atom;                      /* atom是原子结点的值域,AtomType由用户定义*/
        struct ptr
        {
            struct GLNode *hp,*tp;
        }ptr;                               /* ptr是表结点的指针域,prt.hp和ptr.tp分别指向表头和表尾*/
    };
};                                          /* 广义表类型*/

typedef struct GLNode GLNode;
typedef GLNode * GList;
enum ElemTag{ATOM,LIST};                    /* ATOM==0:原子,LIST==1:子表*/


/*
 * Function: 生成一个其值等于chars的串T
 * Parameter:T
 *       T:串
 *   chars:字符串
 *  Return:如果串chars大约最大字符串的长度返回：0，否则返回：1
 */
extern Status StrAssign(SString T, char *chars);

/*
 * Function: 由串S复制得串T
 * Parameter:S,T
 *       S:字符串
 *       T:字符串
 *  Return:1
 */
extern Status StrCopy(SString T, SString S);

/*
 * Function: 若S为空串,则返回OK,否则返回ERROR
 * Parameter:S
 *       S:字符串
 *  Return:若s字符串空返回：1，否则返回：0
 */
extern Status StrEmpty(SString S);

/*
 * Function: 初始条件: 串S和T存在 ，操作结果: 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0
 * Parameter:S，T
 *       S:字符串
 *       T:字符串
 *  Return:如果串S不等于串T返回：S[i] - T[i]，否则返回：S[0]-T[0]
 */
extern int StrCompare(SString S, SString T);

/*
 * Function: 返回串的元素个数
 * Parameter:S
 *       S:串
 *  Return:S[0]
 */
extern int StrLength(SString S);

/*
 * Function:  初始条件:串S存在。操作结果:将S清为空串
 * Parameter:S
 *       S:串
 *  Return:1
 */
extern Status ClearString(SString S);

/*
 * Function: 用T返回S1和S2联接而成的新串。若未截断，则返回OK，否则ERROR
 * Parameter:T，S1，S2
 *       T:新串
 *      S1:串
 *      S2:串
 *  Return:若未截断返回：0，否则返回：1
 */
extern Status Concat(SString T, SString S1, SString S2);

/*
 * Function: 用Sub返回串S的第pos个字符起长度为len的子串
 * Parameter:sub,s,pos,len
 *      sub:字符串
 *        S:字符串
 *      pos:元素位
 *      len:元素长度
 *   Return:当pos < 1 || pos > S[0] || len < 0 || len > S[0]-pos+1时返回0，否则返回：1
 */
extern Status SubString(SString Sub, SString S, int pos, int len);

/*
 * Function:  返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数值为0。其中,T非空,1≤pos≤StrLength(S)
 * Parameter:S，T,pos
 *       S:字符串
 *       T:字符串
 *     pos:元素位
 *  Return:1
 */
extern int Index(SString S, SString T, int pos);

/*
 * Function: 初始条件: 串S和T存在,1≤pos≤StrLength(S)+1，操作结果: 在串S的第pos个字符之前插入串T。完全插入返回OK,部分插入返回ERROR  
 * Parameter:S,T,pos
 *       S:串
 *       T:串
 *     pos:元素位
 *  Return:完全插入返回：1，部分插入返回：0
 */
extern Status StrInsert(SString S, int pos, SString T);

/*
 * Function: 初始条件: 串S存在,1≤pos≤StrLength(S)-len+1 ，操作结果: 从串S中删除第pos个字符起长度为len的子串
 * Parameter:S,T,pos，len
 *       S:串
 *       T: 串
 *     pos:元素位
 *     len:子串的长度
 *  Return:如果(pos < 1 || pos > S[0] - len + 1 || len < 0)返回：0，否则返回：1
 */
extern Status StrDelete(SString S, int pos, int len);

/*
 * Function:  初始条件: 串S,T和V存在,T是非空串（此函数与串的存储结构无关），操作结果: 用V替换主串S中出现的所有与T相等的不重叠的子串
 * Parameter:S，T，V
 *        S:串
 *        T:串
 *        V:串
 *   Return:如果T空串返回0，否则返回1
 */
extern Status Replace(SString S, SString T, SString V);

/*
 * Function:  由于SString是定长类型,无法销毁
 */
extern void DestroyString(SString T);

/*
 * Function:  输出字符串T
 * Parameter:T
 *         T:字符串
 */
extern void StrPrint(SString T);

 /*
 * Function: 创建空的广义表L
 * Parameter:L
 *         L:广义表
 *    Return:1
 */    
extern Status InitGList(GList *L);
 
 /*
 * Function: 广义表的头尾链表存储的销毁操作
 * Parameter:L
 *       L:广义表
 */  
extern void DestroyGList(GList *L); 
 
/*
 * Function: 采用头尾链表存储结构,由广义表L复制得到广义表T
 * Parameter:T,L
 *       T:广义表
 *       L:广义表
 *  Return:1
 */  
extern Status CopyGList(GList *T, GList L);

/*
 * Function: 返回广义表的长度,即元素个数
 * Parameter:L
 *         L:广义表
 *    Return:如果L是空返回0，如果(L -> tag == ATOM)返回1，否则返回：len
 */ 
extern int GListLength(GList L);
      
/*
 * Function: 采用头尾链表存储结构,求广义表L的深度。
 * Parameter:L
 *       L:广义表
 * Return:空表L返回：1，如果(L -> tag == ATOM)，返回：0，否则返回：max+1
 */ 
extern int GListDepth(GList L);
      
/*
 * Function: 判定广义表是否为空
 * Parameter:L
 *       L:广义表
 * Return:如果不空返回：1，否则返回：0
 */  
extern Status GListEmpty(GList L);
    
/*
 * Function: 取广义表L的头
 * Parameter:L
 *       L:广义表
 * Return:h
 */ 
extern GList GetHead(GList L);
       
/*
 * Function:  取广义表L的尾
 * Parameter:L
 *       L:广义表
 * Return:t
 */  
extern GList GetTail(GList L); 
      
/*
 * Function:  // 初始条件: 广义表存在 ，操作结果: 插入元素e作为广义表L的第一元素(表头,也可能是子表)      
 * Parameter:L，E
 *       L:广义表
         E:广义表元素
 * Return:1
 */ 
extern Status InsertFirst_GL(GList *L, GList e);

/*
 * Function:  // 初始条件: 广义表L存在，操作结果: 删除广义表L的第一元素,并用e返回其值
 * Parameter:L
 *       L:广义表
 *       E:广义表元素
 * Return:1
 */
extern Status DeleteFirst_GL(GList *L, GList *e);

 /*
 * Function: 利用递归算法遍历广义表L
 * Parameter:L
 *       L:广义表
 */
extern void Traverse_GL(GList L, void(*v)(AtomType));

/*
 * Function: 将非空串str分割成两部分:hsub为第一个','之前的子串,str为之后的子串
 * Parameter:STR，hSTR
 *       STR:非空串
 *      HSTR:串
 */ 
extern void sever(SString str, SString hstr);
 
/*
 * Function: 算法5.7// 采用头尾链表存储结构,由广义表的书写形式串S创建广义表L。设emp="()"
 * Parameter:L，S
 *       S:广义表
 *       L:广义表
 * Return:1
 */ 
extern Status CreateGList(GList *L, SString S); 
  
#endif