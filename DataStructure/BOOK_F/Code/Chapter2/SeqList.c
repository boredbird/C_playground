#include<stdio.h>
#include <stdlib.h>
#define INIT_SIZE  100     //���Ա�洢�ռ�ĳ�ʼ������
#define INCREMENT  10    //���Ա�洢�ռ�ķ�������
typedef  int ElemType;   //Ĭ����������Ϊint
typedef  struct{
   ElemType  *elem;   //�洢�ռ�Ļ���ַ
   int  length;       //��ǰ����
   int  listsize;     //��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ��
}SqList;
//��ʼ��˳����ɹ�����1��ʧ�ܷ���0
int SqListInit(SqList *L)
{
    L->elem=(ElemType *)malloc(INIT_SIZE*sizeof(ElemType));
    if(!L->elem) return 0;
    L->length=0;
    L->listsize=INIT_SIZE;
    return 1;
}

//��˳���L�ĵ�i��λ��֮ǰ�����µ�Ԫ��e���ɹ�����1��ʧ�ܷ���0
int SqListInsert(SqList *L, int i, ElemType e)
{
	int j;
	ElemType *newbase;
	if(i<1 || i>L->length+1)   return 0;    //����λ�ò��Ϸ�
	if(L->length>=L->listsize)              //��ǰ�洢�ռ����������ӷ���
	{ 
		newbase = (ElemType *)realloc(L->elem, (L->listsize +INCREMENT)*sizeof(ElemType));
		if(!newbase) return 0;              //�洢����ʧ��
		L->elem = newbase;
		L->listsize += INCREMENT;   
	}
	for(j=L->length-1;j>=i-1;j--)
		L->elem[j+1] = L->elem[j];  //����λ�ü�֮���Ԫ�غ���
	L->elem[i-1]=e;                 //����e
	++L->length;                    //����1
	return 1;
}

//��˳���L��ɾ����i��Ԫ�أ�����e������ֵ���ɹ�����1��ʧ�ܷ���0
int SqListDelete(SqList *L, int i, ElemType *e)

{
    int j;
    if(i<1 || i>L->length)  return 0;   //ɾ��λ�ò��Ϸ�
    *e=L->elem[i-1];                    //��ɾ��Ԫ�ص�ֵ����e
    for(j=i-1; j<L->length-1; j++)                
         L->elem[j]=L->elem[j+1];       //��ɾԪ��֮���Ԫ��ǰ��
    --L->length;
    return 1;
}

//��˳�����Ա�L�в��ҵ�1��ֵ��e��ȵ�Ԫ�ص�λ��
//���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0
int SqListLocate(SqList L, ElemType e)

{
         int i=1;     //i�ĳ�ֵΪ��һ��Ԫ�ص�λ��
         while(i<=L.length&&L.elem[i-1]!=e)  i++;
         if(i<=L.length)  return i;
         else return 0;
}

//��֪˳�����Ա�LA��LB��Ԫ�ذ�ֵ�ǵݼ����У��鲢LA��LB�õ��µİ�ֵ�ǵݼ�����LC
void MergeList_Sq(SqList LA,SqList LB,SqList *LC)
{
	int i=0,j=0,k=0;
	int La_len,Lb_len;
	ElemType La_elem,Lb_elem;
	La_len=LA.length;    //���LA��Ԫ�ظ���
	Lb_len=LB.length;    //���LB��Ԫ�ظ���
	while(i<La_len&&j<Lb_len)
	{
		La_elem=LA.elem[i];   //���LA�ĵ�i��Ԫ�ص�ֵ
		Lb_elem=LB.elem[j];    //���LB�ĵ�j��Ԫ�ص�ֵ
		if(La_elem<=Lb_elem)//��LA�ĵ�i��Ԫ�ص�ֵ���뵽LC��
		{
			SqListInsert(LC,++k,La_elem);i++;
		}
		else //��LB�ĵ�J��Ԫ�ص�ֵ���뵽LC��
		{
			SqListInsert(LC,++k,Lb_elem);j++;
		}
	}
	while(i<La_len)SqListInsert(LC,++k,LA.elem[i++]);//����ʣ���
	while(j<Lb_len)SqListInsert(LC,++k,LB.elem[j++]);;
}

//�����ͱ����±���s��t��Ԫ�����ã�����
//��L.elem[s],L.elem[s+1],��,L.elem[t-1],L.elem[t]���ı�Ϊ
//��L.elem[t],L.elem[t-1],��,L.elem[s+1],L.elem[s]��
void Invert(SqList *L,int s,int t )
{
	ElemType w;
	int k;
	for(k=s; k<=(s+t)/2; k++ )
	{
		w=L->elem[s];
		L->elem[s]=L->elem[t-k+s];
		L->elem[t-k+s]=w;		
	}
}
//���㷨ʵ��˳�����ǰ m ��Ԫ�غͺ�n��Ԫ�صĻ���
void Exchange (SqList *L,int m,int n ) 
{
	if(m>0&&n>0&&m+n== L->length)
	{ 
		Invert(L, 0, m+n-1 );
		Invert(L, 0, n-1 );
		Invert(L, n, m+n-1);
	}
}


int main()
{
	int i,x,loc,e;	
	/*SqList sq;  //����һ�����Ա�
	SqListInit(&sq); //��ʼ�����Ա�	

	system("title ��2�� ���Ա�-˳���ı�ʾ��ʵ��");
	for(i=0;i<5;i++)
	{
		printf("�������%d��Ԫ�ص�ֵ:",i+1);
		scanf("%d",&x);
		SqListInsert(&sq,i+1,x);//���β���5��Ԫ��
	}
	printf("��ǰ���Ա��е�Ԫ������Ϊ��\n");
	for(i=0;i<sq.length;i++)
		printf("%3d",sq.elem[i]);
	printf("\n��������Ҫ����Ԫ�ص�λ�ú�ֵ��");
	scanf("%d%d",&loc,&x);
	SqListInsert(&sq,loc,x);//�ڵ�loc��λ�ò���x
	printf("��������Ա��е�Ԫ������Ϊ��\n");
	for(i=0;i<sq.length;i++)
		printf("%3d",sq.elem[i]);
	printf("\n��������Ҫɾ��Ԫ�ص�λ�ã�");
	scanf("%d",&loc);
	SqListDelete(&sq,loc,&e);//ɾ����loc��Ԫ��
	printf("ɾ��%d�����Ա��е�Ԫ������Ϊ��\n",e);
	for(i=0;i<sq.length;i++)
		printf("%3d",sq.elem[i]);
	printf("\n��������Ҫ����Ԫ�ص�ֵ��");
	scanf("%d",&x);
	loc=SqListLocate(sq,x);//����ֵΪx��Ԫ��λ��
	if(loc>0)
		printf("�ҵ��ˣ�%d�����Ա��е�%d��Ԫ��\n",x,loc);
	else*/

	SqList la,lb,lc;
	SqListInit(&la);
	SqListInit(&lb);
	SqListInit(&lc);

	SqListInsert(&la,1,23);
	SqListInsert(&la,2,27);
	SqListInsert(&la,3,32);
	SqListInsert(&la,4,39);
	SqListInsert(&la,5,41);

	for(i=0;i<la.length;i++)
		printf("%3d",la.elem[i]);
	printf("\n");

	SqListInsert(&lb,1,13);
	SqListInsert(&lb,2,28);
	SqListInsert(&lb,3,30);
	SqListInsert(&lb,4,42);
	SqListInsert(&lb,5,47);

	for(i=0;i<lb.length;i++)
		printf("%3d",lb.elem[i]);
	printf("\n");

	MergeList_Sq(la,lb,&lc);

	for(i=0;i<lc.length;i++)
		printf("%3d",lc.elem[i]);printf("\n");

	Exchange(&lc,6,4);

		for(i=0;i<lc.length;i++)
		printf("%3d",lc.elem[i]);



	



	return 0;	
}
