/*程序4.14（方法1）：用三层循环求解百钱百鸡
*/
#include<stdio.h>
int main( )
{	
    int x,y,z;
    for(x=0;x<=20;x++)
        for(y=0;y<=33;y++)
            for(z=0;z<=100;z++)	
                if(x+y+z==100&&15*x+9*y+z==300)
                        printf("%5d%5d%5d\n",x,y,z);

    scanf("%d");
    return 0;
} 
