//程序9.1 字符串处理函数的应用示例。
#include<stdio.h>
#include<string.h>
int main( )
{
	char s1[20]="We all", s2[20],s3[30];           //定义3个字符数组
	printf("s1=%s,strlen(s1)=%d\n",s1,strlen(s1));   //输出串s1的值及长度
    printf("Input s2:");                         //提示输入s2串
	gets(s2);                                 //用gets函数输入可带空格的串
	printf("s2=%s\n",s2);                       //用printf函数输出串s2
	strcpy(s3,s1);		 	                    //将串s1拷贝到串s3
	strcat(s3,s2);	                            //将串s2连接到s3后面
	printf("s3=");                             //用puts输出串s3
	puts(s3);
	if (strcmp(s1,s2)>0)                        //比较s1串和s2串的大小
		printf("s1 is larger than s2\n");            //s1串大于s2串
	else if (strcmp(s1,s2)<0)
        printf("s1 is smaller than s2\n");          //s1串小于s2串
	else printf("s1 is equal to s2\n");              //s1串等于s2串
	strupr(s3);                                //将串s3中的小写字母改为大写
    printf("after strupr,s3=");                    //输出修改后的s3
	puts(s3);

    strlwr(s3);                                //将串s3中的小写字母改为大写
    printf("after strlwr,s3=");                    //输出修改后的s3
	puts(s3);
	return 0;
}
