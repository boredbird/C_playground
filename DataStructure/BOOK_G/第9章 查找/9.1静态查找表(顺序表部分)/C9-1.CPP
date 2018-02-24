#include "C9-1.H"

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
   printf("%-8ld%-8s%4d%5d%5d%5d%5d%5d%5d%5d\n",c.number,c.name,c.politics,
	   c.Chinese,c.English,c.math,c.physics,c.chemistry,c.biology,c.total);
 }
