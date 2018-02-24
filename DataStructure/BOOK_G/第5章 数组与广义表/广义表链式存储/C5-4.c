/*bo5-5.cpp 广义表的头尾链表存储(存储结构由c5-5.h定义)的基本操作*/
#include <string.h>
#include <malloc.h>                            
#include <stdio.h>                             
#include <stdlib.h>                           
#include <math.h>                               

#include "C5-4.h"

Status StrAssign(SString T, char *chars)
{                                               /* 生成一个其值等于chars的串T*/
    int i;

    if (strlen(chars) > MAXSTRLEN)
    {
        return ERROR;
    }
    else
    {
        T[0] = strlen(chars);
        for (i=1; i <= T[0]; i++) 
        {
            T [i] = *(chars + i - 1);
        }

        return OK;
    }
}

Status StrCopy(SString T, SString S)
{                                            
    /* 由串S复制得串T*/
    int i;

    for (i = 0; i <= S[0]; i++)
    {
        T[i] = S[i];
    }

    return OK;
}

Status StrEmpty(SString S)
{                                            
    /*若S为空串,则返回OK,否则返回ERROR*/
    if (0 == S[0])
    {
        return OK;
    }
    else   
    {
        return ERROR;
    }
}

int StrCompare(SString S, SString T)
{                                        
    /* 初始条件: 串S和T存在*/
    /* 操作结果: 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0*/
    int i;

    for (i = 1; i <= S[0] && i <= T[0]; ++i)
    {
        if (S[i] != T[i])	        
        {
            return S[i] - T[i];
        }
    }
    return S[0] - T[0];
}

int StrLength(SString S)
{                                        
    /* 返回串的元素个数*/
    return S[0];
}

Status ClearString(SString S)
{                                      
    /*初始条件:串S存在。操作结果:将S清为空串*/
    S[0] = 0;                                    /* 令串长为零*/

    return OK;
}

Status Concat(SString T, SString S1, SString S2) 
{                                       
    /* 用T返回S1和S2联接而成的新串。若未截断，则返回OK，否则ERROR*/
    int i;

    if (S1[0] + S2[0] <= MAXSTRLEN)
    {                                           /* 未截断*/
        for (i = 1; i <= S1[0]; i++)
        {
            T[i] = S1[i];
        }
        for (i = 1; i <= S2[0]; i++)
        {
            T[S1[0] + i] = S2[i];
        }
        T[0] = S1[0] + S2[0];

        return OK;
    }
    else
    {                                          /* 截断S2*/
        for (i = 1; i <= S1[0]; i++)
        {
            T[i] = S1[i];
        }
        for (i = 1; i <= MAXSTRLEN - S1[0]; i++)
        {
            T[S1[0] + i] = S2[i];
        }
        T[0] = (char)MAXSTRLEN;

        return ERROR;
    }
}

Status SubString(SString Sub, SString S, int pos, int len)
{                                   
    /* 用Sub返回串S的第pos个字符起长度为len的子串。算法4.3*/
    int i;

    if (pos < 1 || pos > S[0] || len < 0 || len > S[0] - pos + 1)
    {
        return ERROR;
    }
    for (i = 1; i <= len; i++) 
    {
        Sub[i] = S[pos + i - 1];
    }
    Sub[0] = len;

    return OK;
}

int Index(SString S, SString T, int pos)
{                               
    /* 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数值为0。*/
    /* 其中,T非空,1≤pos≤StrLength(S)。算法4.5*/
    int i,j;

    if (1 <= pos && pos <= S[0])
    {
        i = pos;
        j = 1;
        while (i <= S[0] && j <= T[0])
            if (S[i] == T[j])               /* 继续比较后继字符*/
            {
                ++i;
                ++j;
            }
            else                            /* 指针后退重新开始匹配*/
            {
                i = i - j +2;
                j = 1;
            }
            if (j > T[0])
            {
                return i - T[0];
            }
            else
            {
                return 0;
            }
    }
    else    
        return 0;
}

Status StrInsert(SString S, int pos, SString T)
{  
    /* 初始条件: 串S和T存在,1≤pos≤StrLength(S)+1*/
    /* 操作结果: 在串S的第pos个字符之前插入串T。完全插入返回OK,部分插入返回ERROR*/
    int i;

    if (pos < 1 || pos > S [0] + 1)
    {
        return ERROR;
    }
    if (S[0] + T[0] <= MAXSTRLEN)
    { 
        /* 完全插入*/
        for (i = S[0]; i >= pos; i--)
        {
            S[i + T[0]] = S[i];
        }
        for (i = pos; i < pos + T[0]; i++)
        {
            S[i] = T[i - pos + 1];
        }
        S[0] = S[0] + T[0];

        return OK;
    }
    else
    { 
        /* 部分插入*/
        for (i = MAXSTRLEN; i <= pos; i--) 
        {
            S[i] = S[i - T[0]];
        }
        for (i = pos; i < pos + T[0]; i++)
        {
            S[i] = T[i - pos + 1];
        }
        S[0] = (char)MAXSTRLEN;

        return ERROR;
    }
}

Status StrDelete(SString S, int pos, int len)
{  
    /* 初始条件: 串S存在,1≤pos≤StrLength(S)-len+1*/
    /* 操作结果: 从串S中删除第pos个字符起长度为len的子串*/
    int i;

    if (pos < 1 || pos > S[0] - len + 1 || len < 0)
    {
        return ERROR;
    }
    for (i = pos + len; i <= S[0]; i++)
    {
        S[i - len] = S[i];
    }
    S[0] -= len;

    return OK;

}

Status Replace(SString S, SString T, SString V)
{                                                         
    /* 初始条件: 串S,T和V存在,T是非空串（此函数与串的存储结构无关）*/
    /* 操作结果: 用V替换主串S中出现的所有与T相等的不重叠的子串*/
    int i = 1;                                   /* 从串S的第一个字符起查找串T*/

    if (StrEmpty(T))                             /* T是空串*/
    {
        return ERROR;
    }
    do
    {
        i = Index(S, T, i);                      /* 结果i为从上一个i之后找到的子串T的位置*/
        if (i)                                   /* 串S中存在串T*/
        {
            StrDelete(S, i, StrLength(T));       /* 删除该串T*/
            StrInsert(S, i, V);                  /* 在原串T的位置插入串V*/
            i += StrLength(V);                   /* 在插入的串V后面继续查找串T*/
        }
    }while (i);

    return OK;
}

void DestroyString(SString T)
{                                          
    /* 由于SString是定长类型,无法销毁*/
}

void StrPrint(SString T)
{                                                 /* 输出字符串T。*/
    int i;

    for (i = 1; i <= T[0]; i++)
    {
        printf("%c",T[i]);
        printf("\n");
    }
}

void sever(SString str, SString hstr)            /* 算法5.8 SString是数组，不需引用类型*/
{                                                /* 将非空串str分割成两部分:hsub为第一个','之前的子串,str为之后的子串*/
    int n, k, i;                                 /* k记尚未配对的左括号个数*/

    SString ch, c1, c2, c3;
    n = StrLength(str);
    StrAssign(c1, ",");
    StrAssign(c2, "(");
    StrAssign(c3, ")");
    SubString(ch, str, 1, 1);
    for (i = 1,k = 0; i <= n && StrCompare(ch, c1) || k != 0; ++i)
    {                                            /* 搜索最外层的第一个逗号*/
        SubString(ch, str, i, 1);
        if (!StrCompare(ch, c2))
        {
            ++k;
        }
        else if (!StrCompare(ch, c3))
        {
            --k;
        }
    }
    if (i <= n)
    {
        SubString(hstr, str, 1, i - 2);
        SubString(str, str, i, n - i + 1);
    }
    else
    {
        StrCopy(hstr, str);
        ClearString(str);
    }
}

Status CreateGList(GList *L, SString S)              /* 算法5.7*/
{                                                    /* 采用头尾链表存储结构,由广义表的书写形式串S创建广义表L。设emp="()"*/
    SString  sub, hsub, emp;
    GList p, q;
    StrAssign(emp, "()");
    if (!StrCompare(S, emp))
    {
        (*L) = NULL;                                  /* 创建空表*/
    }
    else
    {
        if (!((*L) = (GList)malloc(sizeof(GLNode))))  /* 建表结点*/
        {
            exit(OVERFLOW);
        }
        if (1 == StrLength(S))                        /* S为单原子*/
        {
            (*L) -> tag = ATOM;
            (*L) -> atom = S[1];                      /* 创建单原子广义表*/
        }
        else
        {
            (*L) -> tag = LIST;
            p = (*L);
            SubString(sub, S, 2, StrLength(S) - 2);   /* 脱外层括号*/
            do
            {                                         /* 重复建n个子表*/
                sever(sub, hsub);                     /* 从sub中分离出表头串hsub*/
                CreateGList(&p->ptr.hp, hsub);
                q = p;
                if (!StrEmpty(sub))                    /* 表尾不空*/
                {
                    if (!(p = (GLNode *)malloc(sizeof(GLNode))))
                    {
                        exit(OVERFLOW);
                    }
                    p -> tag = LIST;
                    q -> ptr.tp = p;
                }
            }while (!StrEmpty(sub));
            q -> ptr.tp = NULL;
        }
    }
    return OK;
}


Status InitGList(GList *L)
{   
    /* 创建空的广义表L*/
    (*L) = NULL;

    return OK;
}

void DestroyGList(GList *L)          
{   
    /* 广义表的头尾链表存储的销毁操作*/       
    GList q1, q2;
    if ((*L))
    {
        if (ATOM == (*L) -> tag)
        {
            free((*L));                          /* 删除原子结点*/
            (*L) = NULL;
        }
        else                                     /* 删除表结点*/
        {
            q1 = (*L) -> ptr.hp;
            q2 = (*L) -> ptr.tp;
            free((*L));
            (*L) = NULL;
            DestroyGList(&q1);
            DestroyGList(&q2);
        }
    }
}

Status CopyGList(GList *T, GList L)
{                                
    /* 采用头尾链表存储结构,由广义表L复制得到广义表T。算法5.6*/ 
    if (!L)                      
    {
        (*T) = NULL;                                        /* 复制空表*/
    }
    else
    {
        (*T) = (GList)malloc(sizeof(GLNode));               /* 建表结点*/
        if (!(*T))
        {
            exit(OVERFLOW);
        }
        (*T) -> tag = L -> tag;
        if ( ATOM == L -> tag)
        {
            (*T) -> atom = L -> atom;                       /* 复制单原子*/
        }
        else
        {
            CopyGList(&(*T) -> ptr.hp,L -> ptr.hp);
                                                            /* 复制广义表L->ptr.hp的一个副本T->ptr.hp*/
            CopyGList(&(*T) -> ptr.tp,L -> ptr.tp);
                                                            /* 复制广义表L->ptr.tp的一个副本T->ptr.tp*/
        }
    }

    return OK;
}

int GListLength(GList L)
{                              
    /* 返回广义表的长度,即元素个数*/
    int len = 0;

    if (!L)
    {
        return 0;
    }
    if (ATOM == L -> tag)
    {
        return 1;
    }
    while (L)
    {
        L = L -> ptr.tp;
        len++;
    }

    return len;
}

int GListDepth(GList L)
{                                 
    /* 采用头尾链表存储结构,求广义表L的深度。算法5.5*/
    int max, dep;

    GList pp;
    if (!L)
    {
        return 1;
    }                                               /* 空表深度为1*/
    if (ATOM == L -> tag)
    {
        return 0;   
    }                                               /* 原子深度为0*/
    for (max = 0 , pp = L; pp; pp = pp -> ptr.tp)
    {
        dep = GListDepth(pp -> ptr.hp);             /* 求以pp->a.ptr.hp为头指针的子表深度*/
        if (dep > max)
        {
            max = dep;
        }
    }

    return max + 1;                                /* 非空表的深度是各元素的深度的最大值加1*/
}

Status GListEmpty(GList L)
{             
    /* 判定广义表是否为空*/
    if (!L)
    {
        return OK;
    }
    else
    {
        return ERROR;
    }
}

GList GetHead(GList L)
{         
    /* 取广义表L的头*/
    GList h, p;

    if (!L)
    {
        printf("空表无表头!\n");
        exit(0);
    }
    p = L -> ptr.tp;
    L->ptr.tp = NULL;
    CopyGList(&h, L);
    L->ptr.tp = p;

    return h;
}

GList GetTail(GList L)
{                                         /* 取广义表L的尾*/
    GList t;

    if (!L)
    {
        printf("空表无表尾!\n");
        exit(0);
    }
    CopyGList(&t, L -> ptr.tp);

    return t;
}

Status InsertFirst_GL(GList *L, GList e)
{                  
    /* 初始条件: 广义表存在*/
    /* 操作结果: 插入元素e作为广义表L的第一元素(表头,也可能是子表)*/
    GList p = (GList)malloc(sizeof(GLNode));

    if (!p)
    {
        exit(OVERFLOW);
    }
    p -> tag = LIST;
    p -> ptr.hp = e;
    p -> ptr.tp = (*L);
    (*L) = p;

    return OK;
}

Status DeleteFirst_GL(GList *L, GList *e)
{                     
    /* 初始条件: 广义表L存在*/
    /* 操作结果: 删除广义表L的第一元素,并用e返回其值*/
    GList p;

    *e = (*L) -> ptr.hp;
    p = *L;
    *L = (*L) -> ptr.tp;	

    free(p);

    return OK;
}

void Traverse_GL(GList L, void(*v)(AtomType))
{              
    /* 利用递归算法遍历广义表L*/
    if (L)                                         /* L不空*/
        if (ATOM == L -> tag)                      /* L为单原子*/
        {
            v(L -> atom);
        }
        else                                       /* L为广义表*/
        {
            Traverse_GL(L -> ptr.hp,v);
            Traverse_GL(L -> ptr.tp,v);
        }
}
