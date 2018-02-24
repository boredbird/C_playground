/*程序8.4  从键盘读入3条学生记录，按成绩从小到大排序，然后在显示器上输出排序结果。*/
#include<stdio.h>
struct Student		                //结构类型定义
{
		long unsigned id;              //学号
		double grades;			        //记录成绩
};
typedef struct Student Student;       //定义结构类型的别名为Student
void Input(Student* pa,int n);			//从键盘输入记录
void Output(const Student* pa,int n);  //在显示器上输出记录，形参设为指向常量的指针
void SelectSort(Student* pa,int n);		//对记录数组用选择法进行排序
int main( )
{	Student sa[3];
		printf("Enter 3 records:\n"); 		//输入提示：输入3个记录
		Input(sa,3);
		printf("After Sort:\n");
		SelectSort(sa,3);
		Output(sa,3);
		return 0 ;
}
void Input(Student* pa,int n)
{
		int i;
		for(i=0;i<n;i++)
{
			printf("id:    ");			//输入提示：输入学号
			scanf("%ld",&pa[i].id);		
			printf("grades:");			//输入提示：输入成绩
			scanf("%Lf",&pa[i].grades); 	
		}
}
void SelectSort(Student* pa,int n)     //选择排序
{
		int i,j,min;
		Student temp;                 //定义结构临时变量
  		for(i=0;i<n-1;i++)		        //控制n-1趟循环
		{	min=i;				    //用min记下本趟分数最小元素的下标
			for(j=i+1;j<n;j++)
				if(pa[j].grades<pa[min].grades)   //比较分数
					min=j;           //二层循环结束时min中是本趟分数最小元素下标
			if(min!=i)                //如果分数最小元素未到位，交换元素
			{	temp=pa[i];	        //同为Student类型的结构变量可相互赋值
pa[i]=pa[min];
pa[min]=temp;
			}
		}
}
void Output(const Student* pa,int n)
{
		int i;
		for(i=0;i<n;i++)		        //输出数组
			printf("%Ld: %g\n",(pa+i)->id,(pa+i)->grades);
}
