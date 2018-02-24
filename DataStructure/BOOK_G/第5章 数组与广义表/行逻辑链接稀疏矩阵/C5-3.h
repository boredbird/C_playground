#ifndef _C5_3_H
#define _C5_3_H

#define MAXSIZE         100	            /* ����Ԫ���������ֵ*/
#define MAXCOL          20              /* ���������*/

typedef enum
{
    OK    = 1,
    ERROR = 0
}Status;

typedef struct Triple 
{
    int i, j;                             /* ���±�,���±�*/
    int e;                               /* ����Ԫ��ֵ*/
}Triple, *PTriple;

typedef struct RLSMatrix
{
    Triple data[MAXSIZE + 1];              /* ����Ԫ��Ԫ���,data[0]δ��*/
    int rpos[MAXCOL + 1];                   /* ���е�һ������Ԫ�ص�λ�ñ�,��c5-2.h���ӵ���*/
    int mu, nu, tu;                        /* ����������������ͷ���Ԫ����*/
}RLSMatrix, *PRLSMatrix;

/*
 * Function: ����ϡ�����M
 * Parameter:M
 *       M:ϡ�����
 * Return: OK
 */
extern Status CreateSMatrix(RLSMatrix *M);

/*
 * Function:����ϡ�����M(ʹMΪ0��0��0������Ԫ�صľ���)
 * Parameter:M
 *       M:ϡ�����
 */
extern void DestroySMatrix(RLSMatrix *M);

/*
 * Function:���ϡ�����M

 * Parameter:M
 *       M:ϡ�����
 */
extern void PrintSMatrix(RLSMatrix M);

/*
 * Function:��ϡ�����M���Ƶõ�T
 * Parameter:
 *       M:ϡ�����
 *       T:����
 * Return:OK
 */
extern Status CopySMatrix(RLSMatrix M, RLSMatrix *T);

/*
 * Function:��ϡ�����ĺ�Q=M+N
 * Parameter:M��N��Q
 *       M:ϡ�����
 *       N:ϡ�����
 *       Q:ϡ�����
 * Return:�ɹ�����OK,ʧ�ܷ���ERROR
 */
extern Status AddSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix *Q);

/*
 * Function:��ϡ�����Ĳ�Q=M-N
 * Parameter:Q,M,N
 *       M:ϡ�����
 *       N:ϡ�����
 *       Q:����
 * Return:�ɹ�����OK,ʧ�ܷ���ERROR
 */
extern Status SubtSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix *Q);

/*
 * Function:��ϡ�����˻�Q=M��N
 * Parameter:M,N,Q
 *       M:�������M
 *       N:�������N
 *       Q:ϡ�����Q
 * Return:�ɹ�����OK,ʧ�ܷ���ERROR
 */
extern Status MultSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix *Q);

/*
 * Function: ��ϡ�����M��ת�þ���T
 * Parameter:m��T
 *       M:ϡ�����M
 *       T:ת�þ���T
 * Return:OK
 */
Status TransposeSMatrix(RLSMatrix M, RLSMatrix *T);

#endif
