#define MAXSIZE 100
typedef int keyType;
typedef struct
{
	keyType key;/*关键字域*/
	/*其它域*/
}SElemType;
typedef struct
{
	SElemType *elem;/*数据元素存储空间基址*/
	int length;/*表长度*/
} SeqTable;
int Search_Seq(SeqTable ST,keyType key) 
/*在顺序表ST中顺序查找其关键字等于 key的数据元素。若找到，则返回为该元素在表中的索引，否则为-1。*/
{
	int i;
	ST.elem[ST.length].key=key;          /* "哨兵"*/ 	
	for (i=0;ST.elem[i].key!=key;++i); /*从前往后找*/
	if(i<ST.length)return i;
	else return -1;
}
void main()
{
	SeqTable ST;	keyType key;	int index;
	SElemType Data[MAXSIZE]={34, 44, 43, 12, 53, 55,73, 64, 77};
	ST.elem=Data;	ST.length=9;
	printf("请输入待查元素的关键字:");scanf("%d",&key);
	index=Search_Seq(ST,key);             /* 算法7-1*/
	if(index==-1) 
		printf("找不到关键字为%d的元素!\n",key);
	else
		printf("关键字为%d的元素在查找表索引号为：%d",key,index);
}

