#include "stdio.h"
#include "string.h"
//ȡ�Ӵ�����
char *substr(char *p,int i,int m)
{
	int j,k;
	char s[100]={""};
	for(j=i,k=0;j<i+m;j++,k++)
        s[k]=p[j];
	s[k]='\0';
	return s;
}
//�滻����
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
		   strcat(news,v);//�滻
		   pos=i=i+m;
	   }
	}
	strcat(news,substr(s,pos,n-pos));//����ʣ�µ��ַ���
	strcpy(s,news);
}
main()
{
	int i;
	char s[100]={"The name of my father is tom,The name of my mother is alice!\0"};
	char t[100],v[100];
	printf("������Ҫ�滻���ַ���:");
	gets(t);
    printf("������Ҫ������ַ���:");
	gets(v);
	strmatch(s,t,v);
	for(i=0;s[i]!='\0';i++)
		printf("%c",s[i]);
}