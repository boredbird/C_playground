#include "stdio.h"
#include "stdlib.h"
//0���Ͼ�  1������  2������   3������  4������  5�����Ƹ�  6������  7����ͨ  8���γ�
int visited[10]={0};
typedef struct node
{
	int cityid;
	struct node *next;
}Anode;
typedef struct
{
	char city[10];
	Anode *first;
}Vnode;
typedef struct
{
	Vnode citys[10];
	int n,e;//n������������e���������
}Map;
//��ͼ�Ľ���
Map creat()
{
  Anode *p;
  int i,s,d;
  Map map;
  printf("��������к͹�·��������");
  scanf("%d,%d",&map.n,&map.e);
  getchar();//���ջس���
  for(i=0;i<map.n;i++)//���붥��
  {
      printf("��������е����ƣ�");
	  scanf("%s",&map.citys[i].city);
	  //getchar();
      map.citys[i].first=NULL;
  }
  for(i=0;i<map.e;i++)
  {
     printf("�����빫·����ţ�");
	 scanf("%d,%d",&s,&d);
	 //ǰ�巨
	 p=(Anode *)malloc(sizeof(Anode));
	 p->cityid=d;
	 p->next=map.citys[s].first;
     map.citys[s].first=p;
     p=(Anode *)malloc(sizeof(Anode));
     p->cityid=s;
	 p->next=map.citys[d].first;
     map.citys[d].first=p;
  }
  return map;
}
//��ͼ��������ȱ���
void dfs(Map map,int i)
{
   Anode *p;
   if(visited[i]==0)
   {
     printf("%s  ",map.citys[i].city);
	 visited[i]=1;
     p=map.citys[i].first;
     while(p!=NULL)
	 {
	   if(visited[p->cityid]==0)
		   dfs(map,p->cityid);
	   p=p->next;//��˷
	 }
   }
}
main()
{
   Map map;
   int i;
   map=creat();
   for(i=0;i<map.n;i++)
	   dfs(map,i);
}