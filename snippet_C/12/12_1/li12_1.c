/*
例12_1 链表的基本操作。
*/


#include<stdio.h>
#include<stdlib.h>
#include"list.h"
void menu( )
{
	printf("********1. 建立新链表,结点在尾部插入 ********\n");
	printf("********2. 建立新链表,结点在头部插入 ********\n");
	printf("********3. 建立新链表,结点非递减插入 ********\n");
	printf("********4. 在链表中插入新结点保证原序********\n");
    printf("********5. 在链表中尾部直接插入新结点********\n");
	printf("********6. 从链表中删除一个结点      ********\n");
	printf("********7. 在链表中寻找一个结点      ********\n");
	printf("********8. 单链表的逆置              ********\n");
	printf("********9. 单链表的遍历(输出单链表)  ********\n");
	printf("********0. 退出                      ********\n");
	return;
}

struct node *  run(struct node *head,int choice)
{
	Type data;
	switch(choice)
	{
		case 1: head=CreateBackward(); break;
		case 2: head=CreateForward();  break;
		case 3: head=CreateInsert();   break;
		case 4: printf("Input an integer will be inserted:\n");
				readNode(&data);
				head=InsertOrder(head, data,1);
				break;
		case 5: printf("Input an integer will be inserted:\n");
				readNode(&data);
				head=InsertAfter(head, data);
				break;
		case 6: printf("Input an integer will be deleted:\n");
				readNode(&data);
				head=Delete(head, data);
				break;
		case 7: printf("Input an integer will be searched:\n");
				readNode(&data);
				if (SearchNode(head, data,1))
					printf("it is in the list.\n",data);
				else
					printf("it is not in the list\n",data);
				break;
		case 8: head=Reverse(head);
			    break;
        case 9: printf("the list is:\n");
                head=printList(head);
				break;
		case 0: break;
	}
	return head;
}

int main( )
{
	struct node *head=NULL;
    int choice;
	do
	{
	   menu();
	   printf("Please input your choice: ");
	   scanf("%d",&choice);
	   if (choice>=0&&choice<=9)
	      head=run(head,choice);
	}while (choice);
    return 0;
}
