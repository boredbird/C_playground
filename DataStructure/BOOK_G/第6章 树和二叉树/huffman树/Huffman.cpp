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
}HTNode,*HuffmanTree;//赫夫曼树结点结构
 
typedef char **HuffmanCode;

void Calculate_weight(char a[],char b[],int m,int n,int *w)//计算权值
{	
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(b[i]==a[j])
				A[i+1]=w[i+1]++;
}

void FindNode(HuffmanTree HT,int n,int &t1,int &t2)
{
	HT[0].weight=100;//输入权值一般不能超过次数
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
	ofstream outfile("output_tree_info.txt");//写入output_tree_info文件
    outfile<<"编号  权重  父结点  左孩子  右孩子"<<endl;
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
    ofstream outfile("output_code_info.txt");//写入output_code_info文件
	outfile<<"编码表:"<<"\t"<<"编码频度"<<endl;
    for(i=1;i<=n;i++)
    outfile<<b[i-1]<<":"<<HC[i]<<"\t"<<A[i]+1<<endl; 
}

//赫夫曼二叉树编码 
//其中w存放n个字符的权值(均>0)，构造赫夫曼树HT，并求出n个字符的赫夫曼编码HC
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int*w,int n)
{
    int m,i,t1,t2,start; 
    unsigned c,f; 
    HuffmanTree p; 
    char *cd; 
    m=2*n-1;
    HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode)); 
    for(p=HT+1,i=1;i<=n;++i,++p)//前n个结点初始化 
	{
        p->weight=w[i];
        p->parent=0; 
        p->lchild=0; 
        p->rchild=0; 
	} 
    for(;i<=m;++i,++p)//对从第n+1个顶点到第2n-1个顶点初始化 
	{
        p->weight=0; 
        p->parent=0; 
        p->lchild=0; 
        p->rchild=0;
	}
    for(i=n+1;i<=m;++i)//构建赫夫曼树
	{
        FindNode(HT,i-1,t1,t2);
        HT[t1].parent=i;
        HT[t2].parent=i; 
        HT[i].lchild=t1; 
        HT[i].rchild=t2; 
        HT[i].weight=HT[t1].weight+HT[t2].weight; 
	} 

	output_tree_info(HT,m);
    printf("\nHuffman二叉树的结构:\n");
    printf("编号  权重  父结点  左孩子  右孩子\n");
    for(i=1;i<=m;i++)
	{
		printf("%d\t",i);
        printf("%d\t",HT[i].weight);
        printf("%d\t",HT[i].parent);
		printf("%d\t",HT[i].lchild);
		printf("%d\n",HT[i].rchild);
	}

	//--- 从叶子结点到根结点逆向求每个字符的赫夫曼编码 ---
	HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
    cd=(char*)malloc(n*sizeof(char));//分配求编码的工作空间
    cd[n-1]='\0';//编码结束符
    for(i=1;i<=n;i++)//逐个字符求赫夫曼编码
	{
        start=n-1;//编码结束符位置
        for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)//从叶子到根逆向求编码
            if(HT[f].lchild==c)  cd[--start]='0'; 
		    else  cd[--start]='1'; 
        HC[i]=(char*)malloc((n-start)*sizeof(char));//为第i个字符编码分配空间
        strcpy(HC[i],&cd[start]);//从cd复制编码串到HC
	} 
    free(cd);//释放工作空间
}

void Output_HuffmanCoding(char a[],char b[],int m,int n,HuffmanCode HC)//输出huffman编码
{
	int i,j;
    printf("字符串转换成的Huffman编码如下:\n");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(a[i]==b[j])
			cout<<HC[j+1]<<"\t";
			cout<<endl;
}

void HuffmanDecoding(int n,char b[],HuffmanTree HT)//对编码的二进制串进行解码
{
	int m=2*n-1;
	int i=m;
	char c;
	printf("\n请输入一串编码:\n");
	cin>>c;
	printf("\n所得译码为:\n");
	while((c=='0')||(c=='1'))//判断是否是合法字符
	{ 
		if(c=='0')   i=HT[i].lchild;//继续向左查找
		else  i=HT[i].rchild;//继续向右查找
		if(HT[i].lchild==0)//直到分支的末端
		{
			printf("%c",b[i-1]);//输出对应的符号
			i=m;//重新开始查找下一个
		}
		cin>>c;
	}
	printf("\n");
}

void main()
{
    HuffmanTree HTree; 
    HuffmanCode HCode; 
    char a[100],b[100];//a为输入的字符串
    int i=0,j=0,len=0,n=0,*w;
    printf("请任意输入一组字符:\n");
	gets(a);
	len = strlen(a);//len为长度
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
    printf("\nHuffman各个字符的详细编码如下:\n");
    printf("编码表:\t编码频度:\n");
    for(i=1;i<=n;i++)		
		cout<<b[i-1]<<":"<<HCode[i]<<"\t"<<A[i]+1<<endl;


    Output_HuffmanCoding(a,b,len,n,HCode);//输出huffman编码
    HuffmanDecoding(n,b,HTree);//对编码的二进制串进行解码
}

