// main.cpp 循环队列 检验C3-4.cpp的主程序

#include"C3-4.H"


void main()
{
	QElemType cache,e;
	char select;
	int i=0;
	SqQueue Q;
	InitQueue(&Q);
	printf("初始化队列后，队列空否？%u(1:空 0:否)\n",QueueEmpty(Q));

	while(1)
	{
		printf("**************************************************\n");
		printf("请选择操作：\n");
		printf("a 从队尾插入元素    ");
		printf("b 删除队头元素    ");
		printf("c 查询队列长度   ");
		printf("d 查询队头元素\n");
		printf("e 是否为空队列    ");
		printf("f 依次输出队列中的元素    ");
		printf("g 清空队列    ");
		printf("q 退出程序\n");
		printf("*************************************************\n");
        printf("输入你的选择: ");
		scanf("%c",&select);
		switch(select){
		case 'a':
			printf("请输入整型队列元素(不超过%d个),'-1'为提前结束符: \n",MAXQSIZE-1);
			do {
				getchar();
				scanf("%d",&e);
				if(e==-1) break;
				i++;
			EnQueue(&Q,e);
			}while(i<MAXQSIZE-1);
			getchar();
			break;
		case 'b':
			if(DeQueue(&Q,&e)) printf("队头元素: %d 已被删除！\n",e);
			else printf("队列为空！ \n");
			getchar();
			break;
		case 'c':
			printf("此时队列的长度为%d\n",QueueLength(Q));
			getchar();
			break;
		case 'd':
			GetHead(Q,&e);
			if(e)
			printf("队头元素是:%d \n",e);
			else printf("队列为空! \n");
			getchar();
			break;
		case 'e':
			printf("是否空队列？%d(1:空 0:否)\n",QueueEmpty(Q));
			getchar();
			break;
		case 'f':
			if(!QueueEmpty(Q))
				QueueTraverse(&Q,print);
			else 
				printf("队列为空！\n");
			getchar();
			break;
		case 'g':
			ClearQueue(&Q);
			getchar();
			break;
		case 'q':
			DestroyQueue(&Q);
			exit(0);
			break;
		default:
		    printf("输入无法识别，请重新输入!!! \n"); 
			break;
		}
	}
}