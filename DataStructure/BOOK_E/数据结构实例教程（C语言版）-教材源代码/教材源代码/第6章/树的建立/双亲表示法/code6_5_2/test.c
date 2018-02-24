#include "stdio.h"
#define MaxTreeSize 10
typedef struct
{
	char data;//结点数据
	int parent; //双亲指针，指示结点的双亲在向量中的位置
}PTreeNode;
//树的类型定义
typedef struct
{
	PTreeNode nodes[MaxTreeSize];
	int n; //结点总数 
}PTree;
main()
{
   PTree T;
   int i;
   printf("请输入结点个数:");
   scanf("%d",&T.n);
   for(i=0;i<T.n;i++)
   {
	   printf("请输入第%d个结点信息:",i);
	   getchar();
       scanf("%c",&T.nodes[i].data);
       printf("请输入第%d个结点的双亲下标:",i);
       scanf("%d",&T.nodes[i].parent);
   }
   //打印树的存储结果
   for(i=0;i<T.n;i++)
   	   printf("%3c",T.nodes[i].data);
   printf("\n");
   for(i=0;i<T.n;i++)
       printf("%3d",T.nodes[i].parent);
   printf("\n");
 }
