// main.cpp ����C3-1.cpp��������

#include "C3-1.H"

void check()
 { /* �������������һ���ַ��������������Ƿ���� */
   SqStack s;
   SElemType ch[80],*p,e;
   InitStack(s); /* ��ʼ��ջ�ɹ� */
   printf("����������ţ�()��[]��{}���ı��ʽ\n");
   gets(ch);
   p=ch; /* pָ���ַ��������ַ� */
   while(*p) /* û����β */
     switch(*p)
     {
       case '(':
       case '[':
       case '{':Push(s,*p++); /* ��������ջ����p++ */
                break;
       case ')':
       case ']':
       case '}':if(!StackEmpty(s)) /* ջ���� */
                {
                  e = Pop(s); /* ����ջ��Ԫ�� */
                  if(!(e=='('&&*p==')'||e=='['&&*p==']'||e=='{'&&*p=='}'))
                  { /* ����3��ƥ�����֮������ */
                    printf("�������Ų����\n");
                    exit(ERROR);
                  }
                }
                else /* ջ�� */
                {
                  printf("ȱ��������\n");
                  exit(ERROR);
                }
       default: p++; /* �����ַ�������ָ������� */
     }
   if(StackEmpty(s)) /* �ַ�������ʱջ�� */
     printf("����ƥ��\n");
   else
     printf("ȱ��������\n");
 }

 void main()
 {
   check();
 }