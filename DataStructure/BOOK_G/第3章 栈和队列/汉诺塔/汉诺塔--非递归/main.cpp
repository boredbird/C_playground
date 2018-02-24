#include "stdio.h"
#include "stdlib.h"

int count=1; 
int N;

int ldx(int a,int x) 
{   
	int sum = 1;   
	for(;x>0;x--)   
	{       
		sum*=a; 
	}
	return sum; 
} 

void MoveHanoi(int j,char ch1,char ch2) 
{  
	printf("%d(%c,%c)%d\n",j,ch1,ch2,count++); 
} 

void Hanoi(char a,char b,char c) 
{   
	int n = 1,j = 1;   
	char temp; 
	if(!(N%2))  
	{   
		temp=b;
		b=c;
		c=temp;
	}  
	while(n<ldx(2,N))   
	{     
		j=1;
		while(j<=N)
		{       
			if(n%ldx(2,j)==ldx(2,j-1))
			{  
				if(j%2==1)  
				{      
					if(n%(3*ldx(2,j))==ldx(2,j-1))    
					{ 
						MoveHanoi(j,a,c);
						break;           
					}          
					if(n%(3*ldx(2,j))==3*ldx(2,j-1))           
					{  
						MoveHanoi(j,c,b);    
						break;         
					}           
					if(n%(3*ldx(2,j))==5*ldx(2,j-1))          
					{ 
						MoveHanoi(j,b,a);
						break;        
					}
					j++;      
				}
				else        
				{
					if(n%(3*ldx(2,j))==ldx(2,j-1))
						{
						MoveHanoi(j,a,b);
						break;
				}           
	      if(n%(3*ldx(2,j))==3*ldx(2,j-1)) 
			  {
			  MoveHanoi(j,b,c);          
		      break;         
		  }          
	      if(n%(3*ldx(2,j))==5*ldx(2,j-1))
			  {        
			  MoveHanoi(j,c,a);  
			  break; 
			  }
		  j++;        
				}     
			}     
			else   j++;  
		}    
    		n++;   
	}
} 

int main() 
{
	char sel;
	char a='A',b='B',c='C';
	char select;
	do{
	printf("输入圆盘个数:");
	scanf("%d",&N);
	Hanoi(a,b,c);
	printf("按任意键继续...'q'：退出 \n");
	getchar();
	select = getchar();
	}while(select!='q');
	return 0; 
} 

