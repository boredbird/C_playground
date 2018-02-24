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

    /*�����б�*/
    printf("1.���봮\n");
    printf("2.���ĳ���\n");
    printf("3.���ıȽ�\n");
    printf("4.������\n");
    printf("5.��մ�\n");
    printf("6.���Ӵ�\n");
    printf("7.�����\n");
    printf("0.����\n");
               
    printf("\n��ʼ���봮1:");                                     /*��ʼ����1*/
    gets( chars1 );
    StrAssign( &T, chars1 );
    printf("��1�������!\n\n");     

    while ( 1 )
    {
        printf("����������Ҫ�Ĳ���(0-7):");                                                                
        while ( ( scanf("%d", &x) ) != 1 || x > 7 || x < 0 )      /*����������ݴ���*/
        {
            printf("����������������룡\n");
            fflush( stdin );
        }
        printf("\n");

        switch ( x )
        {
        case 0:
            exit( 0 );
        case 1:
            fflush( stdin );                                      /*ˢ�¼��̻�������Ϊ�����ַ�����׼��*/
            printf("��ʼ���봮1:");
            gets( chars1 );
            StrAssign( &T, chars1);
            printf("��1�������!\n\n");              
            break;
        case 2:
            printf("��1�ĳ���Ϊ:%d\n\n", StrLength( T ));           
            break;
        case 3:
            fflush( stdin );                                                      
            printf("������Ҫ�Ƚϵ��ַ���2:");
            gets( chars2 );
            StrAssign( &S, chars2);
            comp = StrCompare( T, S);
            printf("�ȽϽ������1%c��2\n\n",comp > 0 ? '>' : ( comp < 0 ? '<' : '=') );           
            break;
        case 4:
            fflush( stdin );                                             
            printf("������Ҫ���ӵ��ַ���2:");
            gets( chars2 );
            StrAssign( &S, chars2 );
            Concat( &W, T, S);
            printf("���������Ӻ�Ϊ:");
            print( W );         
            break;
        case 5:
            printf("��1�Ƿ����(0.δ���1.�����)\n%d\n", ClearString( &T ) );          
            break;
        case 6:
            printf("���봮1���Ӵ���λ�úͳ���(�м��Կո����):");
            while ( ( scanf("%d %d", &pos, &len) ) != 2 || ERROR == SubString(&Sub, T, pos, len) )
            {
                printf("����������������룡\n");
                fflush( stdin );
            }
            printf("�Ӵ�Ϊ��");
            print( Sub );           
            break;
        case 7:
            printf("�ô�Ϊ�� ");
            print( T );         
            break;
        }
    }

    return 0;
}
