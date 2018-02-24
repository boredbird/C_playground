/*
* 
* 文件名称：Xiti9_4_1.cpp
* 摘 要：在例9-4的基础上，继续实现单向链表类模版中能够实现节点的插入、删除、排序等的成员函数
* 完成日期：2009.1
* 
*/

#include<iostream.h>
template<class T>
class List
{
	private:
		T data;
		List *next;
		static List *curnode;	//当前节点指针，静态数据成员，为List类的所有对象所共有
		static List *head;		//头指针，静态数据成员，为List类的所有对象所共有
	public:
		List():next(NULL)		//无参构造函数，用于构造头节点
		{
			head=curnode=this;
		}
		List(T newdata):data(newdata),next(NULL)	//有参构造函数，用于构造新节点
		{

		}
		void create(T newnode);						//创建链表函数
		void display();								//输出函数

        //所添加的节点的插入、删除、排序等的成员函数//////////
		int insert(int insert_number,T newdata);	//插入函数
		int del(int del_number);					//删除函数
		void sequence();							//排序函数
		//////////////////////////////////////////////////////

};

template<class T>
List<T>*List<T>::curnode;
template<class T>
List<T>*List<T>::head;

template<class T>
void List<T>::create(T newdata)	//创建链表函数
{
	curnode->next=new List(newdata);
	curnode=curnode->next;
}

template<class T>
void List<T>::display()			//输出函数
{
	curnode=head->next;
	while(curnode!=NULL)
	{
		cout<<curnode->data<<endl;
		curnode=curnode->next;
	}
}


////////////////////////////////////////////
//插入函数                                //
//实现在链表的某一位置插入节点的功能      //
//其中：                                  //
//insert_number：要插入的位置             //
//insert_data：要插入的新节点中存储的数据 //
////////////////////////////////////////////
template<class T>
int List<T>::insert(int insert_number,T insert_data)
{
	List *temp=new List(insert_data);
	curnode=head;
	for(int i=1;i<insert_number;i++)	//找到插入位置
	{
		curnode=curnode->next;
	}		
	if(curnode==NULL)					//如果没有找到插入位置，则插入失败，返回-1
	{
		return -1;
	}
	else
	{
		temp->next=curnode->next;		//通过移动指针，实现插入操作，插入成功，返回0
		curnode->next=temp;
		return 0;

	}

}



////////////////////////////////////////////
//删除函数                                //
//实现在链表的某一位置删除节点的功能      //
//其中：                                  //
//del_number：要删除节点的位置            //
////////////////////////////////////////////
template<class T>
int List<T>::del(int del_number)
{
	curnode=head;
	if(del_number==1)								//第一种情况：要删除的是头节点
	{
		head->next=(curnode->next)->next;			//通过移动指针，实现删除操作，删除成功，返回0
		return 0;
	}
	else											//第二种情况：要删除的是一般节点
	{
		for(int i=1;i<del_number;i++)				//找到要删除的节点的位置
		{
			curnode=curnode->next;
		}
		if(curnode==NULL)
		{
			return -1;								//如果没有找到删除位置，则删除失败，返回-1
		}
		else
		{
			curnode->next=(curnode->next)->next;	//通过移动指针，实现删除操作，删除成功，返回0
			return 0;
		}
	}

}

////////////////////////////////////////////
//排序函数                                //
//实现对链表节点的排序功能（从小到大排序）//
////////////////////////////////////////////
template<class T>
void List<T>::sequence()
{

	List *temp_node=new List(1);		//新建一个临时节点（由于只做临时应用故随意给其赋了一个值）
	List *tail;							//定义指针表示链表的结尾
	tail=NULL;							
	temp_node->next=head;				//通过指针的变换，将新节点设为最开始节点
	head=temp_node;
	while(tail!=head->next)				//循环进行排序
	{
        temp_node=head;
        curnode=temp_node->next;
        while(tail!=curnode->next)		
		{
            if(temp_node->next->data > curnode->next->data)	//如果后一个节点储存的值小于前一个节点，则移动指针对链表进行重新排列
			{
                temp_node->next=curnode->next;
                curnode->next=curnode->next->next;
                temp_node->next->next=curnode;
            }
            temp_node=temp_node->next;
            curnode=temp_node->next;
        }
        tail=curnode;
    }
    temp_node=head;
	head=head->next;										//最后通过指针移动将临时的最开始节点删除

}

void main()
{
	cout<<"建立两个链表并输出"<<endl;
	cout<<"第一个链表："<<endl;
	List<int> list1;
	list1.create(2);
	list1.create(0);
	list1.create(0);
	list1.create(6);
	list1.display();
		
	cout<<"第二个链表："<<endl;
	List<char> list2;
	list2.create('O');
	list2.create('K');
	list2.create('!');
	list2.display();

	cout<<"向第二个链表的第2个位置添加字符“*”"<<endl;
	char a='*';
    list2.insert(2,a);
	list2.display();

	cout<<"删除第二个链表的第3个位置的节点元素"<<endl;
	list2.del(3);
	list2.display();
	
	cout<<"新建立一个链表为："<<endl;
	List<int> list3;
	list3.create(2);
	list3.create(3);
	list3.create(5);
	list3.create(7);
	list3.create(10);
	list3.create(9);
	list3.create(1);
	list3.create(4);
	list3.create(6);
	list3.create(8);
	list3.display();
	
	cout<<"对其进行排序并输出："<<endl;
	list3.sequence();
	list3.display();
}