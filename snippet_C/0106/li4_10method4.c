/*程序4.10 模拟投骰子的第四种实现方法。
以6点为目标，投中目标2次获胜，最多投10次。
方法4： 在while语句中使用break
*/
#include<stdio.h>
#include<stdlib.h>					
#include<time.h>					
int main()
{
	int count=0,y=0,dice;		
	srand(time(0));				
	while(count<10)       //循环条件少了1个 
	{
		dice=1+rand()%6;		    
		count++;                
		if(dice==6)			   
			y++;				
	    if (y==2) break;    //新增加的语句 
}
	printf("%d,%d\n",count,y);	
	return 0;
}
