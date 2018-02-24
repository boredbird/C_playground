#include "stdio.h"
#include "string.h"
//用户结构体定义
typedef struct
{
   long id;
   char pwd[6];
}user;
user users[50];//数组定义，用来存储多个用户信息
void init(int n)//输入用户信息
{
	user *p;
	int i;
	p=users;//指针的应用
	printf("请管理员输入用户信息:\n");
	for(i=0;i<n;i++)
	{
       scanf("%ld,%s",&p[i].id,p[i].pwd);
	}
}
main()
{
   long stuid;
   char stupwd[6];
   int i;
   int n;
   printf("请输入用户数量：");
   scanf("%d",&n);
   init(n);//调用输入用户信息函数
   printf("请您输入账号和密码:");
   scanf("%ld,%s",&stuid,stupwd);
   for(i=0;i<n;i++)
   {
       if(stuid==users[i].id && strcmp(stupwd,users[i].pwd)==0)//验证
	   {
		   printf("登录成功！");	
	       break;
	   }
   }
   if(i==5)
      printf("账号或者密码错误！");
}