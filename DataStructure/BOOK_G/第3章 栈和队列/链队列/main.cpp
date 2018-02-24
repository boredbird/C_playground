// maincpp ����C3-3.cpp��������

#include "C3-3.h"

void main()
{
	int i;
	char select;
	SElemType e,cache;
	LinkQueue q;
	i=InitQueue(q);
	if(i) printf("�ɹ���ʼ���ն���!\n");

	while(1)
	{
		printf("**************************************************\n");
		printf("��ѡ�������\n");
		printf("a �Ӷ�β����Ԫ��   ");
		printf("b ɾ����ͷԪ��          ");
		printf("c ��ѯ���г���    ");
		printf("d ��ѯ��ͷԪ��\n");
		printf("e �Ƿ�Ϊ�ն���     ");
		printf("f ������������е�Ԫ��  ");
		printf("g ��ն���        ");
		printf("q �˳�����\n");
		printf("*************************************************\n");
		printf("��������ѡ�� : ");
		scanf("%c",&select);

        switch(select){
		case 'a':
			printf("������Ҫ����Ԫ�صĸ���:");
			scanf("%d",&i);
			if(i<=0) continue;
			printf("��������������Ԫ��:\n");
			while(i--)
			{
				getchar();
				scanf("%d",&e);
				EnQueue(q,e);
			}
			printf("Ԫ���ѳɹ����룡\n");
			getchar();
			break;
		case 'b':
			cache = DeQueue(q);
			if(cache)
				printf("��ͷԪ��Ϊ��%d �ѱ�ɾ����\n",cache);
			else printf("����Ϊ�գ�\n");
			getchar();
			break;
		case 'c':
			printf("��ʱ���еĳ���Ϊ%d\n",QueueLength(q));
			getchar();
			break;
		case 'd':
			e=GetHead(q);
			if(e)
			printf("��ͷԪ����: %d \n",e);
			else printf("����Ϊ��\n");
			getchar();
			break;
		case 'e':
			printf("�Ƿ�ն��У�%d(1:�� 0:��)\n",QueueEmpty(q));
			getchar();
			break;
		case 'f':
			if(!QueueEmpty(q))
				QueueTraverse(q);
			else printf("����Ϊ�գ�\n");
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
			 printf("�����޷�ʶ������������!!!\n");
			 break;
		}

}
}