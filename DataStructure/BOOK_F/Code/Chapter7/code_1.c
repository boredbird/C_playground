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
/*��˳���ST��˳�������ؼ��ֵ��� key������Ԫ�ء����ҵ����򷵻�Ϊ��Ԫ���ڱ��е�����������Ϊ-1��*/
{
	int i;
	ST.elem[ST.length].key=key;          /* "�ڱ�"*/ 	
	for (i=0;ST.elem[i].key!=key;++i); /*��ǰ������*/
	if(i<ST.length)return i;
	else return -1;
}
void main()
{
	SeqTable ST;	keyType key;	int index;
	SElemType Data[MAXSIZE]={34, 44, 43, 12, 53, 55,73, 64, 77};
	ST.elem=Data;	ST.length=9;
	printf("���������Ԫ�صĹؼ���:");scanf("%d",&key);
	index=Search_Seq(ST,key);             /* �㷨7-1*/
	if(index==-1) 
		printf("�Ҳ����ؼ���Ϊ%d��Ԫ��!\n",key);
	else
		printf("�ؼ���Ϊ%d��Ԫ���ڲ��ұ�������Ϊ��%d",key,index);
}

