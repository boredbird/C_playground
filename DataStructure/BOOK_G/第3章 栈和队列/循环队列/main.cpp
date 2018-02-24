// main.cpp ѭ������ ����C3-4.cpp��������

#include"C3-4.H"


void main()
{
	QElemType cache,e;
	char select;
	int i=0;
	SqQueue Q;
	InitQueue(&Q);
	printf("��ʼ�����к󣬶��пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));

	while(1)
	{
		printf("**************************************************\n");
		printf("��ѡ�������\n");
		printf("a �Ӷ�β����Ԫ��    ");
		printf("b ɾ����ͷԪ��    ");
		printf("c ��ѯ���г���   ");
		printf("d ��ѯ��ͷԪ��\n");
		printf("e �Ƿ�Ϊ�ն���    ");
		printf("f ������������е�Ԫ��    ");
		printf("g ��ն���    ");
		printf("q �˳�����\n");
		printf("*************************************************\n");
        printf("�������ѡ��: ");
		scanf("%c",&select);
		switch(select){
		case 'a':
			printf("���������Ͷ���Ԫ��(������%d��),'-1'Ϊ��ǰ������: \n",MAXQSIZE-1);
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
			if(DeQueue(&Q,&e)) printf("��ͷԪ��: %d �ѱ�ɾ����\n",e);
			else printf("����Ϊ�գ� \n");
			getchar();
			break;
		case 'c':
			printf("��ʱ���еĳ���Ϊ%d\n",QueueLength(Q));
			getchar();
			break;
		case 'd':
			GetHead(Q,&e);
			if(e)
			printf("��ͷԪ����:%d \n",e);
			else printf("����Ϊ��! \n");
			getchar();
			break;
		case 'e':
			printf("�Ƿ�ն��У�%d(1:�� 0:��)\n",QueueEmpty(Q));
			getchar();
			break;
		case 'f':
			if(!QueueEmpty(Q))
				QueueTraverse(&Q,print);
			else 
				printf("����Ϊ�գ�\n");
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
		    printf("�����޷�ʶ������������!!! \n"); 
			break;
		}
	}
}