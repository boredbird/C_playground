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
int Search_Bin(SeqTable ST, keyType key)
/*�������ST���۰���ҹؼ��ֵ���key��Ԫ�أ����ҵ����򷵻�Ϊ��Ԫ���ڱ��е�����������Ϊ-1��*/
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
   return -1;                 /*˳����в����ڴ���Ԫ��*/
}
void main()
{
	SeqTable ST;	keyType key;	int index;
	SElemType Data[MAXSIZE]={12, 33, 40, 45, 53, 55, 64, 66, 77};
	ST.elem=Data;	ST.length=9;
	printf("���������Ԫ�صĹؼ���:");scanf("%d",&key);
	index=Search_Bin(ST,key);            /* �㷨7-2*/
	if(index==-1) 
printf("�Ҳ����ؼ���Ϊ%d��Ԫ��!\n",key);
	else
		printf("�ؼ���Ϊ%d��Ԫ���ڲ��ұ�������Ϊ��%d",key,index);
}
