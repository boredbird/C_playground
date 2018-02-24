#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node/*定义结点的类型*/
{
 char num[11],name[15],address[20];/*num为电话号码，name为用户名，address为地址*/
 struct node *next;/*指向下一个结点的指针*/
}NUM,NAME;

NUM * num_list[19];/*电话号码为存储关键字的散列表中存储链表的头指针的数组,*/
NAME * name_list[19];/*电话号码为存储关键字的散列表中存储链表的头指针的数组*/

int hash1(char num[])/*电话号码为关键字用除余法求散列地址，输入的号码转换为整数进行除余运算*/
{
  int i;
  int k=0;
  for(i=0;num[i]!='\0';i++)
  {
        k=10*k+num[i]-48;
  }

   k=(k%19);
   return k;
}
int hash2(char name[])/*姓名为关键字用除余法求散列地址*/
{
  int i;
  int k=0;
  for(i=0;name[i]!='\0';i++)
  {
        k=10*k+name[i];
  }

   k=(k%19);
   return k;
}

void create()/*创建两个散列表，一个以电话号码为关键字，一个以姓名为关键字*/
{
 char num[11],name[15],address[20];
 struct node *p1;
 struct node *q1;
 int k1,k2;
 printf("please input the information you want :num   name  address,# # #is end\n");
 scanf("%s%s%s",num,name,address);
 while(strcmp(num,"#")!=0)
 {  
    p1=(struct node *)malloc(sizeof(struct node));
	q1=(struct node *)malloc(sizeof(struct node));/*生成两个结点p1和q1，p1插入到号码所在散列表，q1插入到姓名所在散列表*/
    strcpy(p1->num,num);
    strcpy(p1->name,name);
    strcpy(p1->address,address);
	k1=hash1(num);
	p1->next=num_list[k1];
    num_list[k1]=p1;
    strcpy(q1->num,num);
    strcpy(q1->name,name);
    strcpy(q1->address,address);
    k2=hash2(name);
	q1->next=name_list[k2];
    name_list[k2]=q1;
	scanf("%s%s%s",num,name,address);
 }
 

 printf("list is created\n");
}
 void print()/*打印散列表*/
{
  struct node *f;
  int x,i;
  printf("input your select:\n");
  printf("1.output num table.\n");
  printf("2.output name table\n");
  scanf("%d",&x);
  switch(x)
  {
    case 1: for(i=0;i<19;i++)
			{
				printf("%d:",i);
				f=num_list[i];
				while(f!=NULL)
				{
				  printf("--->num:%s name:%s address:%s",f->num,f->name,f->address);
				  f=f->next;
				}
				printf("\n");
            }
		    break;
	case 2:for(i=0;i<19;i++)
			{
				printf("%d:",i);
			    f=name_list[i];
				while(f!=NULL)
				{
				  printf("--->num:%s name:%s address:%s",f->num,f->name,f->address);
				  f=f->next;
				}
				printf("\n");
            }
		    break;
  }
 }

void insert()
{
   char num[11],name[15],address[20];
   struct node *p1;
   struct node *q1;
   int k1,k2;
   printf("please input the newnode information:num   name  address\n");
   scanf("%s%s%s",num,name,address);
   p1=(struct node *)malloc(sizeof(struct node));
   q1=(struct node *)malloc(sizeof(struct node));/*动态生成两个结点p1和q1，p1插入到号码所在散列表，q1插入到姓名所在散列表*/
   strcpy(p1->num,num);
   strcpy(p1->name,name);
   strcpy(p1->address,address);
   k1=hash1(p1->num);
   p1->next=num_list[k1];
   num_list[k1]=p1;
   strcpy(q1->num,p1->num);
   strcpy(q1->name,p1->name);
   strcpy(q1->address,p1->address);
   k2=hash2(q1->name);
   q1->next=name_list[k2];
   name_list[k2]=q1;
   printf("OK\n");	
}

void search()
{
  char num[11],name[15];
  int k1,k2;
  int x,find=0;
  struct node *f;
  printf("printf search choose:\n");
  printf("1.according to num.\n");
  printf("2.according to name.\n"); 
  scanf("%d",&x);
  switch(x)
  {
  case 1: printf("please input the num:");
	      scanf("%s",num);
		  k1=hash1(num);
		  f=num_list[k1];
		  while(f!=NULL)
		  {
			  if(strcmp(f->num,num)==0) 
			  {
				  printf("the node is:num:%s  name:%s address:%s\n",f->num,f->name,f->address);
			      find=1;
			  }
			  f=f->next;
		  }
		  if(find==0)
             printf("the node has not been found\n"); 	 
		  break;
  case 2: printf("please input the name:");
	      scanf("%s",name);
		  k2=hash2(name);
		  f=name_list[k2];
		   while(f!=NULL)
		  {
			  if(strcmp(f->name,name)==0) 
			  {
				  printf("the node is:num:%s  name:%s address:%s\n",f->num,f->name,f->address);
			      find=1;
			  }
			  f=f->next;
		  }
		  if(find==0)
             printf("the node has not been found\n"); 	  
		  break;
  }
 
}

 void main()
{
  int x,i;
  for(i=0;i<19;i++)
 {
   num_list[i]=NULL;
   name_list[i]=NULL;
 }
  while(1)
  {
  printf("1.create table.\n");
  printf("2.search.\n");
  printf("3.insert node.\n");
  printf("4.print table.\n");
  printf("5.end.\n");
  printf("please input your choose:");
  scanf("%d",&x);
     switch(x)
     { 
	    case 1:   create(); break;
        case 2:   search();break;
		case 3:   insert();break;
		case 4:   print();break;
        case 5:   return; 
	   default:printf("please input the number between 1 to 5\n");
	 }
  }
 }