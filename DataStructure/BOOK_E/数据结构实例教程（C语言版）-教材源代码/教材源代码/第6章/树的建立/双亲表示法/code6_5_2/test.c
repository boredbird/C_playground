#include "stdio.h"
#define MaxTreeSize 10
typedef struct
{
	char data;//�������
	int parent; //˫��ָ�룬ָʾ����˫���������е�λ��
}PTreeNode;
//�������Ͷ���
typedef struct
{
	PTreeNode nodes[MaxTreeSize];
	int n; //������� 
}PTree;
main()
{
   PTree T;
   int i;
   printf("�����������:");
   scanf("%d",&T.n);
   for(i=0;i<T.n;i++)
   {
	   printf("�������%d�������Ϣ:",i);
	   getchar();
       scanf("%c",&T.nodes[i].data);
       printf("�������%d������˫���±�:",i);
       scanf("%d",&T.nodes[i].parent);
   }
   //��ӡ���Ĵ洢���
   for(i=0;i<T.n;i++)
   	   printf("%3c",T.nodes[i].data);
   printf("\n");
   for(i=0;i<T.n;i++)
       printf("%3d",T.nodes[i].parent);
   printf("\n");
 }
