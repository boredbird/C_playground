// main.cpp 检验C3-1.cpp的主程序

#include "C3-1.H"

Status visit(SElemType c)
{
	 printf("%d ",c);
	return OK;
}

void main()
{
	char select;
	SElemType cache,e,i;
	SqStack s;
	InitStack(s);
	printf("栈已初始化成功！\n");
	while(1)
	{
		printf("**************************************************\n");
		printf("请选择操作：\n");
		printf("a 从栈顶插入元素     ");
		printf("b 弹出栈顶元素        ");
		printf("c 查询栈长度     ");
		printf("d 查询栈顶元素\n");
		printf("e 是否为空栈         ");
		printf("f 依次输出栈中的元素  ");
		printf("g 清空栈         ");
		printf("q 退出程序\n");
		printf("*************************************************\n");
		printf("输入你的选择: \n");
		scanf("%c",&select);
		switch(select){
		case 'a':
			printf("请输入要插入元素个数:");
			scanf("%d",&i);
			printf("请依次输入要插入的元素:");
			getchar();
			while(i--)
			{
				scanf("%c",&e);
				Push(s,e);
			}
			printf("元素已成功入栈！\n");
			getchar();
			break;
		case 'b':
			printf("栈顶元素: %c 已弹出! \n", Pop(s));
			getchar();
			break;
		case 'c':
			printf("此时栈的长度为%d\n",StackLength(s));
				getchar();
			break;
		case 'd':
		    GetTop(s,e);
			if(e)
				printf("栈顶元素是:%c \n",e);
			else printf("栈为空\n");
				getchar();
				break;
		case 'e':
				printf("是否空栈？%d(1:空 0:否)\n",StackEmpty(s));
					getchar();
				break;
		case 'f':
				StackTraverse(s);
					getchar();
				break;
		case 'g':
			    ClearStack(s);
					getchar();
				break;
		case 'q': 
			DestroyStack(s);
			exit(0);
			break;
		default:
			 printf("输入无法识别，请重新输入!!!\n");
			 	getchar();
			 break;	
		}
	}	
}
