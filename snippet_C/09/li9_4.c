/*程序9.4 判断一个字符串是否是回文。*/
#include<stdio.h>
#include<string.h>
#define MAX 80
int Palindrome (const char *str);
int main( )
{ 
		char str[MAX],ch;
		do                          //该循环用于控制是否需要多次判断串是否回文
		{
			printf("Input a string:\n");	//输入提示：输入一个字符串
			gets(str);			        //从键盘输入一个字符串
			if(Palindrome(str))         //调用函数判断是否为回文，输出不同的的结论
			  printf("It is a palindrom.\n");
			else
				printf("It is not a palindrom.\n");
			printf("continue?(Y/N)\n");  //询问是否要继续判断回文
			ch=getchar( );             //输入一个字符，通常是'Y'或'N'
			getchar();                //跳过刚刚输入的回车符
		}while (ch!='N'&&ch!='n');      //如果既不是N也不是n表示需要继续判断
        return 0;
}
int Palindrome(const char *str)      //判断回文的函数定义
{	int i=0,j=strlen(str)-1; 	 	   //步骤①
		while(i<j)				   //步骤②
		{
			while(str[i]==32)		   //步骤③，32是空格字符的代码
				i++;
	  		while(str[j]==32) 		   //步骤③，32是空格字符的代码
				j--;
	   		if(str[j]==str[i])          //对应字符相同，则继续比较
	   		{ 	 i++;   j--;         //i下标增加1，j下标减少1
	   		}
 			else  return(0);          //对应字符不同，则返回0，表示不是回文		
		}
		return(1);					   //步骤④，循环停止，i>=j，所有的str[j]==str[i]
}
