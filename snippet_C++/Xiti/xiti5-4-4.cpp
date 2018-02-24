//编写一个程序，实现方程式的相加。
#include <iostream.h>
#include <string>
struct coefficient
{
	bool pn;
	int num;
}a[3],b[3],c[3],d[3];
void main()
{
	char equation[2][50],ch,z[8];
	int m,j; 

	cout<<"Input NO. 1 Equation:"<<endl;
	cin>>equation[0];
	cout<<"Input NO. 2 Equation:"<<endl;
	cin>>equation[1];
	for (int i=0; i<2;i++)
	{
		j=0;
		ch=equation[i][0];
		if (ch=='-') 
		{
			a[i].pn=false;
			j++;
			ch=equation[i][j];
		}
		else
			a[i].pn=true;
		if(ch>='0'&&ch<='9') /* 提取a的系数 */
		 {
		   m=0;
		   do
		   {
			 z[m]=ch;
			 j++;
			 m++;
			 ch=equation[i][j];
		   }while(ch>='0'&&ch<='9');
		   z[m]=0;
		   if (a[i].pn)
			   a[i].num=atoi(z);
		   else
			   a[i].num=-1*atoi(z);
		}
		j++;
		ch=equation[i][j];
		if (ch=='-') 
			b[i].pn=false;
		else
			b[i].pn=true;
		j++;
		ch=equation[i][j];	
		if(ch>='0'&&ch<='9') /* 提取b的系数 */
		 {
		   m=0;
		   do
		   {
			 z[m]=ch;
			 j++;
			 m++;
			 ch=equation[i][j];
		   }while(ch>='0'&&ch<='9');
		   z[m]=0;
		   if (b[i].pn)
			   b[i].num=atoi(z);
		   else
			   b[i].num=-1*atoi(z);
		}
		j++;
		ch=equation[i][j];
		if (ch=='-') 
			c[i].pn=false;
		else
			c[i].pn=true;
		j++;
		ch=equation[i][j];
		if(ch>='0'&&ch<='9') /* 提取c的系数 */
		 {
		   m=0;
		   do
		   {
			 z[m]=ch;
			 j++;
			 m++;
			 ch=equation[i][j];
		   }while(ch>='0'&&ch<='9');
		   z[m]=0;
		   if (c[i].pn)
			   c[i].num=atoi(z);
		   else
			   c[i].num=-1*atoi(z);
		}
		j++;
		j++;
		ch=equation[i][j];
		if (ch=='-') 
		{
			d[i].pn=false;
			j++;
			ch=equation[i][j];
		}
		else
			d[i].pn=true;
		if(ch>='0'&&ch<='9') /* 提取=右侧的常数 */
		 {
		   m=0;
		   do
		   {
			 z[m]=ch;
			 j++;
			 m++;
			 ch=equation[i][j];
		   }while(ch>='0'&&ch<='9');
		   z[m]=0;
		   if (d[i].pn)
			   d[i].num=atoi(z);
		   else
			   d[i].num=-1*atoi(z);
		}
	}
	//计算相加后a,b,c的系数和常数的结果
	a[2].num=a[0].num+a[1].num;
	b[2].num=b[0].num+b[1].num;
	c[2].num=c[0].num+c[1].num;
	d[2].num=d[0].num+d[1].num;
	cout<<"The added equation is :"<<endl;
	if (a[2].num!=0)
		cout<<a[2].num<<"a";
	if (b[2].num>0)
		cout<<"+"<<b[2].num<<"b";
	else if (b[2].num<0)
		cout<<b[2].num<<"b";
		if (c[2].num>0)
		cout<<"+"<<c[2].num<<"c";
	else if (c[2].num<0)
		cout<<c[2].num<<"c";
	cout<<"="<<d[2].num<<endl;

}
