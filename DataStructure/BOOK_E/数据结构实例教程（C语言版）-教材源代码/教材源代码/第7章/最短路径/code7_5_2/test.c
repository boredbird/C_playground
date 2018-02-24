#include "stdio.h"
#define Maxsize 10
//ͼ�Ľṹ��
typedef struct
{
	int vexs[Maxsize]; //MaxsizeΪ��������
	int arcs[Maxsize][Maxsize];
	int vexnum,arcnum;
}mgraph;
int path[Maxsize][Maxsize];
//�����ڽӾ��󴴽�ͼ
void create_net(mgraph *g)
{
   int i,j,k,n;
   printf("�����붥�����ͱ���:");
   scanf("%d,%d",&i,&j);
   g->vexnum=i;
   g->arcnum=j;
   for(i=1;i<=g->vexnum;i++)//���붥����Ϣ
   {
	   printf("��%d���������Ϣ:",i);
	   scanf("%d",&g->vexs[i]);
   }
   for(i=1;i<=g->vexnum;i++)//��ʼ������
	   for(j=1;j<=g->vexnum;j++)
	     g->arcs[i][j]=999; //����999���Ǿ����еġ�
   for(k=1;k<=g->arcnum;k++)//����ߵ���Ϣ��Ȩֵ
   {
	   printf("�����%d���ߵ������յ�ı��:",k);
	   scanf("%d,%d",&i,&j);
	   printf("�����<%d,%d>��Ȩֵ",i,j);
	   scanf("%d",&n);
	   g->arcs[i][j]=n;
   }
}
//�õݹ�ʵ�ֱ���·��
void putpath(int i,int j)
{
	int k;
	k=path[i][j];
	if(k==-1)//û���м��
	  return;
	putpath(i,k);
	printf("%d->",k);
	putpath(k,j);
}
//�����·��
void minpath(mgraph *g)
{
   int d[5][5],i,j,k;
   for(i=1;i<=g->vexnum;i++)
	   for(j=1;j<=g->vexnum;j++)
	   {
		   d[i][j]=g->arcs[i][j];
		   path[i][j]=-1;
	   }
   for(k=1;k<=g->vexnum;k++)//��1��2....Ϊ�м��
	{
	   for(i=1;i<=g->vexnum;i++)
		   for(j=1;j<=g->vexnum;j++)
	        if((d[i][k]+d[k][j]<d[i][j])&&(i!=j)&&(i!=k)&&(j!=k))//����
			{
               d[i][j]=d[i][k]+d[k][j];
				printf("%d",d[i][j]);
				path[i][j]=k;//��¼���·�������Ľ��
			}
	}
	printf("\n������·��:\n");
	for(i=1;i<=g->vexnum;i++)
	   for(j=1;j<=g->vexnum;j++)
	   {
		   if(i==j)
			continue;
		   printf("%d->",i);
		   putpath(i,j);
		   printf("%d",j);
		   printf("���·��Ϊ:%d\n",d[i][j]);
	   }
}
main()
{
  mgraph net,*g;
  g=&net;
  create_net(g);
  minpath(g);
}
