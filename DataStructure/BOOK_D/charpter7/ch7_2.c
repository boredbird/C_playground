#include<stdio.h>
#define MAXSIZE 100
typedef int keyType;
typedef struct
{
	keyType key;/*�ؼ�����*/
	/*������*/
}SElemType;
typedef struct
{
	SElemType *elem;/*����Ԫ�ش洢�ռ��ַ*/
	int length;/*����*/
} SeqTable;
int Search_Seq(SeqTable ST,keyType key) 
/*��˳���ST��˳�������ؼ��ִ��ڻ���� key������Ԫ�ء����ز���λ�á�*/
{
	int i;
	ST.elem[ST.length].key=key;          /* "�ڱ�"*/ 	
	for (i=0;ST.elem[i].key<key;++i); /*��ǰ������*/
     return i;
	
}
int Search_Bin(SeqTable ST, keyType key)
/*�������ST���۰���Ҳ���λ�ò����ء�*/
{
	int low,high,mid;
	low =0;  high=ST.length-1;/*�������ֵ*/
	while (low <= high) 
    {
         mid = (low + high) / 2;
		 if (key==ST.elem[mid].key)
			 return  mid;        /*�ҵ�����Ԫ��*/
         else  if (key<ST.elem[mid].key)
			 high = mid - 1;     /*������ǰ��������в���*/
         else  low = mid + 1;    /*�����ں��������в���*/
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
		
		printf("\t\t******��ѡ������㷨************************\n");
		printf("\t\t*  1.˳�����.........................(1)  *\n");
		printf("\t\t*  2.�۰����.........................(2)  *\n");
     	printf("\t\t*  3.�˳�.............................(3) *\n");
		printf("\t\t********************************************\n");
		printf("\n��ѡ��������룺");
        scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("ԭʼ����:");DisPlay(ST);
				printf("\n���������Ԫ�صĹؼ���:");scanf("%d",&key);
				index=Search_Seq(ST,key);
				Insert(&ST,key,index);
				printf("���������У�");
				DisPlay(ST);
				printf("\n");
				system("pause");
				break;	
			case 2:
			    printf("ԭʼ����:");DisPlay(ST);
				printf("\n���������Ԫ�صĹؼ���:");scanf("%d",&key);
				index=Search_Bin(ST,key);
				Insert(&ST,key,index);
				printf("���������У�");
				DisPlay(ST);
				printf("\n");
				system("pause");
				break;
		    case 3:
				getchar();
				printf("\n���Ƿ����Ҫ�˳�����(Y/N):");
				exit=getchar();getchar();
				break;
			default:
				printf("\n��Ч���룬������ѡ��...:");				

		}
		
	}while(exit!='y'&&exit!='Y');

}
