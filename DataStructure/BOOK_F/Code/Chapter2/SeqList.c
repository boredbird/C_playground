#include<stdio.h>
#include <stdlib.h>
#define INIT_SIZE  100     //线性表存储空间的初始分配量
#define INCREMENT  10    //线性表存储空间的分配增量
typedef  int ElemType;   //默认数据类型为int
typedef  struct{
   ElemType  *elem;   //存储空间的基地址
   int  length;       //当前长度
   int  listsize;     //当前分配的存储容量（以sizeof(ElemType)为单位）
}SqList;
//初始化顺序表，成功返回1，失败返回0
int SqListInit(SqList *L)
{
    L->elem=(ElemType *)malloc(INIT_SIZE*sizeof(ElemType));
    if(!L->elem) return 0;
    L->length=0;
    L->listsize=INIT_SIZE;
    return 1;
}

//在顺序表L的第i个位置之前插入新的元素e，成功返回1，失败返回0
int SqListInsert(SqList *L, int i, ElemType e)
{
	int j;
	ElemType *newbase;
	if(i<1 || i>L->length+1)   return 0;    //插入位置不合法
	if(L->length>=L->listsize)              //当前存储空间已满，增加分配
	{ 
		newbase = (ElemType *)realloc(L->elem, (L->listsize +INCREMENT)*sizeof(ElemType));
		if(!newbase) return 0;              //存储分配失败
		L->elem = newbase;
		L->listsize += INCREMENT;   
	}
	for(j=L->length-1;j>=i-1;j--)
		L->elem[j+1] = L->elem[j];  //插入位置及之后的元素后移
	L->elem[i-1]=e;                 //插入e
	++L->length;                    //表长增1
	return 1;
}

//在顺序表L中删除第i个元素，并用e返回其值，成功返回1，失败返回0
int SqListDelete(SqList *L, int i, ElemType *e)

{
    int j;
    if(i<1 || i>L->length)  return 0;   //删除位置不合法
    *e=L->elem[i-1];                    //被删除元素的值赋给e
    for(j=i-1; j<L->length-1; j++)                
         L->elem[j]=L->elem[j+1];       //被删元素之后的元素前移
    --L->length;
    return 1;
}

//在顺序线性表L中查找第1个值与e相等的元素的位序，
//若找到，则返回其在L中的位序，否则返回0
int SqListLocate(SqList L, ElemType e)

{
         int i=1;     //i的初值为第一个元素的位序
         while(i<=L.length&&L.elem[i-1]!=e)  i++;
         if(i<=L.length)  return i;
         else return 0;
}

//已知顺序线性表LA和LB的元素按值非递减排列，归并LA和LB得到新的按值非递减序列LC
void MergeList_Sq(SqList LA,SqList LB,SqList *LC)
{
	int i=0,j=0,k=0;
	int La_len,Lb_len;
	ElemType La_elem,Lb_elem;
	La_len=LA.length;    //获得LA的元素个数
	Lb_len=LB.length;    //获得LB的元素个数
	while(i<La_len&&j<Lb_len)
	{
		La_elem=LA.elem[i];   //获得LA的第i个元素的值
		Lb_elem=LB.elem[j];    //获得LB的第j个元素的值
		if(La_elem<=Lb_elem)//把LA的第i个元素的值插入到LC中
		{
			SqListInsert(LC,++k,La_elem);i++;
		}
		else //把LB的第J个元素的值插入到LC中
		{
			SqListInsert(LC,++k,Lb_elem);j++;
		}
	}
	while(i<La_len)SqListInsert(LC,++k,LA.elem[i++]);//插入剩余段
	while(j<Lb_len)SqListInsert(LC,++k,LB.elem[j++]);;
}

//将线型表中下标自s到t的元素逆置，即将
//（L.elem[s],L.elem[s+1],…,L.elem[t-1],L.elem[t]）改变为
//（L.elem[t],L.elem[t-1],…,L.elem[s+1],L.elem[s]）
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
//本算法实现顺序表中前 m 个元素和后n个元素的互换
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
	/*SqList sq;  //创建一个线性表
	SqListInit(&sq); //初始化线性表	

	system("title 第2章 线性表-顺序表的表示与实现");
	for(i=0;i<5;i++)
	{
		printf("请输入第%d个元素的值:",i+1);
		scanf("%d",&x);
		SqListInsert(&sq,i+1,x);//依次插入5个元素
	}
	printf("当前线性表中的元素依次为：\n");
	for(i=0;i<sq.length;i++)
		printf("%3d",sq.elem[i]);
	printf("\n请输入需要插入元素的位置和值：");
	scanf("%d%d",&loc,&x);
	SqListInsert(&sq,loc,x);//在第loc个位置插入x
	printf("插入后线性表中的元素依次为：\n");
	for(i=0;i<sq.length;i++)
		printf("%3d",sq.elem[i]);
	printf("\n请输入需要删除元素的位置：");
	scanf("%d",&loc);
	SqListDelete(&sq,loc,&e);//删除第loc个元素
	printf("删除%d后线性表中的元素依次为：\n",e);
	for(i=0;i<sq.length;i++)
		printf("%3d",sq.elem[i]);
	printf("\n请输入需要查找元素的值：");
	scanf("%d",&x);
	loc=SqListLocate(sq,x);//查找值为x的元素位置
	if(loc>0)
		printf("找到了！%d是线性表中第%d个元素\n",x,loc);
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
