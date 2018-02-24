#include<stdio.h>
#define MAXSIZE 10
typedef int keyType;
typedef struct
{
	keyType key;/*�ؼ�����*/
	/*������*/
}RecordType; /*��¼����*/
void DisPlay(RecordType R[],int n);
void InsertSort(RecordType r[],int n)
/*�Ա�r�еĵ�1����n����¼����ֱ�Ӳ�������r[0]Ϊ������*/
{
	int i,j;
	for(i=2;i<=n;i++)
	{
        r[0]=r[i];                  /*���ü�����*/
		j=i-1;
		while(r[0].key<r[j].key)
		{
              r[j+1]=r[j];j--;    /*��¼����*/
		}
		r[j+1]=r[0];  /*�Ѵ����r[0]�е�ԭ��¼������ȷλ��*/
	}
}
void ShellSort(RecordType r[],int n)
/*�Ա�r�еĵ�1����n����¼����ϣ������r[0]Ϊ������*/
{
	int i,j,d;
	for(d=n/2;d>0;d=d/2) /*��ʼ����Ϊn/2��ÿ����С����ֵΪd/2*/
{
		for(i=d+1;i<=n;i++){
			r[0]=r[i];
			j=i-d;            /* ǰ���¼λ�õ�������dk,������1*/
/*��L.r[i]�������������ӱ�*/
while(j>=0&&r[0].key<r[j].key) /*��r[i]���������ӱ�*/
{		    r[j+d]=r[j];j=j-d; }/*��¼����,���Ҳ���λ�� */ 
			r[j+d]=r[0];     /*����*/
		}
	}
}

void Bubble_sort(RecordType r[],int n)
/*�Ա�r�еĵ�1����n����¼����ϣ������r[0]Ϊ��ʱ�����ռ�*/
{
	int i,j;
	int isExcheng;       /*������־*/
	for(i=1;i<n;i++)
{
		isExcheng=0;    /* isExcheng=0Ϊδ����*/
		for(j=1;j<=n-i;j++)
{
			if(r[j].key>r[j+1].key)
{    /*��ǰ�ߴ��ں󣬽���*/
			     r[0]=r[j+1];r[j+1]=r[j];r[j]=r[0];
			     isExcheng=1; /*isExcheng=1Ϊ��������*/
			}
		}
		if(isExcheng==0)break; /*δ�������������*/
	}
}
int Partition(RecordType r[],int low,int high)
/*�Ա�r�еĵ�low����high����¼����һ�ο�������Ļ��֣��ѹؼ���С��r[low].key�ļ�¼����r[low]ǰ�棬����r[low].key�ļ�¼����r[low]����*/
{  
	r[0]= r[low]; /* ��r[low]����r[0]*/
     while (low<high) /*��r[low]����һ�˻���*/
{ 
   /*��high��,Ѱ��һ����r[low].keyС�ļ�¼����low*/
        while (low<high &&r[high].key>=r[0].key) --high;
        r[low]=r[high]; 
        /*��low��,Ѱ��һ����r[low].key��ļ�¼����high*/
        while (low<high &&r[low].key<=r[0].key) ++low;
        r[high]=r[low]; 
      }
  r[low]=r[0];
  return low;      //���ػ��ֺ�Ļ�׼��¼��λ��
}
void  Quicksort(RecordType r[],int low,int high)
/*�Ա�r�еĵ�low����high����¼���п�������*/
{
    int loc;
	if  (low<high)
{  
/*�Ե�low����high����¼����һ�ο�������Ļ���*/       
loc=Partition(r,low,high); 
       Quicksort(r,low,loc-1);  /*��ǰ���������һ�λ���*/
       Quicksort(r,loc+1,high); /*�Ժ���������һ�λ���*/
     }	
}
void  Selectsort(RecordType r[],int n)
/*�Ա�r�еĵ�1����n����¼���м�ѡ������r[0]Ϊ��ʱ�����ռ�*/
{  
	int i,j,min;
	for(i=1;i<n;i++) 
	{ 
		min=i;
        /*��i...n ��Χ��Ѱ��һ����СԪ�ط���r[i]��*/
		for (j=i+1;j<=n;++j)
		     if (r[min].key>r[j].key) min=j;
        if(min!=i) 
{
		    r[0]=r[min]; r[min]=r[i]; r[i]=r[0];
	    }
	}
}
void Creatheap(RecordType r[],int m,int n)
/*�Ա�r�еĽ����Ϊm��n��Ԫ�ؽ��н��ѣ�r[0]Ϊ��ʱ�����ռ�*/
{
	int i,j,flag;
	i=m;	j=2*i; /*jΪi������*/ 
	r[0]=r[i];flag=0; 
	while(j<=n&&flag!=1) /*��ֵ��С�ķ�֧����ɸѡ*/
{ 
		if (j<n&&r[j].key>r[j+1].key)j++;/*ѡȡ������ֵ��С�ķ�֧*/
		if(r[0].key<r[j].key)flag=1; 
		else { 
		     r[i]=r[j]; i=j; j=2*i;        /*��������ɸѡ*/
		     r[i]=r[0];			
		} 
	} 
}
void Heapsort(RecordType x[],int n)
/*/*�Ա�r�еĵ�1����n����¼���ж�����r[0]Ϊ��ʱ�����ռ�*/
{
	int i; 
	for (i=n/2;i>=1;i--)Creatheap(x,i,n);   /*��ʼ����*/ 
	printf("Output x[]:"); 
/*����Ѷ�Ԫ�أ��������һ��Ԫ�طŵ��Ѷ�λ�ã����½���*/
	for (i=n;i>=1;i--)
{
		printf("%4d",x[1]);    /*����Ѷ�Ԫ��*/
		x[1]=x[i];               /*����βԪ�������Ѷ�*/
		Creatheap(x,1,i);      /*�����*/
	} 
	printf("\n"); 
}
void  Merge (RecordType a[],RecordType b[],int i,int m, int n)
//�������a[i..m]�Լ�a[m+1..n]����鲢��b[i..m]��
{   int la,lb,lc;
    la=i;lb=m+1;lc=i;                                      //���� la,lb,lc ��ʼ��
    while(la<=m &&lb<=n)
    { if (a[la].key<a[lb].key)
         b[lc++].key=a[la++].key ;                        //����ϲ�
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
//������� a[s..t]����鲢���� b[s..t]��
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
		printf("\t\t******����ǰ������**************************\n");
        printf("\t\t*  ");DisPlay(R,MAXSIZE);
	    printf("          *\n\n");
	
		printf("\t\t******��ѡ�������㷨************************\n");
		printf("\t\t*  1.ֱ�Ӳ�������.....................(1)  *\n");
		printf("\t\t*  2.ϣ������.........................(2)  *\n");
		printf("\t\t*  3.ð������.........................(3)  *\n");
	    printf("\t\t*  4.��������.........................(4)  *\n");
		printf("\t\t*  5.��ѡ������.....................(5)  *\n");
	    printf("\t\t*  6.������...........................(6)  *\n");
		printf("\t\t*  7.��·�鲢����.....................(7)  *\n");
		printf("\t\t*  8.�˳�.............................(8) *\n");
		printf("\t\t********************************************\n");
		printf("\n��ѡ��������룺");
        scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				InsertSort(R,MAXSIZE);
				printf("���������У�");
				DisPlay(R,MAXSIZE);
				printf("\n");
				system("pause");
				break;	
			case 2:
			    ShellSort(R,MAXSIZE);
				printf("���������У�");
				DisPlay(R,MAXSIZE);
				printf("\n");
				system("pause");
				break;
			case 3:
			    Bubble_sort(R,MAXSIZE);
				printf("���������У�");
				DisPlay(R,MAXSIZE);
				printf("\n");
				system("pause");
				break;
            case 4:
			    Quicksort(R,1,MAXSIZE);
				printf("���������У�");
				DisPlay(R,MAXSIZE);
				printf("\n");
				system("pause");
				break;
			case 5:
				Selectsort(R,MAXSIZE);
				printf("���������У�");
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
				printf("���������У�");
				DisPlay(R,MAXSIZE);
				printf("\n");
				system("pause");
				break;
			case 8:
				getchar();
				printf("\n���Ƿ����Ҫ�˳�����(Y/N):");
				exit=getchar();getchar();
				break;
			default:
				printf("\n��Ч���룬������ѡ��...:");				

		}
		
	}while(exit!='y'&&exit!='Y');

}
