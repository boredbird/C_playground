#include<stdio.h>
#define MAXSIZE 10
#define QUEUESIZE 100         //队列的允许的最大长度
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
	int i,j,k;
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




typedef struct  SqQueue
{
	ElemType  *data;      //队列存储空间的首地址
	int front;         //队头位置：指向当前队头元素
	int rear;    //队尾位置：指向当前队尾元素的下一位置
}SqQueue;             // 循环队列


//构造空队，如果成功，返回1，如果失败，返回0
int InitQueue(SqQueue *Q)
{
	Q->data=(ElemType *)malloc(QUEUESIZE*sizeof(SqQueue));
	if (Q->data==NULL)return 0; // 存储分配失败 
	Q->front=Q->rear=0;	
	return 1;
 }
// 插入元素e为Q的新的队尾元素 ,如果成功，返回1，如果失败，返回0
int EnQueue (SqQueue *Q,ElemType e)
{ 
    if ((Q->rear+1) % QUEUESIZE == Q->front) 
        return 0; //队列满
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1) % QUEUESIZE; //队尾后移一位
    return 1;
}
//若队列不空，则删除Q的队头元素，用e返回其值,并返回1；否则返回0
int DeQueue (SqQueue *Q,ElemType *e) 
{
	if (Q->front == Q->rear)  return 0; //队列为空
    *e = Q->data[Q->front];
    Q->front = (Q->front+1) % QUEUESIZE; //队头后移一位
    return 1;
}
//若栈不空，则用e返回队头元素,并返回1；否则返回0
int GetFront(SqQueue Q,ElemType *e)
{
	if (Q.front == Q.rear)  return 0; //队列为空
	*e=Q.data[Q.front];
    return  1;
 }
//若队列为空栈，则返回1，否则返回0 
int QueueEmpty(SqQueue Q)//栈非空
{ 
	if(Q.front == Q.rear)return 1; //队列为空
	else return 0;
}
//返回队列的元素个数，即队列的长度
int QueueLength(SqQueue Q)
{ 
	return (Q.rear-Q.front+QUEUESIZE) % QUEUESIZE;
}
//【算法6-10：利用邻接矩阵实现连通图的广度优先搜索遍历】
int visited[MAXSIZE];
SqQueue Q;
/*从第k个顶点出发广度优先遍历图G,G以邻接矩阵表示。*/
void BFS(Graph G,int k){
	int i,j;	
	InitQueue(&Q);/*初始化队列*/
	printf("%3c",G.V[k]);/*访问第k个顶点*/
	visited[k]=1;
	EnQueue(&Q,k);/*第k个顶点进队*/
	while(QueueEmpty(Q)==0) {/*队列非空*/
		DeQueue(&Q,&i);
		for(j=0;j<G.n;j++){
		   if((G.arcs[i][j]==1)&&(visited[j]==0)){
/*访问第i个顶点的末曾访问的顶点j*/
			    printf("%3c",G.V[j]);
				visited[j]=1;
				EnQueue(&Q,j);/*第k个顶点进队*/
			}
		}
	}
}
//【算法6-11：对图G进行广度优先遍历】
void BFSTraverse(Graph  G) //对图G进行广度优先遍历
{
	int v;
    for (v=0; v<G.n;v++) //初始化标志数组
        visited[v]=0; 
    for  (v=0; v<G.n;v++) //保证非连通图的遍历
        if (!visited[v])BFS(G,v); 
       //从第v个顶点出发递归地深度优先遍历图G
}



void main()
{

	Graph G;
	CreateAdj(&G);
	printf("图的广度优先遍历序列：\n");
	BFSTraverse(G);
	printf("\n");
}