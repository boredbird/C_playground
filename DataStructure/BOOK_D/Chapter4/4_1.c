#include<stdio.h>
//��source���е����е��ַ�chɾ��
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