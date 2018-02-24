// main.cpp ����C3-1.cpp��������

#include "C3-1.H"

 FILE *fp;

void copy(SElemType c)
 { /* ���ַ�c����fp��ָ���ļ��� */
   fputc(c,fp);
 }

 void LineEdit()
 { /* �����ַ�ջs�����ն˽���һ�в��������ù��̵����������㷨3.2 */
   SqStack s;
   char ch;
   InitStack(s);
   printf("������һ���ı��ļ�,^Z(��F6)��������:\n");
   ch=getchar();
   while(ch!=EOF)
   { /* ��ȫ��û����(EOFΪ^Z����ȫ�Ľ�����) */
     while(ch!=EOF&&ch!='\n')
     { /* ��ȫ��û������û����ĩ(���ǻ��з�) */
       switch(ch)
       {
         case '#':if(!StackEmpty(s))
                    Pop(s); /* ����ջ�ǿ�ʱ��ջ,c����ch��� */
                  break;
         case '@':ClearStack(s); /* ����sΪ��ջ */
                  break;
         default :Push(s,ch); /* �����ַ���ջ */
       }
       ch=getchar(); /* ���ն˽�����һ���ַ� */
     }
     StackTraverse(s); /* ����ջ�׵�ջ����ջ���ַ��������ļ� */
     fputc('\n',fp); /* ���ļ�����һ�����з� */
     ClearStack(s); /* ����sΪ��ջ */
     if(ch!=EOF)
       ch=getchar();
   }
   DestroyStack(s);
 }

 Status StackTraverse(SqStack S)
{	// ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ؽ��з���
	while(S.top>S.base) 
		copy(*S.base++);
	printf("\n");
	return OK;
}


 void main()
 {
   fp=fopen("in.txt","w"); /* �ڵ�ǰĿ¼�½���ed.txt�ļ�������д���ݣ�*/
   if(fp)                  /* ������ͬ���ļ�����ɾ��ԭ�ļ� */
   {
     LineEdit();
     fclose(fp); /* �ر�fp��ָ���ļ� */
   }
   else
     printf("�����ļ�ʧ��!\n");
 }

