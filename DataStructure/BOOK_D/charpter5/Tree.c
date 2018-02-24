#include<stdio.h>
#include<stdlib.h>
typedef  char ElemType;   //Ĭ����������Ϊchar
//���Ա�ĵ�����洢�ṹ����
typedef struct BiNode{
   ElemType data;
   struct BiNode *lchild,*rchild;    //���Һ���ָ��
}BiNode;


BiNode *Creat();
void PreOrder(BiNode *);
void Visit(ElemType);
void InOrder (BiNode *);
void PostOrder(BiNode *);
void ComputeNode(BiNode *);
void InsertNodeL(BiNode *,ElemType,ElemType);
void InsertNodeR(BiNode *,ElemType,ElemType);
void DelectNode(BiNode *bt,ElemType x);
int nodeNum,leafNum;

void main()
{
	int ch;
	char exit='N';
	BiNode *T;
	ElemType x,y;
	int loc;

	nodeNum=leafNum=0;
	do
	{
		system("CLS");
		printf("\t\t********************************************\n");
		printf("\t\t*  1.����һ��������  .................(1)  *\n");
		printf("\t\t*  2.�������������  .................(2)  *\n");
		printf("\t\t*  3.�������������  .................(3)  *\n");
	    printf("\t\t*  4.�������������  .................(4)  *\n");
		printf("\t\t*  5.������������Ҷ����.............(5)  *\n");
		printf("\t\t*  6.�������в����µĽ��.............(6)  *\n");
		printf("\t\t*  7.ɾ��������ָ�����...............(7)  *\n");
		printf("\t\t*  8.�˳�              ............. .(8) *\n");
		printf("\t\t********************************************\n");
		printf("\n��ѡ��������룺");
        scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				getchar();
				printf("����������:\n�������Ƕ��������������У���#��ʾ����Ϊ�գ�");
				T=Creat();				
				printf("�����������ɹ�!\n");			
				system("pause");
				break;
			case 2:
				printf("�������������:\n");
                PreOrder(T);
				system("pause");
				break;
			case 3:
               printf("�������������:\n");
               InOrder(T);
			   system("pause");
				break;
			case 4:				
		        printf("�������������:\n");
				PostOrder(T);
				system("pause");
				break;
			case 5:			   	
				ComputeNode(T);
				printf("�������н������Ϊ��%d,Ҷ�������Ϊ��%d\n",nodeNum,leafNum);
				system("pause");		

				break;
			case 6:
				printf("�������в����µĽ��:\n");
				printf("������Ҫ����Ľ�㣺");fflush(stdin);scanf("%c",&x);
				printf("������Ҫ�����ֵ��");fflush(stdin);scanf("%c",&y);
				printf("��������������(1)����������(2)���룺");scanf("%d",&loc);
				if(loc==1)
					InsertNodeL(T,x,y);
				else
					InsertNodeR(T,x,y);

				printf("�������������:\n");
               InOrder(T);

				
			
				system("pause");
				break;
			case 7:
				printf("��������ɾ���Ľ��:\n");
				printf("������Ҫɾ���Ľ���ֵ��");fflush(stdin);scanf("%c",&x);
				DelectNode(T,x);

				printf("�������������:\n");
               InOrder(T);
                
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
void Visit(ElemType data)
{
	printf("%c",data);
}
void PreOrder(BiNode *bt) 
{
    if (bt == NULL)  return;              //�ݹ���õĽ�������
    else
	{
		Visit(bt->data);                  //���ʸ����bt��������
        PreOrder(bt->lchild);             //ǰ��ݹ����bt��������
        PreOrder(bt->rchild);             //ǰ��ݹ����bt��������  
    }
}

void InOrder (BiNode *bt)
{
     if (bt == NULL) return;                 //�ݹ���õĽ�������
     else 
	 {
         InOrder(bt->lchild);                //����ݹ����bt��������
         Visit(bt->data);                    //���ʸ����bt��������
         InOrder(bt->rchild);                //����ݹ����bt��������
    }
}

void PostOrder(BiNode *bt)
{ 
     if (bt == NULL) return;                //�ݹ���õĽ�������
     else 
	 {
         PostOrder(bt->lchild);             //����ݹ����bt��������
         PostOrder(bt->rchild);             //����ݹ����bt��������
         Visit(bt->data);                   //���ʸ����bt��������
    }
}

BiNode *Creat()
{
	BiNode *bt;
    ElemType ch;
    scanf("%c",&ch);                           //�������������Ϣ������Ϊ�ַ�
    if (ch =='#') bt = NULL;                //����һ�ÿ���
    else
    {
        bt = (BiNode*)malloc(sizeof(BiNode));;
		bt->data = ch;  //����һ����㣬������Ϊch
        bt->lchild = Creat();        //�ݹ齨��������
        bt->rchild = Creat();        //�ݹ齨��������
    }
    return bt;
}

void Release(BiNode *bt)
{
    if (bt == NULL) return;                 //�ݹ���õĽ�������
    else
    {
        Release(bt->lchild);               //����ݹ����bt��������
        Release(bt->rchild);               //����ݹ����bt��������
        free(bt);                        //���ٸ����bt
    }
}
//����������Ľڵ�����Ҷ�ڵ���
void ComputeNode(BiNode *bt)
{
	if (bt) { //�ݹ���õĽ�������ΪbtΪ��
		nodeNum++; 	 //���ʽ���������
		if(bt->lchild==NULL&&bt->rchild==NULL)leafNum++;
		ComputeNode(bt->lchild);  //����ݹ����bt��������
		ComputeNode(bt->rchild);  //����ݹ����bt��������
     }
}

BiNode *SelectNode(BiNode *bt,ElemType e)
{
	 if (bt == NULL) return NULL;                 //�ݹ���õĽ�������
     else 
	 {
         SelectNode(bt->lchild,e);                //����ݹ����bt��������
         if(e==bt->data)return bt;             //�ҵ���㣬������
         SelectNode(bt->rchild,e);                //����ݹ����bt��������
    }

}
void InsertNodeL(BiNode *bt,ElemType x,ElemType y)
{
	BiNode *p,*s;
	p=SelectNode(bt,x);
	if(p==NULL)printf("û���ҵ�ֵΪ%c�Ľ�㣬�޷����룡\n",x);
	else if(p->lchild!=NULL)printf("���%c����������Ϊ�գ��޷����룡\n",x);
	else
	{
		s=(BiNode *)malloc(sizeof(BiNode));
		s->data=y;
		s->lchild=s->rchild=NULL;
		p->lchild=s;
	}
}
void InsertNodeR(BiNode *bt,ElemType x,ElemType y)
{
	BiNode *p,*s;
	p=SelectNode(bt,x);
	if(p==NULL)printf("û���ҵ�ֵΪ%c�Ľ�㣬�޷����룡\n",x);
	else if(p->rchild!=NULL)printf("���%c����������Ϊ�գ��޷����룡\n",x);
	else
	{
		s=(BiNode *)malloc(sizeof(BiNode));
		s->data=y;
		s->lchild=s->rchild=NULL;
		p->rchild=s;
	}
}

BiNode *SelectParentsNode(BiNode *bt,ElemType e)
{
	 if (bt == NULL) return NULL;                 //�ݹ���õĽ�������
     else 
	 {
		 if(bt->lchild!=NULL)
			 if(e==bt->lchild->data)return bt;
			 else SelectParentsNode(bt->lchild,e);
		 if(bt->rchild!=NULL)
			 if(e==bt->rchild->data)return bt;
			 else SelectParentsNode(bt->rchild,e);    }

}
void DelectNode(BiNode *bt,ElemType x)
{
	BiNode *p;
	if(bt->data==x)Release(bt);
	else
	{
		p=SelectParentsNode(bt,x);
		if(p==NULL)
			printf("û���ҵ�ֵΪ%c�Ľ�㣬�޷�ɾ����\n",x);
		else
		{
			if(p->lchild->data==x)
			{
				Release(p->lchild);p->lchild=NULL;
			}
			else
			{
				Release(p->rchild);p->rchild=NULL;
			}
		
		}
	}

}