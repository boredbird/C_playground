#include "C9-1.H"

void main()
 {
	char select;
   ElemType r[N]={{179328,"何芳芳",85,89,98,100,93,80,47},
   {179325,"陈红",85,86,88,100,92,90,45},
	{179326,"陆华",78,75,90,80,95,88,37},
	{179327,"张平",82,80,78,98,84,96,40},
	{179324,"赵小怡",76,85,94,57,77,69,44}}; /* 数组不按关键字有序 */
   SSTable st;
   int i;
   long s;
   for(i=0;i<N;i++) /* 计算总分 */
     r[i].total=r[i].politics+r[i].Chinese+r[i].English+r[i].math+r[i].physics+
	 r[i].chemistry+r[i].biology;
   Creat_Seq(&st,r,N); /* 由数组r产生顺序静态查找表st */
   printf("准考证号  姓名  政治 语文 外语 数学 物理 化学 生物 总分\n");
   Traverse(st,print); /* 按顺序输出静态查找表st */
   do{
   printf("请输入待查找人的考号: ");
   scanf("%ld",&s);
   i=Search_Seq(st,s); /* 顺序查找 */
   if(i)
     print(st.elem[i]);
   else
     printf("没找到\n");
   printf("任意键继续...；'q'退出! \n");
   getchar();
   select = getchar();
   }
   while(select !='q');
   Destroy(&st);
 }