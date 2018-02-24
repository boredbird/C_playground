#include<stdio.h>
#define MAXSIZE 10
typedef char ElemType;/*定义顶点类型为char*/
typedef struct
{
	ElemType  V[MAXSIZE];/*顶点信息*/
	int arcs[MAXSIZE][MAXSIZE];/*邻接矩阵*/
	int e;/*边数*/
	int n;/*顶点数*/
}Graph;/*图的邻接矩阵数据类型*/
/*在图G中查找顶点v,找到后返回其在顶点数组中的索引号，若不存在，返回-1*/
int LocateVex(Graph G,ElemType v)
{
	int i;
	for(i=0;i<G.n;i++)
	{
		if(G.V[i]==v)return i;
	}
	return -1;

}
/*在屏幕上显示图G的邻接矩阵表示*/
void DisplayAdjMatrix(Graph G)
{
	int i,j;
	printf("图的邻接矩阵表示：\n");
	for(i=0;i<G.n;i++)
	{
		for(j=0;j<G.n;j++)
		{
			printf("%3d",G.arcs[i][j]);
		}
		printf("\n");
	}
}
/*创建无向图的邻接矩阵*/
void CreateAdj(Graph *pg)
{
	int i,j,k,w;
	ElemType v1,v2;
	printf("请输入图的顶点数及边数\n");
	printf("顶点数 n=");scanf("%d",&pg->n);
	printf("边  数 e=");scanf("%d",&pg->e);
	printf("请输入图的顶点信息：\n");getchar();
	for(i=0;i<=pg->n;i++)scanf("%c",&pg->V[i]); /*构造顶点信息*/
	for(i=0;i<pg->n;i++)
		for(j=0;j<pg->n;j++)
			pg->arcs[i][j]=0;/*初始化邻接矩阵*/
    printf("请输入图的边的信息：\n");
for(k=0;k<pg->e;k++)
	{
		printf("请输入第%d条边的两个端点：",k+1);
		scanf("%c%c",&v1,&v2);getchar();/*输入一条边的两个顶点*/
/*确定两个顶点在图G中的位置*/
		i=LocateVex(*pg,v1);j=LocateVex(*pg,v2);
		if(i>=0&&j>=0)		{
			pg->arcs[i][j]=1;
			pg->arcs[j][i]=1;
		}
	}
}
//【算法6-7：利用邻接矩阵实现连通图的遍历】
int visited[MAXSIZE];/* 访问标志数组*/
 /*从第i个顶点出发递归地深度优先遍历图G*/
void DFS(Graph G,int i)
{
	int j;
	printf("%3c",G.V[i]); /*访问第i个项点*/
	visited[i]=1;
	for(j=0;j<G.n;j++)
	{
	    if((G.arcs[i][j]==1)&&(visited[j]==0))
		    DFS(G,j);/* //对i的尚未访问的邻接顶点j递归调用DFS */
	}
}
//【算法6-8：对图G进行深度优先遍历】
void DFSTraverse(Graph  G) /*对图G进行深度优先遍历*/
{
	int v;
    for (v=0; v<G.n;v++)visited[v]=0; /*初始化标志数组*/
    for  (v=0; v<G.n;v++) /*保证非连通图的遍历*/
/*从第v个顶点出发递归地深度优先遍历图G*/
        if (!visited[v]) DFS(G,v);        
}

void main()
{
	Graph G;
	CreateAdj(&G);
	system("title 第6章 图-深度优先遍历");
    printf("图的深度优先遍历序列：\n");
	DFSTraverse(G);printf("\n");
}
