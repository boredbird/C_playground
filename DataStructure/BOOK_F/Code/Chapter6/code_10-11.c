#include<stdio.h>
#define MAXSIZE 10
#define QUEUESIZE 100         //���е��������󳤶�
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
	int i,j,k;
	ElemType v1,v2;
	printf("������ͼ�Ķ�����������\n");
	printf("������ n=");scanf("%d",&pg->n);
	printf("��  �� e=");scanf("%d",&pg->e);
	printf("������ͼ�Ķ�����Ϣ��\n");getchar();
	for(i=0;i<=pg->n;i++)scanf("%c",&pg->V[i]); /*���춥����Ϣ*/
	for(i=0;i<pg->n;i++)
		for(j=0;j<pg->n;j++)
			pg->arcs[i][j]=0;/*��ʼ���ڽӾ���*/
    printf("������ͼ�ıߵ���Ϣ��\n");
for(k=0;k<pg->e;k++)
	{
		printf("�������%d���ߵ������˵㣺",k+1);
		scanf("%c%c",&v1,&v2);getchar();/*����һ���ߵ���������*/
/*ȷ������������ͼG�е�λ��*/
		i=LocateVex(*pg,v1);j=LocateVex(*pg,v2);
		if(i>=0&&j>=0)		{
			pg->arcs[i][j]=1;
			pg->arcs[j][i]=1;
		}
	}
}




typedef struct  SqQueue
{
	ElemType  *data;      //���д洢�ռ���׵�ַ
	int front;         //��ͷλ�ã�ָ��ǰ��ͷԪ��
	int rear;    //��βλ�ã�ָ��ǰ��βԪ�ص���һλ��
}SqQueue;             // ѭ������


//����նӣ�����ɹ�������1�����ʧ�ܣ�����0
int InitQueue(SqQueue *Q)
{
	Q->data=(ElemType *)malloc(QUEUESIZE*sizeof(SqQueue));
	if (Q->data==NULL)return 0; // �洢����ʧ�� 
	Q->front=Q->rear=0;	
	return 1;
 }
// ����Ԫ��eΪQ���µĶ�βԪ�� ,����ɹ�������1�����ʧ�ܣ�����0
int EnQueue (SqQueue *Q,ElemType e)
{ 
    if ((Q->rear+1) % QUEUESIZE == Q->front) 
        return 0; //������
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear+1) % QUEUESIZE; //��β����һλ
    return 1;
}
//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ,������1�����򷵻�0
int DeQueue (SqQueue *Q,ElemType *e) 
{
	if (Q->front == Q->rear)  return 0; //����Ϊ��
    *e = Q->data[Q->front];
    Q->front = (Q->front+1) % QUEUESIZE; //��ͷ����һλ
    return 1;
}
//��ջ���գ�����e���ض�ͷԪ��,������1�����򷵻�0
int GetFront(SqQueue Q,ElemType *e)
{
	if (Q.front == Q.rear)  return 0; //����Ϊ��
	*e=Q.data[Q.front];
    return  1;
 }
//������Ϊ��ջ���򷵻�1�����򷵻�0 
int QueueEmpty(SqQueue Q)//ջ�ǿ�
{ 
	if(Q.front == Q.rear)return 1; //����Ϊ��
	else return 0;
}
//���ض��е�Ԫ�ظ����������еĳ���
int QueueLength(SqQueue Q)
{ 
	return (Q.rear-Q.front+QUEUESIZE) % QUEUESIZE;
}
//���㷨6-10�������ڽӾ���ʵ����ͨͼ�Ĺ����������������
int visited[MAXSIZE];
SqQueue Q;
/*�ӵ�k���������������ȱ���ͼG,G���ڽӾ����ʾ��*/
void BFS(Graph G,int k){
	int i,j;	
	InitQueue(&Q);/*��ʼ������*/
	printf("%3c",G.V[k]);/*���ʵ�k������*/
	visited[k]=1;
	EnQueue(&Q,k);/*��k���������*/
	while(QueueEmpty(Q)==0) {/*���зǿ�*/
		DeQueue(&Q,&i);
		for(j=0;j<G.n;j++){
		   if((G.arcs[i][j]==1)&&(visited[j]==0)){
/*���ʵ�i�������ĩ�����ʵĶ���j*/
			    printf("%3c",G.V[j]);
				visited[j]=1;
				EnQueue(&Q,j);/*��k���������*/
			}
		}
	}
}
//���㷨6-11����ͼG���й�����ȱ�����
void BFSTraverse(Graph  G) //��ͼG���й�����ȱ���
{
	int v;
    for (v=0; v<G.n;v++) //��ʼ����־����
        visited[v]=0; 
    for  (v=0; v<G.n;v++) //��֤����ͨͼ�ı���
        if (!visited[v])BFS(G,v); 
       //�ӵ�v����������ݹ��������ȱ���ͼG
}



void main()
{

	Graph G;
	CreateAdj(&G);
	printf("ͼ�Ĺ�����ȱ������У�\n");
	BFSTraverse(G);
	printf("\n");
}