#include<stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef char ElemType;//默认定义顶点类型为char
typedef struct
{
	ElemType  V[MAXSIZE];//顶点信息
	int arcs[MAXSIZE][MAXSIZE];//邻接矩阵
	int e;//边数
	int n;//顶点数
}Graph;//图的邻接矩阵数据类型

//在图中查找顶点v,找到后返回其在顶点数组中的索引号，若不存在，返回-1
int LocateVex(Graph G,ElemType v)
{
	int i;
	for(i=0;i<G.n;i++)if(G.V[i]==v)return i;
	return -1;
}
//在屏幕上显示图G的邻接矩阵表示
void DisplayAdjMatrix(Graph G)
{
	int i,j;
	printf("图的邻接矩阵表示：\n");
	for(i=0;i<G.n;i++){
		for(j=0;j<G.n;j++){
			printf("%3d",G.arcs[i][j]);
		}
		printf("\n");
	}
}

//创建无向图的邻接矩阵
void CreateAdj(Graph *pg)
{
	int i,j,k,w;
	ElemType v1,v2;
	printf("请输入图的顶点数及边数\n");
	printf("顶点数 n=");scanf("%d",&pg->n);
	printf("边  数 e=");scanf("%d",&pg->e);
	printf("请输入图的顶点信息：\n");getchar();
	for(i=0;i<=pg->n;i++)scanf("%c",&pg->V[i]); //构造顶点信息
	for(i=0;i<pg->n;i++)
		for(j=0;j<pg->n;j++)
			pg->arcs[i][j]=0;//初始化邻接矩阵
    printf("请输入图的边的信息：\n");
	/*for(k=0;k<pg->e;k++)
	{
		printf("请输入第%d条边的两个端点：",k+1);
		scanf("%c%c",&v1,&v2);getchar();//输入一条边的两个顶点
		//确定两个顶点在图G中的位置
		i=LocateVex(*pg,v1);j=LocateVex(*pg,v2);
		if(i>=0&&j>=0){
			pg->arcs[i][j]=1;
			pg->arcs[j][i]=1;
		}

		//建立有向图的邻接矩阵
		//if(i>=0&&j>=0)pg->arcs[i][j]=1;
	}*/

	//建立有向网的邻接矩阵
	for(k=0;k<pg->e;k++)
	{
		printf("请输入第%d条边的两个端点,及权值：",k+1);
		scanf("%c%c%d",&v1,&v2,&w);//输入一条边的两个顶点
		fflush(stdin);
        /*确定两个顶点在图G中的位置*/
		i=LocateVex(*pg,v1);j=LocateVex(*pg,v2);
		if(i>=0&&j>=0)pg->arcs[i][j]=w;
	}

}
int main()
{

	Graph G;
	system("title 第6章 图-有向网的邻接矩阵");
	CreateAdj(&G);//创建无向图的邻接矩阵
	DisplayAdjMatrix(G);//在屏幕上显示该图的邻接矩阵表示
	return 0;
}

