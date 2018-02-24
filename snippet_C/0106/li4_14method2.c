/*程序4.13方法2:用两层循环求解百钱百鸡
*/
#include<stdio.h>
int main(  )
{
int x,y,z; 
for(x=0;x<=20;x++)
for(y=0;y<=33;y++)
{	z=100-x-y;
	     if(15*x+9*y+z==300)
		      printf("%5d%5d%5d\n",x,y,z);
}
return 0;
}
