#include<stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef char ElemType;//默认定义顶点类型为char
//边结点的类型定义
typedef struct ArcNode
{
	int adjVex;//存放与 邻接的点的序号
	struct ArcNode *nextArc;//指向Vi下一个邻接点的边结点
	int weight;/*权值*/
}ArcNode;
//顶点结点类型定义
typedef struct VNode
{
	ElemType data; //存储顶点的名称或其相关信息
	ArcNode *firstArc;//指向顶点Vi的第一个邻接点的边结点
}VNode;
//图的邻接表数据类型
typedef struct 
{
	VNode  adjList[MAXSIZE];//顶点结点信息
	int n,e;//图的顶点数和弧数
}ALGraph;

//在图G中查找顶点v,找到后返回其在顶点数组中的索引号，若不存在，返回-1
int LocateVex(ALGraph G,ElemType v)
{
	int i;
	for(i=0;i<G.n;i++)
		if(G.adjList[i].data==v)return i;
	return -1;
}
//在屏幕上显示图G的邻接表表示
void DisplayAdjList(ALGraph G)
{
	int i;
	ArcNode *p;
	printf("图的邻接表表示：");
	for(i=0;i<G.n;i++){
		printf("\n%4c",G.adjList[i].data);
		p=G.adjList[i].firstArc;
		while(p!=NULL){
			printf("-->%d",p->adjVex);p=p->nextArc;
		}
	}
	printf("\n");
}
//创建无向图的邻接表
void CreateLink(ALGraph *pg)
{
	int i,j,k;
	ElemType v1,v2;
	ArcNode *s;
	printf("请输入图的顶点数及边数\n");
	printf("顶点数 n=");scanf("%d",&pg->n);
	printf("边  数 e=");scanf("%d",&pg->e);
	printf("请输入图的顶点信息：\n");getchar();
	for(i=0;i<=pg->n;i++){
		scanf("%c",&pg->adjList[i].data); //构造顶点信息
		pg->adjList[i].firstArc=NULL;
	}
	printf("请输入图的边的信息：\n");
	for(k=0;k<pg->e;k++)
	{
		printf("请输入第%d条边的两个端点：",k+1);
		scanf("%c%c",&v1,&v2);getchar();//输入一条边的两个顶点
         //确定两个顶点在图G中的位置
		i=LocateVex(*pg,v1);j=LocateVex(*pg,v2);
		/*if(i>=0&&j>=0){
			s=(ArcNode *)malloc(sizeof(ArcNode));
			s->adjVex=j;
			s->nextArc=pg->adjList[i].firstArc;
			pg->adjList[i].firstArc=s;
			s=(ArcNode *)malloc(sizeof(ArcNode));
			s->adjVex=i;
			s->nextArc=pg->adjList[j].firstArc;
			pg->adjList[j].firstArc=s;
		}*/
		
		if(i>=0&&j>=0){ //建立有向图的邻接表
			s=(ArcNode *)malloc(sizeof(ArcNode));
			s->adjVex=j;
			s->nextArc=pg->adjList[i].firstArc;
			pg->adjList[i].firstArc=s;
		}



	}
}
int main()
{
	ALGraph G;
	system("title 第6章 图-有向图的邻接表");
	CreateLink(&G);//创建无向图的邻接表，算法6-6
	DisplayAdjList(G); //在屏幕上显示图邻接表表示，算法6-5
	return 0;
}
