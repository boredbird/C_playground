#include "stdio.h"
#include "string.h"
#define MAXLEN 10
typedef struct 
{	char ch[MAXLEN];
	int len;
}SeqString;

int StrMatch(SeqString T,SeqString P)
{//��ģʽP��Ŀ��T���״γ��ֵ�λ�ã��ɹ����ص�1����Чλ�ƣ����򷵻�-1
    int i,j,k;
    int m=P.len;  //ģʽ������ 
    int n=T.len;  //Ŀ�괮����
    for(i=0;i<=n-m;i++)//0<=i<=n-m�ǺϷ���λ��
	{   
      j=0;k=i;  
      while(j<m&&T.ch[k]==P.ch[j])//��whileѭ���ж�i�Ƿ�Ϊ��Чλ��
	  {
       k++;j++;
	  }
      if(j==m) //��T[i..i+m-1]=P[0..m-1]
           return i;//iΪ��Чλ�ƣ����������һ��λ��
	}
    return -1;//�Ҳ�����Чλ�ƣ�ƥ��ʧ��
}
main()
{
   SeqString t,p;
   int position;
   printf("������Ŀ�괮:");
   gets(t.ch);
   t.len=strlen(t.ch);
   printf("������ƥ�䴮:");
   gets(p.ch);
   p.len=strlen(p.ch);
   position=StrMatch(t,p);
   if(position==-1)
       printf("����ʧ��!\n");
   else
       printf("���ҳɹ�,λ��Ϊ%d\n",position);

}