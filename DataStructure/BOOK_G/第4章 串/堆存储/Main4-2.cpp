#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#include "C4-2.h"

void print(HString T)
{
    int i;

    for (i = 0; i < T.length; i++)
    {
        printf("%c", T.ch[i]);
    }
    printf("\n\n");
}

int main()
{
    char chars1[]  =  "";
    char chars2[]  =  "";
    int x, pos, len, comp;
    HString  T, S, W, Sub;
   
    Sub.ch  =  (char *)malloc(sizeof(char));
    W.ch    =  (char *)malloc(sizeof(char));
    T.ch    =  (char *)malloc(sizeof(char));
    S.ch    =  (char *)malloc(sizeof(char));

    /*功能列表*/
    printf("1.输入串\n");
    printf("2.串的长度\n");
    printf("3.串的比较\n");
    printf("4.串连接\n");
    printf("5.清空串\n");
    printf("6.求子串\n");
    printf("7.输出串\n");
    printf("0.结束\n");
               
    printf("\n开始输入串1:");                                     /*初始化串1*/
    gets( chars1 );
    StrAssign( &T, chars1 );
    printf("串1建立完毕!\n\n");     

    while ( 1 )
    {
        printf("请输入所需要的操作(0-7):");                                                                
        while ( ( scanf("%d", &x) ) != 1 || x > 7 || x < 0 )      /*对于输入的容错处理*/
        {
            printf("输入错误，请重新输入！\n");
            fflush( stdin );
        }
        printf("\n");

        switch ( x )
        {
        case 0:
            exit( 0 );
        case 1:
            fflush( stdin );                                      /*刷新键盘缓冲区，为输入字符串做准备*/
            printf("开始输入串1:");
            gets( chars1 );
            StrAssign( &T, chars1);
            printf("串1建立完毕!\n\n");              
            break;
        case 2:
            printf("串1的长度为:%d\n\n", StrLength( T ));           
            break;
        case 3:
            fflush( stdin );                                                      
            printf("请输入要比较的字符串2:");
            gets( chars2 );
            StrAssign( &S, chars2);
            comp = StrCompare( T, S);
            printf("比较结果：串1%c串2\n\n",comp > 0 ? '>' : ( comp < 0 ? '<' : '=') );           
            break;
        case 4:
            fflush( stdin );                                             
            printf("请输入要连接的字符串2:");
            gets( chars2 );
            StrAssign( &S, chars2 );
            Concat( &W, T, S);
            printf("两个串链接后为:");
            print( W );         
            break;
        case 5:
            printf("串1是否清空(0.未清空1.已清空)\n%d\n", ClearString( &T ) );          
            break;
        case 6:
            printf("输入串1中子串的位置和长度(中间以空格隔开):");
            while ( ( scanf("%d %d", &pos, &len) ) != 2 || ERROR == SubString(&Sub, T, pos, len) )
            {
                printf("输入错误，请重新输入！\n");
                fflush( stdin );
            }
            printf("子串为：");
            print( Sub );           
            break;
        case 7:
            printf("该串为： ");
            print( T );         
            break;
        }
    }

    return 0;
}
