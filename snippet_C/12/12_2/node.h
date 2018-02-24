//12.2节中结点类型
#ifndef _NODE
#define _NODE
struct Student
{
		long num;
		char name[20];
		char sex[10];
		int score[3];
		int total;
		int rank;
};
typedef struct Student Type;
const int sizeStu=sizeof(Type);     //学生记录所需要的内存空间大小
struct node
{
  	   Type data;
   		struct node *next;
};
const int size=sizeof(struct node);   //结点所需要的内存空间的大小
#endif
