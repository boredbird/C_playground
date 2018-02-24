#include<stdio.h>
#define MAXSIZE 10
typedef char ElemType;/*���嶥������Ϊchar*/
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
			pg->arcs[i][j]=999;/*��ʼ���ڽӾ���*/
    printf("������ͼ�ıߵ���Ϣ��\n");
    for(k=0;k<pg->e;k++)
	{
		printf("�������%d���ߵ������˵�,��Ȩֵ��",k+1);
		scanf("%c%c%d",&v1,&v2,&w);/*����һ���ߵ���������*/
		getchar();
        /*ȷ������������ͼG�е�λ��*/
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
//���㷨6-13�����������V-U�����ڶ���u��u��U����Ȩֵ��С�Ķ������š�
/*�ڸ������������Ȩֵ��С�Ķ������*/
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

//���㷨6-12������ķ�㷨��
/*�Ӷ���V����������G����С���������������С�������ĸ�����*/
void MiniSpanTree_PRIM(Graph G,ElemType v)
{
	int i,j,k;
	closedge dge[MAXSIZE];
	k=LocateVex(G,v);/*ȷ������v����G�е����*/
	for(j=0;j<G.n;j++){/*��ʼ����������*/
		if(j!=k){
			dge[j].adjvax=v;
			dge[j].lowcost=G.arcs[k][j];
		}
	}
/*��ʼ�������������ϣ�lowcostֵΪ0����ʾ�ö����Ѳ�������������*/
	dge[k].lowcost=0;
	for(i=0;i<G.n-1;i++){
		k=Mininum(G,dge);/*����������Ȩֵ��С�Ķ���*/
/*������С��������һ���ߺͶ�ӦȨֵ*/
        printf("(%c,%c,%d)",
dge[k].adjvax,G.V[k],dge[k].lowcost);
		dge[k].lowcost=0;/*������k��������������*/
		for(j=0;j<G.n;j++){/*���µ���dge*/
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
