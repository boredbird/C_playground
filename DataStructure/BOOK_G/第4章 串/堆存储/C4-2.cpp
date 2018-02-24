#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#include "C4-2.h"

Status StrAssign(PHString T, char *chars)
{
    int i, j;

    if (T->ch)
    {
        free(T->ch);
    }

    i = strlen(chars);
    if (!i)
    {
        T->ch = NULL;
        T->length = 0;
    }
    else
    {
        if( !(T->ch = ( char * )malloc( i * sizeof(char) ) ) )
        {
            return ERROR;
        }

        for(j = 0; j < i; j++)
        {
            T->ch[j]  =  chars[j];                    /*将串导入T*/
        }
        T->length  =  i;                              /*将串的长度存放在length变量里面*/
    }

    return OK;
}

int StrLength(HString S)
{
    return S.length;
}

int StrCompare(HString S, HString T)
{
    int i;

    for (i = 0; i < S.length && i < T.length; i++)
    {
        if (S.ch[i] != T.ch[i])
        {
            return S.ch[i] - T.ch[i];
        }
    }

    return S.length - T.length;
}

Status ClearString(PHString S)
{
    if (S->ch)
    {
        free(S->ch);
        S->ch = NULL;
    }
    S->length = 0;

    return OK;
}

Status Concat(PHString T, HString S1, HString S2)
{
    int i;

    if (T->ch)
    {
        free(T->ch);
    }
    if ( !(T->ch = ( char * )malloc( (S1.length + S2.length) * sizeof(char) ) ) )
    {
        return ERROR;
    }

    for (i = 0; i < S1.length; i++)
    {
        T->ch[i]  =  S1.ch[i];
    }

    for (i = 0; i < S2.length; i++)
    {
        T->ch[i + S1.length] = S2.ch[i];
    }
    T->length = S1.length + S2.length;

    return OK;
}

Status SubString(PHString Sub, HString S, int pos, int len)
{
    int i;

    if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1)
    {
        return ERROR;                              /*检验输入的pos是否符合条件，如果不符合就输出ERROR*/
    }

    if (Sub->ch)
    {
        free(Sub->ch);
    }

    if (!len)
    {                                              /*Sub清空*/
        Sub->ch = NULL;
        Sub->length = 0;
    }
    else
    {
        Sub->ch = ( char * )malloc( len * sizeof( char ) );

        for (i = 0; i < len; i++)
        {
            Sub->ch[i] = S.ch[pos - 1 + i];
        }
        Sub->length = len;
    }

    return OK;
}