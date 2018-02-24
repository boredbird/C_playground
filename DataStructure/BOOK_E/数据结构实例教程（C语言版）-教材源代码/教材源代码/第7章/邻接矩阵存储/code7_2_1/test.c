#include "stdio.h"
#define Num 100 
typedef struct 
{
	char vexs[Num];// vexs���ڴ�Ŷ�����Ϣ
	int edges[Num][Num];//�ڽӾ���edges�洢����Ϣ
	int n,e;//�ֱ����ͼ�Ķ������ͱ��� 
}MGraph;//�ṹ������
void CreateMGraph(MGraph *G)
{
	int i,j,k;
	printf("�����붥�����ͱ���:");
	scanf("%d,%d",&G->n,&G->e); //���붥�����ͱ���
	getchar();
	printf("�����붥����Ϣ:");
	for(i=0;i<G->n;i++)
		G->vexs[i]=getchar(); //���붥����Ϣ
	for(i=0;i<G->n;i++)
		for(j=0;j<G->n;j++)
			G->edges[i][j]=0;  //�ڽӾ����ʼ��
	for(k=0;k<G->e;k++)  
	{
		printf("�������<i,j>�����:");
		scanf("%d,%d",&i,&j);  //����ߵ�һ�Զ������
		G->edges[i][j]=1;
		G->edges[j][i]=1;
	}
    printf("ͼ���ڽӾ���Ϊ:\n");
	for(i=0;i<G->n;i++)
	{
		for(j=0;j<G->n;j++)
			printf("%3d",G->edges[i][j]);
		printf("\n");
	}
}
main()
{
  MGraph g;
  CreateMGraph(&g);
}