#include<stdio.h>
#define MAXSIZE 10
typedef struct 
{
	int i,j,value;//i:�кţ�j���кţ�e������Ԫ�ص�ֵ
}Triple;

typedef struct 
{
	int mu,nu,tu; //mu:���кţ�nu�����кţ�tu������Ԫ�ظ���
	Triple data[MAXSIZE];


}TSMatirx;
void TransPoseSMatrix(TSMatirx M, TSMatirx *T)
{
	int col,p,q;
	T->mu = M.nu ;T->nu = M.mu ; T->tu = M.tu ;
	if (T->tu!=0) 
	{ 
		q=0;   
		for(col=0; col<M.nu; col++)
			for(p=0; p<M.tu; p++) 
			{
				if (M.data[p].j==col)
				{
					T->data[q].i=M.data[p].j; 
					T->data[q].j=M.data[p].i;
					T->data[q].value=M.data[p].value;  
					q++;
				} 
			}
	}
}


int num[MAXSIZE];//num[col]���M�е�col���з�0Ԫ�ظ���
int cpos[MAXSIZE];//cpos[col]���M�е�col�еĵ�һ����0Ԫ�ص�λ��

void FastTransposeSMatrix(TSMatirx M, TSMatirx *T)
{ 
	int i,col,p,q;
	T->mu = M.nu ;T->nu = M.mu ; T->tu = M.tu ;
	
	if ( T->tu!=0 )
	{
		for(col=0;col<M.nu;col++) num[col] =0;  
		for( i =0; i<M.tu; i++) 
		{
			col=M.data[i].j;++num [col] ;
		}
		cpos[0]=0;
		for(col =1; col<M.nu;col++) 
			cpos[col]=cpos[col-1]+num[col-1]; 
		for( p=0; p<M.tu ; p ++ )//pָ��a.data��ѭ������Ϊ��0Ԫ���ܸ���tu
		{
			col =M.data[ p ]. j ; q =cpos [col]; 
			//�鸨���������q����T��λ��
			T->data[q].i = M.data[p].j;
			T->data[q].j = M.data[p].i;
			T->data[q].value = M.data[p].value;
			++cpos[col] ; //�޸���������������ֵ����ͬһ����һ����Ԫ��
		} 
	}
} 
void main()
{
	int i;
	TSMatirx M,T;;
	M.mu=6;
	M.nu=6;
	M.tu=8;
	M.data[0].i=1;M.data[0].j=2;M.data[0].value=12;
	M.data[1].i=1;M.data[1].j=3;M.data[1].value=9;
	M.data[2].i=3;M.data[2].j=1;M.data[2].value=-3;
	M.data[3].i=3;M.data[3].j=5;M.data[3].value=14;
	M.data[4].i=4;M.data[4].j=3;M.data[4].value=24;
	M.data[5].i=5;M.data[5].j=2;M.data[5].value=18;
	M.data[6].i=6;M.data[6].j=1;M.data[6].value=15;
	M.data[7].i=6;M.data[7].j=4;M.data[7].value=-7;

	for(i=0;i<M.tu;i++)
	{
		printf("%3d%3d%3d\n",M.data[i].i,M.data[i].j,M.data[i].value);
	}
	TransPoseSMatrix(M,&T);
	printf("\n********************\n");
	for(i=0;i<T.tu;i++)
	{
		printf("%3d%3d%3d\n",T.data[i].i,T.data[i].j,T.data[i].value);
	}


}
