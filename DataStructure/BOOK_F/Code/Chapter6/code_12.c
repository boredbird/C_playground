#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

#define QUEUESIZE 100         //队列的允许的最大长度
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

int visited[MAXSIZE];
SqQueue Q;
//【算法6-12：用邻接表实现连通图的的广度优先搜索遍历】
void BFS(ALGraph G,int k){
	int i;
	ArcNode *p;
	InitQueue(&Q);/*初始化队列*/
	printf("%3c",G.adjList[k].data);/*访问第k个项点*/
	visited[k]=1;	
	EnQueue(&Q,k);/*第k个顶点进队*/
	while(QueueEmpty(Q)==0) {/*队列非空*/
		DeQueue(&Q,&i);
		p=G.adjList[i].firstArc;/*获取第1个邻接点*/
		while(p!=NULL){
			if(visited[p->adjVex]==0){
                /*访问第i个顶点的末曾访问的顶点*/
				printf("%3c",G.adjList[p->adjVex].data);
				visited[p->adjVex]=1;
				EnQueue(&Q,p->adjVex);/*第k个顶点进队*/
			}
			p=p->nextArc;
		}		
	}
}

void BFSTraverse(ALGraph  G) //对图G进行广度优先遍历
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
    ALGraph G;
	CreateLink(&G);
    printf("图的深度优先遍历序列：\n");
	BFSTraverse(G);printf("\n");
}
