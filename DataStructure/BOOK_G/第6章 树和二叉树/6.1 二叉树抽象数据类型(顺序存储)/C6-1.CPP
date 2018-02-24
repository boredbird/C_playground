 /* C6-1.cpp 二叉树的顺序存储(存储结构由c6-1.h定义)的基本操作*/
#include "C6-1.H" /* 链队列 */

 void InitBiTree(SqBiTree T)
 { /* 构造空二叉树T。因为T是数组名，故不需要& */
   int i;
   for(i=0;i<MAX_TREE_SIZE;i++)
     T[i]=NULL; /* 初值为空(NULL在主程中定义) */
 }

 void CreateBiTree(SqBiTree T)
 { /* 按层序次序输入二叉树中结点的值(字符型或整型), 构造顺序存储的二叉树T */
   int i=0;
 
   int l;
   char s[MAX_TREE_SIZE];
  // InitBiTree(T); /* 构造空二叉树T */
   printf("请按层序输入结点的值(字符)，空格表示空结点，结点数≤%d:\n",MAX_TREE_SIZE);
   getchar();
   gets(s); /* 输入字符串 */
   l=strlen(s); /* 求字符串的长度 */
   for(;i<l;i++) /* 将字符串赋值给T */
   T[i]=s[i];
 }

 Status BiTreeEmpty(SqBiTree T)
 { /* 初始条件：二叉树T存在。操作结果：若T为空二叉树，则返回TRUE，否则FALSE */
   if(T[0]==NULL) /* 根结点为空，则树空 */
     return TRUE;
   else
     return FALSE;
 }

 int BiTreeDepth(SqBiTree T)
 { /* 初始条件：二叉树T存在。操作结果：返回T的深度 */
   int i,j=-1;
   for(i=MAX_TREE_SIZE-1;i>=0;i--) /* 找到最后一个结点 */
     if(T[i]!=NULL)
       break;
   i++; /* 为了便于计算 */
   do
     j++;
   while(i>=pow(2,j));
   return j;
 }

 TElemType Root(SqBiTree T)
 { /* 初始条件：二叉树T存在。操作结果：当T不空，用e返回T的根，返回OK；否则返回ERROR，e无定义 */
   if(BiTreeEmpty(T)) /* T空 */
     return ERROR;
   else
   {
     return T[0];
   }
 }

 TElemType Value(SqBiTree T,position e)
 { /* 初始条件：二叉树T存在，e是T中某个结点(的位置) */
   /* 操作结果：返回处于位置e(层,本层序号)的结点的值 */
   return T[(int)pow(2,e.level-1)+e.order-2];
 }

 Status Assign(SqBiTree T,position e,TElemType value)
 { /* 初始条件：二叉树T存在，e是T中某个结点(的位置) */
   /* 操作结果：给处于位置e(层,本层序号)的结点赋新值value */
   int i=(int)pow(2,e.level-1)+e.order-2; /* 将层、本层序号转为矩阵的序号 */
   if(value!=NULL&&T[(i+1)/2-1]==NULL) /* 给叶子赋非空值但双亲为空 */
     return ERROR;
   else if(value==NULL&&(T[i*2+1]!=NULL||T[i*2+2]!=NULL)) /*  给双亲赋空值但有叶子(不空) */
     return ERROR;
   T[i]=value;
   return OK;
 }

 TElemType Parent(SqBiTree T,TElemType e)
 { /* 初始条件：二叉树T存在，e是T中某个结点 */
   /* 操作结果：若e是T的非根结点，则返回它的双亲，否则返回＂空＂ */
   int i;
   if(T[0]==NULL) /* 空树 */
     return FALSE;
   for(i=1;i<=MAX_TREE_SIZE-1;i++)
     if(T[i]==e) /* 找到e */
       return T[(i+1)/2-1];
   return NULL; /* 没找到e */
 }

 TElemType LeftChild(SqBiTree T,TElemType e)
 { /* 初始条件：二叉树T存在，e是T中某个结点。操作结果：返回e的左孩子。若e无左孩子,则返回"空" */
   int i;
   if(T[0]==NULL) /* 空树 */
     return FALSE;
   for(i=0;i<=MAX_TREE_SIZE-1;i++)
     if(T[i]==e) /* 找到e */
       return T[i*2+1];
   return FALSE; /* 没找到e */
 }

 TElemType RightChild(SqBiTree T,TElemType e)
 { /* 初始条件：二叉树T存在，e是T中某个结点。操作结果：返回e的右孩子。若e无右孩子,则返回"空" */
   int i;
   if(T[0]==FALSE) /* 空树 */
     return FALSE;
   for(i=0;i<=MAX_TREE_SIZE-1;i++)
     if(T[i]==e) /* 找到e */
       return T[i*2+2];
   return FALSE; /* 没找到e */
 }

 TElemType LeftSibling(SqBiTree T,TElemType e)
 { /* 初始条件：二叉树T存在，e是T中某个结点 */
   /* 操作结果：返回e的左兄弟。若e是T的左孩子或无左兄弟，则返回＂空＂ */
   int i;
   if(T[0]==FALSE) /* 空树 */
     return FALSE;
   for(i=1;i<=MAX_TREE_SIZE-1;i++)
     if(T[i]==e&&i%2==0) /* 找到e且其序号为偶数(是右孩子) */
       return T[i-1];
   return FALSE; /* 没找到e */
 }

 TElemType RightSibling(SqBiTree T,TElemType e)
 { /* 初始条件：二叉树T存在，e是T中某个结点 */
   /* 操作结果：返回e的右兄弟。若e是T的右孩子或无右兄弟，则返回＂空＂ */
   int i;
   if(T[0]==FALSE) /* 空树 */
     return FALSE;
   for(i=1;i<=MAX_TREE_SIZE-1;i++)
     if(T[i]==e&&i%2) /* 找到e且其序号为奇数(是左孩子) */
       return T[i+1];
   return FALSE; /* 没找到e */
 }

 void Move(SqBiTree q,int j,SqBiTree T,int i) /* InsertChild()用到。加 */
 { /* 把从q的j结点开始的子树移为从T的i结点开始的子树 */
   if(q[2*j+1]!=NULL) /* q的左子树不空 */
     Move(q,(2*j+1),T,(2*i+1)); /* 把q的j结点的左子树移为T的i结点的左子树 */
   if(q[2*j+2]!=NULL) /* q的右子树不空 */
     Move(q,(2*j+2),T,(2*i+2)); /* 把q的j结点的右子树移为T的i结点的右子树 */
   T[i]=q[j]; /* 把q的j结点移为T的i结点 */
   q[j]=FALSE; /* 把q的j结点置空 */
 }

 void InsertChild(SqBiTree T,TElemType p,int LR,SqBiTree c)
 { /* 初始条件：二叉树T存在，p是T中某个结点的值，LR为0或1，非空二叉树c与T不相交且右子树为空 */
   /* 操作结果: 根据LR为0或1,插入c为T中p结点的左或右子树。p结点的原有左或右子树则成为c的右子树 */
   int j,k,i=0;
   for(j=0;j<(int)pow(2,BiTreeDepth(T))-1;j++) /* 查找p的序号 */
     if(T[j]==p) /* j为p的序号 */
       break;
   k=2*j+1+LR; /* k为p的左或右孩子的序号 */
   if(T[k]!=FALSE) /* p原来的左或右孩子不空 */
   Move(T,k,T,2*k+2); /* 把从T的k结点开始的子树移为从k结点的右子树开始的子树 */
   Move(c,i,T,k); /* 把从c的i结点开始的子树移为从T的k结点开始的子树 */
 }

/* 设队列元素类型为整型(序号) */

 Status DeleteChild(SqBiTree T,position p,int LR)
 { /* 初始条件：二叉树T存在，p指向T中某个结点，LR为1或0 */
   /* 操作结果：根据LR为1或0，删除T中p所指结点的左或右子树 */
   int i;
   Status k=OK; /* 队列不空的标志 */
   LinkQueue q;
   InitQueue(q); /* 初始化队列，用于存放待删除的结点 */
   i=(int)pow(2,p.level-1)+p.order-2; /* 将层、本层序号转为矩阵的序号 */
   if(T[i]==FALSE) /* 此结点空 */
     return ERROR;
   i=i*2+1+LR; /* 待删除子树的根结点在矩阵中的序号 */
   while(k)
   {
     if(T[2*i+1]!=NULL) /* 左结点不空 */
       EnQueue(q,2*i+1); /* 入队左结点的序号 */
     if(T[2*i+2]!=NULL) /* 右结点不空 */
       EnQueue(q,2*i+2); /* 入队右结点的序号 */
     T[i]=NULL; /* 删除此结点 */
     k=DeQueue(q,i); /* 队列不空 */
   }
   return OK;
 }

 void VisitFunc(TElemType e)
 {
	 if(e!=' ')
	      printf("%c",e);
 }

 void PreTraverse(SqBiTree T,int e)
 { /* PreOrderTraverse()调用 */
   VisitFunc(T[e]);
   if(T[2*e+1]!=NULL) /* 左子树不空 */
     PreTraverse(T,2*e+1);
   if(T[2*e+2]!=NULL) /* 右子树不空 */
     PreTraverse(T,2*e+2);
 }

 void PreOrderTraverse(SqBiTree T)
 { // 先序遍历T，对每个结点访问一次且仅一次 
   if(!BiTreeEmpty(T)) /* 树不空 */
     PreTraverse(T,0);
   printf("\n");
 }

 void InTraverse(SqBiTree T,int e)
 { /* InOrderTraverse()调用 */
   if(T[2*e+1]!=NULL) /* 左子树不空 */
     InTraverse(T,2*e+1);
   VisitFunc(T[e]);
   if(T[2*e+2]!=NULL) /* 右子树不空 */
     InTraverse(T,2*e+2);
 }

 void InOrderTraverse(SqBiTree T)
 { // 中序遍历T，对每个结点访问一次且仅一次 
   if(!BiTreeEmpty(T)) /* 树不空 */
     InTraverse(T,0);
   printf("\n");
 }

 void PostTraverse(SqBiTree T,int e)
 { /* PostOrderTraverse()调用 */
    
    if(T[2*e+1]!=NULL) /* 左子树不空 */
       PostTraverse(T,2*e+1);
    if(T[2*e+2]!=NULL) /* 右子树不空 */
       PostTraverse(T,2*e+2);
    VisitFunc(T[e]);
 }

 void PostOrderTraverse(SqBiTree T)
 { // 后序遍历T，对每个结点访问一次且仅一次 
   if(!BiTreeEmpty(T)) /* 树不空 */
     PostTraverse(T,0);
   printf("\n");
 }

 void LevelOrderTraverse(SqBiTree T)
 { /* 层序遍历二叉树 */
   int i=MAX_TREE_SIZE-1,j;
   while(T[i]==NULL)
     i--; /* 找到最后一个非空结点的序号 */
   for(j=0;j<=i;j++) /* 从根结点起，按层序遍历二叉树 */
     if(T[j]!=NULL)
       VisitFunc(T[j]); /* 只遍历非空的结点 */
   printf("\n");
 }

 void Print(SqBiTree T)
 { /* 逐层、按本层序号输出二叉树 */
   int j,k;
   position p;
   TElemType e;
   for(j=1;j<=BiTreeDepth(T);j++)
   {
     printf("第%d层: ",j);
     for(k=1;k<=pow(2,j-1);k++)
     {
       p.level=j;
       p.order=k;
       e=Value(T,p);
       if(e!=NULL)   printf("%c",e);
     }
     printf("\n");
   }
 }

//↓↓↓********************************************
//LevelOrderTraverse(T, Visit())中需要调用的队列算法
Status	InitQueue(LinkQueue &Q)
{	// 构造一个空队列Q
	if(!(Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode))))  exit(OVERFLOW);
	Q.front->next=NULL;
	return OK;
}

Status	DestroyQueue(LinkQueue &Q)
{	// 销毁队列Q(无论空否均可)
	while(Q.front)
	{
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return OK;
}

Status	EnQueue(LinkQueue &Q,QElemType e)
{	// 插入元素e为Q的新的队尾元素
	QueuePtr p;
	if(!(p=(QueuePtr)malloc(sizeof(QNode)))) // 存储分配失败
		exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
}

Status	QueueEmpty(LinkQueue Q)
{	// 若Q为空队列,则返回TRUE,否则返回FALSE
	if(Q.front==Q.rear) return TRUE; else return FALSE;
}

Status	DeQueue(LinkQueue &Q,QElemType &e)
{	// 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR
	QueuePtr p;
	if(Q.front==Q.rear) return ERROR;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	return OK;
}
//LevelOrderTraverse(T, Visit())中需要调用的队列算法
//↑↑↑********************************************