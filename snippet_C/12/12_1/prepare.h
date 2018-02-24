#include "node.h"                 //文件包含，因为本文件中的函数是针对Type类型
                                //的数据定义的一些基本操作
void printNode(Type data)           //输出结点的数据域，对于整型这样输出，其他
{                               //类型的数据域，可以重新定义函数体的内容
   printf("%8d", data); 
}
void readNode(Type *pdata)         //读入结点的数据域，对于整型这样输入，其他
{                               //类型的数据域，可以重新定义函数体的内容
	scanf("%d", pdata);	            //定制符合数据域类型的输入方法
}
int endWith(Type data)              //此函数是为了控制建立链表时的结束条件
{                               //这里实际上表示读入值为0时结束，其他类型
	return data==0;                //的数据成员输入如何结束，需要重新定义
}
int equal(Type data1,Type data2,int condition)//根据condition判断两个Type类型的变量是
{                               //否相等，对于不同数据类型，需要自己重新定义
	if (condition==1)
	   return data1==data2;
	return 1;
}
int larger(Type data1,Type data2,int condition) //根据condition判断两个Type类型的变量
{                                     //的大小，当Type代表的类型不同时，该函
	if (condition==1)                    //数需要重新定义
		return data1>data2;
	return 1;
}
