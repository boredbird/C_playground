#include "C9-3.H"

 void Creat_Seq(SSTable *ST,ElemType r[],int n)
 { /* 操作结果：由含n个数据元素的数组r构造静态顺序查找表ST */
   int i;
   (*ST).elem=(ElemType*)calloc(n+1,sizeof(ElemType)); /* 动态生成n+1个数据元素空间(0号单元不用) */
   if(!(*ST).elem)
     exit(ERROR);
   for(i=1;i<=n;i++)
     (*ST).elem[i]=r[i-1]; /* 将数组r的值依次赋给ST */
   (*ST).length=n;
 }

 void Ascend(SSTable *ST)
 { /* 重建静态查找表为按关键字非降序排序 */
   int i,j,k;
   for(i=1;i<(*ST).length;i++)
   {
     k=i;
     (*ST).elem[0]=(*ST).elem[i]; /* 待比较值存[0]单元 */
     for(j=i+1;j<=(*ST).length;j++)
       if LT((*ST).elem[j].key,(*ST).elem[0].key)
       {
	 k=j;
	 (*ST).elem[0]=(*ST).elem[j];
       }
     if(k!=i) /* 有更小的值则交换 */
     {
       (*ST).elem[k]=(*ST).elem[i];
       (*ST).elem[i]=(*ST).elem[0];
     }
   }
 }

 void Creat_Ord(SSTable *ST,ElemType r[],int n)
 { /* 操作结果：由含n个数据元素的数组r构造按关键字非降序查找表ST */
   Creat_Seq(ST,r,n); /* 建立无序的查找表ST */
   Ascend(ST); /* 将无序的查找表ST重建为按关键字非降序查找表 */
 }

 Status Destroy(SSTable *ST)
 { /* 初始条件：静态查找表ST存在。操作结果：销毁表ST */
   free((*ST).elem);
   (*ST).elem=NULL;
   (*ST).length=0;
   return OK;
 }

 int Search_Seq(SSTable ST,KeyType key)
 { /* 在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则返回 */
   /* 该元素在表中的位置，否则返回0。算法9.1 */
   int i;
   ST.elem[0].key=key; /* 哨兵 */
   for(i=ST.length;!EQ(ST.elem[i].key,key);--i); /* 从后往前找 */
   return i; /* 找不到时，i为0 */
 }

 int Search_Bin(SSTable ST,KeyType key)
 { /* 在有序表ST中折半查找其关键字等于key的数据元素。若找到，则返回 */
   /* 该元素在表中的位置，否则返回0。算法9.2 */
   int low,high,mid;
   low=1; /* 置区间初值 */
   high=ST.length;
   while(low<=high)
   {
     mid=(low+high)/2;
     if EQ(key,ST.elem[mid].key)  /* 找到待查元素 */
       return mid;
     else if LT(key,ST.elem[mid].key)
       high=mid-1; /* 继续在前半区间进行查找 */
     else
       low=mid+1; /* 继续在后半区间进行查找 */
   }
   return 0; /* 顺序表中不存在待查元素 */
 }

 void Traverse(SSTable ST,void(*Visit)(ElemType))
 { /* 初始条件：静态查找表ST存在，Visit()是对元素操作的应用函数 */
   /* 操作结果：按顺序对ST的每个元素调用函数Visit()一次且仅一次 */
   ElemType *p;
   int i;
   p=++ST.elem; /* p指向第一个元素 */
   for(i=1;i<=ST.length;i++)
     Visit(*p++);
 }

 void print(ElemType c) /* Traverse()调用的函数 */
 {
   printf("(%c %d) ",c.key,c.weight);
 }

 Status SecondOptimal(BiTree *T, ElemType R[],int sw[],int low,int high)
 { /* 由有序表R[low..high]及其累计权值表sw(其中sw[0]==0)递归构造次优查找树T。算法9.3 */
   int i,j;
   double min,dw;
   i=low;
   min=fabs(sw[high]-sw[low]);
   dw=sw[high]+sw[low-1];
   for(j=low+1;j<=high;++j) /* 选择最小的△Pi值 */
     if(fabs(dw-sw[j]-sw[j-1])<min)
     {
       i=j;
       min=fabs(dw-sw[j]-sw[j-1]);
     }
   *T=(BiTree)malloc(sizeof(BiTNode));
   if(!*T)
     return ERROR;
   (*T)->data=R[i]; /* 生成结点 */
   if(i==low)
     (*T)->lchild=NULL; /* 左子树空 */
   else
     SecondOptimal(&(*T)->lchild,R,sw,low,i-1); /* 构造左子树 */
   if(i==high)
     (*T)->rchild=NULL; /* 右子树空 */
   else
     SecondOptimal(&(*T)->rchild,R,sw,i+1,high); /* 构造右子树 */
   return OK;
 }

 void FindSW(int sw[],SSTable ST)
 { /* 按照有序表ST中各数据元素的Weight域求累计权值表sw */
   int i;
   sw[0]=0;
   for(i=1;i<=ST.length;i++)
     sw[i]=sw[i-1]+ST.elem[i].weight;
 }


 void CreateSOSTree(SOSTree *T,SSTable ST)
 { /* 由有序表ST构造一棵次优查找树T。ST的数据元素含有权域weight。算法9.4 */
   int sw[N+1]; /* 累计权值 */
   if(ST.length==0)
     *T=NULL;
   else
   {
     FindSW(sw,ST); /* 按照有序表ST中各数据元素的weight域求累计权值表sw */
     SecondOptimal(T,ST.elem,sw,1,ST.length);
   }
 }

 Status Search_SOSTree(SOSTree *T,KeyType key)
 { /* 在次优查找树T中查找关键字等于key的元素。找到则返回OK，否则返回FALSE */
   while(*T) /* T非空 */
     if((*T)->data.key==key)
       return OK;
     else if((*T)->data.key>key)
       *T=(*T)->lchild;
     else
       *T=(*T)->rchild;
   return FALSE; /* 顺序表中不存在待查元素 */
 }