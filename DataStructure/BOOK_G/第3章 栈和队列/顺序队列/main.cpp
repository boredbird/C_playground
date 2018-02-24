// maincpp 检验C3-3.cpp的主程序

#include "C3-2.h"

void main()
{
	int i;	char select;
	QElemType e,cache;
	SqQueue1 q;
	InitQueue(&q);
	printf("成功初始化空队列!\n");

	while(1)
	{
		printf("**************************************************\n");
		printf("请选择操作：\n");
		printf("a 创建新队列操作   ");
		printf("b 元素从队尾入队操作   ");
        printf("c 元素从队头出队操作   ");
		printf("d 查询队列长度\n");
		printf("e 查询队头元素     ");
		printf("f 是否为空队列         ");
		printf("g 遍历队列             ");
		printf("h 清空队列\n");
		printf("q 退出程序\n");
		printf("*************************************************\n");
		printf("输入您的选择 : ");
		scanf("%c",&select);
        switch(select){
		case 'a':
			printf("请输入要插入元素的个数:");
			scanf("%d",&i);
			if(i<=0) continue;
			printf("请依次输入插入的元素(整型):\n");
			while(i--)
			{
				getchar();
				scanf("%d",&e);
				EnQueue(&q,e);
			}
			printf("元素已成功插入！\n");
			getchar();
			break;
		case 'b':
			printf("输入您要插入的元素(整型)! \n");
			scanf("%d",&e);
            EnQueue(&q,e);
			printf("元素入队成功! \n");
			getchar();
			break;
		case 'c':
			DeQueue(&q,&e);
			if(e)
				printf("队头元素为：%d 已被删除！\n",e);
			else printf("队列为空！\n");
			getchar();
			break;
		case 'd':
			printf("此时队列的长度为%d\n",QueueLength(q));
			getchar();
			break;
		case 'e':
			GetHead(q,&e);
			if(e)
			printf("队头元素是: %d \n",e);
			else printf("队列为空\n");
			getchar();
			break;
		case 'f':
			printf("是否空队列？%d(1:空 0:否)\n",QueueEmpty(q));
			getchar();
			break;
		case 'g':
			if(!QueueEmpty(q))
				QueueTraverse(q,print);
			else printf("队列为空！\n");
			getchar();
			break;
		case 'h':
			ClearQueue(&q);
			getchar();
			break;
       case 'q':
           DestroyQueue(&q);
		   exit(0);
		   break;
		default:
			 printf("输入无法识别，请重新输入!!!\n");
			 break;
		}

}
}