// main.cpp ����C3-1.cpp��������

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
	printf("ջ�ѳ�ʼ���ɹ���\n");
	while(1)
	{
		printf("**************************************************\n");
		printf("��ѡ�������\n");
		printf("a ��ջ������Ԫ��     ");
		printf("b ����ջ��Ԫ��        ");
		printf("c ��ѯջ����     ");
		printf("d ��ѯջ��Ԫ��\n");
		printf("e �Ƿ�Ϊ��ջ         ");
		printf("f �������ջ�е�Ԫ��  ");
		printf("g ���ջ         ");
		printf("q �˳�����\n");
		printf("*************************************************\n");
		printf("�������ѡ��: \n");
		scanf("%c",&select);
		switch(select){
		case 'a':
			printf("������Ҫ����Ԫ�ظ���:");
			scanf("%d",&i);
			printf("����������Ҫ�����Ԫ��:");
			getchar();
			while(i--)
			{
				scanf("%c",&e);
				Push(s,e);
			}
			printf("Ԫ���ѳɹ���ջ��\n");
			getchar();
			break;
		case 'b':
			printf("ջ��Ԫ��: %c �ѵ���! \n", Pop(s));
			getchar();
			break;
		case 'c':
			printf("��ʱջ�ĳ���Ϊ%d\n",StackLength(s));
				getchar();
			break;
		case 'd':
		    GetTop(s,e);
			if(e)
				printf("ջ��Ԫ����:%c \n",e);
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
			 	getchar();
			 break;	
		}
	}	
}
