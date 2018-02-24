//学生总成绩排序模块设计
#include "stdio.h"
typedef struct 
{
	long id;//学号
	int math;//数学成绩
	int cprogram;//C语言成绩
	int english;//英语成绩
	int totalscore;//总成绩
}stu;
//冒泡排序函数
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
//划分函数,返回基准记录的位置
int partition(stu s[],int i,int j)
{
	stu pivot=s[i];//选择第一个数作为基准数
	while(i<j)
	{
		while(i<j&&s[j].totalscore>=pivot.totalscore)//从右向左扫描，找到第一个小于pivot.totalscore的记录
			j--;
		if(i<j)
			s[i++]=s[j];//相当于s[i]和s[j]交换
        while(i<j&&s[i].totalscore<=pivot.totalscore)//从左向右扫描，找到第一个大于pivot.totalscore的记录
			i++;
		if(i<j)
            s[j--]=s[i];
	}
	s[i]=pivot;//基准数最后定位
	return i;
}
//快速排序函数
void quicksort(stu s[],int low,int high)
{
   int pivotpos;//划分后的基准记录的位置
   if(low<high)
   {
	   pivotpos=partition(s,low,high);//做划分
	   quicksort(s,low,pivotpos-1);
	   quicksort(s,pivotpos+1,high);
   }
}
main()
{
	stu s[5];
	int i;
	printf("请输入学号、数学成绩、C语言成绩和英语成绩:\n");
	for(i=0;i<5;i++)
	{
		scanf("%ld,%d,%d,%d",&s[i].id,&s[i].math,&s[i].cprogram,&s[i].english);
		s[i].totalscore=s[i].math+s[i].cprogram+s[i].english;
	}
    bubblesort(s,5);//调用冒泡排序函数
	printf("冒泡排序后的结果:\n");
    for(i=0;i<5;i++)
	{
		printf("%ld,%d,%d,%d,%d\n",s[i].id,s[i].math,s[i].cprogram,s[i].english,s[i].totalscore);
	}
	quicksort(s,0,4);//调用快速排序函数
	printf("快速排序后的结果:\n");
    for(i=4;i>=0;i--)
	{
		printf("%ld,%d,%d,%d,%d\n",s[i].id,s[i].math,s[i].cprogram,s[i].english,s[i].totalscore);
	}
	
}