//12.2中的prepare.h
#ifndef _PREP
#define _PREP
#include "node.h"
#include <string.h>
void printNode(Type data)          //输出结点的所有数据域的值
{
    int i;
	printf("%8ld  ", data.num);
	printf("%8s",data.name);
	printf("%8s",data.sex);
	for (i=0;i<3;i++)
		printf("%6d",data.score[i]);
	printf("%7d",data.total);
	printf("%5d\n",data.rank);
}

void readNode(Type *pdata)        //根据提示读入结点的相关数据域的值
{
		int i;
		printf("Input one student\'s information\n");
		printf("num:  ");
		scanf("%ld", &pdata->num);
		printf("name: ");
		scanf("%s",pdata->name);	
		printf("sex:  ");
		scanf("%s",pdata->sex);
    	pdata->total=0;               //总分需要计算求得，初值置为0
		printf("Input three courses of the student:\n");
		for (i=0;i<3;i++)
		{
			scanf("%d",&pdata->score[i]);	   
		}
		pdata->rank=0;               //名次需要根据总分来计算，初值置为0

}

int endWith(Type data)                 //输入结点数据时以学号域为0作为结束条件
{
		return data.num==0;
}

int equal(Type data1,Type data2,int condition)//如何判断两个Type类型的数据相等
{
		if (condition==1)                   //如果参数condition的值为1，则比较学号
			return data1.num==data2.num;
		else if (condition==2)                //如果参数condition的值为2，则比较姓名
			   if (strcmp(data1.name,data2.name)==0) 
				    return 1;
			  else return 0;
		   else if (condition==3)             //如果参数condition的值为3，则比较名次
				 return data1.rank==data2.rank;
		       else return 1;                //其余情况下返回值为1
} 

int larger(Type data1,Type data2,int condition)//如何根据condition比较Type类型数据大小
{
		if (condition==1)                    //如果参数condition的值为1，则比较学号
			return data1.num>data2.num;
		if (condition==2)                    //如果参数condition的值为2，则比较名次
			return data1.total>data2.total;
		return 1;                           //其余情况下返回值为1
}
#endif
