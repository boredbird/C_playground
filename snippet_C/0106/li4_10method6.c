/*程序4.10 模拟投骰子的第四种实现方法。
以6点为目标，投中目标2次获胜，最多投10次。
方法6：用goto语句控制循环 
*/
#include<stdio.h>
#include<stdlib.h>			
#include<time.h>				
int main()
{
	int count=0,y=0,dice;		
	srand(time(0));				
	repeat:	            //repeat为语句标号
		dice=1+rand()%6;		     
		count++;                
		if(dice==6)			   
			y++;	
	if (count<10&&y<2)
		goto repeat;      //goto语句
	printf("%d,%d\n",count,y);	
	return 0;
}
