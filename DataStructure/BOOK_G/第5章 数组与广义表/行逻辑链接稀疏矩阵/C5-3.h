#ifndef _C5_3_H
#define _C5_3_H

#define MAXSIZE         100	            /* 非零元个数的最大值*/
#define MAXCOL          20              /* 最大行列数*/

typedef enum
{
    OK    = 1,
    ERROR = 0
}Status;

typedef struct Triple 
{
    int i, j;                             /* 行下标,列下标*/
    int e;                               /* 非零元素值*/
}Triple, *PTriple;

typedef struct RLSMatrix
{
    Triple data[MAXSIZE + 1];              /* 非零元三元组表,data[0]未用*/
    int rpos[MAXCOL + 1];                   /* 各行第一个非零元素的位置表,比c5-2.h增加的项*/
    int mu, nu, tu;                        /* 矩阵的行数、列数和非零元个数*/
}RLSMatrix, *PRLSMatrix;

/*
 * Function: 创建稀疏矩阵M
 * Parameter:M
 *       M:稀疏矩阵
 * Return: OK
 */
extern Status CreateSMatrix(RLSMatrix *M);

/*
 * Function:销毁稀疏矩阵M(使M为0行0列0个非零元素的矩阵)
 * Parameter:M
 *       M:稀疏矩阵
 */
extern void DestroySMatrix(RLSMatrix *M);

/*
 * Function:输出稀疏矩阵M

 * Parameter:M
 *       M:稀疏矩阵
 */
extern void PrintSMatrix(RLSMatrix M);

/*
 * Function:由稀疏矩阵M复制得到T
 * Parameter:
 *       M:稀疏矩阵
 *       T:矩阵
 * Return:OK
 */
extern Status CopySMatrix(RLSMatrix M, RLSMatrix *T);

/*
 * Function:求稀疏矩阵的和Q=M+N
 * Parameter:M，N，Q
 *       M:稀疏矩阵
 *       N:稀疏矩阵
 *       Q:稀疏矩阵
 * Return:成功返回OK,失败返回ERROR
 */
extern Status AddSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix *Q);

/*
 * Function:求稀疏矩阵的差Q=M-N
 * Parameter:Q,M,N
 *       M:稀疏矩阵
 *       N:稀疏矩阵
 *       Q:矩阵
 * Return:成功返回OK,失败返回ERROR
 */
extern Status SubtSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix *Q);

/*
 * Function:求稀疏矩阵乘积Q=M＊N
 * Parameter:M,N,Q
 *       M:非零矩阵M
 *       N:非零矩阵N
 *       Q:稀疏矩阵Q
 * Return:成功返回OK,失败返回ERROR
 */
extern Status MultSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix *Q);

/*
 * Function: 求稀疏矩阵M的转置矩阵T
 * Parameter:m和T
 *       M:稀疏矩阵M
 *       T:转置矩阵T
 * Return:OK
 */
Status TransposeSMatrix(RLSMatrix M, RLSMatrix *T);

#endif
