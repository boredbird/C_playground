/* main4-3.c ����bo4-3.c�������� */
#include<stdio.h>
#include"c4-3.h"

int main()
{
    char *s1 = "ABCDEFGHI",*s2 = "12345",*s3 = "",*s4 = "asd#tr",*s5 = "ABCD";
    int pos,len;
    Status k;
    LString t1,t2,t3,t4;

    printf("�ѽ���t1,t2,t3,t4�ĸ����� \n\n");

    SetBlank('#');
    InitString(&t1);
    InitString(&t2);

    printf("��ʼ����t1��,��t1�շ�(1:�� 0:��) : %d \n����=%d\n\n",StrEmpty(t1),StrLength(t1));

    k = StrAssign(&t1, s3);
    if(k == OK)
    {
        printf("��t1Ϊ: ");
        StrPrint(t1);
    }
    else
    {
        printf("��s3����t1ʱ����\n");                                 /* �������ɿմ� */
    }

    k = StrAssign(&t1, s4);
    if(k == OK)
    {
        printf("��t1Ϊ: ");
        StrPrint(t1);
    }
    else
    {
        printf("��s4����t1ʱ������Ϊs4���б���blank���ַ���\n\n");   /* �������ɺ��б���blank��������ַ��Ĵ� */
    }

    k = StrAssign(&t1, s1);
    if(k == OK)
    {
        printf("��t1Ϊ: ");
        StrPrint(t1);
    }
    else
    {
        printf("����\n");
    }

    printf("��t1�շ�(1:�� 0:��) : %d\n����=%d\n\n",StrEmpty(t1),StrLength(t1));
    StrAssign(&t2, s2);
    printf("��t2Ϊ: ");
    StrPrint(t2);

    StrCopy(&t3, t1);
    printf("\n�ɴ�t1�����õ���t3,��t3Ϊ: ");
    StrPrint(t3);

    InitString(&t4);
    StrAssign(&t4, s5);
    printf("\n��t4Ϊ: ");
    StrPrint(t4);

    Replace(&t3, t4, t2);
    printf("��t2ȡ����t3�е�t4���󣬴�t3Ϊ: ");
    StrPrint(t3);

    ClearString(&t1);
    printf("\n��մ�t1�󣬴�t1�շ�(1:�� 0:��) : %d \n����=%d\n",StrEmpty(t1),StrLength(t1));

    Concat(&t1, t2, t3);
    printf("��t1(=t2+t3)Ϊ: ");
    StrPrint(t1);

    Zip(&t1);
    printf("\nȥ������Ҫ��ռλ���󣬴�t1Ϊ: ");
    StrPrint(t1);

    pos = Index(t1, t3, 1);
    printf("t3������t1�е�%d��λ��\n\n",pos);

    printf("�ڴ�t1�ĵ�pos���ַ�֮ǰ���봮t2��������pos: ");
    while(((scanf("%d",&pos)) != 1) || pos > 16)
    {
        printf("���벻�Ϸ������������룡\n");
        fflush(stdin);                                                  /*ˢ�¼��̻�����*/
    }

    k = StrInsert(&t1,pos, t2);
    if(k)
    {
        printf("���봮t2�󣬴�t1Ϊ: ");
        StrPrint(t1);
    }
    else
    {
        printf("����ʧ�ܣ�\n");
    }

    printf("\n���t1�ĵ�pos���ַ���,����Ϊlen���Ӵ�t2,������pos��len(�м��Կո����): ");

    while(((scanf("%d %d",&pos, &len)) != 2) || pos < 1 || len < 0 || len > 20 - pos + 1)
    {
        printf("���벻�Ϸ������������룡\n");
        fflush(stdin);                                        
    }

    SubString(&t2, t1, pos, len);
    printf("��t2Ϊ: ");
    StrPrint(t2);

    printf("StrCompare(t1,t2)=%d\n",StrCompare(t1,t2));

    printf("\nɾ����t1�е����ַ������ӵ�pos���ַ���ɾ��len���ַ���������pos��len��");

    while (((scanf("%d %d",&pos, &len)) != 2) || pos < 1 || len < 0 || len > 20 - pos + 1)
    {
        printf("���벻�Ϸ������������룡\n");
        fflush(stdin);                                          
    }

    k = StrDelete(&t1, pos, len);
    if (k)
    {
        printf("�ӵ�%dλ����ɾ��%d��Ԫ�غ�t1Ϊ:", pos, len);
        StrPrint(t1);
    }
    return 0;
}