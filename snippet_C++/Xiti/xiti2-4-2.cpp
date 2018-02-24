//编写程序，求解各种数据类型的存储长度并显示出来，在其中找出存储长度最大的和最小的两种数据类型并输出。
#include <iostream.h>
void main()
{ 
  int length[7];
  int max=0,min=0;

  cout<<"data type\tmemory used(bytes)";
  length[0]=sizeof(short int);		//获取短整型长度
  cout<<"\nshort int\t"<<length[0]<<"\t";
   length[1]=sizeof(int);			//获取整型长度
  cout<<"\ninteger  \t"<<length[1];
   length[2]=sizeof(long);			//获取长整型长度
  cout<<"\nlong integer\t"<<length[2];
   length[3]=sizeof(char);			//获取字符型长度
  cout<<"\nchar     \t" <<length[3];
   length[4]=sizeof(float);			//获取单浮点型长度
  cout<<"\nfloat     \t"<<length[4];
   length[5]=sizeof(double);		//获取双浮点型长度
  cout<<"\ndouble     \t"<<length[5];
   length[6]=sizeof(bool);			//获取布尔型长度
  cout<<"\nbool     \t"<<length[6]<<endl;

  for(int i=0;i<7;i++)
  {
	if (length[i]>length[max])//求取长度最大的类型的存取位置
		max=i;
	if (length[i]<length[min])//求取长度最小的类型的存取位置
		min=i;
  }
  cout<<"The longest length is from ";
  switch (max)
  {
	case 0:cout<<"short int."<<endl;
		break;
	case 1:cout<<"int."<<endl;
		break;
	case 2:cout<<"long."<<endl;
		break;
	case 3:cout<<"char."<<endl;
		break;
	case 4:cout<<"float."<<endl;
		break;
	case 5:cout<<"double."<<endl;
		break;
	case 6:cout<<"bool."<<endl;
		break;
  }
  cout<<"The shortest length is from ";
  switch (min)
  {
	case 0:cout<<"short int."<<endl;
		break;
	case 1:cout<<"int."<<endl;
		break;
	case 2:cout<<"long."<<endl;
		break;
	case 3:cout<<"char."<<endl;
		break;
	case 4:cout<<"float."<<endl;
		break;
	case 5:cout<<"double."<<endl;
		break;
	case 6:cout<<"bool."<<endl;
		break;
  }

 
}
