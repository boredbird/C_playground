/*bo5-5.cpp ������ͷβ����洢(�洢�ṹ��c5-5.h����)�Ļ�������*/
#include <string.h>
#include <malloc.h>                            
#include <stdio.h>                             
#include <stdlib.h>                           
#include <math.h>                               

#include "C5-4.h"

Status StrAssign(SString T, char *chars)
{                                               /* ����һ����ֵ����chars�Ĵ�T*/
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
    /* �ɴ�S���Ƶô�T*/
    int i;

    for (i = 0; i <= S[0]; i++)
    {
        T[i] = S[i];
    }

    return OK;
}

Status StrEmpty(SString S)
{                                            
    /*��SΪ�մ�,�򷵻�OK,���򷵻�ERROR*/
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
    /* ��ʼ����: ��S��T����*/
    /* �������: ��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0*/
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
    /* ���ش���Ԫ�ظ���*/
    return S[0];
}

Status ClearString(SString S)
{                                      
    /*��ʼ����:��S���ڡ��������:��S��Ϊ�մ�*/
    S[0] = 0;                                    /* ���Ϊ��*/

    return OK;
}

Status Concat(SString T, SString S1, SString S2) 
{                                       
    /* ��T����S1��S2���Ӷ��ɵ��´�����δ�ضϣ��򷵻�OK������ERROR*/
    int i;

    if (S1[0] + S2[0] <= MAXSTRLEN)
    {                                           /* δ�ض�*/
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
    {                                          /* �ض�S2*/
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
    /* ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ����㷨4.3*/
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
    /* �����Ӵ�T������S�е�pos���ַ�֮���λ�á���������,����ֵΪ0��*/
    /* ����,T�ǿ�,1��pos��StrLength(S)���㷨4.5*/
    int i,j;

    if (1 <= pos && pos <= S[0])
    {
        i = pos;
        j = 1;
        while (i <= S[0] && j <= T[0])
            if (S[i] == T[j])               /* �����ȽϺ���ַ�*/
            {
                ++i;
                ++j;
            }
            else                            /* ָ��������¿�ʼƥ��*/
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
    /* ��ʼ����: ��S��T����,1��pos��StrLength(S)+1*/
    /* �������: �ڴ�S�ĵ�pos���ַ�֮ǰ���봮T����ȫ���뷵��OK,���ֲ��뷵��ERROR*/
    int i;

    if (pos < 1 || pos > S [0] + 1)
    {
        return ERROR;
    }
    if (S[0] + T[0] <= MAXSTRLEN)
    { 
        /* ��ȫ����*/
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
        /* ���ֲ���*/
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
    /* ��ʼ����: ��S����,1��pos��StrLength(S)-len+1*/
    /* �������: �Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�*/
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
    /* ��ʼ����: ��S,T��V����,T�Ƿǿմ����˺����봮�Ĵ洢�ṹ�޹أ�*/
    /* �������: ��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�*/
    int i = 1;                                   /* �Ӵ�S�ĵ�һ���ַ�����Ҵ�T*/

    if (StrEmpty(T))                             /* T�ǿմ�*/
    {
        return ERROR;
    }
    do
    {
        i = Index(S, T, i);                      /* ���iΪ����һ��i֮���ҵ����Ӵ�T��λ��*/
        if (i)                                   /* ��S�д��ڴ�T*/
        {
            StrDelete(S, i, StrLength(T));       /* ɾ���ô�T*/
            StrInsert(S, i, V);                  /* ��ԭ��T��λ�ò��봮V*/
            i += StrLength(V);                   /* �ڲ���Ĵ�V����������Ҵ�T*/
        }
    }while (i);

    return OK;
}

void DestroyString(SString T)
{                                          
    /* ����SString�Ƕ�������,�޷�����*/
}

void StrPrint(SString T)
{                                                 /* ����ַ���T��*/
    int i;

    for (i = 1; i <= T[0]; i++)
    {
        printf("%c",T[i]);
        printf("\n");
    }
}

void sever(SString str, SString hstr)            /* �㷨5.8 SString�����飬������������*/
{                                                /* ���ǿմ�str�ָ��������:hsubΪ��һ��','֮ǰ���Ӵ�,strΪ֮����Ӵ�*/
    int n, k, i;                                 /* k����δ��Ե������Ÿ���*/

    SString ch, c1, c2, c3;
    n = StrLength(str);
    StrAssign(c1, ",");
    StrAssign(c2, "(");
    StrAssign(c3, ")");
    SubString(ch, str, 1, 1);
    for (i = 1,k = 0; i <= n && StrCompare(ch, c1) || k != 0; ++i)
    {                                            /* ���������ĵ�һ������*/
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

Status CreateGList(GList *L, SString S)              /* �㷨5.7*/
{                                                    /* ����ͷβ����洢�ṹ,�ɹ�������д��ʽ��S���������L����emp="()"*/
    SString  sub, hsub, emp;
    GList p, q;
    StrAssign(emp, "()");
    if (!StrCompare(S, emp))
    {
        (*L) = NULL;                                  /* �����ձ�*/
    }
    else
    {
        if (!((*L) = (GList)malloc(sizeof(GLNode))))  /* ������*/
        {
            exit(OVERFLOW);
        }
        if (1 == StrLength(S))                        /* SΪ��ԭ��*/
        {
            (*L) -> tag = ATOM;
            (*L) -> atom = S[1];                      /* ������ԭ�ӹ����*/
        }
        else
        {
            (*L) -> tag = LIST;
            p = (*L);
            SubString(sub, S, 2, StrLength(S) - 2);   /* ���������*/
            do
            {                                         /* �ظ���n���ӱ�*/
                sever(sub, hsub);                     /* ��sub�з������ͷ��hsub*/
                CreateGList(&p->ptr.hp, hsub);
                q = p;
                if (!StrEmpty(sub))                    /* ��β����*/
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
    /* �����յĹ����L*/
    (*L) = NULL;

    return OK;
}

void DestroyGList(GList *L)          
{   
    /* ������ͷβ����洢�����ٲ���*/       
    GList q1, q2;
    if ((*L))
    {
        if (ATOM == (*L) -> tag)
        {
            free((*L));                          /* ɾ��ԭ�ӽ��*/
            (*L) = NULL;
        }
        else                                     /* ɾ������*/
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
    /* ����ͷβ����洢�ṹ,�ɹ����L���Ƶõ������T���㷨5.6*/ 
    if (!L)                      
    {
        (*T) = NULL;                                        /* ���ƿձ�*/
    }
    else
    {
        (*T) = (GList)malloc(sizeof(GLNode));               /* ������*/
        if (!(*T))
        {
            exit(OVERFLOW);
        }
        (*T) -> tag = L -> tag;
        if ( ATOM == L -> tag)
        {
            (*T) -> atom = L -> atom;                       /* ���Ƶ�ԭ��*/
        }
        else
        {
            CopyGList(&(*T) -> ptr.hp,L -> ptr.hp);
                                                            /* ���ƹ����L->ptr.hp��һ������T->ptr.hp*/
            CopyGList(&(*T) -> ptr.tp,L -> ptr.tp);
                                                            /* ���ƹ����L->ptr.tp��һ������T->ptr.tp*/
        }
    }

    return OK;
}

int GListLength(GList L)
{                              
    /* ���ع����ĳ���,��Ԫ�ظ���*/
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
    /* ����ͷβ����洢�ṹ,������L����ȡ��㷨5.5*/
    int max, dep;

    GList pp;
    if (!L)
    {
        return 1;
    }                                               /* �ձ����Ϊ1*/
    if (ATOM == L -> tag)
    {
        return 0;   
    }                                               /* ԭ�����Ϊ0*/
    for (max = 0 , pp = L; pp; pp = pp -> ptr.tp)
    {
        dep = GListDepth(pp -> ptr.hp);             /* ����pp->a.ptr.hpΪͷָ����ӱ����*/
        if (dep > max)
        {
            max = dep;
        }
    }

    return max + 1;                                /* �ǿձ������Ǹ�Ԫ�ص���ȵ����ֵ��1*/
}

Status GListEmpty(GList L)
{             
    /* �ж�������Ƿ�Ϊ��*/
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
    /* ȡ�����L��ͷ*/
    GList h, p;

    if (!L)
    {
        printf("�ձ��ޱ�ͷ!\n");
        exit(0);
    }
    p = L -> ptr.tp;
    L->ptr.tp = NULL;
    CopyGList(&h, L);
    L->ptr.tp = p;

    return h;
}

GList GetTail(GList L)
{                                         /* ȡ�����L��β*/
    GList t;

    if (!L)
    {
        printf("�ձ��ޱ�β!\n");
        exit(0);
    }
    CopyGList(&t, L -> ptr.tp);

    return t;
}

Status InsertFirst_GL(GList *L, GList e)
{                  
    /* ��ʼ����: ��������*/
    /* �������: ����Ԫ��e��Ϊ�����L�ĵ�һԪ��(��ͷ,Ҳ�������ӱ�)*/
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
    /* ��ʼ����: �����L����*/
    /* �������: ɾ�������L�ĵ�һԪ��,����e������ֵ*/
    GList p;

    *e = (*L) -> ptr.hp;
    p = *L;
    *L = (*L) -> ptr.tp;	

    free(p);

    return OK;
}

void Traverse_GL(GList L, void(*v)(AtomType))
{              
    /* ���õݹ��㷨���������L*/
    if (L)                                         /* L����*/
        if (ATOM == L -> tag)                      /* LΪ��ԭ��*/
        {
            v(L -> atom);
        }
        else                                       /* LΪ�����*/
        {
            Traverse_GL(L -> ptr.hp,v);
            Traverse_GL(L -> ptr.tp,v);
        }
}
