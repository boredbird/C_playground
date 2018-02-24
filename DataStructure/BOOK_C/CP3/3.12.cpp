/***Hanoi������***/
#include<iostream>
using namespace std;

int m = 0;//��m�ǳ�ֵΪ0��ȫ�ֱ������԰ᶯ������
void move(char A,int n,char C) // �ᶯ����
{
	cout<<"��"<<++m<<"��,"<<"�����Ϊ"<<n<<"��Բ�̴ӵ�"<<A<<"���������Ƶ���"<<C<<"��������"<<endl;
}

//�㷨3.12��Hanoi������ĵݹ��㷨
void Hanoi (int n, char A, char B, char C)
{
      // ������A�ϵ�n��Բ�̰�����ᵽC�ϣ�B��������������
      if (n == 1)
          move(A, 1, C);       //�����Ϊ1��Բ�̴�A�Ƶ�C
	  else
	  {
		  Hanoi(n-1, A, C, B);  //��A�ϱ��Ϊ1��n-1��Բ���Ƶ�B��C��������
		  move(A, n, C);  //�����Ϊn��Բ�̴�A�Ƶ�C
		  Hanoi(n-1, B, A, C);  //�� B���Ϊ1��n-1��Բ���Ƶ�C��A��������
	  }
}
int main()
{
    int n;
    char a,b,c;
    a='1';   b='2';   c='3';
    cout<<"�������ʼ��һ�������ϵ�Բ�̸�����"<<endl;
    cin>>n;
    cout<<"����һ�������ϵ�Բ��ȫ���ƶ��������������ϵĹ���Ϊ��"<<endl;
    Hanoi(n, a, b, c);
    return 0;
}