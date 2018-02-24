#include "stdio.h"
#include "stdlib.h"
//0：南京  1：苏州  2：无锡   3：常州  4：淮安  5：连云港  6：徐州  7：南通  8：盐城
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
	int n,e;//n代表顶点数量、e代表边数量
}Map;
//地图的建立
Map creat()
{
  Anode *p;
  int i,s,d;
  Map map;
  printf("请输入城市和公路的数量：");
  scanf("%d,%d",&map.n,&map.e);
  getchar();//吸收回车符
  for(i=0;i<map.n;i++)//输入顶点
  {
      printf("请输入城市的名称：");
	  scanf("%s",&map.citys[i].city);
	  //getchar();
      map.citys[i].first=NULL;
  }
  for(i=0;i<map.e;i++)
  {
     printf("请输入公路的序号：");
	 scanf("%d,%d",&s,&d);
	 //前插法
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
//地图的深度优先遍历
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
	   p=p->next;//回朔
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