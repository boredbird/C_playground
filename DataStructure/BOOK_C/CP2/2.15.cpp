#include<iostream>
using namespace std;

typedef struct											//����˳���
{
	int *elem;
	int length;
}SqList;

void InitList_Sq(SqList &L,int n)						//����˳���
{
	L.elem=new int[n];
	if(!L.elem)
		exit(0);
	L.length=0;
}

void input(SqList &L,int n)						//������˳���L����������
{
	int i;
	cout<<"������ñ��Ԫ�أ����ǵݼ���˳�򣩣�";
	for(i=0;i<n;i++)
	{
		cin>>L.elem[i];
		L.length++;
	}
}

void output(SqList L)									//�������˳������ÿ��Ԫ��
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(i)
			cout<<",";
		cout<<L.elem[i];
	}
}

void MergeList_Sq(SqList LA,SqList LB,SqList &LC)		//�㷨2.15 ˳�������ĺϲ�
{
	//��֪˳�������LA��LB��Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢LA��LB�õ��µ�˳�������LC��LC��Ԫ��Ҳ��ֵ�ǵݼ�����
	int *pa,*pb,*pc,*pa_last,*pb_last;
	pa=LA.elem;pb=LB.elem;								//ָ��pa��pb�ĳ�ֵ�ֱ�ָ��������ĵ�һ��Ԫ��
	LC.length=LA.length+LB.length;						//�±���Ϊ���ϲ�����ĳ���֮��
	LC.elem=new int[LC.length];							//Ϊ�ϲ�����±����һ������ռ�
	pc=LC.elem;											//ָ��pcָ���±�ĵ�һ��Ԫ��
	pa_last=LA.elem+LA.length-1;						//ָ��pa_lastָ��LA������һ��Ԫ��
	pb_last=LB.elem+LB.length-1;						//ָ��pb_lastָ��LB������һ��Ԫ��
	while(pa<=pa_last && pb<=pb_last)					//�������ǿ�
	{
		if(*pa<=*pb)									//���Ρ�ժȡ��������ֵ��С�Ľ����뵽LC������
			*pc++=*pa++;
		else
			*pc++=*pb++;
	}
	while(pa<=pa_last)									//LB�ѵ����β�����ν�LA��ʣ��Ԫ�ز���LC������
		*pc++=*pa++;
	while(pb<=pb_last)									//LA�ѵ����β�����ν�LB��ʣ��Ԫ�ز���LC������
		*pc++=*pb++;
}														//MergeList_List

int main()
{
	SqList La,Lb,Lc;
	int num_a,num_b;

	cout<<"������ǵݼ����Ա�a�ĸ���n��";	
	cin>>num_a;
	InitList_Sq(La,num_a);								//La��Ĵ���
	input(La,num_a);									//������˳���La����������
	
	cout<<"������ǵݼ����Ա�b�ĸ���n��";	
	cin>>num_b;
	InitList_Sq(Lb,num_b);								//Lb��Ĵ���	
	input(Lb,num_b);									//������˳���La����������
	
	MergeList_Sq(La,Lb,Lc);								//��˳���La��Lb���кϲ�
	
	cout<<"�ǵݼ����Ա�a��b�ϲ���ķǵݼ����Ա�cΪ��\n";			//����ϲ��������˳���Lc
	output(Lc);
	cout<<endl;
	return 0;
}