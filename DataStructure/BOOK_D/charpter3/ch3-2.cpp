#include"stdio.h"
#include"stdlib.h"
#define MAXSIZE 20                       //数组最大界限
typedef struct 
{
	int stack[MAXSIZE];
	int  lefttop;  		//左栈栈顶位置指示器
	int  righttop;  	//右栈栈顶位置指示器
  } dupsqstack;

//创建两个共享邻接空间的空栈，指针S指向该空间
int initDupStack(dupsqstack *s)
{
	s=(dupsqstack*)malloc(sizeof(dupsqstack));
	if (s==NULL) return 0;
	s->lefttop= -1;
	s->righttop=MAXSIZE;
	return 1;
};

//把数据元素x压入左栈（status='L'）或右栈（status='R'）
int pushDupStack(dupsqstack *s,char status,int x)
{
	if(s->lefttop+1==s->righttop) return 0; //栈满
	if(status='L')  s->stack[++s->lefttop]=x; //左栈进栈
    else if(status='R')  s->stack[--s->righttop]=x;  //右栈进栈
	else return 0; 						//参数错误
	return 1;
};
//从左栈（status='L'）或右栈（status='R'）退出栈顶元素
int  popDupStack(dupsqstack *s,char status)
{
	if(status=='L')
	{
		if (s->lefttop<0)
			return 0;  				//左栈为空
		else return (s->stack[s->lefttop--]);   		//左栈出栈
	}
	else if(status=='R')
	{
		if (s->righttop>MAXSIZE-1)
			return 0;  				//右栈为空
		else return (s->stack[s->righttop++]);  	//右栈出栈
	}
	else  return 0;  				//参数错误
};

void main()
{
dupsqstack *s;
int initDupStack(dupsqstack *s);
int pushDupStack(dupsqstack *s,char status,int x);
int popDupStack(dupsqstack *s,char status);
}