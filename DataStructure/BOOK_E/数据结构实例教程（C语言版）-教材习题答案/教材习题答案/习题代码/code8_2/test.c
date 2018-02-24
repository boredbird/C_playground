
int count(BTreeNode *T,int a)
{
	int sum;
	if(T==NULL) return 0;
	else
	{
		sum=count(T->rchild,a);
		if(T->data>a)
			return sum+1+count(T->lchild,a);
		else 
            return sum;
	}
}