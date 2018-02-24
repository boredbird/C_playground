/*程序4.10:模拟投骰子。以6点为目标，投中目标2次获胜，最多投10次
方法二: while语句实现
*/

#include<stdio.h>
#include<stdlib.h>					//包含系统函数rand和srand原型
#include<time.h>					//包含系统函数time的原型
int main()
{
	int count=0,y=0,dice;		//y记录投中的次数，count记录总次数，dice记录点数
	srand(time(0));				//系统函数，使随机函数rand的值随时间变化
	while(count<10&&y<2)        //投掷次数小于10且投中次数小于2为循环条件
	{
		dice=1+rand()%6;		    //生成1~6随机数作为模拟的点子
		count++;                 //投掷次数无条件加1
		if(dice==6)			    //如果点数等于6，投中次数加1
			y++;				
	}

	printf("%d,%d\n",count,y);	//输出总次数和投中次数
	return 0;
}
