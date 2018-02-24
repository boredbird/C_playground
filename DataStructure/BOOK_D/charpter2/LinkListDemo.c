#include<stdio.h>
#include<stdlib.h>
//��������Ĵ洢�ṹ
typedef struct  LNode 
{
       int    data;//������
       struct  LNode  *next;//ָ����
} node;
void Display(node*);
void GreatLink(node*);
void DeleteRepeat(node *head);
void SingleToCycle(node *head);
void DisplayCycle(node *head);
int  Search(node *head, int e);
int listInsert(node *head, int i, int e);
int listDelete(node *head, int i,int *e);
void  DeleteEven(node *head);
void main()
{

	node *Head;
	char exit='N';
	int ch,result,loc;
	int data;
	//����һ��ͷ��㡣
	Head=(node *)malloc(sizeof(node));
	if(Head!=NULL)
	{
		Head->next=NULL;
	}
	else return;
	do
	{
		system("CLS");
		printf("\t\t********************************************\n");
		printf("\t\t*  1.����һ���������  ...............(1)  *\n");
		printf("\t\t*  2.�ڵ������в���Ԫ��...............(2)  *\n");
		printf("\t\t*  3.�ڵ������в���Ԫ��...............(3)  *\n");
	    printf("\t\t*  4.�ڵ�������ɾ��Ԫ��...............(4)  *\n");
		printf("\t\t*  5.ɾ�����������ظ�Ԫ��.............(5)  *\n");
		printf("\t\t*  6.ɾ��������������ֵΪż����Ԫ��...(6)  *\n");
		printf("\t\t*  7.�ѵ������ɴ���ͷ����ѭ������.(7)  *\n");
		printf("\t\t*  8.�˳�              ...............(8)  *\n");
		printf("\t\t********************************************\n");
		printf("\n��ѡ��������룺");
        scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("����һ���������\n");
				GreatLink(Head);
				Display(Head);
				system("pause");
				break;
			case 2:
				printf("�ڵ������в���Ԫ��\n");
				printf("����������ҵ�Ԫ�ص�ֵ:");
				scanf("%d",&data);
				result=Search(Head,data);
				if(result==0)printf("�Ҳ���Ԫ��%d\n",data);
				else printf("�ҵ���Ԫ��%d,�ǵ������еĵ�%d��Ԫ��\n",data,result);
				system("pause");
				break;
			case 3:
				printf("�ڵ������в���Ԫ��\n");
				printf("������������Ԫ�ص�λ��:");
				scanf("%d",&loc);
				printf("������������Ԫ�ص�ֵ:");
				scanf("%d",&data);
				result=listInsert(Head,loc,data);
				if(result==0)printf("����λ�ò���ȷ���޷�����!\n");
				else printf("����Ԫ��%d�ɹ�!\n",data);
				Display(Head);
				system("pause");
				break;
			case 4:
				
				printf("�ڵ�������ɾ��Ԫ��\n");	
				printf("�������ɾ����Ԫ�ص�λ��:");
				scanf("%d",&loc);
				result=listDelete(Head,loc,&data);
				if(result==0)printf("ɾ��λ�ò���ȷ���޷�ɾ��!\n");
				else printf("ɾ��Ԫ��%d�ɹ�!\n",data);
				Display(Head);
				system("pause");
				break;
			case 5:
			    printf("ɾ�����������ظ�Ԫ��\n");
				DeleteRepeat(Head);
                Display(Head);
				system("pause");
				break;
			case 6:
				
				printf("ɾ��������������ֵΪż����Ԫ��\n");
			    DeleteEven(Head);
				Display(Head);
				system("pause");
				break;
			case 7:
				printf("�ѵ������ɴ���ͷ����ѭ������!\nע��,�ò��������ƻ��ԣ��������2��6������������ִ�У������!\n");
				SingleToCycle(Head);
				DisplayCycle(Head);
				system("pause");
				break;
			case 8:
				getchar();
				printf("\n���Ƿ����Ҫ�˳�����(Y/N):");
				exit=getchar();getchar();
				break;
			default:
				printf("\n��Ч���룬������ѡ��...:");				

		}
		
	}while(exit!='y'&&exit!='Y');

}
//��ʾ������������Ԫ��
void Display(node *head)
{
	node *p=head->next;
	printf("\n��ǰ������������Ԫ��Ϊ��\n");
	while(p!=NULL)
	{
		printf("%4d",p->data);
		p=p->next;
	}
	printf("\n");

}
/*�Ӽ�������һϵ��������������ֵΪ0ʱ��ֹͣ���룬����������*/
void GreatLink(node *head)
{
	int elem;
	node *p,*q;
	printf("������һϵ��������������0ʱ����������:");
	p=head;
	do
	{
		scanf("%d",&elem);
		if(elem!=0)
		{
			q=malloc(sizeof(node));
			if(q!=NULL)
			{
				q->next=NULL;
				q->data=elem;
				p->next=q;//�ѽ��q����p֮��
				p=q;

			}
		}
	}while(elem!=0);

}
/*����������ֵ�ظ��Ľ��ɾ����ʹ���õĽ�����и����ֵ������ͬ*/
void DeleteRepeat(node *head)
{
	int elem;
	node *p,*q,*r;
	p=head->next;
	while(p!=NULL&&p->next!=NULL)
	{
		//������û�к�p->data��ͬ��Ԫ��
		elem=p->data;
		r=p;//rʼ��ָ��q����ǰ��
		q=r->next;//Ϊ��ǰ��㣬���ڱȽ��Ƿ��p->data��ͬ
		while(q!=NULL)
		{

			if(q->data==elem)//q->data��p->data��ͬ��ɾ��qָ��Ľ�㣬��ʹqָ����һ��Ԫ�أ���������
			{
				r->next=q->next;
				free(q);
				q=r->next;
			}
			else//���q->data��p->data����ͬ����qָ����һ��Ԫ�أ���������
			{
				r=q;
				q=q->next;
			}			
		}
		
		p=p->next;

	}

}
//�ѵ�������ѭ������
void SingleToCycle(node *head)
{
	node *p;
	p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=head;//��ԭ���������β����nextָ��ָ��ͷ��㡣

}
//��ʾѭ������
void DisplayCycle(node *head)
{
	node *p=head->next;
	printf("\n��ǰѭ������������Ԫ��Ϊ��\n");
	while(p!=head)
	{
		printf("%4d",p->data);
		p=p->next;
	}
	printf("\n");

}
//���� �ɹ�--����λ�ã�ʧ��--0
int  Search(node *head, int e)
{ 
	node *p;
	int i;
	p= head->next;  
    i=1;
	while (p!=NULL&&p->data!=e)
	{
		p = p -> next;
		++i;
	} 
	if(p==NULL)return 0;
	return i;
} 
// �ɹ�--1��ʧ��--0
int listInsert(node *head, int i, int e)
{
  	node *p,*s;
	int j;
	p =head;j = 0;
	while (p && j < i - 1)
	{
     p = p -> next; ++ j;
	}
	if ( !p||j > i - 1) return 0;
	s = (node *) malloc ( sizeof (node)); 
	s -> data = e; 
	s -> next = p -> next; 
	p -> next = s;
	return 1;
}
// �ɹ�--1��ʧ��--0
int listDelete(node *head, int i,int *e)
{ 
	node *p,*q;
	int j;
    p =head; j = 0;
   while (p -> next && j < i-1)
   {
     p = p -> next; ++j; 
   }
   if ( !(p -> next) ||j > i - 1)return 0; // ɾ��λ�ò�����
   q = p -> next ; 
   p -> next = q -> next; 
   *e=q->data;
   free(q); // ɾ�����ͷŽ��
   return 1;
} 
//ɾ��ż���ڵ�
void  DeleteEven(node *head)
{
	node *p,*q;//pΪ��ǰ��㣬qΪǰ��
	p=head->next;
	q=head;
	while(p!=NULL)
	{
		if(p->data%2==0)//ż����ɾ��������pָ����һ��Ԫ�ء�q����
		{
			q->next=p->next;
			free(p);
			p=q->next;
		}
		else//��ż����pָ����һ��Ԫ�أ�qָ����ǰ����
		{
			q=p;
			p=p->next;
			
		}
	}
}

