#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

//内存空间状态
enum State
{
	Free, //空闲状态
	Busy  //占用状态
};

//定义分段储存区
class FreeStorage
{
public:
	string name;  //作业名称
	long size;    //空间大小
	long address; //空间地址
	State state;  //空间状态
};

//定义链表结构
class PCBList
{
public:
	FreeStorage* data;
	PCBList* front;   //前一个分区
	PCBList* next;    //后一个分区
};

PCBList* head; //头结点
PCBList* last; //尾结点

void Start(int max_size)
{
	//head->data = NULL;
	head->next = last;
	last->front = head;
	//last->next = NULL;
	last->data->address = 0;
	last->data->size = max_size;
	last->data->state = State::Free;
}

void Show()
{
	int flag = 0;  //分区号
	PCBList *p = head->next;
	cout << endl << "目前分配情况" << endl;
	cout << "==============================================" << endl << endl;
	cout << "分区号\t起始地址\t分区大小\t状态\t" << endl;
	while (p)
	{
		cout << "  " << flag++ << "\t"
		     << "  " << p->data->address << "\t\t"
			 << " " << p->data->size << "KB\t\t";
		if (p->data->state == State::Free) cout << "空闲\n\n";
		else cout << p->data->name << endl << endl;
		p = p->next;
	}
	cout << "==============================================" << endl << endl;
}

int main()
{
	int size = 640;  //初始化状态下可用空间
	//while (1)
	//{
	//	cout << "请输入初始状态下可用的空间（KB）：";
	//	cin >> size;
	//	if (cin.good() && size > 0 && size < 1000)
	//	{
	//		break;
	//	}
	//	else
	//	{
	//		cin.clear();
	//		cin.ignore();  //当输入非法字符时，清空
	//		cout << "空间大小不能小于0，大于1000，请重新输入!" << endl;
	//	}
	//}

	int choice=1;  //算法选择编号
	cout << "请输入所使用的内存分配算法："<<endl
		<< "1.首次适应算法" << endl
		<< "2.最佳适应算法" << endl;
	//cin >> choice;
	if (choice == 2)
	{
		cout << "当前选择最佳适应算法" << endl;
	}
	else
	{
		choice = 1;
		cout << "当前选择首次适应算法" << endl;
	}

	Start(size);   //初始化链表
	
	Show();
	//while (true)
	//{
	//	Show();
	//}
}