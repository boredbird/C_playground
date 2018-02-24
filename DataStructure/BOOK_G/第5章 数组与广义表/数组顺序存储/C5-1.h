#ifndef text5_1_H
#define text5_1_H                        

#include <stdarg.h> 

#define MAX_ARRAY_DIM 8                 /*假设数组维数的最大值为8*/

typedef enum
{
    OK       = 1,
    ERROR    = 0
}Status;

typedef int ElemType;

typedef struct Array
{
    ElemType *base;                     /*数组元素基址，由InitArray分配*/
    int dim;                            /*数组维数*/
    int *bounds;                        /*数组维界基址，由InitArray分配*/
    int *constants;                     /*数组映象函数常量基址，由InitArray分配*/
}Array, *PArray;


/*
 * Function:若维数dim和各维长度合法，则构造相应的数组A，并返回OK
 * Parameter:A，dim
        A:数组
 *     dim:维数
 * Return:如果溢出，返回ERROR，否则返回OK
 */
extern Status InitArray(Array *A, int dim,...);
   /*
 * Function:销毁数组A
 * Parameter:A
 *       A:数组
 * Return:如果数组已经被销毁或未初始化，返回ERROR。否则返回OK
 */  
extern Status DestroyArray(Array *A);    
     /*
 * Function:若ap指示的各下标值合法，则求出该元素在A中的相对地址off
 * Parameter:A
 *       A:数组
 * Return:如果溢出，返回ERROR，否则返回OK
 */    
extern Status Locate(Array A, va_list ap, int *off);
 /*
 * Function:在VC++中，...之前的形参不能是引用类型 ...依次为各维的下标值，若各下标合法，则e被赋值为A的相应的元素值
 * Parameter:A,E
 *       A:数组
 *       E:相应的数组元素
 * Return:如果溢出，返回ERROR，否则返回OK
 */
extern Status Value(ElemType *e, Array A, ...); 
    /*
 * Function: ...依次为各维的下标值，若各下标合法，则将e的值赋给A的指定的元素
 * Parameter:A,E
 *       A:数组
 *       E:相应的数组元素
 * Return:如果溢出，返回ERROR，否则返回OK

 */ 
                                                   
extern Status Assign(Array *A, ElemType e, ...);     

#endif
