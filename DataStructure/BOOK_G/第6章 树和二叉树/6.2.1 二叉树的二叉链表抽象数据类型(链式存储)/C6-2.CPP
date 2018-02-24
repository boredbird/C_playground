 // C6-2.cpp 二叉树(存储结构由C6-2.h定义)的基本操作

#include "C6-2.H"

//↓↓↓********************************************
//二叉树抽象数据类型算法实现
Status InitBiTree(BiTree &T){
	//初始化二叉树
	T = NULL;
    return TRUE;
}

BiTree Point(BiTree T,TElemType s)
 { /* 返回二叉树T中指向元素值为s的结点的指针。另加 */
   LinkQueue q;
   QElemType a;
   if(!BiTreeEmpty(T)) /* 非空树 */
   {
     InitQueue(q); /* 初始化队列 */
     EnQueue(q,T); /* 根指针入队 */
     while(!QueueEmpty(q)) /* 队不空 */
     {
       DeQueue(q,a); /* 出队，队列元素赋给a */
       if(a->data==s)
         return a;
       if(a->lchild) /* 有左孩子 */
         EnQueue(q,a->lchild); /* 入队左孩子 */
       if(a->rchild) /* 有右孩子 */
         EnQueue(q,a->rchild); /* 入队右孩子 */
     }
   }
   return NULL;
 }

void DeleteBiTree(BiTree *T){
	//删除二叉树(条件：二叉树存在)
		if(*T){
		if((*T)->lchild)
			DeleteBiTree(&(*T)->lchild);
	    if((*T)->rchild)
			DeleteBiTree(&(*T)->rchild);
		free(*T);
		(*T)=NULL;
	}
}

Status CreateBiTree(BiTree *T) 
//此处参数应该用指针的指针，应给它要改变指向二叉树根的那个指针   
{
     char ch;
     getchar();//清除输入前的回车符
     ch = getchar();  //获取节点值
	 if(ch=='#'||ch==' '){*T=NULL;} /*   #代表空指针*/ 
     else 
		{
        if(!((*T) = (BiTree)malloc(sizeof(BiTNode)))) return FALSE;
		(*T)->data = ch; 
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
		}//if-else
	return TRUE;
}

void ClearBiTree(BiTree T){
    //清空二叉树(条件：二叉树存在)
    DeleteBiTree(&T);
}

Status BiTreeEmpty(BiTree  T){
    //判定二叉树是否为空,为空，返回TRUE，否则返回FALSE
	if(T)
	    return FALSE;
    else
		return TRUE;
}

int BiTreeDepth(BiTree T){
	//返回二叉树的深度
	int max, k, j;
    if(T)
	{
	    k = BiTreeDepth(T->lchild);
	    j = BiTreeDepth(T->rchild);
		max = k>j?k:j;
		return (max+1);
	}
	else 
		return 0;
}

TElemType Root(BiTree T){
    // 求二叉树的根
   if(BiTreeEmpty(T))
     return FALSE;
   else
     return T->data;
}

TElemType Value(BiTNode node){
    //求给定节点的值
	return node.data;
}

void  Assign(BiTree T,TElemType value){
    //为给定节点赋值
	T->data=value;  
}

TElemType Parent(BiTree T,TElemType e)
 { /* 初始条件：二叉树T存在，e是T中某个结点 */
   /* 操作结果：若e是T的非根结点，则返回它的双亲，否则返回＂空＂*/
   LinkQueue q;
   QElemType a;
   if(!BiTreeEmpty(T)) /* 非空树 */
   {
     InitQueue(q); /* 初始化队列 */
     EnQueue(q,T); /* 树根指针入队 */
     while(!QueueEmpty(q)) /* 队不空 */
     {
       DeQueue(q,a); /* 出队，队列元素赋给a */
       if(a->lchild&&a->lchild->data==e||a->rchild&&a->rchild->data==e)
       /* 找到e(是其左或右孩子) */
         return a->data; /* 返回e的双亲的值 */
       else /* 没找到e，则入队其左右孩子指针(如果非空) */
       {
         if(a->lchild)
           EnQueue(q,a->lchild);
         if(a->rchild)
           EnQueue(q,a->rchild);
       }
     }
   }
   return FALSE; /* 树空或没找到e */
 }

 TElemType LeftChild(BiTree T,TElemType e)
 { /* 初始条件：二叉树T存在，e是T中某个结点。操作结果：返回e的左孩子。若e无左孩子,则返回"空" */
   BiTree a;
   if(!BiTreeEmpty(T)) /* 非空树 */
   {
     a=Point(T,e); /* a是结点e的指针 */
     if(a&&a->lchild) /* T中存在结点e且e存在左孩子 */
       return a->lchild->data; /* 返回e的左孩子的值 */
   }
   return FALSE; /* 其余情况返回空 */
 }

 TElemType RightChild(BiTree T,TElemType e)
 { /* 初始条件：二叉树T存在，e是T中某个结点。操作结果：返回e的右孩子。若e无右孩子,则返回"空" */
   BiTree a;
   if(!BiTreeEmpty(T)) /* 非空树 */
   {
     a=Point(T,e); /* a是结点e的指针 */
     if(a&&a->rchild) /* T中存在结点e且e存在右孩子 */
       return a->rchild->data; /* 返回e的右孩子的值 */
   }
   return FALSE; /* 其余情况返回空 */
 }

TElemType LeftSibling(BiTree T,TElemType e)
 { /* 初始条件：二叉树T存在，e是T中某个结点 */
   /* 操作结果：返回e的左兄弟。若e是T的左孩子或无左兄弟，则返回＂空＂*/
   TElemType a;
   BiTree p;
   if(!BiTreeEmpty(T)) /* 非空树 */
   {
     a=Parent(T,e); /* a为e的双亲 */
     if(a!=FALSE) /* 找到e的双亲 */
     {
       p=Point(T,a); /* p为指向结点a的指针 */
       if(p->lchild&&p->rchild&&p->rchild->data==e) /* p存在左右孩子且右孩子是e */
         return p->lchild->data; /* 返回p的左孩子(e的左兄弟) */
     }
   }
   return FALSE; /* 其余情况返回空 */
 }

 TElemType RightSibling(BiTree T,TElemType e)
 { /* 初始条件：二叉树T存在，e是T中某个结点 */
   /* 操作结果：返回e的右兄弟。若e是T的右孩子或无右兄弟，则返回＂空＂*/
   TElemType a;
   BiTree p;
   if(!BiTreeEmpty(T)) /* 非空树 */
   {
     a=Parent(T,e); /* a为e的双亲 */
     if(a!=FALSE) /* 找到e的双亲 */
     {
       p=Point(T,a); /* p为指向结点a的指针 */
       if(p->lchild&&p->rchild&&p->lchild->data==e) /* p存在左右孩子且左孩子是e */
         return p->rchild->data; /* 返回p的右孩子(e的右兄弟) */
     }
   }
   return FALSE; /* 其余情况返回空 */
 }

Status InsertChild(BiTree p, int LR, BiTree c) // 形参T无用
{	// 根据LR为0或1,插入c为T中p所指结点的左或右子树。p所指结点的
	//  原有左或右子树则成为c的右子树
	if(!BiTreeEmpty(p)) // p不空
	{
		if(LR == 0)
		{
			c->rchild = p->lchild;
			p->lchild = c;
		}
		else // LR == 1
		{
			c->rchild = p->rchild;
			p->rchild = c;
		}
		return OK;
	}
	return ERROR; // p空
}

Status DeleteChild(BiTree T, int LR) // 形参T无用
{	//根据LR为0或1,删除T中p所指结点的左或右子树
	if(!BiTreeEmpty(T)) // T不空
	{
		if(LR == 0) // 删除左子树
		{
			DeleteBiTree(&T->lchild);
		}
		else // 删除右子树
		{
			DeleteBiTree(&T->rchild);
		}
		return OK;
	}
	return ERROR; // p空
}

Status Visit(TElemType e){
	//访问节点并输出
    printf("%c",e);
    return OK;
}

void PreOrderTraverse(BiTree T)
{
	// 先序递归遍历T
	if(!BiTreeEmpty(T)) // T不空
	{
		Visit(T->data); // 先访问根结点
		PreOrderTraverse(T->lchild); // 再先序遍历左子树
		PreOrderTraverse(T->rchild); // 最后先序遍历右子树
	}
}

void InOrderTraverse(BiTree T)
{	// 中序递归遍历T
	if(!BiTreeEmpty(T))
	{
		InOrderTraverse(T->lchild); // , Visit 先中序遍历左子树
		Visit(T->data); // 再访问根结点
		InOrderTraverse(T->rchild); // , Visit 最后中序遍历右子树
	}
}

void PostOrderTraverse(BiTree T)
{	// 后序递归遍历T
	if(!BiTreeEmpty(T)) // T不空
	{
		PostOrderTraverse(T->lchild); // ,Visit 先后序遍历左子树
		PostOrderTraverse(T->rchild); // ,Visit 再后序遍历右子树
		Visit(T->data); // 最后访问根结点
	}
}

void LevelOrderTraverse(BiTree T)
{	// 层序递归遍历T(利用队列,需要预先编辑队列算法)
	LinkQueue q;
	QElemType a;
	if(T)
	{
		InitQueue(q);
		EnQueue(q,T);
		while(!QueueEmpty(q))
		{
			DeQueue(q,a);
			Visit(a->data);
			if(a->lchild != NULL) EnQueue(q,a->lchild);
			if(a->rchild != NULL) EnQueue(q,a->rchild);
		}
		printf("\n");
	}
	DestroyQueue(q);
}
//二叉树抽象数据类型算法实现
//↑↑↑********************************************


//↓↓↓********************************************
//LevelOrderTraverse(T)中需要调用的队列算法
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
//LevelOrderTraverse(T)中需要调用的队列算法
//↑↑↑********************************************