#ifndef TEST_H
#define TEST_H

#define MAXSIZE    100               /*����Ԫ���������ֵ*/

typedef enum
{
    OK	  = 1,
    ERROR = 0
}Status;

typedef struct Triple
{
    int i,j;                         /*���±�,���±�*/
    int e;                           /*����Ԫ��ֵ*/
}Triple, *PTriple;

typedef struct TSMatrix
{
    struct Triple data[MAXSIZE+1];   /*����Ԫ��Ԫ���,data[0]δ��*/
    int mu,nu,tu;                    /*����������������ͷ���Ԫ����*/
}TSMatrix, *PTSMatrix;

 /*
 * Function:  ����ϡ�����M
 * Parameter:M
 *       M:ϡ�����
 * Return:OK
 */

extern Status CreateSMatrix(TSMatrix *M); 
  /*
 *  Function: ����ϡ�����M
 * Parameter:M
 *         M:ϡ�����
 */

extern void DestroySMatrix(TSMatrix *M);  
 /*
 * Function: ���ϡ�����M
 * Parameter:M
 *       M:ϡ�����
 */  
     
extern void PrintSMatrix(TSMatrix M);     
 /*
 * Function: ��ϡ�����M���Ƶõ�T
 * Parameter:M,T
 *      M:ϡ�����
 *      T:����
 * Return:OK
 */ 
      
extern Status CopySMatrix(TSMatrix M, TSMatrix *T);
/*
 * Function:  ��ϡ�����ĺ�Q=M+N
 * Parameter:Q,M,N
 *       M:ϡ�����
 *       N:ϡ�����
 *       Q:����
 * Return:���M.nu != N.mu���أ�ERROR�����򷵻أ�OK
 */
                 
extern Status AddSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q);
/*
 * Function:  ��ϡ�����Ĳ�Q=M-N
 * Parameter:Q,M,N
 *       M:ϡ�����
 *       N:ϡ�����
 *       Q:����
 * Return:OK
 */  

extern Status SubtSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q); 
/*
 * Function: ��ϡ�����ĳ˻�Q=M*N
 * Parameter:Q,M,N
 *       M:ϡ�����
 *       N:ϡ�����
 *       Q:����
 * Return:���M.nu != N.mu�Ļ����أ�ERROR�����򷵻أ�OK
 */

extern Status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q);
/*
 * Function: ��ϡ�����M��ת�þ���T��
 * Parameter:M,T
 *       M:ϡ�����
 *       T:ϡ�����     
 * Return:OK
 */

extern Status TransposeSMatrix(TSMatrix M, TSMatrix *T);      

/*
 * Function: �Ƚ��������Ĵ�С
 * Parameter:c1,c2
 *       c1:������
 *       c2:������
 * Return: ���c1 < c2 : 1,���c1 == c2: 0,���c1 > c2 :-1
*/
extern int comp(int c1, int c2);  

#endif