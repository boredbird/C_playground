//ѧ���ܳɼ�����ģ�����
#include "stdio.h"
typedef struct 
{
	long id;//ѧ��
	int math;//��ѧ�ɼ�
	int cprogram;//C���Գɼ�
	int english;//Ӣ��ɼ�
	int totalscore;//�ܳɼ�
}stu;
//ð��������
void bubblesort(stu s[],int n)
{
	int i,j;
	stu temp;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1;j++)
		{
			if(s[j].totalscore<s[j+1].totalscore)
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
}
//���ֺ���,���ػ�׼��¼��λ��
int partition(stu s[],int i,int j)
{
	stu pivot=s[i];//ѡ���һ������Ϊ��׼��
	while(i<j)
	{
		while(i<j&&s[j].totalscore>=pivot.totalscore)//��������ɨ�裬�ҵ���һ��С��pivot.totalscore�ļ�¼
			j--;
		if(i<j)
			s[i++]=s[j];//�൱��s[i]��s[j]����
        while(i<j&&s[i].totalscore<=pivot.totalscore)//��������ɨ�裬�ҵ���һ������pivot.totalscore�ļ�¼
			i++;
		if(i<j)
            s[j--]=s[i];
	}
	s[i]=pivot;//��׼�����λ
	return i;
}
//����������
void quicksort(stu s[],int low,int high)
{
   int pivotpos;//���ֺ�Ļ�׼��¼��λ��
   if(low<high)
   {
	   pivotpos=partition(s,low,high);//������
	   quicksort(s,low,pivotpos-1);
	   quicksort(s,pivotpos+1,high);
   }
}
main()
{
	stu s[5];
	int i;
	printf("������ѧ�š���ѧ�ɼ���C���Գɼ���Ӣ��ɼ�:\n");
	for(i=0;i<5;i++)
	{
		scanf("%ld,%d,%d,%d",&s[i].id,&s[i].math,&s[i].cprogram,&s[i].english);
		s[i].totalscore=s[i].math+s[i].cprogram+s[i].english;
	}
    bubblesort(s,5);//����ð��������
	printf("ð�������Ľ��:\n");
    for(i=0;i<5;i++)
	{
		printf("%ld,%d,%d,%d,%d\n",s[i].id,s[i].math,s[i].cprogram,s[i].english,s[i].totalscore);
	}
	quicksort(s,0,4);//���ÿ���������
	printf("���������Ľ��:\n");
    for(i=4;i>=0;i--)
	{
		printf("%ld,%d,%d,%d,%d\n",s[i].id,s[i].math,s[i].cprogram,s[i].english,s[i].totalscore);
	}
	
}