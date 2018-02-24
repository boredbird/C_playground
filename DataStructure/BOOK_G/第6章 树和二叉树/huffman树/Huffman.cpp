#include<stdio.h>
#include<stdlib.h>
#include<string> 
#include<conio.h>
#include<iostream.h>
#include<fstream.h>

int A[100];

typedef struct 
{  
  int weight; 
  int parent,lchild,rchild; 
}HTNode,*HuffmanTree;//�շ��������ṹ
 
typedef char **HuffmanCode;

void Calculate_weight(char a[],char b[],int m,int n,int *w)//����Ȩֵ
{	
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(b[i]==a[j])
				A[i+1]=w[i+1]++;
}

void FindNode(HuffmanTree HT,int n,int &t1,int &t2)
{
	HT[0].weight=100;//����Ȩֵһ�㲻�ܳ�������
	t1=0;t2=0;
	for(int i=1;i<=n;++i)
		if(HT[i].parent==0)
		{
			if(HT[i].weight<HT[t2].weight)
			{
				if(HT[t2].weight<HT[t1].weight) t1=t2;
				t2=i;
			}
			else if(HT[i].weight<HT[t1].weight){t1=t2;t2=i;}
		}
}

void output_tree_info(HuffmanTree HT,int m)
{
	int i;
	ofstream outfile("output_tree_info.txt");//д��output_tree_info�ļ�
    outfile<<"���  Ȩ��  �����  ����  �Һ���"<<endl;
    for(i=1;i<=m;i++)
	{       
		outfile<<i<<"\t";
		outfile<<HT[i].weight<<"\t";
		outfile<<HT[i].parent<<"\t";
		outfile<<HT[i].lchild<<"\t";
		outfile<<HT[i].rchild<<endl;
	}
}

void output_code_info(char b[],HuffmanCode HC,int n)
{
	int i;
    ofstream outfile("output_code_info.txt");//д��output_code_info�ļ�
	outfile<<"�����:"<<"\t"<<"����Ƶ��"<<endl;
    for(i=1;i<=n;i++)
    outfile<<b[i-1]<<":"<<HC[i]<<"\t"<<A[i]+1<<endl; 
}

//�շ������������� 
//����w���n���ַ���Ȩֵ(��>0)������շ�����HT�������n���ַ��ĺշ�������HC
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int*w,int n)
{
    int m,i,t1,t2,start; 
    unsigned c,f; 
    HuffmanTree p; 
    char *cd; 
    m=2*n-1;
    HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode)); 
    for(p=HT+1,i=1;i<=n;++i,++p)//ǰn������ʼ�� 
	{
        p->weight=w[i];
        p->parent=0; 
        p->lchild=0; 
        p->rchild=0; 
	} 
    for(;i<=m;++i,++p)//�Դӵ�n+1�����㵽��2n-1�������ʼ�� 
	{
        p->weight=0; 
        p->parent=0; 
        p->lchild=0; 
        p->rchild=0;
	}
    for(i=n+1;i<=m;++i)//�����շ�����
	{
        FindNode(HT,i-1,t1,t2);
        HT[t1].parent=i;
        HT[t2].parent=i; 
        HT[i].lchild=t1; 
        HT[i].rchild=t2; 
        HT[i].weight=HT[t1].weight+HT[t2].weight; 
	} 

	output_tree_info(HT,m);
    printf("\nHuffman�������Ľṹ:\n");
    printf("���  Ȩ��  �����  ����  �Һ���\n");
    for(i=1;i<=m;i++)
	{
		printf("%d\t",i);
        printf("%d\t",HT[i].weight);
        printf("%d\t",HT[i].parent);
		printf("%d\t",HT[i].lchild);
		printf("%d\n",HT[i].rchild);
	}

	//--- ��Ҷ�ӽ�㵽�����������ÿ���ַ��ĺշ������� ---
	HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
    cd=(char*)malloc(n*sizeof(char));//���������Ĺ����ռ�
    cd[n-1]='\0';//���������
    for(i=1;i<=n;i++)//����ַ���շ�������
	{
        start=n-1;//���������λ��
        for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)//��Ҷ�ӵ������������
            if(HT[f].lchild==c)  cd[--start]='0'; 
		    else  cd[--start]='1'; 
        HC[i]=(char*)malloc((n-start)*sizeof(char));//Ϊ��i���ַ��������ռ�
        strcpy(HC[i],&cd[start]);//��cd���Ʊ��봮��HC
	} 
    free(cd);//�ͷŹ����ռ�
}

void Output_HuffmanCoding(char a[],char b[],int m,int n,HuffmanCode HC)//���huffman����
{
	int i,j;
    printf("�ַ���ת���ɵ�Huffman��������:\n");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(a[i]==b[j])
			cout<<HC[j+1]<<"\t";
			cout<<endl;
}

void HuffmanDecoding(int n,char b[],HuffmanTree HT)//�Ա���Ķ����ƴ����н���
{
	int m=2*n-1;
	int i=m;
	char c;
	printf("\n������һ������:\n");
	cin>>c;
	printf("\n��������Ϊ:\n");
	while((c=='0')||(c=='1'))//�ж��Ƿ��ǺϷ��ַ�
	{ 
		if(c=='0')   i=HT[i].lchild;//�����������
		else  i=HT[i].rchild;//�������Ҳ���
		if(HT[i].lchild==0)//ֱ����֧��ĩ��
		{
			printf("%c",b[i-1]);//�����Ӧ�ķ���
			i=m;//���¿�ʼ������һ��
		}
		cin>>c;
	}
	printf("\n");
}

void main()
{
    HuffmanTree HTree; 
    HuffmanCode HCode; 
    char a[100],b[100];//aΪ������ַ���
    int i=0,j=0,len=0,n=0,*w;
    printf("����������һ���ַ�:\n");
	gets(a);
	len = strlen(a);//lenΪ����
	for(i=0;i<len;i++)
	{
		for(j=0;j<i;j++)
			if((i<len)&&(a[j]==a[i]))
			{
				i++;
				j=-1;
			}
		if(i<len){b[n]=a[i];n++;}
	} 
	w=(int*)malloc((n+1)*sizeof(int));
	for(i=1;i<=n;i++) w[i]=0;
    Calculate_weight(a,b,len,n,w);
    HuffmanCoding(HTree,HCode,w,n);

    output_code_info(b,HCode,n);
    printf("\nHuffman�����ַ�����ϸ��������:\n");
    printf("�����:\t����Ƶ��:\n");
    for(i=1;i<=n;i++)		
		cout<<b[i-1]<<":"<<HCode[i]<<"\t"<<A[i]+1<<endl;


    Output_HuffmanCoding(a,b,len,n,HCode);//���huffman����
    HuffmanDecoding(n,b,HTree);//�Ա���Ķ����ƴ����н���
}

