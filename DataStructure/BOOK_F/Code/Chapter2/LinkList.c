#include<stdio.h>
#include <stdlib.h>

typedef  int ElemType;   //Ĭ����������Ϊint
//���Ա�ĵ�����洢�ṹ����
typedef struct LNode{
	ElemType    data;
	struct  LNode   *next;
}LNode, *LinkList;

typedef struct DuLNode{
	ElemType    data;
	struct  DuLNode   *prior;
	struct  DuLNode   *next;
}DuLNode, *DuLinkList;


//��ʼ��һ���������ɹ�����ͷָ�룬ʧ�ܷ���NULL
LNode * LinkListInit()
{
	LNode *L;
	L=(LNode *)malloc(sizeof(LNode));   //����һ��ͷ���
	if(L==NULL)  return NULL;                   //����ʧ��
	L->next = NULL;                     //ͷ����ָ����Ϊ��
	return L;
}

//�ڴ�ͷ���ĵ�����L�е�i��λ��֮ǰ����Ԫ��e���ɹ�����1��ʧ�ܷ���0
int LinkListInsert(LNode *L, int i, ElemType e)
{
	LNode  *p, *s;
	int  j;
	p=L;   j=0;
	while(p!=NULL&&j<i-1){p=p->next;  ++j;}   //Ѱ�ҵ�i-1�����
	if(p==NULL||j>i-1)return 0;             //����λ�ò��Ϸ�
	s=(LNode *)malloc(sizeof(LNode));           //�����½��
	s->data=e; 
	s->next=p->next;p->next=s;             //ʵ�ֲ���
	return 1;
}
//�ڴ�ͷ���ĵ�����L�У�ɾ����i��Ԫ�أ�����e������ֵ���ɹ�����1��ʧ�ܷ���0
int LinkListDelete(LNode *L, int i, ElemType *e)
{
	LNode *p, *q;
	int j;
	p=L;   j=0;
	while(p->next!=NULL&&j<i-1)          //Ѱ�ҵ�i����㣬����pָ����ǰ��
	{ 
		p=p->next;++j;
	}  
	if(!(p->next)||j>i-1)  return 0;     //ɾ��λ�ò�����
	q=p->next; 
	*e=q->data;                       //��e���ر�ɾ����������ֵ
	p->next=q->next;free(q);   //ɾ�����ͷŽ��
	return 1;
}
//�ڴ�ͷ���ĵ�����L��,�����Ƿ���������ֵ��ͬ��Ԫ�أ�������ڣ��򷵻�λ�ã����򷵻�0��
int LinkListLocate(LNode L, ElemType e)
{
	int i=1;
	LNode *p=L.next;//ָ���1��Ԫ��
	while (p!=NULL&& p->data!=e)
	{
		p=p->next;//ָ����һ��Ԫ��
		i++;
	}
	if(p==NULL)return 0;//û�д����ҵ�Ԫ��
	return i;//�ҵ��ˣ����ظ�Ԫ�ص�λ��
}

//�ڴ�ͷ���ĵ�����L��,���ص�i��Ԫ�ص�ֵ������0��ʾ����
ElemType LinkListGetElem(LNode L,int i)
{

	LNode * p;
	int  j; //j��ʾ��ǰ�ǵڼ���Ԫ��
	if (i<1) return 0;
	p=L.next;j=1; //ָ���1��Ԫ��
	while (p!=NULL && j<i)
	{
		j++;p=p->next;//ָ����һ��Ԫ��
	}
	if (p!=NULL) return 0;  
	return p->data;
}

//�ڴ�ͷ���ĵ�����L��,������ʾÿһ��Ԫ�ص�ֵ
void PrintList(LNode L)
{
	LNode *p;
	p=L.next;//ָ��һ��Ԫ��
	while(p!=NULL)
	{
		printf("%3d",p->data);
		p=p->next;//ָ����һ��Ԫ��
	}
	printf("\n");
}

//��֪������La��Lb��Ԫ�ذ�ֵ�ǵݼ����С�
//�鲢La��Lb�õ��µĵ�����La��La��Ԫ��Ҳ��ֵ�ǵݼ�����
void LinkListMerge(LNode *La, LNode *Lb)
{
	LNode* pa = La->next;//paָ��La�еĵ�1�����
	LNode* pb = Lb->next; //pbָ��Lb�еĵ�1�����
	LNode* pc=La; //pc��ʾ���γɵ������е����һ�����
	while (pa!=NULL && pb!=NULL)
	{ 
		if ( pa->data <= pb->data){
		// �� *pa ����Lc��ָ�� pa ����
			pc->next = pa; pc = pa; pa = pa->next; 
		}
		else{// �� *pb ����Lc��ָ�� pb ����
			pc->next = pb; pc = pb; pb = pb->next;  
		}
	}
	pc->next = pa!=NULL ? pa : pb; // ����ʣ���
	free(Lb);
}

//���ڴ�ͷ���ĵ�����ת
void LinkListInvert(LNode *L)
{ 
	LNode *p,*q;
	p=L->next; //pָ��a1���
	q=p->next; //qָ��a2���
	L->next=NULL; //�赱ǰ����Ϊ��
	while(p!=NULL) //*p���ǿ�ʱѭ��
	{
		p->next=L->next;
		L->next=p; //���*p��next����
		p=q;
		if(p!=NULL)q=p->next;
	} 
}



int main()
{
	/*LNode *head;
	int x,loc;
	int i=0;
	system("title ��3�� ���Ա�-������ı�ʾ��ʵ��");
	head=LinkListInit();//��ʼ��һ����������
	if(head==NULL)
	{
		printf("��ʼ������ʧ�ܣ�\n");return 0;
	}
	//���β���Ԫ�أ���0��Ϊ������־
	do{
		printf("�������%d��Ԫ�ص�ֵ(������������0��:",i+1);
		scanf("%d",&x);
		if(x!=0)
		{
			LinkListInsert(head,++i,x);//���β���Ԫ��
		}		
	}while(x!=0);
	printf("��ǰ���Ա��е�Ԫ������Ϊ��\n");
	PrintList(*head);
	//����һ��Ԫ��
	printf("��������Ҫ����Ԫ�ص�λ�ú�ֵ��");
	scanf("%d%d",&loc,&x);
	LinkListInsert(head,loc,x);//�ڵ�loc��λ�ò���x
	printf("��������Ա��е�Ԫ������Ϊ��\n");
	PrintList(*head);
	//ɾ��һ��Ԫ��
	printf("��������Ҫɾ��Ԫ�ص�λ�ã�");
	scanf("%d",&loc);
	LinkListDelete(head,loc,&x);//ɾ����loc��Ԫ��
	printf("ɾ��%d�����Ա��е�Ԫ������Ϊ��\n",x);
	PrintList(*head);
	//����Ԫ��
	printf("��������Ҫ����Ԫ�ص�ֵ��");
	scanf("%d",&x);
	loc=LinkListLocate(*head, x);//����ֵΪx��Ԫ��λ��
	if(loc>0)
		printf("�ҵ��ˣ�%d�����Ա��е�%d��Ԫ��\n",x,loc);
	else
		printf("�����Ա���û���ҵ�ֵΪ%d��Ԫ��\n",x);*/


	LNode *la,*lb;
	la=LinkListInit();
	lb=LinkListInit();

	LinkListInsert(la,1,23);
	LinkListInsert(la,2,27);
	LinkListInsert(la,3,32);
	LinkListInsert(la,4,39);
	LinkListInsert(la,5,41);

	PrintList(*la);

	LinkListInsert(lb,1,13);
	LinkListInsert(lb,2,28);
	LinkListInsert(lb,3,30);
	LinkListInsert(lb,4,42);
	LinkListInsert(lb,5,47);
	PrintList(*lb);

	LinkListMerge(la,lb);
	PrintList(*la);

	LinkListInvert(la);
	PrintList(*la);
	return 0;
}
