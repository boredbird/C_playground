/*����7.1:��������ʾ��*/
#define DEBUG						//����DEBUG����
#include<stdio.h>						//������printfԭ��
#include<stdlib.h>						//������randԭ��
int main( )
{
		int a,b,r;
		double s;
		a=rand( )%10;
		b=rand( )%10;
		if (a && b)
		{
			#ifdef DEBUG 				//��������ָ�ʼ�������DEBUG�Ѷ���
			printf("%-4d%-4d\n",a,b);		//�������
		    #endif 							//��������ָ�����
		    r=((a)>(b)?(a):(b));
		    s=(r)*(r)*3.1415926;
		    printf("%g\n",s);
		}
}

