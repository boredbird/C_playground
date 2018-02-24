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
int Search_Bin(SeqTable ST, keyType key)
/*在有序表ST中折半查找关键字等于key的元素，若找到，则返回为该元素在表中的索引，否则为-1。*/
{
	int low,high,mid;
	low =0;  high=ST.length-1;/*置区间初值*/
	while (low <= high) 
    {
         mid = (low + high) / 2;
		 if (key==ST.elem[mid].key)
			 return  mid;        /*找到待查元素*/
         else  if (key<ST.elem[mid].key)
			 high = mid - 1;     /*继续在前半区间进行查找*/
         else  low = mid + 1;    /*继续在后半区间进行查找*/
   }
   return -1;                 /*顺序表中不存在待查元素*/
}
void main()
{
	SeqTable ST;	keyType key;	int index;
	SElemType Data[MAXSIZE]={12, 33, 40, 45, 53, 55, 64, 66, 77};
	ST.elem=Data;	ST.length=9;
	printf("请输入待查元素的关键字:");scanf("%d",&key);
	index=Search_Bin(ST,key);            /* 算法7-2*/
	if(index==-1) 
printf("找不到关键字为%d的元素!\n",key);
	else
		printf("关键字为%d的元素在查找表索引号为：%d",key,index);
}
