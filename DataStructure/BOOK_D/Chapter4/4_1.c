#include<stdio.h>
//把source串中的所有的字符ch删除
void CharDelete(char source[],char ch)
{
	int i,j;
	i=j=0;
	while(source[j]!='\0')
	{
		if(source[j]!=ch)
		{
			source[i]=source[j];
			i++,j++;

		}
		else
		{
			j++;

		}
	}
	source[i]='\0';



}
shjjiego
void main()
{
	char s[]="shujujiegou";
	CharDelete(s,'u');
	puts(s);

}