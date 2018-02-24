// C1.h
#ifndef C1_H
#define C1_H

#include <string.h>
#include <ctype.h>
#include <malloc.h>   // malloc()等
#include <limits.h>   // INT_MAX等
#include <stdio.h>    // printf()等
#include <stdlib.h>   // atoi()
#include <io.h>       // eof()
#include <math.h>     // floor(), ceil(), abs()
#include <process.h>  // exit()
#include <iostream.h> // cout(), cin()

// 函数结果状态代码
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#ifndef OVERFLOW
#define OVERFLOW    -2 
#endif // math.h中可能已定义OVERFLOW

typedef int Status;  // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE

#endif
