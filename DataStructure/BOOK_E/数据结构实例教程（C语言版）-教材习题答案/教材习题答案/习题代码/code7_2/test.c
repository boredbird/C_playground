#include "stdio.h"
#include "stdlib.h"
int visited[10];
typedef struct 
{
   char vexs[10];
   int edges[10][10];
   int n,e;//�ֱ����ͼ�Ķ������ͱ��� 
}MGraph;//�ṹ������

void CreateMGraph(MGraph *G)
{
    int i,j,k;
    scanf("%d,%d",&G->n,&G->e); //���붥�����ͱ���
    getchar();
    for(i=0;i<G->n;i++)
      G->vexs[i]=getchar(); //���붥����Ϣ
    for(i=0;i<G->n;i++)
      for(j=0;j<G->n;j++)
        G->edges[i][j]=0;  //�ڽӾ����ʼ��
    printf("������һ�Զ�������:\n");
	for(k=0;k<G->e;k++)  
	{
	 scanf("%d,%d",&i,&j);  //����ߵ�һ�Զ������
     G->edges[i][j]=1;
     G->edges[j][i]=1;
	}
}
void dfs(MGraph *G,int i)
{
	int j;
	printf("%c",G->vexs[i]);
	visited[i]=1;
	for(j=0;j<G->n;j++)
		if(G->edges[i][j]==1&&visited[j]==0)
			dfs(G,j);
}
void dfstraverse(MGraph *G)
{
  int i;
  for(i=0;i<G->n;i++)
	  visited[i]=0;//��ʼ����δ�����ʹ�
  for(i=0;i<G->n;i++)
	  if(visited[i]==0)//δ�����ʹ�
		  dfs(G,i);
}


main()
{
    MGraph *G,ag;
	G=&ag;
	CreateMGraph(G);
	dfstraverse(G);
}



