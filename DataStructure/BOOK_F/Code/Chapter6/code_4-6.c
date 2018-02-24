#include<stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef char ElemType;//Ĭ�϶��嶥������Ϊchar
//�߽������Ͷ���
typedef struct ArcNode
{
	int adjVex;//����� �ڽӵĵ�����
	struct ArcNode *nextArc;//ָ��Vi��һ���ڽӵ�ı߽��
	int weight;/*Ȩֵ*/
}ArcNode;
//���������Ͷ���
typedef struct VNode
{
	ElemType data; //�洢��������ƻ��������Ϣ
	ArcNode *firstArc;//ָ�򶥵�Vi�ĵ�һ���ڽӵ�ı߽��
}VNode;
//ͼ���ڽӱ���������
typedef struct 
{
	VNode  adjList[MAXSIZE];//��������Ϣ
	int n,e;//ͼ�Ķ������ͻ���
}ALGraph;

//��ͼG�в��Ҷ���v,�ҵ��󷵻����ڶ��������е������ţ��������ڣ�����-1
int LocateVex(ALGraph G,ElemType v)
{
	int i;
	for(i=0;i<G.n;i++)
		if(G.adjList[i].data==v)return i;
	return -1;
}
//����Ļ����ʾͼG���ڽӱ��ʾ
void DisplayAdjList(ALGraph G)
{
	int i;
	ArcNode *p;
	printf("ͼ���ڽӱ��ʾ��");
	for(i=0;i<G.n;i++){
		printf("\n%4c",G.adjList[i].data);
		p=G.adjList[i].firstArc;
		while(p!=NULL){
			printf("-->%d",p->adjVex);p=p->nextArc;
		}
	}
	printf("\n");
}
//��������ͼ���ڽӱ�
void CreateLink(ALGraph *pg)
{
	int i,j,k;
	ElemType v1,v2;
	ArcNode *s;
	printf("������ͼ�Ķ�����������\n");
	printf("������ n=");scanf("%d",&pg->n);
	printf("��  �� e=");scanf("%d",&pg->e);
	printf("������ͼ�Ķ�����Ϣ��\n");getchar();
	for(i=0;i<=pg->n;i++){
		scanf("%c",&pg->adjList[i].data); //���춥����Ϣ
		pg->adjList[i].firstArc=NULL;
	}
	printf("������ͼ�ıߵ���Ϣ��\n");
	for(k=0;k<pg->e;k++)
	{
		printf("�������%d���ߵ������˵㣺",k+1);
		scanf("%c%c",&v1,&v2);getchar();//����һ���ߵ���������
         //ȷ������������ͼG�е�λ��
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
		
		if(i>=0&&j>=0){ //��������ͼ���ڽӱ�
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
	system("title ��6�� ͼ-����ͼ���ڽӱ�");
	CreateLink(&G);//��������ͼ���ڽӱ��㷨6-6
	DisplayAdjList(G); //����Ļ����ʾͼ�ڽӱ��ʾ���㷨6-5
	return 0;
}
