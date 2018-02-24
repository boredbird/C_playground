// maincpp 检验C3-3.cpp的主程序

#include "C3-3.h"

void main()
{
	int i;
	char select;
	SElemType e,cache;
	LinkQueue q;
	i=InitQueue(q);
	if(i) printf("成功初始化空队列!\n");

	while(1)
	{
		printf("**************************************************\n");
		printf("请选择操作：\n");
		printf("a 从队尾插入元素   ");
		printf("b 删除队头元素          ");
		printf("c 查询队列长度    ");
		printf("d 查询队头元素\n");
		printf("e 是否为空队列     ");
		printf("f 依次输出队列中的元素  ");
		printf("g 清空队列        ");
		printf("q 退出程序\n");
		printf("*************************************************\n");
		printf("输入您的选择 : ");
		scanf("%c",&select);

        switch(select){
		case 'a':
			printf("请输入要插入元素的个数:");
			scanf("%d",&i);
			if(i<=0) continue;
			printf("请依次输入插入的元素:\n");
			while(i--)
			{
				getchar();
				scanf("%d",&e);
				EnQueue(q,e);
			}
			printf("元素已成功插入！\n");
			getchar();
			break;
		case 'b':
			cache = DeQueue(q);
			if(cache)
				printf("队头元素为：%d 已被删除！\n",cache);
			else printf("队列为空！\n");
			getchar();
			break;
		case 'c':
			printf("此时队列的长度为%d\n",QueueLength(q));
			getchar();
			break;
		case 'd':
			e=GetHead(q);
			if(e)
			printf("队头元素是: %d \n",e);
			else printf("队列为空\n");
			getchar();
			break;
		case 'e':
			printf("是否空队列？%d(1:空 0:否)\n",QueueEmpty(q));
			getchar();
			break;
		case 'f':
			if(!QueueEmpty(q))
				QueueTraverse(q);
			else printf("队列为空！\n");
			getchar();
			break;
		case 'g':
			ClearQueue(q);
			getchar();
			break;
       case 'q':
           DestroyQueue(q);
		   exit(0);
		   break;
		default:
			 printf("输入无法识别，请重新输入!!!\n");
			 break;
		}

}
}