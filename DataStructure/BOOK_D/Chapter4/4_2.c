#include<stdio.h>
#define MAXSIZE 10
typedef struct 
{
	int i,j,value;//i:行号，j：列号，e：非零元素的值
}Triple;

typedef struct 
{
	int mu,nu,tu; //mu:总行号，nu：总列号，tu：非零元素个数
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


int num[MAXSIZE];//num[col]存放M中第col列中非0元素个数
int cpos[MAXSIZE];//cpos[col]存放M中第col列的第一个非0元素的位置

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
		for( p=0; p<M.tu ; p ++ )//p指向a.data，循环次数为非0元素总个数tu
		{
			col =M.data[ p ]. j ; q =cpos [col]; 
			//查辅助向量表得q，即T中位置
			T->data[q].i = M.data[p].j;
			T->data[q].j = M.data[p].i;
			T->data[q].value = M.data[p].value;
			++cpos[col] ; //修改向量表中列坐标值，供同一列下一非零元素
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
