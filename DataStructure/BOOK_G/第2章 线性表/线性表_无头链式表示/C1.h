// C1.h
#ifndef C1_H
#define C1_H

#include <string.h>
#include <ctype.h>
#include <malloc.h>   // malloc()��
#include <limits.h>   // INT_MAX��
#include <stdio.h>    // printf()��
#include <stdlib.h>   // atoi()
#include <io.h>       // eof()
#include <math.h>     // floor(), ceil(), abs()
#include <process.h>  // exit()
#include <iostream.h> // cout(), cin()

// �������״̬����
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#ifndef OVERFLOW
#define OVERFLOW    -2 
#endif // math.h�п����Ѷ���OVERFLOW

typedef int Status;  // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE

#endif
