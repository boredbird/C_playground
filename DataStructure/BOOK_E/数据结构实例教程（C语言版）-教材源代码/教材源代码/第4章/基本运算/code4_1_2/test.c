#include "stdio.h"
#include "string.h"
main()
{
	char s1[20]="hcit.edu.cn",s2[20]="computer",s3[30];
	printf("%d",strlen(s1));
	strcpy(s3,s1);  //s3="dir/bin/appl",s1串不变
	printf("%s",s3);
	char s1[20]="www",s2[20]="hcit.edu.cn",s3[30];
1．求串长
   int strlen(char *s);
例如：printf("%d",strlen(s1));//输出3
2. 串复制
   char *strcpy(char *to,char *from);//将from串复制到to串中
例如：strcpy(s3,s1); //s3="www",s1串不变
3. 串联接
char *strcat(char *to,char *from);//将from联接到to末尾
   例如：strcat(s1,s2);//s1=www.hcit.edu.cn
4. 串比较
   int strcmp(char *s1,char *s2);//比较s1和s2的大小， 当s1<s2、s1>s2和s1=s2时，分别返回<0、大于0和等于0的值
   例如：result=strcmp("that","this");//result<0
result=strcmp("311030","311030");//result=0
result=strcmp("sony","lenovo");//result>0

}