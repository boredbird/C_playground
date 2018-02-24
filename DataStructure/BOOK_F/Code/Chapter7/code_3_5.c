typedef int keyType;
typedef struct BTNode
{
	keyType key;/*�ؼ�����*/
	struct BTNode *lchild,*rchild;
}BTNode; 
BiTree  SearchBST(BTNode T, KeyType key)
/*�ڸ�ָ��T��ָ�����������в���ĳ�ؼ��ֵ���key������Ԫ�أ������ҳɹ����򷵻�ָ�������Ԫ�ؽ���ָ�룬���򷵻ؿ�ָ��*/
{ 
    if (!T || key==T->key)) return (T); /* ���ҽ���*/
    else if (key<T-> key) )
	    return(SearchBST(T->lchild, key));
    else   return(SearchBST(T->rchild, key));
}
BTNode * SearchBST(BTNode *T, keyType key, int *f)
/*�����ҳɹ����򷵻ظ�����Ԫ�ؽ�㡣��ʹ*f=1;���򷵻ز���·���Ϸ��ʵ����һ��㲢ʹ*f=0*/
{
	BTNode *p,*pre;
	*f=0;
    if (!T){ *f=0; return T;}
	p=T;pre=T;                          /*preָ��p��˫��*/
	while(p!=NULL&&key!=p->key)
	{
		pre=p;
		if(key<p->key)p=p->lchild;   /*���������в���*/
		else p=p->rchild;              /*���������в���*/
	}
	if(p!=NULL&&key==p->key){*f=1;return p;} /*���ҳɹ�*/
	else{*f=0;return pre;}/*����ʧ��*/
}
BTNode * InsertBST(BTNode *T, keyType key)
/*������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ������key���ض����������ĸ���㡣*/
{   
	BTNode *p,*s;
	int f=0;
	p=SearchBST(T,key,&f);
	if (!f)                         /*���Ҳ��ɹ�*/
	{
        s=(BTNode *)malloc(sizeof(BTNode));
		s->key =key; s->lchild = s->rchild = NULL;
        if ( !p) return s;        /*����Ϊ�����*/
        else  if ( key< p->key)p->lchild=s;
		else p->rchild=s; 
	  }
	return T;
}
