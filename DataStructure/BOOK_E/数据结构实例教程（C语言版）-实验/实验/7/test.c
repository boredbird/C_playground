#include "stdio.h"
#include "string.h"
//取子串操作
char *substr(char *p,int i,int m)
{
	int j,k;
	char s[100]={""};
	for(j=i,k=0;j<i+m;j++,k++)
        s[k]=p[j];
	s[k]='\0';
	return s;
}
//替换操作
void strmatch(char *s,char *t,char *v)
{
	int m,n,pos,i;
	char news[100]={""};
	n=strlen(s);
	m=strlen(t);
	pos=i=0;
    while(i<=n-m)
	{
       if(strcmp(substr(s,i,m),t)!=0) i++;
	   else
	   {
		   strcat(news,substr(s,pos,i-pos));
		   strcat(news,v);//替换
		   pos=i=i+m;
	   }
	}
	strcat(news,substr(s,pos,n-pos));//连接剩下的字符串
	strcpy(s,news);
}
main()
{
	int i;
	char s[100]={"The name of my father is tom,The name of my mother is alice!\0"};
	char t[100],v[100];
	printf("请输入要替换的字符串:");
	gets(t);
    printf("请输入要结果的字符串:");
	gets(v);
	strmatch(s,t,v);
	for(i=0;s[i]!='\0';i++)
		printf("%c",s[i]);
}