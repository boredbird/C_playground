/*程序4.10 模拟投骰子的第四种实现方法。
以6点为目标，投中目标2次获胜，最多投10次。
方法5： 在while语句中使用continue
*/

#include<stdio.h>
#include<stdlib.h>					
#include<time.h>					
int main()
{	int count=0,y=0,dice;		
	srand(time(0));				
	while(count<10&&y<2)      
	{	dice=1+rand()%6;		    
		count++;                
		if(dice!=6)   
			continue;		
		y++;		    // dice!=6被跳过
	}
	printf("%d,%d\n",count,y);	
	return 0;
}
