/* main4-3.c 检验bo4-3.c的主程序 */
#include<stdio.h>
#include"c4-3.h"

int main()
{
    char *s1 = "ABCDEFGHI",*s2 = "12345",*s3 = "",*s4 = "asd#tr",*s5 = "ABCD";
    int pos,len;
    Status k;
    LString t1,t2,t3,t4;

    printf("已建立t1,t2,t3,t4四个变量 \n\n");

    SetBlank('#');
    InitString(&t1);
    InitString(&t2);

    printf("初始化串t1后,串t1空否？(1:空 0:否) : %d \n串长=%d\n\n",StrEmpty(t1),StrLength(t1));

    k = StrAssign(&t1, s3);
    if(k == OK)
    {
        printf("串t1为: ");
        StrPrint(t1);
    }
    else
    {
        printf("由s3生成t1时出错\n");                                 /* 不能生成空串 */
    }

    k = StrAssign(&t1, s4);
    if(k == OK)
    {
        printf("串t1为: ");
        StrPrint(t1);
    }
    else
    {
        printf("由s4生成t1时出错，因为s4含有变量blank的字符串\n\n");   /* 不能生成含有变量blank所代表的字符的串 */
    }

    k = StrAssign(&t1, s1);
    if(k == OK)
    {
        printf("串t1为: ");
        StrPrint(t1);
    }
    else
    {
        printf("出错\n");
    }

    printf("串t1空否？(1:空 0:否) : %d\n串长=%d\n\n",StrEmpty(t1),StrLength(t1));
    StrAssign(&t2, s2);
    printf("串t2为: ");
    StrPrint(t2);

    StrCopy(&t3, t1);
    printf("\n由串t1拷贝得到串t3,串t3为: ");
    StrPrint(t3);

    InitString(&t4);
    StrAssign(&t4, s5);
    printf("\n串t4为: ");
    StrPrint(t4);

    Replace(&t3, t4, t2);
    printf("用t2取代串t3中的t4串后，串t3为: ");
    StrPrint(t3);

    ClearString(&t1);
    printf("\n清空串t1后，串t1空否？(1:空 0:否) : %d \n串长=%d\n",StrEmpty(t1),StrLength(t1));

    Concat(&t1, t2, t3);
    printf("串t1(=t2+t3)为: ");
    StrPrint(t1);

    Zip(&t1);
    printf("\n去除不必要的占位符后，串t1为: ");
    StrPrint(t1);

    pos = Index(t1, t3, 1);
    printf("t3在主串t1中第%d个位置\n\n",pos);

    printf("在串t1的第pos个字符之前插入串t2，请输入pos: ");
    while(((scanf("%d",&pos)) != 1) || pos > 16)
    {
        printf("输入不合法，请重新输入！\n");
        fflush(stdin);                                                  /*刷新键盘缓冲区*/
    }

    k = StrInsert(&t1,pos, t2);
    if(k)
    {
        printf("插入串t2后，串t1为: ");
        StrPrint(t1);
    }
    else
    {
        printf("插入失败！\n");
    }

    printf("\n求从t1的第pos个字符起,长度为len的子串t2,请输入pos和len(中间以空格隔开): ");

    while(((scanf("%d %d",&pos, &len)) != 2) || pos < 1 || len < 0 || len > 20 - pos + 1)
    {
        printf("输入不合法，请重新输入！\n");
        fflush(stdin);                                        
    }

    SubString(&t2, t1, pos, len);
    printf("串t2为: ");
    StrPrint(t2);

    printf("StrCompare(t1,t2)=%d\n",StrCompare(t1,t2));

    printf("\n删除串t1中的子字符串：从第pos个字符起删除len个字符。请输入pos和len：");

    while (((scanf("%d %d",&pos, &len)) != 2) || pos < 1 || len < 0 || len > 20 - pos + 1)
    {
        printf("输入不合法，请重新输入！\n");
        fflush(stdin);                                          
    }

    k = StrDelete(&t1, pos, len);
    if (k)
    {
        printf("从第%d位置起删除%d个元素后串t1为:", pos, len);
        StrPrint(t1);
    }
    return 0;
}