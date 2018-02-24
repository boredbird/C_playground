#include<stdio.h>
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
/*在顺序表ST中顺序查找其关键字大于或等于 key的数据元素。返回插入位置。*/
{
	int i;
	ST.elem[ST.length].key=key;          /* "哨兵"*/ 	
	for (i=0;ST.elem[i].key<key;++i); /*从前往后找*/
     return i;
	
}
int Search_Bin(SeqTable ST, keyType key)
/*在有序表ST中折半查找插入位置并返回。*/
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
   if (key<ST.elem[mid].key)return mid;  
   else return mid+1;
}
void Insert(SeqTable *ST,keyType key,int loc)
{
	int i;
	for(i=ST->length;i>loc;i--)
		ST->elem[i].key=ST->elem[i-1].key;
	ST->elem[loc].key=key;
	ST->length++;
	
}
void DisPlay(SeqTable ST)
{
	int i;
	for(i=0;i<ST.length;i++)
	{
		printf("%3d",ST.elem[i]);
	}
}
void main()
{
	int ch;
	char exit='N';
	SeqTable ST;
	keyType key;
	int index;
	SElemType Data[MAXSIZE]={7,12,15,34,45,52,56,65,70};
	ST.elem=Data;	ST.length=9;
	
	
	do
	{
	    system("CLS");
		
		printf("\t\t******请选择查找算法************************\n");
		printf("\t\t*  1.顺序查找.........................(1)  *\n");
		printf("\t\t*  2.折半查找.........................(2)  *\n");
     	printf("\t\t*  3.退出.............................(3) *\n");
		printf("\t\t********************************************\n");
		printf("\n请选择操作代码：");
        scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("原始序列:");DisPlay(ST);
				printf("\n请输入待查元素的关键字:");scanf("%d",&key);
				index=Search_Seq(ST,key);
				Insert(&ST,key,index);
				printf("插入后的序列：");
				DisPlay(ST);
				printf("\n");
				system("pause");
				break;	
			case 2:
			    printf("原始序列:");DisPlay(ST);
				printf("\n请输入待查元素的关键字:");scanf("%d",&key);
				index=Search_Bin(ST,key);
				Insert(&ST,key,index);
				printf("插入后的序列：");
				DisPlay(ST);
				printf("\n");
				system("pause");
				break;
		    case 3:
				getchar();
				printf("\n您是否真的要退出程序(Y/N):");
				exit=getchar();getchar();
				break;
			default:
				printf("\n无效输入，请重新选择...:");				

		}
		
	}while(exit!='y'&&exit!='Y');

}
