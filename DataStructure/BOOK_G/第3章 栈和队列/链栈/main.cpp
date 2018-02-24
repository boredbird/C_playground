
#include "C3-2.H"

void print(SElemType c)
{
	printf("%d ",c);
}

void main()
{
	int i;
	char select;
	LinkStack s;
	SElemType e;
	InitStack(s);
		printf("��ջ��ʼ����ɣ�\n");
	while(1)
	{
		printf("**************************************************\n");
		printf("��ѡ�������\n");
		printf("a ��ջ������Ԫ��    ");
		printf("b ����ջ��Ԫ��          ");
		printf("c ��ѯջ����      ");
		printf("d ��ѯջ��Ԫ��\n");
		printf("e �Ƿ�Ϊ��ջ        ");
		printf("f �������ջ�е�Ԫ��    ");
		printf("g ���ջ          ");
		printf("q �˳�����\n");
		printf("*************************************************\n");
		printf("����������ѡ��: ");
		scanf("%c",&select);
		switch(select){
		case 'a':
			printf("������Ҫ����Ԫ�ظ���:");
			scanf("%d",&i);
			printf("����������Ҫ�����Ԫ��:");
			while(i--)
			{
				getchar();
				scanf("%d",&e);
				Push(s,e);
			}
			printf("ѹջ�������!\n");
			getchar();
			break;
		case 'b':
			e = Pop(s);
			if(e)
			printf("ջ��Ԫ��: %d �ѵ�����\n",e);
			else printf("ջ��Ԫ�ز����ڣ�\n");
			getchar();
			break;
		case 'c':
			printf("��ʱջ�ĳ���Ϊ%d \n",StackLength(s));
			getchar();
			break;
		case 'd':
			e=GetTop(s);
			if(e)
				printf("ջ��Ԫ����:%d \n",e);
			else printf("ջΪ��\n");
			getchar();
			break;
		case 'e':
				printf("�Ƿ��ջ��%d(1:�� 0:��)\n",StackEmpty(s));
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
			 printf("�����޷�ʶ������������!!!\n");
			 break;
		}
}
}