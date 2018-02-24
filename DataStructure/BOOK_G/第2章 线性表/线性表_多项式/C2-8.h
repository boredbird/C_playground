// C2-8.h 抽象数据类型Polynomial的实现

#ifndef C_2_8_H
#define C_2_8_H

#include "C2-6.h"

// 多项式的基本操作及算法2.22、2.23等(8个)

typedef LinkList     Polynomial;  // 为链表结构起一个别名“多项式”
#define DestroyPolyn DestroyList  // 定义链表操作函数别名
#define PolynLength  ListLength   // 定义链表操作函数别名

int cmp(Term a, Term b); // CreatPolyn()的实参
// 依a的指数值<、=或>b的指数值，分别返回-1、0或+1

void CreatPolyn(Polynomial &p, int m); // 算法2.22
// 输入m项的系数和指数，建立表示一元多项式的有序链表P

void PrintPolyn(Polynomial p);
// 打印输出一元多项式P

void AddPolyn(Polynomial &pa, Polynomial &pb); // 算法2.23
// 多项式加法：pa=pa+pb，并销毁一元多项式pb

void AddPolyn1(Polynomial &pa,Polynomial &pb);
// 另一种多项式加法的算法：pa=pa+pb，并销毁一元多项式pb

void Opposite(Polynomial p);
// 一元多项式p系数取反

void SubtractPolyn(Polynomial &pa, Polynomial &pb);
// 多项式减法：pa=pa-pb，并销毁一元多项式pb

void MultiplyPolyn(Polynomial &pa, Polynomial &pb);
// 多项式乘法：pa=pa×pb，并销毁一元多项式pb

#endif