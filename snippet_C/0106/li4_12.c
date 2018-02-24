/*程序4.12  从键盘上输入一个正整数n，求1!+2!+3!+…+n!的结果
*/
 #include <stdio.h>
int main( )
{
		int i,j,n;
		double f,sum=0;
		do
		{
			printf("Please input n:\n");
			scanf("%d",&n);
		}while (n<=0);         //此循环保证读入的n是一个正整数
		for (i=1; i<=n;i++)      //外层循环，用i控制从1到n
		{                    //外层循环的循环体，此复合语句包含3条子语句
			f=1;              //第1条子语句，为求每一个i的阶乘而设的累乘器
			for (j=1;j<=i;j++)   //此内层循环求得i!，结果在变量f中
				f=f*j;         //这是内层循环的循环体
			sum+=f;           //这是外层循环的最后一条子语句，将i!加入累加器
		}
		printf("sum=%e\n",sum);  //输出累加器中的值，就是所要结果
		return 0;
}


