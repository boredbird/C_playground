#include<stdio.h>
#define MAXSIZE 10
typedef char ElemType;/*���嶥������Ϊchar*/
int Max=999;
typedef struct
{
	ElemType  V[MAXSIZE];/*������Ϣ*/
	int arcs[MAXSIZE][MAXSIZE];/*�ڽӾ���*/
	int e;/*����*/
	int n;/*������*/
}Graph;/*ͼ���ڽӾ�����������*/
/*��ͼG�в��Ҷ���v,�ҵ��󷵻����ڶ��������е������ţ��������ڣ�����-1*/
int LocateVex(Graph G,ElemType v)
{
	int i;
	for(i=0;i<G.n;i++)
	{
		if(G.V[i]==v)return i;
	}
	return -1;

}
/*����Ļ����ʾͼG���ڽӾ����ʾ*/
void DisplayAdjMatrix(Graph G)
{
	int i,j;
	printf("ͼ���ڽӾ����ʾ��\n");
	for(i=0;i<G.n;i++)
	{
		for(j=0;j<G.n;j++)
		{
		
			printf("%3d",G.arcs[i][j]);
			
		}
		printf("\n");
	}
}
/*��������ͼ���ڽӾ���*/
void CreateAdj(Graph *pg)
{
	int i,j,k,w;
	ElemType v1,v2;
	printf("������ͼ�Ķ�����������\n");
	printf("������ n=");scanf("%d",&pg->n);
	printf("��  �� e=");scanf("%d",&pg->e);
	printf("������ͼ�Ķ�����Ϣ��\n");getchar();
	for(i=0;i<=pg->n;i++)scanf("%c",&pg->V[i]); /*���춥����Ϣ*/
	for(i=0;i<pg->n;i++)
		for(j=0;j<pg->n;j++)
			pg->arcs[i][j]=Max;/*��ʼ���ڽӾ���*/
    printf("������ͼ�ıߵ���Ϣ��\n");
    for(k=0;k<pg->e;k++)
	{
		printf("�������%d���ߵ������˵�,��Ȩֵ��",k+1);
		scanf("%c%c%d",&v1,&v2,&w);/*����һ���ߵ���������*/
		getchar();
        /*ȷ������������ͼG�е�λ��*/
		i=LocateVex(*pg,v1);j=LocateVex(*pg,v2);
		if(i>=0&&j>=0)pg->arcs[i][j]=w;
	}

}

//���㷨6-15���Ͻ�˹�����㷨��
void Dijkstra(Graph G,int v0,int path[],int dist[])
/*������ͼG��v0���㵽���ඥ��v�����·����path[i]��v0��vi�����·���ϵ�ǰ�����㣬dist[i]��·������*/
{
	int i,j,v,w;
	int min;
	int s[MAXSIZE];
	for(i=0;i<G.n;i++)/*��ʼ��s��dist��path*/
	{
		s[i]=0;
		dist[i]=G.arcs[v0][i];
		if(dist[i]<Max)path[i]=v0;
		else path[i]=-1;
	}
	dist[v0]=0;s[v0]=1;/*��ʼʱԴ��v0����s��*/
	/*ѭ����v0��ĳ������v�����·��������v����s��*/
	for(i=1;i<G.n-1;i++)
	{
		min= Max;
		for(w=0;w<G.n;w++)
		{
			/*����w������s������v0����*/
			if(!s[w]&&dist[w]<min)
			{
				v=w;min=dist[w];
			}
		}
		s[v]=1;/*����v����s*/
		for(j=0;j<G.n;j++)/*���µ�ǰ���·��������*/
		{
			if(!s[j]&&(min+G.arcs[v][j]<dist[j]))
			{
				dist[j]=min+G.arcs[v][j];
				path[j]=v;
			}
		}
	}
}
//���㷨6-16�����Դ��v0�����ඥ������·����·�����ȡ�
void DisplayPath(Graph G,int v0,int path[],int dist[])
/*���Դ��v0�����ඥ������·����·������*/
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
//����������
void main()
{
	int path[MAXSIZE];
	int dist[MAXSIZE];
	Graph G;
	system("title ��6�� ͼ-�����·��");
	CreateAdj(&G);/* �㷨6-3���������������ڽӾ���*/
	Dijkstra(G,0,path,dist);/*�㷨6-15*/
	DisplayPath(G,0,path,dist); /*�㷨6-16*/
}
