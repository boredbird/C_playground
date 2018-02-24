#include "stdio.h"
#include "string.h"
#define Num 10
//���ν�ͨͼ�ṹ��
typedef struct
{
	char citys[Num][8]; //�洢�������ƣ�NumΪ��ͨͼ������������������
	float time[Num][Num];//���þ���洢��ʻÿ����·���ѵ�ʱ��
	int citynum,roadnum;//���������ͳ��м��·������
}mgraph;
int path[Num][Num];
//�����ڽӾ��󴴽����ν�ͨͼ
void create_net(mgraph *g)
{
   int i,j,k;
   float t;
   printf("��������������͵�·����:");
   scanf("%d,%d",&g->citynum,&g->roadnum);
   getchar();
   for(i=1;i<=g->citynum;i++)//���������Ϣ
   {
	   printf("��%d��������Ϣ:",i);
	   gets(g->citys[i]);
   }
   for(i=1;i<=g->citynum;i++)//��ʼ������
	   for(j=1;j<=g->citynum;j++)
	     g->time[i][j]=999; //����999���Ǿ����еġ�
   for(k=1;k<=g->roadnum;k++)//����ߵ���Ϣ��ÿ����·���ѵ�ʱ��
   {
	   printf("�����%d����·�������յ�ı��:",k);
	   scanf("%d,%d",&i,&j);
	   printf("�����·<%d,%d>��ʻ���ѵ�ʱ��:",i,j);
	   scanf("%f",&t);
	   g->time[i][j]=t;
	   g->time[j][i]=t;
   }
}
//��ӡ���ν�ͨͼ��Ϣ
void pri_net(mgraph *g)
{
	int i,j;
	printf("������Ϣ:");
	printf("\n----------------------------------------------\n");
	for(i=1;i<=g->citynum;i++)
		printf("%-6d",i);
    printf("\n----------------------------------------------\n");
	for(i=1;i<=g->citynum;i++)
	    printf("%-6s",g->citys[i]);
	printf("\n----------------------------------------------\n");
	printf("\n��ʻ��·����ʱ����Ϣ:\n");
	printf("   |");
    for(i=1;i<=g->citynum;i++)
		printf("%-6d",i);
	printf("\n----------------------------------------------\n");
    for(i=1;i<=g->citynum;i++)
	{
	   printf("%3d|",i);
	   for(j=1;j<=g->citynum;j++)
	     printf("%-6.1f",g->time[i][j]); 
	   printf("\n");
	}
}
//�õݹ�ʵ�ֱ���·��
void putpath(int i,int j,mgraph *g)
{
	int k;
	k=path[i][j];
	if(k==-1)//û���м��
		return;
	putpath(i,k,g);
	printf("%s->",g->citys[k]);
	putpath(k,j,g);
}
//�����·��
void minpath(mgraph *g)
{
    int i,j,k,c1=0,c2=0;
	float d[Num][Num];
	char city1[8],city2[8];
    for(i=1;i<=g->citynum;i++)
	   for(j=1;j<=g->citynum;j++)
	   {
		   d[i][j]=g->time[i][j];
		   path[i][j]=-1;
	   }
    for(k=1;k<=g->citynum;k++)//��1��2....Ϊ�м��
	{
	   for(i=1;i<=g->citynum;i++)
		   for(j=1;j<=g->citynum;j++)
	        if((d[i][k]+d[k][j]<d[i][j])&&(i!=j)&&(i!=k)&&(j!=k))//����
			{
                d[i][j]=d[i][k]+d[k][j];
				path[i][j]=k;//��¼���·�������Ľ��
			}
	}
	printf("������������������:\n");
	gets(city1);
	gets(city2);
	for(i=1;i<=g->citynum;i++)//���ճ������Ʋ��Ҷ�Ӧ���±�
	{
	   if(strcmp(g->citys[i],city1)==0)
		   c1=i;
       if(strcmp(g->citys[i],city2)==0)
		   c2=i;
	}
	printf("%d,%d\n",c1,c2);
	if(c1==0||c2==0)
		printf("����һ�����в����ڣ�\n");
	else
	{
	    printf("��������·��Ϊ:");
		printf("%s->",g->citys[c1]);
	    putpath(c1,c2,g);
	    printf("%s\n",g->citys[c2]);
	    printf("��ʻ�������ʱ��Ϊ:%-6.1fСʱ\n",d[c1][c2]);
	}
}

main()
{
    int choice;
	mgraph net,*g;
    g=&net;
  	printf("                       ���ʱ������·�߲�ѯϵͳ\n\n");
	printf("**************************************************************************\n");
    printf(" 1.�������ν�ͨͼ 2. ��ӡ���ν�ͨͼ��Ϣ 3.��ѯ���ʱ������·�� 4.�˳�ϵͳ\n");
    printf("**************************************************************************\n");
	while(1)
	{ printf("������ѡ��:");
	  scanf("%d",&choice);
	  getchar();
	  switch(choice)
	  {
	    case 1:create_net(g);break;
		case 2:pri_net(g);break;
		case 3:minpath(g);break;
	  }
	  if(choice==4)
		  break;
	}
}
