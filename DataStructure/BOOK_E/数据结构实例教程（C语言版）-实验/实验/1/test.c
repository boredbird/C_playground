#include "stdio.h"
#include "string.h"
//�û��ṹ�嶨��
typedef struct
{
   long id;
   char pwd[6];
}user;
user users[50];//���鶨�壬�����洢����û���Ϣ
void init(int n)//�����û���Ϣ
{
	user *p;
	int i;
	p=users;//ָ���Ӧ��
	printf("�����Ա�����û���Ϣ:\n");
	for(i=0;i<n;i++)
	{
       scanf("%ld,%s",&p[i].id,p[i].pwd);
	}
}
main()
{
   long stuid;
   char stupwd[6];
   int i;
   int n;
   printf("�������û�������");
   scanf("%d",&n);
   init(n);//���������û���Ϣ����
   printf("���������˺ź�����:");
   scanf("%ld,%s",&stuid,stupwd);
   for(i=0;i<n;i++)
   {
       if(stuid==users[i].id && strcmp(stupwd,users[i].pwd)==0)//��֤
	   {
		   printf("��¼�ɹ���");	
	       break;
	   }
   }
   if(i==5)
      printf("�˺Ż����������");
}