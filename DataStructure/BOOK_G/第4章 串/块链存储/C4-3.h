#ifndef C4_3_H
#define C4_3_H

#define CHUNKSIZE 4                   /* �����û�����Ŀ��С */

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
    Chunk *head,*tail;                /* ����ͷ��βָ�� */
    int   curlen;                     /* ���ĵ�ǰ���� */
}LString,*PLString;

/**
*Fucntion:  ��ʼ���ַ����������մ�T
*Param:
*           T:Ҫ����ʼ���Ŀ����ַ���ָ��
*/
extern void SetBlank(char c);

/**
*Fucntion:  ��ʼ���ַ����������մ�T
*Param:
*           T:Ҫ����ʼ���Ŀ����ַ���ָ��
*/
extern void InitString(LString *T);

/**
*Function:  ����һ����ֵ����chars�Ĵ�T(Ҫ��chars�в������������ַ�)
*Param:
*           T:�����ַ���ָ��
*           chars:�ַ���ָ��
*Return:    �ɹ�����OK�����򷵻�ERROR
*/
extern Status StrAssign(LString *T, char *chars);

/**
*Function:  �ɴ�S���Ƶô�T(���������ַ�һ�鿽��)
*Param:
*           T:��������ַ���ָ��
*           S:���������ַ���
*Return:    �ɹ�����OK�����򷵻�ERROR
*/
extern Status StrCopy(LString *T, LString S);

/**
*Function:  �жϴ��Ƿ�Ϊ��
*Param:
*           S:���жϵ��ַ���
*Return:    ��SΪ�մ�,�򷵻�OK,���򷵻�ERROR
*/
extern Status StrEmpty(LString S);

/**
*Function:  ���Ƚ�
*Param:
*           S:���ȽϵĴ�
*           T:���ȽϵĴ�
*Return:    ��S>T,�򷵻�ֵ>0;��S = T,�򷵻�ֵ = 0;��S < T ,�򷵻�ֵ < 0
*/
extern int StrCompare(LString S, LString T);

/**
*Function:  �󴮳���
*Param:
*           S:��
*Return:    ��S��Ԫ�صĸ����������ĳ���
*/
extern int StrLength(LString S);

/**
*Function:  ��մ�
*Param:
*           S:����յĴ�ָ��
*Return:    OK
*/
extern Status ClearString(LString *S);

/**
*Function:  ���Ӵ�
*Param:
*           T:���Ӻ���ַ���
*           S1��S2:�����ӵ��ַ�����T = S1 + S2
*Return:    OK
*/
extern Status Concat(LString *T, LString S1, LString S2);

/**
*Function:  ��ȡ��
*Param:
*           Sub:��ȡ��Ĵ�
*           S:����ȡ�Ĵ�
*           pos:��ȡ��ʼλ��
*           len:��ȡ����
*Return:    �ɹ�����OK�����򷵻�ERROR
*/
extern Status SubString(LString *Sub, LString S, int pos, int len);

/**
*Fucntion:  �����Ӵ�
*Param:
*           S:�����ҵ�����
*           T:ƥ�����Ӵ�
*           pos:������ʼλ��
*Return:    �����ҵ������ص�һ��T����S���г��ֵ�λ�á����򷵻�0
*/
extern int Index(LString S, LString T, int pos);

/**
*Function:  ѹ����(������в���Ҫ���������ַ�)
*Param:
*           S:��ѹ���Ĵ�
*/
extern void Zip(LString *S);

/**
*Function:  �ڴ�S�ĵ�pos���ַ�֮ǰ���봮T
*Param:
*           S:�����������ָ��
*           pos:������ʼλ��
*           T:��������Ӵ�
*Return:    �ɹ�����OK,ʧ�ܷ���ERROR
*/
extern Status StrInsert(LString *S, int pos, LString T);

/**
*Function:  �Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
*Param:
*           S:��ɾ���Ĵ�ָ��
*           pos:ɾ����ʼλ��
*           len:ɾ������
*Return:    �ɹ�����OK,ʧ�ܷ���ERROR
*/
extern Status StrDelete(LString *S, int pos, int len);

/**
*Function:  ��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�
*Param:
*           S:���滻������ָ��
*           T:ƥ�䴮
*           V:�滻��
*Return:    �ɹ�����OK,ʧ�ܷ���ERROR
*/
extern Status Replace(LString *S, LString T, LString V);

/**
*Function:  �����
*Param:
*           T:����ӡ�Ĵ�
*/
extern void StrPrint(LString T);

/**
*Function:  ���ٴ�
*/
extern void DestroyString(LString T);

#endif