#include<stdio.h>
#define MAXSIZE 10
typedef char ElemType;/*定义顶点类型为char*/
int Max=999;
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
			pg->arcs[i][j]=Max;/*初始化邻接矩阵*/
    printf("请输入图的边的信息：\n");
    for(k=0;k<pg->e;k++)
	{
		printf("请输入第%d条边的两个端点,及权值：",k+1);
		scanf("%c%c%d",&v1,&v2,&w);/*输入一条边的两个顶点*/
		getchar();
        /*确定两个顶点在图G中的位置*/
		i=LocateVex(*pg,v1);j=LocateVex(*pg,v2);
		if(i>=0&&j>=0)pg->arcs[i][j]=w;
	}

}

//【算法6-15：迪杰斯特拉算法】
void Dijkstra(Graph G,int v0,int path[],int dist[])
/*求有向图G的v0顶点到其余顶点v的最短路径，path[i]是v0到vi的最短路径上的前驱顶点，dist[i]是路径长度*/
{
	int i,j,v,w;
	int min;
	int s[MAXSIZE];
	for(i=0;i<G.n;i++)/*初始化s，dist和path*/
	{
		s[i]=0;
		dist[i]=G.arcs[v0][i];
		if(dist[i]<Max)path[i]=v0;
		else path[i]=-1;
	}
	dist[v0]=0;s[v0]=1;/*初始时源点v0属于s集*/
	/*循环求v0到某个顶点v的最短路径，并将v加入s集*/
	for(i=1;i<G.n-1;i++)
	{
		min= Max;
		for(w=0;w<G.n;w++)
		{
			/*顶点w不属于s集且离v0更近*/
			if(!s[w]&&dist[w]<min)
			{
				v=w;min=dist[w];
			}
		}
		s[v]=1;/*顶点v并入s*/
		for(j=0;j<G.n;j++)/*更新当前最短路径及距离*/
		{
			if(!s[j]&&(min+G.arcs[v][j]<dist[j]))
			{
				dist[j]=min+G.arcs[v][j];
				path[j]=v;
			}
		}
	}
}
//【算法6-16：输出源点v0到其余顶点的最短路径和路径长度】
void DisplayPath(Graph G,int v0,int path[],int dist[])
/*输出源点v0到其余顶点的最短路径和路径长度*/
{
	int i,next;
	for(i=0;i<G.n;i++)
	{
		if(dist[i]< Max &&i!=v0)
		{
			printf("V%d<--",i);
			next=path[i];
			while(next!=v0)
			{
				printf("V%d<--",next);
				next=path[next];
			}
			printf("V%d:%d\n",v0,dist[i]);
		}
		else
			if(i!=v0)printf("V%d<--V%d:no path\n",i,v0);
	}
}
//【主函数】
void main()
{
	int path[MAXSIZE];
	int dist[MAXSIZE];
	Graph G;
	system("title 第6章 图-求最短路径");
	CreateAdj(&G);/* 算法6-3，创建有向网的邻接矩阵*/
	Dijkstra(G,0,path,dist);/*算法6-15*/
	DisplayPath(G,0,path,dist); /*算法6-16*/
}
