#include<string.h>
#include<ctype.h>
#include<malloc.h> // malloc()��
#include<limits.h> // INT_MAX��
#include<stdio.h> // EOF(=^Z��F6),NULL
#include<stdlib.h> // atoi()
#include<io.h> // eof()
#include<math.h> // floor(),ceil(),abs()
#include<time.h>
#include<process.h> // exit()
#include<iostream.h> // cout,cin

 #define MAXLENGTH 25 /* ���Թ����������Ϊ25 */
 typedef int MazeType[MAXLENGTH][MAXLENGTH]; /* �Թ���������[��][��] */

typedef struct
 {
   int xx; /* ��ֵ */
   int yy; /* ��ֵ */
 }PosType; /* �Թ�����λ������ */

 /* ȫ�ֱ��� */
 //MazeType m; /* �Թ����� */
 int x=20,y=20; /* �Թ������������� */
 int Mark=0;
 PosType begin,end; /* �Թ����������,�������� */

 int mg[20][20];

void Print()
 { /* ����Թ��Ľ�(mg����) */
   int i,j;
   for(i=0;i<x;i++)
   {
     for(j=0;j<y;j++)
		    if(i==1&&j==0||i==1&&j==1) printf("��");
			else if(mg[i][j]==1) printf("��");		//�Թ���"ǽ"
			else if(mg[i][j]==0) printf("��");      //��ͨ��·
			else if(mg[i][j]==-1)printf("��");		
			else printf("��");		//ͨ����·��
     printf("\n");
   }
   Mark = 1;
 }

void Random(){
	//��ʱ�����Թ���ǽ�ں�ͨ������Ϊ1:2
	int i,j,k;
	srand(time(NULL));
	mg[1][0]=mg[1][1]=mg[18][19]=0;	//����ڡ���������Ϊ"0"����ͨ��
	for(j=0;j<20;j++)
		mg[0][j]=mg[19][j]=1;		/*�����Թ���Χ"������"����ֻ֤��һ�����ں����*/
	for(i=2;i<19;i++)
		mg[i][0]=mg[i-1][19]=1;		/*�����Թ���Χ"������"����ֻ֤��һ�����ں����*/
	for(i=1;i<19;i++)
		for(j=1;j<19;j++){
			k=rand()%3;	//�������0��1��2������(1��2������ֵĸ��ʱ�0���ֵĸ��ʶ�һ��)
			if(k)
				mg[i][j]=0;
			else{
				if((i==1&&j==1)||(i==18&&j==18))	/*��Ϊ����ڻ����һ����·�Ǳؾ�֮·�������ͨ����Ϊ"0"�Ӵ��Թ���ͨ�еĸ���*/
					mg[i][j]=0;
				else
					mg[i][j]=1;
			}
		}
}

 void Try(PosType cur,int curstep)
 { /* �ɵ�ǰλ��cur����ǰ����curstep��̽��һ�� */
   int i;
   PosType next; /* ��һ��λ�� */
   PosType direc[4]={{0,1},{1,0},{0,-1},{-1,0}}; /* {������,������},�ƶ�����,����Ϊ�������� */
   for(i=0;i<=3;i++) /* ������̽���������ĸ����� */
   {
     next.xx=cur.xx+direc[i].xx; /* �����ƶ����򣬸���һλ�ø�ֵ */
     next.yy=cur.yy+direc[i].yy;
     if(mg[next.xx][next.yy]==0) /* ��һ��λ����ͨ· */
     {
       mg[next.xx][next.yy]=++curstep; /* ����һ��λ����Ϊ�㼣 */
       if(next.xx!=end.xx||next.yy!=end.yy) /* û���յ� */
         Try(next,curstep); /* ����һ��λ�ü�����̽(���׵ݹ���ã����յ����) */
       else /* ���յ� */
       {
         Print(); /* ������(���ڣ����ٵݹ����) */
         printf("\n");
       }
       mg[next.xx][next.yy]=-1; /* �ָ�Ϊͨ·���Ա�����һ��������̽��һ��· */
       curstep--; /* �㼣Ҳ��1 */
     }
   }
 }

 void main()
 {
   char select;
	printf("\n==================�Թ���Ϸ==================");
	printf("\n˵��:�������ߵ�����\t\n     ���߲�ͨ������");
	printf("\n     �������ͨ����·����ָ���յ�");
	printf("\n============================================");
    printf("\n ���Թ�����ڵ����ڵ�·������:\n");
	begin.xx=1;begin.yy=0;	//�������(1��0)	
	end.xx=18;end.yy=19;	//�յ�����(18,19)
   do{
	   Mark=0;
	   Random();
	   Try(begin,0); /* �ɵ�1�������̽�� */
       if(!Mark)printf("\n��������ɵ��Թ��޽�!!!\n");
	   printf("\n�����������...'q':�˳�! \n");
       select = getchar();
	   getchar();
   }while(select!='q');
 }
