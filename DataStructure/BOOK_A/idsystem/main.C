
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//定义结点的结构
typedef struct
{
  char id[19];//多一个字符，存放字符串结束标志，方便输出
  char name[11]; 
  char address[21];
  char phone[12];
}Keytype;
     
//定义在采用二叉排序树存储时的结点结构
typedef struct BSNode
{
    Keytype key;
    struct BSNode*lchild;
    struct BSNode*rchild;
}bsnodetype;

typedef bsnodetype *btree;


//二叉排序树中查询结点的查找算法，这里采用递归的查找算法，在二叉排序树中查找身份证号为id的结点
btree bssearch(btree p,char * id)
{
   
   while(p)//查找要插入的位置
   {
    if(strcmp(id,p->key.id)<0)
       p=p->lchild;
	else if(strcmp(id,p->key.id)>0)
	   p=p->rchild;
	else
       return p;
   }
   return p;
}

//插入算法，在二叉排序树上查找插入,bt为根指针，x为要插入的结点的身份证号
void insert(btree * root,char* id)

{
  btree f,p;
  char name[10],address[20],phone[11];
  f=NULL;
  p= *root;
  while(p)//查找要插入的位置
  {
    if(strcmp(id,p->key.id)==0)
    {
		printf("该号码已经存在，不能插入\n");
		return;
	}
    f=p;
    p=(strcmp(id,p->key.id)<0)?p->lchild:p->rchild;
  }
  p=(btree)malloc(sizeof(bsnodetype));//生成要插入的结点
  strcpy(p->key.id,id);
  printf("请输入10字符之内的姓名\n");
  scanf("%s",name);
  strcpy(p->key.name,name);
  printf("请输入20个字符之内的地址\n");
  scanf("%s",address);
  strcpy(p->key.address,address);
  printf("请输入11个字符之内的电话\n");
  scanf("%s",phone);
  strcpy(p->key.phone,phone);
  p->lchild=NULL;
  p->rchild=NULL;
  if(*root==NULL)  //原树为空
    *root=p;
  else            //原树不空
  {
	  if(strcmp(id,f->key.id)<0)
       f->lchild=p;
     else
      f->rchild=p;
  }
}

//按照身份证号从小到大输出所有的记录
void inorder(btree t)
{
  if(t)
  {
     inorder(t->lchild);
     printf("%s  ",t->key.id);
     printf("%s  ",t->key.name);
     printf("%s  ",t->key.address);
	 printf("%s\n",t->key.phone);
     inorder(t->rchild);
  }
}



//创建二叉排序树的算法，输入-1为结束标志
btree createbtree(void)
{
  btree root;
  char id[19];
  root=NULL;
  printf("\n如果输入结束请输入-1，如果要输入，请输入18位身份证号码：\n");
  scanf("%s",id);
  while(strcmp(id,"-1")!=0)
  {
    while(strlen(id)!=18)
	{      
		printf("身份证号码不是18位,重新输入\n");  
	    scanf("%s",id);
    }
   insert(&root,id);
   printf("\n如果输入结束请输入-1，如果要输入，请输入18位身份证号码：\n");
   scanf("%s",id);
  }
  return root;
 }

//删除算法，在bt为根结点的二叉树中删除身份证号为id的结点
btree  Delete(btree bt,char *id)
{
  btree p,q;
  if(strcmp(bt->key.id,id)==0)         //该结点为要删除的结点
  {
     if(bt->lchild==NULL&&bt->rchild==NULL)  // 删除的是叶子结点
     {
         free(bt);
         return NULL;
     }
     else if(bt->lchild==NULL)     //删除的是无左子树的结点
     {
         p=bt->rchild;
         free(bt);
         return p; 
      }
      else if(bt->rchild==NULL)       // 删除的是无右子树的结点
      {
        p=bt->lchild;
        free(bt);
        return p; 
       } 
       else                        // 删除的是有左、右子树的结点
       {
         p=q=bt->rchild;
         while(q->lchild!=NULL) q=q->lchild;
         q->lchild=bt->lchild;
         free(bt);
         return p;
       }
    }
    else
    {
		if(strcmp(bt->key.id,id)>0&&bt->lchild!=NULL )
           bt->lchild=Delete(bt->lchild,id);
        if (strcmp(bt->key.id,id)<0&&bt->rchild!=NULL )
          bt->rchild=Delete(bt->rchild,id);
        return bt;
	}
}



//主函数
void main()
{
      btree position;
      int c,len;
	  char id[18];
	  btree root;
	  char name[11];
	  char address[21];
	  char phone[12];
	  root=NULL;
      system("cls");	
	  do
	  {   
       	
		printf("---------------    Menu    ---------------\n");
		printf("------------------------------------------\n");
		printf("\t\t1.插入\n");
        printf("\t\t2.删除\n");
        printf("\t\t3.显示\n");
        printf("\t\t4.查找\n");
        printf("\t\t5.修改\n");
        printf("\t\t6.录入\n");
        printf("\t\t7.退出\n");  
		printf("------------------------------------------\n");
		printf("\t\t请按1-7数字选择："); 
        scanf("%d",&c);
	    switch(c)
		{
	       case 1:printf("请输入要插入的身份证号:\n");
			      scanf("%s",id);
				  len=strlen(id);
                  if(len==18)
				  insert(&root,id);
				  else
                    printf("身份证号码不是18位,不能插入,请重新选择 \n");
				  break;
		   case 2:if(root)
                  {
					  printf("请输入要删除的身份证号:\n");
			          scanf("%s",id);
				      len=strlen(id);
					  if(len==18)
					  {
					      position=bssearch(root,id);
						  if(position)
						  {
							  root=Delete(root,id);
                              printf("删除成功。\n"); 
						  }
						  else
							 printf("身份证号码不存在,不能删除,请重新选择：\n"); 
					  }
				      else
                         printf("身份证号码不是18位,不能删除,请重新选择：\n"); 
				  }
				  else
				  {
				     printf("目前没有任何身份证信息,不能删除,请重新选择：\n");
				  }
				  break;   
			     
		   case 3:if(root==NULL)
					 printf("目前没有任何身份证信息,请重新选择：\n");
			      else
			         inorder(root);
			      break;
		   case 4:if(root==NULL)
                     printf("目前没有任何身份证信息,不能查找,请重新选择：\n");
			      else
				  {
					  printf("请输入要查找的身份证号:\n");
			          scanf("%s",id);
				      len=strlen(id);
                      if(len==18)
					  {
					     position=bssearch(root,id);
					     if(position!=NULL)
						 {	 
						    printf("要查找的信息是：\n");
                            printf("%s  %s  %s  %s\n",position->key.id,position->key.name,position->key.address,position->key.phone);
						 }
					     else
						    printf("该信息不存在\n");
					  }
				      else
                        printf("身份证号码不是18位,不能查找,请重新选择。\n"); 
				  }
				  break;
		   case 5:if(root==NULL)
					 printf("目前没有任何身份证信息,请重新选择：。\n");
			      else
				  {
				     printf("请输入要修改信息的身份证号：\n");
					 scanf("%s",id);
				     len=strlen(id);
                     if(len==18)
					  {
					     position=bssearch(root,id);
					     if(position!=NULL)
						 {	 
						    printf("原来的信息是：\n");
                            printf("%s  %s  %s  %s\n",position->key.id,position->key.name,position->key.address,position->key.phone);
						    printf("请输入新的姓名：\n");
							scanf("%s",name);
							strcpy(position->key.name,name);
                             printf("请输入新的地址：\n");
							scanf("%s",address);
							strcpy(position->key.address,address);
							printf("请输入新的电话：\n");
							scanf("%s",phone);
							strcpy(position->key.phone,phone);
						 }
					     else
						    printf("该信息不存在\n");
					  }
				      else
                        printf("身份证号码不是18位,请重新选择。\n"); 
				  }
					  break;
		   case 6:root=createbtree();
                  break;
		   case 7:break;
           default:printf("\n\t\t请按1-7数字选择：\n");
		}
      }while(c!=7); 
	 

}
