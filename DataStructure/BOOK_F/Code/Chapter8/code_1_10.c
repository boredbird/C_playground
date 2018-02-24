#include<stdio.h>
#define MAXSIZE 10
typedef int keyType;
typedef struct
{
	keyType key;/*关键字域*/
	/*其它域*/
}RecordType; /*记录类型*/
void DisPlay(RecordType R[],int n);
void InsertSort(RecordType r[],int n)
/*对表r中的第1到第n个记录进行直接插入排序，r[0]为监视哨*/
{
	int i,j;
	for(i=2;i<=n;i++)
	{
        r[0]=r[i];                  /*设置监视哨*/
		j=i-1;
		while(r[0].key<r[j].key)
		{
              r[j+1]=r[j];j--;    /*记录后移*/
		}
		r[j+1]=r[0];  /*把存放在r[0]中的原记录插入正确位置*/
	}
}
void ShellSort(RecordType r[],int n)
/*对表r中的第1到第n个记录进行希尔排序，r[0]为监视哨*/
{
	int i,j,d;
	for(d=n/2;d>0;d=d/2) /*初始增量为n/2，每次缩小增量值为d/2*/
{
		for(i=d+1;i<=n;i++){
			r[0]=r[i];
			j=i-d;            /* 前后记录位置的增量是dk,而不是1*/
/*将L.r[i]插入有序增量子表*/
while(j>=0&&r[0].key<r[j].key) /*将r[i]插入有序子表*/
{		    r[j+d]=r[j];j=j-d; }/*记录后移,查找插入位置 */ 
			r[j+d]=r[0];     /*插入*/
		}
	}
}

void Bubble_sort(RecordType r[],int n)
/*对表r中的第1到第n个记录进行希尔排序，r[0]为临时交换空间*/
{
	int i,j;
	int isExcheng;       /*交换标志*/
	for(i=1;i<n;i++)
{
		isExcheng=0;    /* isExcheng=0为未交换*/
		for(j=1;j<=n-i;j++)
{
			if(r[j].key>r[j+1].key)
{    /*如前者大于后，交换*/
			     r[0]=r[j+1];r[j+1]=r[j];r[j]=r[0];
			     isExcheng=1; /*isExcheng=1为发生交换*/
			}
		}
		if(isExcheng==0)break; /*未交换，排序结束*/
	}
}
int Partition(RecordType r[],int low,int high)
/*对表r中的第low到第high个记录进行一次快速排序的划分，把关键字小于r[low].key的记录放在r[low]前面，大于r[low].key的记录放在r[low]后面*/
{  
	r[0]= r[low]; /* 把r[low]放在r[0]*/
     while (low<high) /*用r[low]进行一趟划分*/
{ 
   /*在high端,寻找一个比r[low].key小的记录放入low*/
        while (low<high &&r[high].key>=r[0].key) --high;
        r[low]=r[high]; 
        /*在low端,寻找一个比r[low].key大的记录放入high*/
        while (low<high &&r[low].key<=r[0].key) ++low;
        r[high]=r[low]; 
      }
  r[low]=r[0];
  return low;      //返回划分后的基准记录的位置
}
void  Quicksort(RecordType r[],int low,int high)
/*对表r中的第low到第high个记录进行快速排序*/
{
    int loc;
	if  (low<high)
{  
/*对第low到第high个记录进行一次快速排序的划分*/       
loc=Partition(r,low,high); 
       Quicksort(r,low,loc-1);  /*对前半区域进行一次划分*/
       Quicksort(r,loc+1,high); /*对后半区域进行一次划分*/
     }	
}
void  Selectsort(RecordType r[],int n)
/*对表r中的第1到第n个记录进行简单选择排序，r[0]为临时交换空间*/
{  
	int i,j,min;
	for(i=1;i<n;i++) 
	{ 
		min=i;
        /*在i...n 范围内寻找一个最小元素放入r[i]中*/
		for (j=i+1;j<=n;++j)
		     if (r[min].key>r[j].key) min=j;
        if(min!=i) 
{
		    r[0]=r[min]; r[min]=r[i]; r[i]=r[0];
	    }
	}
}
void Creatheap(RecordType r[],int m,int n)
/*对表r中的结点编号为m到n的元素进行建堆，r[0]为临时交换空间*/
{
	int i,j,flag;
	i=m;	j=2*i; /*j为i的左孩子*/ 
	r[0]=r[i];flag=0; 
	while(j<=n&&flag!=1) /*沿值较小的分支向下筛选*/
{ 
		if (j<n&&r[j].key>r[j+1].key)j++;/*选取孩子中值较小的分支*/
		if(r[0].key<r[j].key)flag=1; 
		else { 
		     r[i]=r[j]; i=j; j=2*i;        /*继续向下筛选*/
		     r[i]=r[0];			
		} 
	} 
}
void Heapsort(RecordType x[],int n)
/*/*对表r中的第1到第n个记录进行堆排序，r[0]为临时交换空间*/
{
	int i; 
	for (i=n/2;i>=1;i--)Creatheap(x,i,n);   /*初始化堆*/ 
	printf("Output x[]:"); 
/*输出堆顶元素，并将最后一个元素放到堆顶位置，重新建堆*/
	for (i=n;i>=1;i--)
{
		printf("%4d",x[1]);    /*输出堆顶元素*/
		x[1]=x[i];               /*将堆尾元素移至堆顶*/
		Creatheap(x,1,i);      /*整理堆*/
	} 
	printf("\n"); 
}
void  Merge (RecordType a[],RecordType b[],int i,int m, int n)
//将有序表a[i..m]以及a[m+1..n]有序归并到b[i..m]中
{   int la,lb,lc;
    la=i;lb=m+1;lc=i;                                      //序列 la,lb,lc 的始点
    while(la<=m &&lb<=n)
    { if (a[la].key<a[lb].key)
         b[lc++].key=a[la++].key ;                        //有序合并
       else b[lc++].key=a[lb++].key;
     }
     while(la<=m)
	 {
		 b[lc++].key=a[la++].key;
	 }
     
	 while(lb<=n)
	 {
		 b[lc++].key=a[lb++].key;
	 }
	 
}
void  Mergesort (RecordType a[],RecordType b[],int s,int t)
//将有序表 a[s..t]有序归并排序到 b[s..t]中
{  
	int m;
	RecordType c[MAXSIZE+1];
	if (s==t) b[s].key=a[s].key;
    else {    m=(s+t)/2;
              Mergesort( a,c,s,m);
			  //show(b,N);getchar();
              Mergesort( a,c,m+1,t);
			   //show(b,N);getchar();
              Merge(c,b,s,m,t);
           }
}

void DisPlay(RecordType R[],int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%3d",R[i]);
	}
}
void main()
{
	int ch;
	char exit='N';
	RecordType R[MAXSIZE+1]={0,34, 44, 43, 12, 53, 55,73, 64, 77,13};
	
	do
	{
	    system("CLS");
		printf("\t\t******排序前的序列**************************\n");
        printf("\t\t*  ");DisPlay(R,MAXSIZE);
	    printf("          *\n\n");
	
		printf("\t\t******请选择排序算法************************\n");
		printf("\t\t*  1.直接插入排序.....................(1)  *\n");
		printf("\t\t*  2.希尔排序.........................(2)  *\n");
		printf("\t\t*  3.冒泡排序.........................(3)  *\n");
	    printf("\t\t*  4.快速排序.........................(4)  *\n");
		printf("\t\t*  5.简单选择排序.....................(5)  *\n");
	    printf("\t\t*  6.堆排序...........................(6)  *\n");
		printf("\t\t*  7.二路归并排序.....................(7)  *\n");
		printf("\t\t*  8.退出.............................(8) *\n");
		printf("\t\t********************************************\n");
		printf("\n请选择操作代码：");
        scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				InsertSort(R,MAXSIZE);
				printf("排序后的序列：");
				DisPlay(R,MAXSIZE);
				printf("\n");
				system("pause");
				break;	
			case 2:
			    ShellSort(R,MAXSIZE);
				printf("排序后的序列：");
				DisPlay(R,MAXSIZE);
				printf("\n");
				system("pause");
				break;
			case 3:
			    Bubble_sort(R,MAXSIZE);
				printf("排序后的序列：");
				DisPlay(R,MAXSIZE);
				printf("\n");
				system("pause");
				break;
            case 4:
			    Quicksort(R,1,MAXSIZE);
				printf("排序后的序列：");
				DisPlay(R,MAXSIZE);
				printf("\n");
				system("pause");
				break;
			case 5:
				Selectsort(R,MAXSIZE);
				printf("排序后的序列：");
				DisPlay(R,MAXSIZE);
				printf("\n");
				system("pause");
				break;
			case 6:
				Heapsort(R,MAXSIZE);
				
				system("pause");
				break;
			case 7:
				Mergesort(R,R,1,MAXSIZE);
				printf("排序后的序列：");
				DisPlay(R,MAXSIZE);
				printf("\n");
				system("pause");
				break;
			case 8:
				getchar();
				printf("\n您是否真的要退出程序(Y/N):");
				exit=getchar();getchar();
				break;
			default:
				printf("\n无效输入，请重新选择...:");				

		}
		
	}while(exit!='y'&&exit!='Y');

}
