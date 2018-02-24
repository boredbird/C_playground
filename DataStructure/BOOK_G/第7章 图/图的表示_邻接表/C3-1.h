// C3-1.h ջ��˳��洢��ʾ
#ifndef C_3_1_H
#define C_3_1_H

#include "C1.h"

#define STACK_INIT_SIZE 10 // �洢�ռ��ʼ������
#define STACK_INCREMENT 2 // �洢�ռ��������
typedef int SElemType; // ջԪ������

struct SqStack
{
    SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
    SElemType *top; // ջ��ָ��
    int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}; // ˳��ջ

void InitStack(SqStack &S);
void DestroyStack(SqStack &S);
void ClearStack(SqStack &S);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status GetTop(SqStack S, SElemType &e);
void Push(SqStack &S, SElemType e);
Status Pop(SqStack &S, SElemType &e);
void StackTraverse(SqStack S, void(*visit)(SElemType));

#endif