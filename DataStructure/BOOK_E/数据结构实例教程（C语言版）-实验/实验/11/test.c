//利用二分法查找实现学生信息查询模块设计
//55,60,65,66,70,74,78,80,85,90,95
#include "stdio.h"
#include "stdlib.h"
typedef struct 
{
	long id;
	int score;
}stu;
//二分法查找函数
long binsearch(stu s[],int n,int k)//k为要查找的值
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
	stu s[12];//下标从1开始,存储11个数
	int i,score;
	long id;
    printf("请按照成绩递增顺序输入学号和分数:\n");
	for(i=1;i<=11;i++)
		scanf("%ld,%d",&s[i].id,&s[i].score);
    printf("请输入要查找的分数:");
	scanf("%d",&score);
    id=binsearch(s,11,score);
	if(id==0)
	{
		printf("不存在!");
	}
	else
     	printf("学号为:%ld",id);
}