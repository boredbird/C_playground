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
			pg->arcs[i][j]=999;/*初始化邻接矩阵*/
    printf("请输入图的边的信息：\n");
    for(k=0;k<pg->e;k++)
	{
		printf("请输入第%d条边的两个端点,及权值：",k+1);
		scanf("%c%c%d",&v1,&v2,&w);/*输入一条边的两个顶点*/
		getchar();
        /*确定两个顶点在图G中的位置*/
		i=LocateVex(*pg,v1);j=LocateVex(*pg,v2);
		if(i>=0&&j>=0)
		{
			pg->arcs[i][j]=w;
			pg->arcs[j][i]=w;
		}
	}

}
typedef struct
{
	ElemType adjvax;
	int lowcost;
}closedge;
//【算法6-13：求出集合中V-U依附于顶点u（u∈U）的权值最小的顶点的序号】
/*在辅助数组中求出权值最小的顶点序号*/
int Mininum(Graph G,closedge dge[]){
	int i,j,min;
	for(i=0;i<G.n;i++){
		if(dge[i].lowcost!=0)break;
	}
	min=i;
	for(j=i+1;j<G.n;j++){
		if(dge[j].lowcost!=0&&dge[j].lowcost<dge[min].lowcost)
			min=j;
	}
	return min;
}

//【算法6-12：普里姆算法】
/*从顶点V出发构造网G的最小生成树，并输出最小生成树的各条边*/
void MiniSpanTree_PRIM(Graph G,ElemType v)
{
	int i,j,k;
	closedge dge[MAXSIZE];
	k=LocateVex(G,v);/*确定顶点v在网G中的序号*/
	for(j=0;j<G.n;j++){/*初始化辅助数组*/
		if(j!=k){
			dge[j].adjvax=v;
			dge[j].lowcost=G.arcs[k][j];
		}
	}
/*初始顶点生成树集合，lowcost值为0，表示该顶点已并入生成树集合*/
	dge[k].lowcost=0;
	for(i=0;i<G.n-1;i++){
		k=Mininum(G,dge);/*求辅助数组中权值最小的顶点*/
/*输入最小生成树的一条边和对应权值*/
        printf("(%c,%c,%d)",
dge[k].adjvax,G.V[k],dge[k].lowcost);
		dge[k].lowcost=0;/*将顶点k并入生成树集合*/
		for(j=0;j<G.n;j++){/*重新调整dge*/
			if(G.arcs[k][j]<dge[j].lowcost) {
				dge[j].adjvax=G.V[k];
				dge[j].lowcost=G.arcs[k][j];
			}
		}
	}}


void main()
{
	Graph G;
	CreateAdj(&G);
	MiniSpanTree_PRIM(G,'a');
}
