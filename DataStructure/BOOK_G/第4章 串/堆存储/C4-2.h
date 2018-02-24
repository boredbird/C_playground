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
 * Function:���ĵ���
 * Param:
      T:����֮��Ĵ�
      chars:�ַ���ָ��
 * Return:OK
 */
Status StrAssign(PHString T, char *chars);

/*
 * Function:�󴮵ĳ���
 * Param:
      S:���󳤶ȵĴ�
 */
int StrLength(HString S);

/*
 * Function:�󴮵ıȽ�
 * Param:
      S:���ȽϵĴ�
      T:���ȽϵĴ�
 * Return: 1:S>T��0:S=T��-1:S<T
 */
int StrCompare(HString S, HString T);

/*
 * Function:��մ�
 * Param:
      S:����յĴ�
 * Return:OK
 */
Status ClearString(PHString S);

/*
 * Function:��������
 * Param:
      T:����֮��Ĵ�
      S1:�����ӵĴ�
      S2:�����ӵĴ�
 * Return:OK
 */
Status Concat(PHString T, HString S1, HString S2);

/*
 * Function:���Ӵ�
 * Param:
      Sub:��ȡ֮����Ӵ�
      S:����ȡ�Ĵ�
      pos:��ȡ��ʼλ��
      len:��ȡ����
 * Return:OK
 */
Status SubString(PHString Sub, HString S, int pos, int len);

#endif