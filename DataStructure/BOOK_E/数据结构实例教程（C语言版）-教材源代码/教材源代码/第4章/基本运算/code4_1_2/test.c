#include "stdio.h"
#include "string.h"
main()
{
	char s1[20]="hcit.edu.cn",s2[20]="computer",s3[30];
	printf("%d",strlen(s1));
	strcpy(s3,s1);  //s3="dir/bin/appl",s1������
	printf("%s",s3);
	char s1[20]="www",s2[20]="hcit.edu.cn",s3[30];
1���󴮳�
   int strlen(char *s);
���磺printf("%d",strlen(s1));//���3
2. ������
   char *strcpy(char *to,char *from);//��from�����Ƶ�to����
���磺strcpy(s3,s1); //s3="www",s1������
3. ������
char *strcat(char *to,char *from);//��from���ӵ�toĩβ
   ���磺strcat(s1,s2);//s1=www.hcit.edu.cn
4. ���Ƚ�
   int strcmp(char *s1,char *s2);//�Ƚ�s1��s2�Ĵ�С�� ��s1<s2��s1>s2��s1=s2ʱ���ֱ𷵻�<0������0�͵���0��ֵ
   ���磺result=strcmp("that","this");//result<0
result=strcmp("311030","311030");//result=0
result=strcmp("sony","lenovo");//result>0

}