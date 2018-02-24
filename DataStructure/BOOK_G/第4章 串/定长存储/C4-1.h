#ifndef STRING_H
#define STRING_H

#define  MAXSTRLEN   255                /* �û�����255���ڶ�����󴮳���1���ֽڣ� */	

typedef enum
{
	 OK              = 1,
	 ERROR           = 0
}Status;

typedef char SString[MAXSTRLEN+1];      /* 0�ŵ�Ԫ��Ŵ��ĳ��� */

/*
 * Function:���ĵ���
 * Param:
       T:�������ַ���
       chars:�ַ���ָ��
   Return :�ɹ�����OK,ʧ�ܷ���ERROR
 */
Status StrAssign(SString T, char *chars);

/*
 * Function:���ĸ���
 * Param:
      T:������Ĵ�
      S:�������Ĵ�
 * Return:OK
 */
Status StrCopy(SString T, SString S);

/*
 * Function:�ж��Ƿ�Ϊ�մ�
 * Param:
       S:���жϵĴ�
   Return:�մ�:ERROR,�ǿ�:OK
 */
Status StrEmpty(SString S);

/*
 * Function:�󴮵ıȽ�
 * Param:
      S:���ȽϵĴ�
      T:���ȽϵĴ�
 * Return: 1:S>T��0:S=T��-1:S<T
 */
int StrCompare(SString S, SString T);

/*
 * Function:�󴮵ĳ���
 * Param:
      S:���󳤶ȵĴ�
   Return: ����
 */
int StrLength(SString S);

/*
 * Function:��մ�
 * Param:
      S:����յĴ�
 * Return:OK
 */
Status ClearString(SString S);

/*
 * Function:��������
 * Param:
      T:����֮��Ĵ�
      S1:�����ӵĴ�
      S2:�����ӵĴ�
 * Return:OK
 */
Status Concat(SString T, SString S1, SString S2);

/*
 * Function:���Ӵ�
 * Param:
      Sub:��ȡ֮����Ӵ�
      S:����ȡ�Ĵ�
      pos:��ȡ��ʼλ��
      len:��ȡ����
 * Return:OK
 */
Status SubString(SString Sub, SString S, int pos, int len);

/*
 * Function:�����Ӵ�T������S�е�pos���ַ�֮���һ�γ��ֵ�λ�á�
 * Param:
      S:����
      T:�����ҵ��Ӵ�
      pos:������ʼλ��
 * Return:�Ӵ�T������S�е�pos���ַ�֮���λ�á���������,�򷵻�ֵΪ0
 */
int Index(SString S, SString T, int pos);

/*
 * Function:�ڴ�S�ĵ�pos���ַ�֮ǰ���봮T��
 * Param:
      S:�����������
      T:�Ӵ�
      pos:����λ��
 * Return:�ɹ�����OK��ʧ�ܷ���ERROR
 */
Status StrInsert(SString S, int pos, SString T);

/*
 * Function:�Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
 * Param:
      S:��ɾ���Ĵ�
      pos:ɾ����ʼλ��
      len:ɾ���ĳ���
 * Return:OK
 */
Status StrDelete(SString S, int pos, int len);

/*
 * Function:��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�
 * Param:
      S:���滻������
      T:���滻���Ӵ�
      V:�滻��
 * Return:�ɹ�����OK��ʧ�ܷ���ERROR
 */
Status Replace(SString S, SString T, SString V);

/*
 * Function:���ٴ�
      T:�����ٵĴ�
 */
void DestroyString(SString T);

/*
 * Function:��ӡ�����
 * Param:
      T:����ӡ�Ĵ�
 */
void StrPrint(SString T);

#endif