//程序6.15 "野指针"实验。
#include<stdio.h>
#include<stdlib.h>
int main( )
{
		int *p,*q;                   //定义p、q两个指针，此时p、q中地址值为随机值
		p=(int*)calloc(5,sizeof(int));    //通过p申请动态数组空间，元素初值为0
		printf("after calloc,p=%x\n",p);  //输出p获得的地址值
		free(p);					   //释放p所指的动态空间,指针p称为"野指针"
   		printf("after free,p=%x\n",p);    //输出p中所保留的地址值
		q=(int*)calloc(5,sizeof(int));	    //通过q申请动态数组空间，元素初值为0
    	printf("after calloc,q=%x\n",q);   //输出q获得的地址值
		printf("q[0]=%d\n",q[0]);		//通过合法指针q输出动态数组的首元素q[0]
		p[0]=1;					    //通过"野指针"p非法地修改了动态数组首元素
		printf("changed q[0]=%d\n",q[0]); //通过合法指针输出被非法修改的数组首元素
	    free(q);                      //释放q所指的动态空间,指针q称为"野指针"
// 	free(p);                      //此句若不注释,编译链接时无错,但是运行时出错 
		return 0;
}
