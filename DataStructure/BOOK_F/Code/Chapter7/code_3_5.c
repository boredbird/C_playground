typedef int keyType;
typedef struct BTNode
{
	keyType key;/*关键字域*/
	struct BTNode *lchild,*rchild;
}BTNode; 
BiTree  SearchBST(BTNode T, KeyType key)
/*在根指针T所指二叉排序树中查找某关键字等于key的数据元素，若查找成功，则返回指向该数据元素结点的指针，否则返回空指针*/
{ 
    if (!T || key==T->key)) return (T); /* 查找结束*/
    else if (key<T-> key) )
	    return(SearchBST(T->lchild, key));
    else   return(SearchBST(T->rchild, key));
}
BTNode * SearchBST(BTNode *T, keyType key, int *f)
/*若查找成功，则返回该数据元素结点。并使*f=1;否则返回查找路径上访问的最后一结点并使*f=0*/
{
	BTNode *p,*pre;
	*f=0;
    if (!T){ *f=0; return T;}
	p=T;pre=T;                          /*pre指向p的双亲*/
	while(p!=NULL&&key!=p->key)
	{
		pre=p;
		if(key<p->key)p=p->lchild;   /*在左子树中查找*/
		else p=p->rchild;              /*在右子树中查找*/
	}
	if(p!=NULL&&key==p->key){*f=1;return p;} /*查找成功*/
	else{*f=0;return pre;}/*查找失败*/
}
BTNode * InsertBST(BTNode *T, keyType key)
/*当二叉排序树T中不存在关键字等于key的数据元素时，插入key返回二叉排序树的根结点。*/
{   
	BTNode *p,*s;
	int f=0;
	p=SearchBST(T,key,&f);
	if (!f)                         /*查找不成功*/
	{
        s=(BTNode *)malloc(sizeof(BTNode));
		s->key =key; s->lchild = s->rchild = NULL;
        if ( !p) return s;        /*插入为根结点*/
        else  if ( key< p->key)p->lchild=s;
		else p->rchild=s; 
	  }
	return T;
}
