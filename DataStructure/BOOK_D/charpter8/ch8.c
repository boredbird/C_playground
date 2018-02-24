#include<stdio.h>
#define MAXSIZE 3
typedef int keyType;
/*��дһ������ʵ��ѧ���ɼ�����ÿ��ѧ������3�ſεĳɼ����Ӽ�������ѧ����Ϣ��
2.ѧ����Ϣ����ѧ�š����������ſγɼ��������ѧ����ƽ���ɼ�������ѧ��ƽ���ɼ��ɴ�С����
Ҫ��ֱ����ֱ�Ӳ�������ð�����򡢿������򡢼�ѡ�����򡢶�������·�鲢�����е��������򷽼���ɡ�
*/
typedef struct
{
	int stuNo;
	char name[20];
	float score1;
	float score2;
	float score3;
	float avg;	
}Student; /*��¼����*/
void DisPlay(Student stu[],int n);
void InputStuMsg(Student stu[],int n)
{
	int i;
	
	for(i=1;i<=n;i++)
	{
		printf("�������%d��ѧ������Ϣ:\n",i);
		printf("ѧ�ţ�");scanf("%d",&stu[i].stuNo);
		printf("������");scanf("%s",stu[i].name);
		printf("���ģ�");scanf("%f",&stu[i].score1);
		printf("��ѧ��");scanf("%f",&stu[i].score2);
		printf("���");scanf("%f",&stu[i].score3);
		stu[i].avg=(stu[i].score1+stu[i].score2+stu[i].score3)/3;
		
	}
}
void InsertSort(Student r[],int n)
/*�Ա�r�еĵ�1����n����¼����ֱ�Ӳ�������r[0]Ϊ������*/
{
	int i,j;
	for(i=2;i<=n;i++)
	{
        r[0]=r[i];                  /*���ü�����*/
		j=i-1;
		while(r[0].avg<r[j].avg)
		{
              r[j+1]=r[j];j--;    /*��¼����*/
		}
		r[j+1]=r[0];  /*�Ѵ����r[0]�е�ԭ��¼������ȷλ��*/
	}
}
void ShellSort(Student r[],int n)
/*�Ա�r�еĵ�1����n����¼����ϣ������r[0]Ϊ������*/
{
	int i,j,d;
	for(d=n/2;d>0;d=d/2) /*��ʼ����Ϊn/2��ÿ����С����ֵΪd/2*/
{
		for(i=d+1;i<=n;i++){
			r[0]=r[i];
			j=i-d;            /* ǰ���¼λ�õ�������dk,������1*/
/*��L.r[i]�������������ӱ�*/
while(j>=0&&r[0].avg<r[j].avg) /*��r[i]���������ӱ�*/
{		    r[j+d]=r[j];j=j-d; }/*��¼����,���Ҳ���λ�� */ 
			r[j+d]=r[0];     /*����*/
		}
	}
}

void Bubble_sort(Student r[],int n)
/*�Ա�r�еĵ�1����n����¼����ϣ������r[0]Ϊ��ʱ�����ռ�*/
{
	int i,j;
	int isExcheng;       /*������־*/
	for(i=1;i<n;i++)
{
		isExcheng=0;    /* isExcheng=0Ϊδ����*/
		for(j=1;j<=n-i;j++)
{
			if(r[j].avg>r[j+1].avg)
{    /*��ǰ�ߴ��ں󣬽���*/
			     r[0]=r[j+1];r[j+1]=r[j];r[j]=r[0];
			     isExcheng=1; /*isExcheng=1Ϊ��������*/
			}
		}
		if(isExcheng==0)break; /*δ�������������*/
	}
}
int Partition(Student r[],int low,int high)
/*�Ա�r�еĵ�low����high����¼����һ�ο�������Ļ��֣��ѹؼ���С��r[low].avg�ļ�¼����r[low]ǰ�棬����r[low].avg�ļ�¼����r[low]����*/
{  
	r[0]= r[low]; /* ��r[low]����r[0]*/
     while (low<high) /*��r[low]����һ�˻���*/
{ 
   /*��high��,Ѱ��һ����r[low].avgС�ļ�¼����low*/
        while (low<high &&r[high].avg>=r[0].avg) --high;
        r[low]=r[high]; 
        /*��low��,Ѱ��һ����r[low].avg��ļ�¼����high*/
        while (low<high &&r[low].avg<=r[0].avg) ++low;
        r[high]=r[low]; 
      }
  r[low]=r[0];
  return low;      //���ػ��ֺ�Ļ�׼��¼��λ��
}
void  Quicksort(Student r[],int low,int high)
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
void  Selectsort(Student r[],int n)
/*�Ա�r�еĵ�1����n����¼���м�ѡ������r[0]Ϊ��ʱ�����ռ�*/
{  
	int i,j,min;
	for(i=1;i<n;i++) 
	{ 
		min=i;
        /*��i...n ��Χ��Ѱ��һ����СԪ�ط���r[i]��*/
		for (j=i+1;j<=n;++j)
		     if (r[min].avg>r[j].avg) min=j;
        if(min!=i) 
{
		    r[0]=r[min]; r[min]=r[i]; r[i]=r[0];
	    }
	}
}
void Creatheap(Student r[],int m,int n)
/*�Ա�r�еĽ����Ϊm��n��Ԫ�ؽ��н��ѣ�r[0]Ϊ��ʱ�����ռ�*/
{
	int i,j,flag;
	i=m;	j=2*i; /*jΪi������*/ 
	r[0]=r[i];flag=0; 
	while(j<=n&&flag!=1) /*��ֵ��С�ķ�֧����ɸѡ*/
{ 
		if (j<n&&r[j].avg>r[j+1].avg)j++;/*ѡȡ������ֵ��С�ķ�֧*/
		if(r[0].avg<r[j].avg)flag=1; 
		else { 
		     r[i]=r[j]; i=j; j=2*i;        /*��������ɸѡ*/
		     r[i]=r[0];			
		} 
	} 
}
void Heapsort(Student x[],int n)
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
void  Merge (Student a[],Student b[],int i,int m, int n)
//�������a[i..m]�Լ�a[m+1..n]����鲢��b[i..m]��
{   int la,lb,lc;
    la=i;lb=m+1;lc=i;                                      //���� la,lb,lc ��ʼ��
    while(la<=m &&lb<=n)
    { if (a[la].avg<a[lb].avg)
         b[lc++].avg=a[la++].avg ;                        //����ϲ�
       else b[lc++].avg=a[lb++].avg;
     }
     while(la<=m)
	 {
		 b[lc++].avg=a[la++].avg;
	 }
     
	 while(lb<=n)
	 {
		 b[lc++].avg=a[lb++].avg;
	 }
	 
}
void  Mergesort (Student a[],Student b[],int s,int t)
//������� a[s..t]����鲢���� b[s..t]��
{  
	int m;
	Student c[MAXSIZE+1];
	if (s==t) b[s].avg=a[s].avg;
    else {    m=(s+t)/2;
              Mergesort( a,c,s,m);
			  //show(b,N);getchar();
              Mergesort( a,c,m+1,t);
			   //show(b,N);getchar();
              Merge(c,b,s,m,t);
           }
}

void DisPlay(Student stu[],int n)
{
	int i;
	printf("\nѧ��\t����\t����\t��ѧ\t����\tƽ���ɼ�");
	for(i=1;i<=n;i++)
	{
		printf("\n%d\t",stu[i].stuNo);
		printf("%s\t",stu[i].name);
		printf("%.2f\t",stu[i].score1);
		printf("%.2f\t",stu[i].score2);
		printf("%.2f\t",stu[i].score3);
		printf("%.2f\t",stu[i].avg);
	}
}
void main()
{
	int ch;
	char exit='N';
	Student stu[MAXSIZE+1];
	InputStuMsg(stu,MAXSIZE);
	do
	{
	    system("CLS");
		printf("\t\t******����ǰ������**************************\n");
        DisPlay(stu,MAXSIZE);
	    printf("\n\n");
	
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
				InsertSort(stu,MAXSIZE);
				printf("���������У�");
				DisPlay(stu,MAXSIZE);
				printf("\n");
				system("pause");
				break;	
			case 2:
			    ShellSort(stu,MAXSIZE);
				printf("���������У�");
				DisPlay(stu,MAXSIZE);
				printf("\n");
				system("pause");
				break;
			case 3:
			    Bubble_sort(stu,MAXSIZE);
				printf("���������У�");
				DisPlay(stu,MAXSIZE);
				printf("\n");
				system("pause");
				break;
            case 4:
			    Quicksort(stu,1,MAXSIZE);
				printf("���������У�");
				DisPlay(stu,MAXSIZE);
				printf("\n");
				system("pause");
				break;
			case 5:
				Selectsort(stu,MAXSIZE);
				printf("���������У�");
				DisPlay(stu,MAXSIZE);
				printf("\n");
				system("pause");
				break;
			case 6:
				Heapsort(stu,MAXSIZE);
				
				system("pause");
				break;
			case 7:
				Mergesort(stu,stu,1,MAXSIZE);
				printf("���������У�");
				DisPlay(stu,MAXSIZE);
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
