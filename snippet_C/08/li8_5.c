/* 程序8.5  洗牌程序。
假设洗牌之前52张扑克牌按照红桃、方块、梅花和黑桃四种花色的顺序，
每种花色又是按照从1到13的顺序排列。通过产生随机数模拟洗牌，
每一张牌与随机选定的一张牌调换，从而打乱最初的次序。
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>		                      //包含srand 函数原型
struct Card
{	char suit;	
		int pips;				                  //分别表示花色和点数
};
void Display(const struct Card* p,int n);          //输出
void Shuffle(struct Card* p,int n);	              //洗牌
int main( )
{	int i;
		struct Card deck[52];
		for(i=0;i<52;i++)
		{
			deck[i].suit=i/13+3;			           //赋花色的ASCII码
			deck[i].pips=i%13+1;		           //赋点数
		}
		printf("before suffling:\n");	    	       //洗牌前输出
		Display(deck,52);
		Shuffle(deck,52);				           //洗牌
		printf("after suffling:\n");		           //洗牌后输出
		Display(deck,52);
		return 0;
}
void Display(const struct Card* pa,int n)
{
		int i;
		for(i=0;i<n;i++)
		{
			printf("(%c%-2d)",pa[i].suit,pa[i].pips);	   //输出花色和点数
			if((i+1)%13==0)					   //每行输出13张牌
				printf("\n");                       //换行
		}
}
void Shuffle(struct Card *pa,int n)                 //洗牌函数
{
		int i,j;	
struct Card temp;
		srand(time(0)); 			                 //使随机函数值跟时间变化
		for(i=0;i<n;i++)
		{
			j=rand()%n;                           //产生一个随机数j作为牌的下标
			temp=pa[i];	pa[i]=pa[j];	pa[j]=temp;   // pa[j]与当前牌pa[i]调换
		}
}
