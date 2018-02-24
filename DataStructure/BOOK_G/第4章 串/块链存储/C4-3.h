#ifndef C4_3_H
#define C4_3_H

#define CHUNKSIZE 4                   /* 可由用户定义的块大小 */

typedef enum
{
    OK             = 1,
    ERROR          = 0
}Status;                             

typedef struct Chunk
{
    char ch[CHUNKSIZE];
    struct Chunk *next;
}Chunk;

typedef struct
{
    Chunk *head,*tail;                /* 串的头和尾指针 */
    int   curlen;                     /* 串的当前长度 */
}LString,*PLString;

/**
*Fucntion:  初始化字符串，产生空串T
*Param:
*           T:要被初始化的块链字符串指针
*/
extern void SetBlank(char c);

/**
*Fucntion:  初始化字符串，产生空串T
*Param:
*           T:要被初始化的块链字符串指针
*/
extern void InitString(LString *T);

/**
*Function:  生成一个其值等于chars的串T(要求chars中不包含填补空余的字符)
*Param:
*           T:块链字符串指针
*           chars:字符串指针
*Return:    成功返回OK，否则返回ERROR
*/
extern Status StrAssign(LString *T, char *chars);

/**
*Function:  由串S复制得串T(连填补空余的字符一块拷贝)
*Param:
*           T:拷贝后的字符串指针
*           S:待拷贝的字符串
*Return:    成功返回OK，否则返回ERROR
*/
extern Status StrCopy(LString *T, LString S);

/**
*Function:  判断串是否为空
*Param:
*           S:待判断的字符串
*Return:    若S为空串,则返回OK,否则返回ERROR
*/
extern Status StrEmpty(LString S);

/**
*Function:  串比较
*Param:
*           S:待比较的串
*           T:待比较的串
*Return:    若S>T,则返回值>0;若S = T,则返回值 = 0;若S < T ,则返回值 < 0
*/
extern int StrCompare(LString S, LString T);

/**
*Function:  求串长度
*Param:
*           S:串
*Return:    串S中元素的个数，即串的长度
*/
extern int StrLength(LString S);

/**
*Function:  清空串
*Param:
*           S:待清空的串指针
*Return:    OK
*/
extern Status ClearString(LString *S);

/**
*Function:  连接串
*Param:
*           T:连接后的字符串
*           S1、S2:待连接的字符串，T = S1 + S2
*Return:    OK
*/
extern Status Concat(LString *T, LString S1, LString S2);

/**
*Function:  截取串
*Param:
*           Sub:截取后的串
*           S:待截取的串
*           pos:截取初始位置
*           len:截取长度
*Return:    成功返回OK，否则返回ERROR
*/
extern Status SubString(LString *Sub, LString S, int pos, int len);

/**
*Fucntion:  查找子串
*Param:
*           S:待查找的主串
*           T:匹配项子串
*           pos:查找起始位置
*Return:    若查找到，返回第一次T串在S串中出现的位置。否则返回0
*/
extern int Index(LString S, LString T, int pos);

/**
*Function:  压缩串(清除块中不必要的填补空余的字符)
*Param:
*           S:待压缩的串
*/
extern void Zip(LString *S);

/**
*Function:  在串S的第pos个字符之前插入串T
*Param:
*           S:待插入的主串指针
*           pos:插入起始位置
*           T:待插入的子串
*Return:    成功返回OK,失败返回ERROR
*/
extern Status StrInsert(LString *S, int pos, LString T);

/**
*Function:  从串S中删除第pos个字符起长度为len的子串
*Param:
*           S:待删除的串指针
*           pos:删除起始位置
*           len:删除长度
*Return:    成功返回OK,失败返回ERROR
*/
extern Status StrDelete(LString *S, int pos, int len);

/**
*Function:  用V替换主串S中出现的所有与T相等的不重叠的子串
*Param:
*           S:待替换的主串指针
*           T:匹配串
*           V:替换串
*Return:    成功返回OK,失败返回ERROR
*/
extern Status Replace(LString *S, LString T, LString V);

/**
*Function:  输出串
*Param:
*           T:待打印的串
*/
extern void StrPrint(LString T);

/**
*Function:  销毁串
*/
extern void DestroyString(LString T);

#endif