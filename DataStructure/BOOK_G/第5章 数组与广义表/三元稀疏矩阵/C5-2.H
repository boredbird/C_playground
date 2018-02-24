#ifndef TEST_H
#define TEST_H

#define MAXSIZE    100               /*非零元个数的最大值*/

typedef enum
{
    OK	  = 1,
    ERROR = 0
}Status;

typedef struct Triple
{
    int i,j;                         /*行下标,列下标*/
    int e;                           /*非零元素值*/
}Triple, *PTriple;

typedef struct TSMatrix
{
    struct Triple data[MAXSIZE+1];   /*非零元三元组表,data[0]未用*/
    int mu,nu,tu;                    /*矩阵的行数、列数和非零元个数*/
}TSMatrix, *PTSMatrix;

 /*
 * Function:  创建稀疏矩阵M
 * Parameter:M
 *       M:稀疏矩阵
 * Return:OK
 */

extern Status CreateSMatrix(TSMatrix *M); 
  /*
 *  Function: 销毁稀疏矩阵M
 * Parameter:M
 *         M:稀疏矩阵
 */

extern void DestroySMatrix(TSMatrix *M);  
 /*
 * Function: 输出稀疏矩阵M
 * Parameter:M
 *       M:稀疏矩阵
 */  
     
extern void PrintSMatrix(TSMatrix M);     
 /*
 * Function: 由稀疏矩阵M复制得到T
 * Parameter:M,T
 *      M:稀疏矩阵
 *      T:矩阵
 * Return:OK
 */ 
      
extern Status CopySMatrix(TSMatrix M, TSMatrix *T);
/*
 * Function:  求稀疏矩阵的和Q=M+N
 * Parameter:Q,M,N
 *       M:稀疏矩阵
 *       N:稀疏矩阵
 *       Q:矩阵
 * Return:如果M.nu != N.mu返回：ERROR，否则返回：OK
 */
                 
extern Status AddSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q);
/*
 * Function:  求稀疏矩阵的差Q=M-N
 * Parameter:Q,M,N
 *       M:稀疏矩阵
 *       N:稀疏矩阵
 *       Q:矩阵
 * Return:OK
 */  

extern Status SubtSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q); 
/*
 * Function: 求稀疏矩阵的乘积Q=M*N
 * Parameter:Q,M,N
 *       M:稀疏矩阵
 *       N:稀疏矩阵
 *       Q:矩阵
 * Return:如果M.nu != N.mu的话返回：ERROR，否则返回：OK
 */

extern Status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q);
/*
 * Function: 求稀疏矩阵M的转置矩阵T。
 * Parameter:M,T
 *       M:稀疏矩阵
 *       T:稀疏矩阵     
 * Return:OK
 */

extern Status TransposeSMatrix(TSMatrix M, TSMatrix *T);      

/*
 * Function: 比较两个数的大小
 * Parameter:c1,c2
 *       c1:整型数
 *       c2:整型数
 * Return: 如果c1 < c2 : 1,如果c1 == c2: 0,如果c1 > c2 :-1
*/
extern int comp(int c1, int c2);  

#endif