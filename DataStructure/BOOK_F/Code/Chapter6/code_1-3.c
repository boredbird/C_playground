#include<stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef char ElemType;//Ĭ�϶��嶥������Ϊchar
typedef struct
{
	ElemType  V[MAXSIZE];//������Ϣ
	int arcs[MAXSIZE][MAXSIZE];//�ڽӾ���
	int e;//����
	int n;//������
}Graph;//ͼ���ڽӾ�����������

//��ͼ�в��Ҷ���v,�ҵ��󷵻����ڶ��������е������ţ��������ڣ�����-1
int LocateVex(Graph G,ElemType v)
{
	int i;
	for(i=0;i<G.n;i++)if(G.V[i]==v)return i;
	return -1;
}
//����Ļ����ʾͼG���ڽӾ����ʾ
void DisplayAdjMatrix(Graph G)
{
	int i,j;
	printf("ͼ���ڽӾ����ʾ��\n");
	for(i=0;i<G.n;i++){
		for(j=0;j<G.n;j++){
			printf("%3d",G.arcs[i][j]);
		}
		printf("\n");
	}
}

//��������ͼ���ڽӾ���
void CreateAdj(Graph *pg)
{
	int i,j,k,w;
	ElemType v1,v2;
	printf("������ͼ�Ķ�����������\n");
	printf("������ n=");scanf("%d",&pg->n);
	printf("��  �� e=");scanf("%d",&pg->e);
	printf("������ͼ�Ķ�����Ϣ��\n");getchar();
	for(i=0;i<=pg->n;i++)scanf("%c",&pg->V[i]); //���춥����Ϣ
	for(i=0;i<pg->n;i++)
		for(j=0;j<pg->n;j++)
			pg->arcs[i][j]=0;//��ʼ���ڽӾ���
    printf("������ͼ�ıߵ���Ϣ��\n");
	/*for(k=0;k<pg->e;k++)
	{
		printf("�������%d���ߵ������˵㣺",k+1);
		scanf("%c%c",&v1,&v2);getchar();//����һ���ߵ���������
		//ȷ������������ͼG�е�λ��
		i=LocateVex(*pg,v1);j=LocateVex(*pg,v2);
		if(i>=0&&j>=0){
			pg->arcs[i][j]=1;
			pg->arcs[j][i]=1;
		}

		//��������ͼ���ڽӾ���
		//if(i>=0&&j>=0)pg->arcs[i][j]=1;
	}*/

	//�������������ڽӾ���
	for(k=0;k<pg->e;k++)
	{
		printf("�������%d���ߵ������˵�,��Ȩֵ��",k+1);
		scanf("%c%c%d",&v1,&v2,&w);//����һ���ߵ���������
		fflush(stdin);
        /*ȷ������������ͼG�е�λ��*/
		i=LocateVex(*pg,v1);j=LocateVex(*pg,v2);
		if(i>=0&&j>=0)pg->arcs[i][j]=w;
	}

}
int main()
{

	Graph G;
	system("title ��6�� ͼ-���������ڽӾ���");
	CreateAdj(&G);//��������ͼ���ڽӾ���
	DisplayAdjMatrix(G);//����Ļ����ʾ��ͼ���ڽӾ����ʾ
	return 0;
}

