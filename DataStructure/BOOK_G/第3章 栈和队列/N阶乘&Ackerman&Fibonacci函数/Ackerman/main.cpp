 /* algo3-8.c �õݹ������Ackerman(m,n)��ֵ */
 #include<stdio.h>

 int ack(int m,int n)
 {
   int z;
   if(m==0) /* ���� */
     z=n+1;
   else if(n==0)
     z=ack(m-1,1); /* ���β�m���� */
   else
     z=ack(m-1,ack(m,n-1)); /* ���β�m��n���� */
   return z;
 }

void main()
 {
	char select;
   int m,n;
   do{
   printf("Please input m,n:");
   scanf("%d %d",&m,&n);
   printf("Ack(%d,%d)=%d\n",m,n,ack(m,n));
   printf(" \n���������...'q'���˳���\n");
   getchar();
   select = getchar();
	}while(select!='q');
 }
