#include "stdio.h"
typedef struct student
{
   char name[10];//����
   char sex;//�Ա�
   int age;//����
   float score;//���ݽṹ�ɼ�
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