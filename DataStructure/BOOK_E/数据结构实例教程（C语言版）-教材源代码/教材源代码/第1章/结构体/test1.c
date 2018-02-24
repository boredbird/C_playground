#include "stdio.h"
typedef struct student
{
   char name[10];//姓名
   char sex;//性别
   int age;//年龄
   float score;//数据结构成绩
 }stu;
main()
{
   stu t;
   stu *p;
   p=&t;
   p->sex='F';
   p->age=20;
   printf("sex=%c,age=%d",t.sex,t.age);
}