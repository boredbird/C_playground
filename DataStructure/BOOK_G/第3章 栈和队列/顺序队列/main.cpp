// maincpp ����C3-3.cpp��������

#include "C3-2.h"

void main()
{
	int i;	char select;
	QElemType e,cache;
	SqQueue1 q;
	InitQueue(&q);
	printf("�ɹ���ʼ���ն���!\n");

	while(1)
	{
		printf("**************************************************\n");
		printf("��ѡ�������\n");
		printf("a �����¶��в���   ");
		printf("b Ԫ�شӶ�β��Ӳ���   ");
        printf("c Ԫ�شӶ�ͷ���Ӳ���   ");
		printf("d ��ѯ���г���\n");
		printf("e ��ѯ��ͷԪ��     ");
		printf("f �Ƿ�Ϊ�ն���         ");
		printf("g ��������             ");
		printf("h ��ն���\n");
		printf("q �˳�����\n");
		printf("*************************************************\n");
		printf("��������ѡ�� : ");
		scanf("%c",&select);
        switch(select){
		case 'a':
			printf("������Ҫ����Ԫ�صĸ���:");
			scanf("%d",&i);
			if(i<=0) continue;
			printf("��������������Ԫ��(����):\n");
			while(i--)
			{
				getchar();
				scanf("%d",&e);
				EnQueue(&q,e);
			}
			printf("Ԫ���ѳɹ����룡\n");
			getchar();
			break;
		case 'b':
			printf("������Ҫ�����Ԫ��(����)! \n");
			scanf("%d",&e);
            EnQueue(&q,e);
			printf("Ԫ����ӳɹ�! \n");
			getchar();
			break;
		case 'c':
			DeQueue(&q,&e);
			if(e)
				printf("��ͷԪ��Ϊ��%d �ѱ�ɾ����\n",e);
			else printf("����Ϊ�գ�\n");
			getchar();
			break;
		case 'd':
			printf("��ʱ���еĳ���Ϊ%d\n",QueueLength(q));
			getchar();
			break;
		case 'e':
			GetHead(q,&e);
			if(e)
			printf("��ͷԪ����: %d \n",e);
			else printf("����Ϊ��\n");
			getchar();
			break;
		case 'f':
			printf("�Ƿ�ն��У�%d(1:�� 0:��)\n",QueueEmpty(q));
			getchar();
			break;
		case 'g':
			if(!QueueEmpty(q))
				QueueTraverse(q,print);
			else printf("����Ϊ�գ�\n");
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
			 printf("�����޷�ʶ������������!!!\n");
			 break;
		}

}
}