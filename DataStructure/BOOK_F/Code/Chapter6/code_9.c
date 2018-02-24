#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef char ElemType;/*���嶥������Ϊchar*/
/*�߽������Ͷ���*/
typedef struct ArcNode
{
	int adjVex;
	struct ArcNode *nextArc;
	int weight;
}ArcNode;
/*���������Ͷ���*/
typedef struct VNode
{
	ElemType data;
	ArcNode *firstArc;
}VNode;
/*ͼ���ڽӱ���������*/
typedef struct 
{
	VNode  adjList[MAXSIZE];
	int n,e;/*ͼ�Ķ������ͻ���*/
}ALGraph;

/*��ͼG�в��Ҷ���v,�ҵ��󷵻����ڶ��������е������ţ��������ڣ�����-1*/
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
	printf("������ͼ�Ķ�����������\n");
	printf("������ n=");scanf("%d",&pg->n);
	printf("��  �� e=");scanf("%d",&pg->e);
	printf("������ͼ�Ķ�����Ϣ��\n");getchar();
	for(i=0;i<=pg->n;i++)
	{
		scanf("%c",&pg->adjList[i].data); /*���춥����Ϣ*/
		pg->adjList[i].firstArc=NULL;
	}
	printf("������ͼ�ıߵ���Ϣ��\n");
	for(k=0;k<pg->e;k++)
	{
		printf("�������%d���ߵ������˵㣺",k+1);
		scanf("%c%c",&v1,&v2);getchar();/*����һ���ߵ���������*/
         /*ȷ������������ͼG�е�λ��*/
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


/*����Ļ����ʾͼG���ڽӾ����ʾ*/
void DisplayAdjList(ALGraph G)
{
	int i;
	ArcNode *p;
	printf("ͼ���ڽӱ��ʾ��");
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
int visited[MAXSIZE];/* ���ʱ�־����*/
 /*�ӵ�i����������ݹ��������ȱ���ͼG*/
//���㷨6-9�����ڽӱ�ʵ����ͨͼ�ı�����
void DFS(ALGraph G,int i)
{
	ArcNode *p;
	printf("%3c",G.adjList[i].data);/*���ʵ�i�����*/
	visited[i]=1;
	p=G.adjList[i].firstArc;
	while(p!=NULL)	{
		if(visited[p->adjVex]==0)
		  DFS(G,p->adjVex);/*��i����δ���ʵ��ڽӶ���j�ݹ����DFS*/
		p=p->nextArc;
	}
}

void DFSTraverse(ALGraph  G) /*��ͼG����������ȱ���*/
{
	int v;
    for (v=0; v<G.n;v++)visited[v]=0; /*��ʼ����־����*/
    for  (v=0; v<G.n;v++) /*��֤����ͨͼ�ı���*/
/*�ӵ�v����������ݹ��������ȱ���ͼG*/
        if (!visited[v])DFS(G,v);        
}

void main()
{
    ALGraph G;
	CreateLink(&G);
    printf("ͼ��������ȱ������У�\n");
	DFSTraverse(G);printf("\n");
}
