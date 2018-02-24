#include<stdio.h>
#include<string.h>
void StringCopy(char *s,char *t)
{
	while(*t!='\0')*s++=*t++;
	*s='\0';

}
void StringConcat(char *s,char *t)
{
	while(*s!='\0')s++;
	while(*t!='\0')*s++=*t++;
	*s='\0';
}

int StringCompare(char *s1,char *s2)
{
	int i = 0;
	while (s1[i] == s2[i] && (s1[i]!='\0'|| s2[i]!='\0')) 
		i++; //继续比较
	return (s1[i] - s2[i]); //三种情况：等于0，大于0，小于0
}
int StringLength(char *s)
{
	int i=0;
	while(s[i]!='\0')i++;
	return i;
}
int SubString(char t[], char sub[], int pos, int len)
{
	int strlen,i;
	strlen=StringLength(t);
	//位置合法性和长度合法性判断
	if(pos < 1 || pos >strlen ||len < 0||len >strlen - pos+1)
         return 0;
	i=0; //获取子串
	while(i<len){sub[i]=t[pos+i-1]; i++;}
	sub[i]='\0';
    return 1;
}

void main()
{
	char str1[50]="Happy birthday to ",str2[]="CDCUESTC";
	char temp[100];
	int i=StringLength(str1);
	printf("%d\n",i);
    SubString(str1,temp,1,5);

	puts(temp);





}