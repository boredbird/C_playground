#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;		//Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
typedef int ElemType;	 //ElemType Ϊ�ɶ�����������ͣ�����Ϊint����

#define MAXSIZE 100			//˳�����ܴﵽ����󳤶�

typedef struct{
	ElemType *elem;			//�洢�ռ�Ļ���ַ
	int length;				//��ǰ����
}SqList;

Status InitList_Sq(SqList &L){				//�㷨2.1 ˳���ĳ�ʼ��
	//����һ���յ�˳���L
	L.elem=new ElemType[MAXSIZE];		//Ϊ˳������һ����СΪMAXSIZE������ռ�
	if(!L.elem)  exit(OVERFLOW);		//�洢����ʧ��
	L.length=0;							//�ձ���Ϊ0
	return OK;
}

int LocateElem_Sq(SqList L,ElemType e){		//�㷨2.2 ˳���Ĳ���
	//˳���Ĳ���
	for(int i=0;i<L.length;i++)
		if(L.elem[i]==e) return i+1;
	return 0;
}

Status ListInsert_Sq(SqList &L,int i,ElemType e){		//�㷨2.3 ˳���Ĳ���
	//��˳���L�е�i��λ��֮ǰ�����µ�Ԫ��e
	//iֵ�ĺϷ���Χ��1<=i<=L.length+1
	if(i<1 || i>L.length+1)	return ERROR;		//iֵ���Ϸ�
	if(L.length==MAXSIZE)	return ERROR;		//��ǰ�洢�ռ�����
	for(int j=L.length-1;j>=i-1;j--)
		L.elem[j+1]=L.elem[j];					//����λ�ü�֮���Ԫ�غ���
	L.elem[i-1]=e;								//����Ԫ��e�����i��λ��
	++L.length;									//����1
	return OK;
}

Status ListDelete_Sq(SqList &L,int i,ElemType &e){		//�㷨2.4 ˳����ɾ��
	//��˳���L��ɾ����i��Ԫ�أ�����e������ֵ
	//iֵ�ĺϷ���Χ��1<=i<=L.length
	if(i<1 || i>L.length)	return ERROR;		//iֵ���Ϸ�
	e=L.elem[i-1];								//����ɾ����Ԫ�ر�����e��
	for(int j=i;j<=L.length;j++)				
		L.elem[j-1]=L.elem[j];					//��ɾ��Ԫ��֮���Ԫ��ǰ��
	--L.length;									//����1
	return OK;
}

int main()
{
	SqList L;
	int i,res,temp,a,b,c,e,choose;
	cout<<"1. ����˳���\n";
	cout<<"2. ��������\n";
	cout<<"3. ����\n";
	cout<<"4. ����\n";
	cout<<"5. ɾ��\n";
	cout<<"6. �������\n";
	cout<<"0. �˳�\n\n";

	choose=-1;
	while(choose!=0)
	{
		cout<<"��ѡ��:";
		cin>>choose;
		switch(choose)
		{
		case 1:
			if(InitList_Sq(L))						//����˳���
				cout<<"�ɹ�����˳���\n\n";
			else
				cout<<"˳�����ʧ��\n\n";
			break;
		case 2:										//����10����
			cout<<"������10����:\n";
			for(i=0;i<10;i++)
				cin>>L.elem[i];
			L.length=10;
			cout<<endl;
			break;
		case 3:										//˳���Ĳ���
			cout<<"��������Ҫ���ҵ���:";
			cin>>e;							//����e��������Ҫ���ҵ���ֵ
			temp=LocateElem_Sq(L,e);
			if(temp!=0)
				cout<<e<<" �ǵ� "<<temp<<"����.\n\n";
			else
				cout<<"����ʧ�ܣ�û����������\n\n";
			break;
		case 4:										//˳���Ĳ���
			cout<<"���������������ֱ��������λ�úͲ�����ֵ:";
			cin>>a>>b;				//����a��b��a��������λ�ã�b����������ֵ
			if(ListInsert_Sq(L,a,b))
				cout<<"����ɹ�.\n\n";
			else
				cout<<"I����ʧ��.\n\n";
			break;
		case 5:										//˳����ɾ��
			cout<<"��������Ҫ�������:";
			cin>>c;					//����c������Ҫɾ������λ��
			if(ListDelete_Sq(L,c,res))
				cout<<"ɾ���ɹ�.\n��ɾ��������:"<<res<<endl<<endl;
			else
				cout<<"ɾ��ʧ��.\n\n";
			break;
		case 6:										//˳�������
			cout<<"��ǰ˳���Ϊ:\n";
			for(i=0;i<L.length;i++)
				cout<<L.elem[i]<<" ";
			cout<<endl<<endl;
			break;
		}
	}
	return 0;
}