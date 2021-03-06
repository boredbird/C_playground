#include "C9-5.H"

 void main()
 {
   BSTree dt,p;
   Status k;
   int i;
   KeyType j;
   ElemType r[N]={{13,1},{24,2},{37,3},{90,4},{53,5}}; /* (以教科书图9.12为例) */
   InitDSTable(&dt); /* 初始化空树 */
   for(i=0;i<N;i++)
     InsertAVL(&dt,r[i],&k); /* 建平衡二叉树 */
   PreOrderTraverse(dt,print); /* 先序遍历平衡二叉树 */
   printf("先序遍历平衡二叉树\n");
   TraverseDSTable(dt,print); /* 按关键字顺序遍历二叉树 */
   printf("\n请输入待查找的关键字: ");
   scanf("%d",&j);
   p=SearchBST(dt,j); /* 查找给定关键字的记录 */
   if(p)
     print(p->data);
   else
     printf("表中不存在此值");
   printf("\n");
   DestroyDSTable(&dt);
 }