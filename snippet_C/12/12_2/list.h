#ifndef _LIST
#define _LIST
#include "prepare.h"               //文件包含，本文件是对结点数据域为Type类型的
                                //单链表进行的处理
struct node * CreateBackward();      //后插法新建链表为 12.1.2节方法①对应的函数
struct node * CreateFarward();       //前插法新建链表为 12.1.2节方法②对应的函数
struct node * CreateInsert();         //按序插入法新建链表对应的于 12.1.2节方法③
struct node * printList(struct node * head); //链表的遍历，对应于12.1.3节
struct node * SearchNode(struct node * head,Type data,int condition);//单链表的查找，对应于12.1.4节struct node * InsertAfter(struct node * head, Type data); //尾部插入对应于12.1.5节方法①
struct node * InsertOrder(struct node * head, Type data,int condition); 
struct node * InsertAfter(struct node * head, Type data); 
//有序插入对应于12.1.5节方法②
struct node * Delete(struct node * head, Type data);   //删除结点，对应于12.1.6节
struct node * Reverse(struct node * head);           //单链表的逆置，对应于12.1.7节

struct node * printList(struct node * head) //链表的遍历，对应于12.1.3节
{ 
	struct node * p;
    if(head == NULL)            //如果链表原来为空
    {
       printf("\nNo Records\n");    //输出提示信息，返回
       return NULL;
    } 
   for(p = head; p; p = p->next)     //p从头指针开始，每循环一次向后移动1结点位置，
        printNode(p->data);       //p非空时执行循环体，调用printNode函数输出
	printf("\n");                  //结点的元素值，最后换行
	return head;                  //返回头指针
}

struct node * CreateBackward( )      //后插法新建链表为 12.1.2节方法①对应的函数
{ 
    struct node * head,*p,*tail;      //tail用来定位于当前链表中最后一个结点位置
    Type data;                    
    head=NULL;tail=NULL;       //链表未建立时对头指针和尾指针进行清零处理
    printf("Input data end with 0:\n");
    readNode(&data);             //调用readNode输入一个结点的数据域的值
    while(!endWith(data))          // endWith(data)函数值为真时结束链表结点的生成
	{
       p=(struct node *)malloc(size); //利用指针p申请新结点的动态空间
    	   p->data = data;             //数据域赋值
           p->next=NULL;	        //新结点的指针域赋值
           if (head==NULL)           //初始链为空时，要修改头指针
		       head=p;
	       else                      //链非空时，将p置于tail所指结点之后
	           tail->next=p;       
	       tail=p;                    //使tail指向新的链尾，便于下次插入
	  readNode(&data);	        //继续读入下一个结点的数据域的值
   }
   return head;                    //返回头指针
}

struct node * CreateFarward( )       //前插法新建链表为 12.1.2节方法②对应的函数
{ 
    struct node * head,*p;
    Type data;    
    head=NULL;                 //链表未建立时对头指针进行清零处理
    printf("Input data end with 0:\n");
    readNode(&data);             //调用readNode输入一个结点的数据域的值
    while(!endWith(data))          // endWith(data)函数值为真时结束链表结点的生成
	{
      p = (struct node *) malloc(size); //利用指针p申请新结点的动态空间
      p->data =data;               //数据域赋值
      p->next=head;	            //新结点的指针域赋值为head
      head=p;	                //修改头指针
	  readNode(&data);           //继续读入下一个结点的数据域的值
   }
   return head;                   //返回头指针
}

struct node * SearchNode(struct node * head,Type data,int condition) //单链表的查找，对应于12.1.4节
{ 
    struct node *p=head;          //p从head开始
	if(head == NULL)            //如果链表原来就为空
	{
       printf("\nNo Records\n");   //输出提示信息
       return 0;                 //返回空指针
    }
    while(p&&!equal(p->data,data,condition)) //这里的equql函数用来判两个参数是否相等
	    {                          //当p非空且当前结点的数据值不等于要搜索的
           p=p->next;	               //值data时，指针p顺着链向后移动一个位置
        }
    if(p) return p;                //循环停止时p非空，表示找到了结点，返回指针p
	return 0;                    //此时隐含条件为p等于空，未找到，返回空指针
 }

struct node * InsertAfter(struct node * head, Type data) //尾部插入对应于12.1.5节方法①
{
	struct node *p ,*p1;   
    p=(struct node *) malloc(size);   //利用指针p申请结点动态空间
p->data=data;                 //数据域赋值
p->next=NULL;               //指针域直接赋值为空，因为它是新链最后的结点
 if(head == NULL)             //如果链表原来为空
{ 
        head = p;                 //修改头指针
        return head;               //返回头指针
}
p1=head; 			        //链表原来非空，则指针p1从头指针开始
while( p1->next)              //如果指针还没有指向最后一个结点
{
        p1=p1->next;            //p1顺着链向后移动
}                          //循环停止时，p1指向了链表的最后一个结点处
p1->next=p;                 //将新结点连在p1之后
   	return head;                 //返回头指针
}
                             //有序插入对应于12.1.5节方法②
struct node * InsertOrder(struct node * head, Type data,int condition)  
{  
    struct node *p ,*p1, *p2;
    p2=head; 
    	p=(struct node *) malloc(size);  //利用指针p申请结点动态空间
		p->data=data;                //数据域赋值
		p->next=NULL;              //指针域直接赋值为空，以后根据插入位置再修改
    	if(head == NULL)             //原链表为空时的插入
		{ 
        	head = p; 		       //新插入结点成为头结点
        	return head;
    	}
     			                   //原链表不为空时的插入，larger是一个通用函数，
        while( p2 && larger(p->data,p2->data,condition))  //第一参数大于第二参数，返回真
	    {
          p1=p2; 	               //p1是p2的前趋结点，二者同时后移
          p2=p2->next;
        }
       if(head==p2)                 //如果在最前面插入则要修改head指针
		  head = p;   
       else                         //否则p插在p1的后面
		  p1->next=p;
       p->next=p2;                   //p2作为p的后继结点，即p插在p1和p2之间
   return head;                   //返回头指针
}

struct node * CreateInsert( )         //按序插入法新建链表对应的于 12.1.2节方法③
{
	struct node * head;
    Type data;
    
    head=NULL;
    printf("Input data end with 0:\n");
    readNode(&data);             //调用readNode输入一个结点的数据域的值
    while(!endWith(data))          // endWith(data)函数值为真时结束链表结点的生成         
	{
       head=InsertOrder(head,data,1);//直接调用InsertOrder函数插入新结点
	   readNode(&data);          //继续读入下一个结点的数据域的值
   }
   return head;                   //返回头指针
}

struct node * Delete(struct node * head, Type data)   //删除结点，对应于12.1.6节
{
    struct node *p=head,*q=NULL;      
		if(head == NULL)            //如果原来是空链，则给提示信息并返回
		{
      	 printf("\nNo Records\n");
      	 return head;
   		 }   
    	while(p&&!equal(p->data,data,1)) //如果链表非空，则从第一个结点开始比较，这里
		{                          //equal是针对数据域类型定义的判相等函数
        	q=p;                   //如果没有找到要删除的结点，则q和p同时向后移
			p=p->next;	           //动一个结点位置，q始终是p的前趋
   		}
   		if(p)                       //如果找到需要删除的结点p
		{
			if (q)                   //如果删除的不是第一个结点
				q->next=p->next;     //修改q的next域，使p的后继成为q的后继
			else                    //如果删除的是第一个结点（q保持初值NULL）
				head=head->next;     //修改head指针
			free(p);                 //释放指针p所指向的结点空间
		}
		else                        //如果没有待删除的结点
	  printf("it is not in the list.\n");  //则输出提示信息
return head;                  //返回头指针
}

struct node * Reverse(struct node * head) //单链表的逆置，对应于12.1.7节
{
	struct node *p=head,*q;        //p是当前要处理的结点指针，从原head开始
		head=NULL;                 // head置为空值
	    while (p)                    //用遍历思想，当链表没处理结束时
	    {
		    q=p->next;               //q记下p的后继结点，便于下次继续处理
		    p->next=head;           //修改p的next域，前趋变后继
		    head=p;                //head指向已逆置完成的新的第一个结点处
		    p=q;                   //p移向原链表的下一个结点处，再行处理
	    }
   	return head;                 //返回头指针
}

#endif   
