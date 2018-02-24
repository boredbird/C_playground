// file.h文件的内容如下：
    #include <stdio.h>
#include <stdlib.h>
#include "list.h"        //要包含链表操作的头文件，因为从文件读出的每条记录要依
//学号顺序添加到单链表中，单链表的结点值最终保存到文件中
void createFile( )       //建立初始的数据文件
{
		Type data;
   	    FILE *fp;
   	    if((fp=fopen("d:\\student.dat", "wb")) == NULL) //指定好文件名，以写入方式打开
		{
			printf("can not open file student.dat!\n");  //若打开失败，输出提示信息，退出
			exit(0);                             
    	}
		printf("input students\' information,ended with num=0\n");
		readNode(&data);                         //调用prepare.h中的readNode读数据
		while (!endWith(data))                     //当读入的学号不为0时循环继续
		{
			fwrite(&data,sizeStu,1,fp);              //将刚才读入的一条记录写入文件
 	   		readNode(&data);                     //继续读取下一个元素的数据
		}
		fclose(fp);                               //关闭文件
}

struct node * readFile(struct node *head)           //将文件中的内容读出置于单链表中
{
   		Type data;
   		FILE *fp;
		head=NULL;
    	if((fp=fopen("d:\\student.dat", "rb")) == NULL)  //以读的方式打开指定文件
		{
			printf("file does not exist,you should create a file:\n");            //如果打开失败输出提示信息，返回0
			return 0;
		}	 
    	fread(&data,sizeStu,1,fp);                   //读出第一条记录
   		while(!feof(fp))                           //文件未结束时循环
		{
       		head=InsertOrder(head, data,1);          //从文件中读出后按学号序插入链表
	    	fread(&data,sizeStu,1,fp);               //再读出下一条记录
   		}
		fclose(fp);                                //关闭文件
		return head;                               //返回单链表的头指针
}

void saveFile(struct node *head)                 //将链表中各结点的值依次写入文件
{
   		struct node *p=head;	
  		FILE *fp;	
   		if((fp=fopen("d:\\student.dat", "wb")) == NULL) //以写的方式打开指定文件

		{
			printf("can not open file !\n");          //如果打开失败，输出提示信息，退出
			exit(0);
		}
		if(head == NULL)                       //如果头指针为空输出提示信息，退出
		{
    	   printf("\nNo Records\n");
      	   return ;
    	}   
   		while(p)                               //p从head开始，如果链表未结束
		{     
       		fwrite(&p->data,sizeStu,1,fp);         //则将p所指的结点数据值写入文件中
	  		p=p->next;	                      //p指针后移，准备处理下一个结点
    	}    
		fclose(fp);                              //关闭文件
}
