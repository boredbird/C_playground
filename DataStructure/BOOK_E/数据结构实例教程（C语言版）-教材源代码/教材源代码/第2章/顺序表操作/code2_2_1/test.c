#include "stdio.h" 
typedef struct 
{
      int data[10];//����data���ڴ�ű���
      int length;//��ǰ�ı���   
 }SeqList;//�ṹ������
void InsertList(SeqList *L,int x,int i)
    {//���½�� x����L��ָ��˳���ĵ�i�����ai��λ����
       int j;
       if (i<1||i>L->length+1)
           printf("position error");//�Ƿ�λ�ã��˳�����
       if (L->length>=11)
           printf("overflow");     //��ռ�������˳�����
       for(j=L->length-1;j>=i-1;j--)
            L->data[j+1]=L->data[j];//������
       L->data[i-1]=x;      //����x
       L->length++;        //����1  
}
void DeleteList(SeqList *L,int i)
    {//��L��ָ��˳�����ɾ����i�����ai
        int j;
        if(i<1||i>L->length)
           printf("position error"); //�Ƿ�λ��
        for(j=i;j<=L->length-1;j++)
           L->data[j-1]=L->data[j]; //���ǰ��
        L->length--;                //����С 
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
    InsertList(&list,0,3);//����0����3��λ��
	list.length++;
	for(i=0;i<6;i++)
		printf("%d ",list.data[i]);
	printf("\n");
	DeleteList(&list,3);//����0����3��λ��
	list.length--;
	for(i=0;i<5;i++)
		printf("%d ",list.data[i]);
}
