#include "stdio.h" 
typedef struct 
{
      int data[10];//向量data用于存放表结点
      int length;//当前的表长度   
 }SeqList;//结构体类型
void InsertList(SeqList *L,int x,int i)
    {//将新结点 x插入L所指的顺序表的第i个结点ai的位置上
       int j;
       if (i<1||i>L->length+1)
           printf("position error");//非法位置，退出运行
       if (L->length>=11)
           printf("overflow");     //表空间溢出，退出运行
       for(j=L->length-1;j>=i-1;j--)
            L->data[j+1]=L->data[j];//结点后移
       L->data[i-1]=x;      //插入x
       L->length++;        //表长加1  
}
void DeleteList(SeqList *L,int i)
    {//从L所指的顺序表中删除第i个结点ai
        int j;
        if(i<1||i>L->length)
           printf("position error"); //非法位置
        for(j=i;j<=L->length-1;j++)
           L->data[j-1]=L->data[j]; //结点前移
        L->length--;                //表长减小 
}
main()
{
    SeqList list;
	int i;
	for(i=0;i<5;i++)
		scanf("%d",&list.data[i]);
	list.length=5;
	for(i=0;i<5;i++)
		printf("%d ",list.data[i]);
	printf("\n");
    InsertList(&list,0,3);//插入0到第3个位置
	list.length++;
	for(i=0;i<6;i++)
		printf("%d ",list.data[i]);
	printf("\n");
	DeleteList(&list,3);//插入0到第3个位置
	list.length--;
	for(i=0;i<5;i++)
		printf("%d ",list.data[i]);
}
