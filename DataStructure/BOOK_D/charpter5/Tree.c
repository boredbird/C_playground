#include<stdio.h>
#include<stdlib.h>
typedef  char ElemType;   //默认数据类型为char
//线性表的单链表存储结构描述
typedef struct BiNode{
   ElemType data;
   struct BiNode *lchild,*rchild;    //左右孩子指针
}BiNode;


BiNode *Creat();
void PreOrder(BiNode *);
void Visit(ElemType);
void InOrder (BiNode *);
void PostOrder(BiNode *);
void ComputeNode(BiNode *);
void InsertNodeL(BiNode *,ElemType,ElemType);
void InsertNodeR(BiNode *,ElemType,ElemType);
void DelectNode(BiNode *bt,ElemType x);
int nodeNum,leafNum;

void main()
{
	int ch;
	char exit='N';
	BiNode *T;
	ElemType x,y;
	int loc;

	nodeNum=leafNum=0;
	do
	{
		system("CLS");
		printf("\t\t********************************************\n");
		printf("\t\t*  1.创建一个二叉树  .................(1)  *\n");
		printf("\t\t*  2.先序遍历二叉树  .................(2)  *\n");
		printf("\t\t*  3.中序遍历二叉树  .................(3)  *\n");
	    printf("\t\t*  4.后序遍历二叉树  .................(4)  *\n");
		printf("\t\t*  5.计算结点总数和叶点数.............(5)  *\n");
		printf("\t\t*  6.二叉树中插入新的结点.............(6)  *\n");
		printf("\t\t*  7.删除二叉树指定结点...............(7)  *\n");
		printf("\t\t*  8.退出              ............. .(8) *\n");
		printf("\t\t********************************************\n");
		printf("\n请选择操作代码：");
        scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				getchar();
				printf("创建二叉树:\n请输入是二叉树的先序序列，用#表示子树为空：");
				T=Creat();				
				printf("二叉树创建成功!\n");			
				system("pause");
				break;
			case 2:
				printf("先序遍历二叉树:\n");
                PreOrder(T);
				system("pause");
				break;
			case 3:
               printf("中序遍历二叉树:\n");
               InOrder(T);
			   system("pause");
				break;
			case 4:				
		        printf("后序遍历二叉树:\n");
				PostOrder(T);
				system("pause");
				break;
			case 5:			   	
				ComputeNode(T);
				printf("二叉树中结点总数为：%d,叶结点总数为：%d\n",nodeNum,leafNum);
				system("pause");		

				break;
			case 6:
				printf("二叉树中插入新的结点:\n");
				printf("请输入要插入的结点：");fflush(stdin);scanf("%c",&x);
				printf("请输入要插入的值：");fflush(stdin);scanf("%c",&y);
				printf("请输入在左子树(1)还是右子树(2)插入：");scanf("%d",&loc);
				if(loc==1)
					InsertNodeL(T,x,y);
				else
					InsertNodeR(T,x,y);

				printf("中序遍历二叉树:\n");
               InOrder(T);

				
			
				system("pause");
				break;
			case 7:
				printf("二叉树中删除的结点:\n");
				printf("请输入要删除的结点的值：");fflush(stdin);scanf("%c",&x);
				DelectNode(T,x);

				printf("中序遍历二叉树:\n");
               InOrder(T);
                
				system("pause");
				break;
			case 8:
				getchar();
				printf("\n您是否真的要退出程序(Y/N):");
				exit=getchar();getchar();
				break;
			default:
				printf("\n无效输入，请重新选择...:");				

		}
		
	}while(exit!='y'&&exit!='Y');

}
void Visit(ElemType data)
{
	printf("%c",data);
}
void PreOrder(BiNode *bt) 
{
    if (bt == NULL)  return;              //递归调用的结束条件
    else
	{
		Visit(bt->data);                  //访问根结点bt的数据域
        PreOrder(bt->lchild);             //前序递归遍历bt的左子树
        PreOrder(bt->rchild);             //前序递归遍历bt的右子树  
    }
}

void InOrder (BiNode *bt)
{
     if (bt == NULL) return;                 //递归调用的结束条件
     else 
	 {
         InOrder(bt->lchild);                //中序递归遍历bt的左子树
         Visit(bt->data);                    //访问根结点bt的数据域
         InOrder(bt->rchild);                //中序递归遍历bt的右子树
    }
}

void PostOrder(BiNode *bt)
{ 
     if (bt == NULL) return;                //递归调用的结束条件
     else 
	 {
         PostOrder(bt->lchild);             //后序递归遍历bt的左子树
         PostOrder(bt->rchild);             //后序递归遍历bt的右子树
         Visit(bt->data);                   //访问根结点bt的数据域
    }
}

BiNode *Creat()
{
	BiNode *bt;
    ElemType ch;
    scanf("%c",&ch);                           //输入结点的数据信息，假设为字符
    if (ch =='#') bt = NULL;                //建立一棵空树
    else
    {
        bt = (BiNode*)malloc(sizeof(BiNode));;
		bt->data = ch;  //生成一个结点，数据域为ch
        bt->lchild = Creat();        //递归建立左子树
        bt->rchild = Creat();        //递归建立右子树
    }
    return bt;
}

void Release(BiNode *bt)
{
    if (bt == NULL) return;                 //递归调用的结束条件
    else
    {
        Release(bt->lchild);               //后序递归遍历bt的左子树
        Release(bt->rchild);               //后序递归遍历bt的右子树
        free(bt);                        //销毁根结点bt
    }
}
//计算二叉树的节点数和叶节点数
void ComputeNode(BiNode *bt)
{
	if (bt) { //递归调用的结束条件为bt为空
		nodeNum++; 	 //访问结点的数据域
		if(bt->lchild==NULL&&bt->rchild==NULL)leafNum++;
		ComputeNode(bt->lchild);  //先序递归遍历bt的左子树
		ComputeNode(bt->rchild);  //先序递归遍历bt的右子树
     }
}

BiNode *SelectNode(BiNode *bt,ElemType e)
{
	 if (bt == NULL) return NULL;                 //递归调用的结束条件
     else 
	 {
         SelectNode(bt->lchild,e);                //中序递归遍历bt的左子树
         if(e==bt->data)return bt;             //找到结点，并返回
         SelectNode(bt->rchild,e);                //中序递归遍历bt的右子树
    }

}
void InsertNodeL(BiNode *bt,ElemType x,ElemType y)
{
	BiNode *p,*s;
	p=SelectNode(bt,x);
	if(p==NULL)printf("没有找到值为%c的结点，无法插入！\n",x);
	else if(p->lchild!=NULL)printf("结点%c的左子树不为空，无法插入！\n",x);
	else
	{
		s=(BiNode *)malloc(sizeof(BiNode));
		s->data=y;
		s->lchild=s->rchild=NULL;
		p->lchild=s;
	}
}
void InsertNodeR(BiNode *bt,ElemType x,ElemType y)
{
	BiNode *p,*s;
	p=SelectNode(bt,x);
	if(p==NULL)printf("没有找到值为%c的结点，无法插入！\n",x);
	else if(p->rchild!=NULL)printf("结点%c的右子树不为空，无法插入！\n",x);
	else
	{
		s=(BiNode *)malloc(sizeof(BiNode));
		s->data=y;
		s->lchild=s->rchild=NULL;
		p->rchild=s;
	}
}

BiNode *SelectParentsNode(BiNode *bt,ElemType e)
{
	 if (bt == NULL) return NULL;                 //递归调用的结束条件
     else 
	 {
		 if(bt->lchild!=NULL)
			 if(e==bt->lchild->data)return bt;
			 else SelectParentsNode(bt->lchild,e);
		 if(bt->rchild!=NULL)
			 if(e==bt->rchild->data)return bt;
			 else SelectParentsNode(bt->rchild,e);    }

}
void DelectNode(BiNode *bt,ElemType x)
{
	BiNode *p;
	if(bt->data==x)Release(bt);
	else
	{
		p=SelectParentsNode(bt,x);
		if(p==NULL)
			printf("没有找到值为%c的结点，无法删除！\n",x);
		else
		{
			if(p->lchild->data==x)
			{
				Release(p->lchild);p->lchild=NULL;
			}
			else
			{
				Release(p->rchild);p->rchild=NULL;
			}
		
		}
	}

}