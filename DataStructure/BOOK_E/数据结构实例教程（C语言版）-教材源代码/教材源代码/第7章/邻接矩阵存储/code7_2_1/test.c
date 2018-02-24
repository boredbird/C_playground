#include "stdio.h"
#define Num 100 
typedef struct 
{
	char vexs[Num];// vexs用于存放顶点信息
	int edges[Num][Num];//邻接矩阵，edges存储边信息
	int n,e;//分别代表图的顶点数和边数 
}MGraph;//结构体类型
void CreateMGraph(MGraph *G)
{
	int i,j,k;
	printf("请输入顶点数和边数:");
	scanf("%d,%d",&G->n,&G->e); //输入顶点数和边数
	getchar();
	printf("请输入顶点信息:");
	for(i=0;i<G->n;i++)
		G->vexs[i]=getchar(); //输入顶点信息
	for(i=0;i<G->n;i++)
		for(j=0;j<G->n;j++)
			G->edges[i][j]=0;  //邻接矩阵初始化
	for(k=0;k<G->e;k++)  
	{
		printf("请输入边<i,j>的序号:");
		scanf("%d,%d",&i,&j);  //输入边的一对顶点序号
		G->edges[i][j]=1;
		G->edges[j][i]=1;
	}
    printf("图的邻接矩阵为:\n");
	for(i=0;i<G->n;i++)
	{
		for(j=0;j<G->n;j++)
			printf("%3d",G->edges[i][j]);
		printf("\n");
	}
}
main()
{
  MGraph g;
  CreateMGraph(&g);
}