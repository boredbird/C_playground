#include "stdio.h"
#include "stdlib.h"
int visited[10];
typedef struct 
{
   char vexs[10];
   int edges[10][10];
   int n,e;//分别代表图的顶点数和边数 
}MGraph;//结构体类型

void CreateMGraph(MGraph *G)
{
    int i,j,k;
    scanf("%d,%d",&G->n,&G->e); //输入顶点数和边数
    getchar();
    for(i=0;i<G->n;i++)
      G->vexs[i]=getchar(); //输入顶点信息
    for(i=0;i<G->n;i++)
      for(j=0;j<G->n;j++)
        G->edges[i][j]=0;  //邻接矩阵初始化
    printf("请输入一对顶点的序号:\n");
	for(k=0;k<G->e;k++)  
	{
	 scanf("%d,%d",&i,&j);  //输入边的一对顶点序号
     G->edges[i][j]=1;
     G->edges[j][i]=1;
	}
}
void dfs(MGraph *G,int i)
{
	int j;
	printf("%c",G->vexs[i]);
	visited[i]=1;
	for(j=0;j<G->n;j++)
		if(G->edges[i][j]==1&&visited[j]==0)
			dfs(G,j);
}
void dfstraverse(MGraph *G)
{
  int i;
  for(i=0;i<G->n;i++)
	  visited[i]=0;//初始化都未曾访问过
  for(i=0;i<G->n;i++)
	  if(visited[i]==0)//未曾访问过
		  dfs(G,i);
}


main()
{
    MGraph *G,ag;
	G=&ag;
	CreateMGraph(G);
	dfstraverse(G);
}



