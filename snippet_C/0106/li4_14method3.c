/*程序4.14（方法3）：用一层循环求解百钱百鸡。
*/
#include <stdio.h>
int main()
{
	int x,y,z;
	for (x=0;x<=14;x++)
	{	y=(100-7*x)/4;
		z=100-x-y;
		if (15*x+9*y+z==300)
			printf("%5d%5d%5d\n",x,y,z);
	}
    return 0;
}
