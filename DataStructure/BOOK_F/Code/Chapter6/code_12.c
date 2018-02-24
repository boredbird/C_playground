#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

#define QUEUESIZE 100         //���е��������󳤶�
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

int visited[MAXSIZE];
SqQueue Q;
//���㷨6-12�����ڽӱ�ʵ����ͨͼ�ĵĹ����������������
void BFS(ALGraph G,int k){
	int i;
	ArcNode *p;
	InitQueue(&Q);/*��ʼ������*/
	printf("%3c",G.adjList[k].data);/*���ʵ�k�����*/
	visited[k]=1;	
	EnQueue(&Q,k);/*��k���������*/
	while(QueueEmpty(Q)==0) {/*���зǿ�*/
		DeQueue(&Q,&i);
		p=G.adjList[i].firstArc;/*��ȡ��1���ڽӵ�*/
		while(p!=NULL){
			if(visited[p->adjVex]==0){
                /*���ʵ�i�������ĩ�����ʵĶ���*/
				printf("%3c",G.adjList[p->adjVex].data);
				visited[p->adjVex]=1;
				EnQueue(&Q,p->adjVex);/*��k���������*/
			}
			p=p->nextArc;
		}		
	}
}

void BFSTraverse(ALGraph  G) //��ͼG���й�����ȱ���
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
    ALGraph G;
	CreateLink(&G);
    printf("ͼ��������ȱ������У�\n");
	BFSTraverse(G);printf("\n");
}
