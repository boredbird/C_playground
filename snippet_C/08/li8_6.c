
/*程序8.6 联合类型的定义及使用简单示例。*/
#include<stdio.h>
union UNI
{	char ch; 
	float x;
};
typedef union UNI UNI;
int main( )
{	
	UNI u;
	printf("Input a real number:");          //输入提示：输入一个实数
	scanf("%f",&u.x);
	printf("u.ch=%c, u.x=%f\n",u.ch,u.x);	  //输出联合成员x的值
	getchar( );                          //跳过回车符
	printf("Input a character:");	          //输入提示：输入一个字符
	scanf("%c",&u.ch);			
	printf("u.ch=%c, u.x=%f\n",u.ch,u.x);	  //输出联合成员x的值	
	return 0;
}

