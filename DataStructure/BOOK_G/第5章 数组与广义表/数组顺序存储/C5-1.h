#ifndef text5_1_H
#define text5_1_H                        

#include <stdarg.h> 

#define MAX_ARRAY_DIM 8                 /*��������ά�������ֵΪ8*/

typedef enum
{
    OK       = 1,
    ERROR    = 0
}Status;

typedef int ElemType;

typedef struct Array
{
    ElemType *base;                     /*����Ԫ�ػ�ַ����InitArray����*/
    int dim;                            /*����ά��*/
    int *bounds;                        /*����ά���ַ����InitArray����*/
    int *constants;                     /*����ӳ����������ַ����InitArray����*/
}Array, *PArray;


/*
 * Function:��ά��dim�͸�ά���ȺϷ���������Ӧ������A��������OK
 * Parameter:A��dim
        A:����
 *     dim:ά��
 * Return:������������ERROR�����򷵻�OK
 */
extern Status InitArray(Array *A, int dim,...);
   /*
 * Function:��������A
 * Parameter:A
 *       A:����
 * Return:��������Ѿ������ٻ�δ��ʼ��������ERROR�����򷵻�OK
 */  
extern Status DestroyArray(Array *A);    
     /*
 * Function:��apָʾ�ĸ��±�ֵ�Ϸ����������Ԫ����A�е���Ե�ַoff
 * Parameter:A
 *       A:����
 * Return:������������ERROR�����򷵻�OK
 */    
extern Status Locate(Array A, va_list ap, int *off);
 /*
 * Function:��VC++�У�...֮ǰ���ββ������������� ...����Ϊ��ά���±�ֵ�������±�Ϸ�����e����ֵΪA����Ӧ��Ԫ��ֵ
 * Parameter:A,E
 *       A:����
 *       E:��Ӧ������Ԫ��
 * Return:������������ERROR�����򷵻�OK
 */
extern Status Value(ElemType *e, Array A, ...); 
    /*
 * Function: ...����Ϊ��ά���±�ֵ�������±�Ϸ�����e��ֵ����A��ָ����Ԫ��
 * Parameter:A,E
 *       A:����
 *       E:��Ӧ������Ԫ��
 * Return:������������ERROR�����򷵻�OK

 */ 
                                                   
extern Status Assign(Array *A, ElemType e, ...);     

#endif
