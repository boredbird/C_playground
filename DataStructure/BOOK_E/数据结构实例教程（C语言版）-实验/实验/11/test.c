//���ö��ַ�����ʵ��ѧ����Ϣ��ѯģ�����
//55,60,65,66,70,74,78,80,85,90,95
#include "stdio.h"
#include "stdlib.h"
typedef struct 
{
	long id;
	int score;
}stu;
//���ַ����Һ���
long binsearch(stu s[],int n,int k)//kΪҪ���ҵ�ֵ
{
    int low=1,high=n,mid;
	while(low<=high)
	{
        mid=(low+high)/2;
		if(s[mid].score==k) 
			return s[mid].id;
		else if(s[mid].score>k)  
			high=mid-1;
		else
			low=mid+1;
	}
	return 0;
}
main()
{
	stu s[12];//�±��1��ʼ,�洢11����
	int i,score;
	long id;
    printf("�밴�ճɼ�����˳������ѧ�źͷ���:\n");
	for(i=1;i<=11;i++)
		scanf("%ld,%d",&s[i].id,&s[i].score);
    printf("������Ҫ���ҵķ���:");
	scanf("%d",&score);
    id=binsearch(s,11,score);
	if(id==0)
	{
		printf("������!");
	}
	else
     	printf("ѧ��Ϊ:%ld",id);
}