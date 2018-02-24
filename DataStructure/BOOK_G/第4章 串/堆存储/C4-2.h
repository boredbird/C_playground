#ifndef _HSTRING_H
#define _HSTRING_H

typedef enum
{
    OK    = 1,
    ERROR = -1
}Status;

typedef struct
{
    char      *ch;
    int    length;
}HString,*PHString;

/*
 * Function:串的导入
 * Param:
      T:导入之后的串
      chars:字符串指针
 * Return:OK
 */
Status StrAssign(PHString T, char *chars);

/*
 * Function:求串的长度
 * Param:
      S:待求长度的串
 */
int StrLength(HString S);

/*
 * Function:求串的比较
 * Param:
      S:待比较的串
      T:待比较的串
 * Return: 1:S>T、0:S=T、-1:S<T
 */
int StrCompare(HString S, HString T);

/*
 * Function:清空串
 * Param:
      S:待清空的串
 * Return:OK
 */
Status ClearString(PHString S);

/*
 * Function:串的链接
 * Param:
      T:连接之后的串
      S1:待连接的串
      S2:待连接的串
 * Return:OK
 */
Status Concat(PHString T, HString S1, HString S2);

/*
 * Function:求子串
 * Param:
      Sub:截取之后的子串
      S:待截取的串
      pos:截取起始位置
      len:截取长度
 * Return:OK
 */
Status SubString(PHString Sub, HString S, int pos, int len);

#endif