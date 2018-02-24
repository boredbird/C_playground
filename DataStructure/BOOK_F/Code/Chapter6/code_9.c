#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef char ElemType;/*定义顶点类型为char*/
/*边结点的类型定义*/
typedef struct ArcNode
{
	int adjVex;
	struct ArcNode *nextArc;
	int weight;
}ArcNode;
/*顶点结点类型定义*/
typedef struct VNode
{
	ElemType data;
	ArcNode *firstArc;
}VNode;
/*图的邻接表数据类型*/
typedef struct 
{
	VNode  adjList[MAXSIZE];
	int n,e;/*图的顶点数和弧数*/
}ALGraph;

/*在图G中查找顶点v,找到后返回其在顶点数组中的索引号，若不存在，返回-1*/
int LocateVex(ALGraph G,ElemType v)
{
	int i;
	for(i=0;i<G.n;i++)
	{
		if(G.adjList[i].data==v)return i;
	}
	return -1;

}
void CreateLink(ALGraph *pg)
{
	int i,j,k;
	ElemType v1,v2;
	ArcNode *s;
	printf("请输入图的顶点数及边数\n");
	printf("顶点数 n=");scanf("%d",&pg->n);
	printf("边  数 e=");scanf("%d",&pg->e);
	printf("请输入图的顶点信息：\n");getchar();
	for(i=0;i<=pg->n;i++)
	{
		scanf("%c",&pg->adjList[i].data); /*构造顶点信息*/
		pg->adjList[i].firstArc=NULL;
	}
	printf("请输入图的边的信息：\n");
	for(k=0;k<pg->e;k++)
	{
		printf("请输入第%d条边的两个端点：",k+1);
		scanf("%c%c",&v1,&v2);getchar();/*输入一条边的两个顶点*/
         /*确定两个顶点在图G中的位置*/
		i=LocateVex(*pg,v1);j=LocateVex(*pg,v2);
		if(i>=0&&j>=0)
		{
			s=(ArcNode *)malloc(sizeof(ArcNode));
			s->adjVex=j;
			s->nextArc=pg->adjList[i].firstArc;
			pg->adjList[i].firstArc=s;
		}
	}


}


/*在屏幕上显示图G的邻接矩阵表示*/
void DisplayAdjList(ALGraph G)
{
	int i;
	ArcNode *p;
	printf("图的邻接表表示：");
	for(i=0;i<G.n;i++)
	{
		printf("\n%4c",G.adjList[i].data);
		p=G.adjList[i].firstArc;
		while(p!=NULL)
		{
			printf("-->%d",p->adjVex);p=p->nextArc;
		}
		
		
	}
	printf("\n");
}
int visited[MAXSIZE];/* 访问标志数组*/
 /*从第i个顶点出发递归地深度优先遍历图G*/
//【算法6-9：用邻接表实现连通图的遍历】
void DFS(ALGraph G,int i)
{
	ArcNode *p;
	printf("%3c",G.adjList[i].data);/*访问第i个项点*/
	visited[i]=1;
	p=G.adjList[i].firstArc;
	while(p!=NULL)	{
		if(visited[p->adjVex]==0)
		  DFS(G,p->adjVex);/*对i的尚未访问的邻接顶点j递归调用DFS*/
		p=p->nextArc;
	}
}

void DFSTraverse(ALGraph  G) /*对图G进行深度优先遍历*/
{
	int v;
    for (v=0; v<G.n;v++)visited[v]=0; /*初始化标志数组*/
    for  (v=0; v<G.n;v++) /*保证非连通图的遍历*/
/*从第v个顶点出发递归地深度优先遍历图G*/
        if (!visited[v])DFS(G,v);        
}

void main()
{
    ALGraph G;
	CreateLink(&G);
    printf("图的深度优先遍历序列：\n");
	DFSTraverse(G);printf("\n");
}
