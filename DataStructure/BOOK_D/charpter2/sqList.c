#include<stdio.h>
#include<stdlib.h>
#define N 100 //˳�����������
int length=0;  //˳���ĵ�ǰԪ�ظ���
void CreatList(int[]);
void Display(int[]);
int Search(int[],int);

void main()
{
	int List[N];
	int ch;
	int loc,data,result;
	char exit='N';
	do
	{
		system("CLS");
		printf("\t\t********************************************\n");
		printf("\t\t*  1.����һ��˳���    .........(1)        *\n");
		printf("\t\t*  2.��˳����в���Ԫ��.........(2)        *\n");
		printf("\t\t*  3.��˳����в���Ԫ��.........(3)        *\n");
	    printf("\t\t*  4.��˳�����ɾ��Ԫ��.........(4)        *\n");
		printf("\t\t*  5.�˳�              .........(5)        *\n");
		printf("\t\t********************************************\n");
		printf("\n��ѡ��������룺");
        scanf("%d",&ch);
		getchar();
		switch(ch)
		{
			case  1 :
			    CreatList(List);
				Display(List);
				system("pause");
				break;
			case  2 :
				printf("��˳����в���Ԫ��\n");
				printf("����������ҵ�Ԫ�ص�ֵ:");
				scanf("%d",&data);
				result=Search(List,data);
				if(result==-1)printf("�Ҳ���Ԫ��%d\n",data);
				else printf("�ҵ���Ԫ��%d,��˳����еĵ�%d��Ԫ��\n",data,result+1);
				system("pause");
				break;
			case  3 :
				
				printf("��˳����в���Ԫ��\n");
			
				system("pause");
				break;
			case  4 :
				
				printf("��˳�����ɾ��Ԫ��\n");
			
				system("pause");
				break;
			case  5 :
				printf("\n���Ƿ����Ҫ�˳�����(Y/N):");
				exit=getchar();getchar();
				break;
			default:
				printf("\n��Ч���룬������ѡ��...:");
				system("pause");

		}
		
	}while(exit!='y'&&exit!='Y');

}
//����һ��˳�����������Ԫ��ֵ��������0ʱ����
void CreatList(int sl[])
{
	int data;
	length=0;
	printf("������һϵ������(������0ʱ����:)");
	do
	{
		if(length>=N)return;
		scanf("%d",&data);
		if(data!=0)
			sl[length++]=data;
		
		
	}while(data!=0);
}
//˳���Ĳ���
int Search(int sl[],int e)
{
	int i;
	sl[length]=e;//�ڱ�
	for(i=0;sl[i]!=e;i++);
	if(i<length)return i;//���ҵ�������Ԫ�ص�������
	else return -1;//�鲻��
	
}

void Display(int sl[])
{
	int i;
	printf("��ǰԪ������Ϊ��");
	for(i=0;i<length;i++)
	{
		printf("%4d",sl[i]);
	}
	printf("\n");
}
