// C2-8.h ������������Polynomial��ʵ��

#ifndef C_2_8_H
#define C_2_8_H

#include "C2-6.h"

// ����ʽ�Ļ����������㷨2.22��2.23��(8��)

typedef LinkList     Polynomial;  // Ϊ����ṹ��һ������������ʽ��
#define DestroyPolyn DestroyList  // �������������������
#define PolynLength  ListLength   // �������������������

int cmp(Term a, Term b); // CreatPolyn()��ʵ��
// ��a��ָ��ֵ<��=��>b��ָ��ֵ���ֱ𷵻�-1��0��+1

void CreatPolyn(Polynomial &p, int m); // �㷨2.22
// ����m���ϵ����ָ����������ʾһԪ����ʽ����������P

void PrintPolyn(Polynomial p);
// ��ӡ���һԪ����ʽP

void AddPolyn(Polynomial &pa, Polynomial &pb); // �㷨2.23
// ����ʽ�ӷ���pa=pa+pb��������һԪ����ʽpb

void AddPolyn1(Polynomial &pa,Polynomial &pb);
// ��һ�ֶ���ʽ�ӷ����㷨��pa=pa+pb��������һԪ����ʽpb

void Opposite(Polynomial p);
// һԪ����ʽpϵ��ȡ��

void SubtractPolyn(Polynomial &pa, Polynomial &pb);
// ����ʽ������pa=pa-pb��������һԪ����ʽpb

void MultiplyPolyn(Polynomial &pa, Polynomial &pb);
// ����ʽ�˷���pa=pa��pb��������һԪ����ʽpb

#endif