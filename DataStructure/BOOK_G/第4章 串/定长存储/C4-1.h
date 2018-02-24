#ifndef STRING_H
#define STRING_H

#define  MAXSTRLEN   255                /* 用户可在255以内定义最大串长（1个字节） */	

typedef enum
{
	 OK              = 1,
	 ERROR           = 0
}Status;

typedef char SString[MAXSTRLEN+1];      /* 0号单元存放串的长度 */

/*
 * Function:串的导入
 * Param:
       T:导入后的字符串
       chars:字符串指针
   Return :成功返回OK,失败返回ERROR
 */
Status StrAssign(SString T, char *chars);

/*
 * Function:串的复制
 * Param:
      T:拷贝后的串
      S:待拷贝的串
 * Return:OK
 */
Status StrCopy(SString T, SString S);

/*
 * Function:判断是否为空串
 * Param:
       S:待判断的串
   Return:空串:ERROR,非空:OK
 */
Status StrEmpty(SString S);

/*
 * Function:求串的比较
 * Param:
      S:待比较的串
      T:待比较的串
 * Return: 1:S>T、0:S=T、-1:S<T
 */
int StrCompare(SString S, SString T);

/*
 * Function:求串的长度
 * Param:
      S:待求长度的串
   Return: 串长
 */
int StrLength(SString S);

/*
 * Function:清空串
 * Param:
      S:待清空的串
 * Return:OK
 */
Status ClearString(SString S);

/*
 * Function:串的链接
 * Param:
      T:连接之后的串
      S1:待连接的串
      S2:待连接的串
 * Return:OK
 */
Status Concat(SString T, SString S1, SString S2);

/*
 * Function:求子串
 * Param:
      Sub:截取之后的子串
      S:待截取的串
      pos:截取起始位置
      len:截取长度
 * Return:OK
 */
Status SubString(SString Sub, SString S, int pos, int len);

/*
 * Function:返回子串T在主串S中第pos个字符之后第一次出现的位置。
 * Param:
      S:主串
      T:待查找的子串
      pos:查找起始位置
 * Return:子串T在主串S中第pos个字符之后的位置。若不存在,则返回值为0
 */
int Index(SString S, SString T, int pos);

/*
 * Function:在串S的第pos个字符之前插入串T。
 * Param:
      S:待插入的主串
      T:子串
      pos:插入位置
 * Return:成功返回OK，失败返回ERROR
 */
Status StrInsert(SString S, int pos, SString T);

/*
 * Function:从串S中删除第pos个字符起长度为len的子串
 * Param:
      S:待删除的串
      pos:删除起始位置
      len:删除的长度
 * Return:OK
 */
Status StrDelete(SString S, int pos, int len);

/*
 * Function:用V替换主串S中出现的所有与T相等的不重叠的子串
 * Param:
      S:待替换的主串
      T:待替换的子串
      V:替换串
 * Return:成功返回OK，失败返回ERROR
 */
Status Replace(SString S, SString T, SString V);

/*
 * Function:销毁串
      T:待销毁的串
 */
void DestroyString(SString T);

/*
 * Function:打印输出串
 * Param:
      T:待打印的串
 */
void StrPrint(SString T);

#endif