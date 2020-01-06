#include<iostream>
#include<stdlib.h>
#include<string>>
using namespace std;

typedef int Status;
int flag;

//区块状态
enum State
{
	FREE,  //空闲
	BUSY   //占用
};
typedef struct structure   //定义内存结构
{
	long size;    //内存区块大小
	long address; //内存区块地址
	State state;   //内存区块状态
}PCB;


typedef struct PCB_Part  //通过链表连接各个分区
{
	PCB data;
	struct PCB_Part *pre; //前趋指针
	struct PCB_Part *next;  //后继指针
}

PCB_Part, *PCBList;
PCBList head; //头结点
PCBList last;  //尾结点
Status alloc(int);//内存分配
Status free(int); //内存回收
Status FirstFit(int);//首次适应算法
Status BestFit(int); //最佳适应算法
void Show();//查看分配
Status CreatList(int);//开创空间表

Status CreatList(int max_length)//初始化内存链表结构
{
	head = (PCBList)malloc(sizeof(PCB_Part));
	last = (PCBList)malloc(sizeof(PCB_Part));
	head->pre = NULL;
	head->next = last;
	last->pre = head;
	last->next = NULL;
	last->data.address = 0;
	last->data.size = max_length;
	last->data.state = State::FREE;
	return 1;
}

//分配内存
Status alloc(int choicec)
{
	int request = 0;
	cout << "输入需要分配的内存大小(KB)：";
	cin >> request;
	if (request<0 || request == 0)
	{
		cout << "分配大小不合适，请重试！" << endl;
		return 0;
	}

	//最佳适应算法
	if (choicec == 2)
	{
		if (BestFit(request) == 1) cout << "分配成功！" << endl;
		else cout << "空闲内存不足，分配不成功" << endl;
		return 1;
	}
	//首次适应算法（默认）
	else
	{
		if (FirstFit(request) == 1) cout << "分配成功！" << endl;
		else cout << "空闲内存不足，分配不成功" << endl;
		return 1;
	}
}

//首次适应算法
Status FirstFit(int request)
{
	//为申请作业开辟新空间且初始化
	PCBList temp = (PCBList)malloc(sizeof(PCB_Part));
	temp->data.size = request;
	temp->data.state = State::BUSY;

	PCB_Part *p = head->next;
	while (p)
	{
		if (p->data.state == State::FREE && p->data.size == request)
		{//有大小恰好合适的空闲块
			p->data.state = State::BUSY;
			return 1;
			break;
		}
		if (p->data.state == State::FREE && p->data.size>request)
		{//有空闲块能满足需求，需要分割剩余
			temp->pre = p->pre;
			temp->next = p;
			temp->data.address = p->data.address;
			p->pre->next = temp;
			p->pre = temp;
			p->data.address = temp->data.address + temp->data.size;
			p->data.size -= request;
			return 1;
			break;
		}
		p = p->next;
	}
	return 0;
}

//最佳适应算法
Status BestFit(int request)
{
	int least; //记录最小剩余空间
	PCBList temp = (PCBList)malloc(sizeof(PCB_Part));
	temp->data.size = request;
	temp->data.state = State::BUSY;
	PCB_Part *p = head->next;
	PCB_Part *q = NULL; //记录最佳插入程序位置

	while (p) //初始化最小空间和最佳位置
	{
		if (p->data.state == State::FREE && (p->data.size >= request))
		{
			if (q == NULL)
			{
				q = p;
				least = p->data.size - request;
			}
			else if (q->data.size > p->data.size)
			{
				q = p;
				least = p->data.size - request;
			}
		}
		p = p->next;
	}

	if (q == NULL) return 0;//没有找到空闲分区
	else if (q->data.size == request)
	{
		q->data.state = State::BUSY;
		return 1;
	}
	else
	{
		temp->pre = q->pre;
		temp->next = q;
		temp->data.address = q->data.address;
		q->pre->next = temp;
		q->pre = temp;
		q->data.address += request;
		q->data.size = least;
		return 1;
	}
	return 1;
}


//内存回收
Status free(int flag)
{
	PCB_Part *p = head;
	for (int i = 0; i <= flag; i++)
		if (p != NULL)
			p = p->next;
		else
			return 0;
	if (p == NULL)
	{
		cout << endl << "此分区号不存在！" << endl;
	}
	else if (p->data.state == State::FREE)
	{
		cout <<endl<< "此内存空间已处于空闲状态，无需回收" << endl;
	}
	else
	{

		p->data.state = State::FREE;
		if (p->pre != head && p->pre->data.state == State::FREE)//与前面的空闲块相连
		{
			p->pre->data.size += p->data.size;
			p->pre->next = p->next;
			p->next->pre = p->pre;
			p = p->pre;
		}
		if (p->next != last && p->next->data.state == State::FREE)//与后面的空闲块相连
		{
			p->data.size += p->next->data.size;
			p->next->next->pre = p;
			p->next = p->next->next;
		}
		if (p->next == last && p->next->data.state == State::FREE)//与最后的空闲块相连
		{
			p->data.size += p->next->data.size;
			p->next = NULL;
		}
	}
	return 1;
}

//显示主存分配情况
void Show()
{
	int flag = 0;
	cout << "\n内存分配情况:\n";
	cout << "===============================================\n\n";
	PCB_Part *p = head->next;
	cout << "分区号\t起始地址\t分区大小\t状态\n\n";
	while (p)
	{
		cout << "  " << flag++ << "\t";
		cout << "  " << p->data.address << "\t\t";
		cout << " " << p->data.size << "KB\t\t";
		if (p->data.state == State::FREE) cout << "空闲\n\n";
		else cout << "已分配" << endl;
		p = p->next;
	}
	cout << "================================================\n\n";
}

//主函数
void main()
{
	cout << "================================================\n";
	cout << "请输入内存大小(KB)：";
	int max_length;
	cin >> max_length;   //输入内存最大空间
	while (true)
	{
		if (cin.good() && max_length > 0 && max_length < 100000)
		{
			break;
		}
		else
		{
			cin.clear();   //清空cin流
			cin.ignore();
			cout << "输入错误，内存大小大于1且少于100000：\n";
			cin >> max_length;
		}
	}
	cout << "================================================\n\n";
	int choicec;//算法选择标记
	cout << "请输入所使用的内存分配算法：\n";
	cout << "1.首次适应算法（First Fit）\n2.最佳适应算法(Best Fit)\n";

	cin >> choicec;

	while (true)
	{
		if (cin.good() && (choicec==1 > 0 || choicec == 2))
		{
			break;
		}
		else
		{
			cin.clear();   //清空cin流
			cin.ignore();
			cout << "输入错误，请重新输入：\n";
			cin >> choicec;
		}
	}

	CreatList(max_length); //开创空间表
	int choice;  //操作选择标记

	while (1)
	{
		Show();
		cout << "请输入您的操作：";
		cout << "\n1: 分配内存\n2: 回收内存\n0: 退出\n";

		cin >> choice;
		if (choice == 1) alloc(choicec); // 分配内存
		else if (choice == 2)  // 内存回收
		{
			int flag;
			cout << "请输入您要释放的分区号：";
			cin >> flag;
			free(flag);
		}
		else if (choice == 0) break; //退出
		else //输入操作有误
		{
			cout << "输入错误，重新输入" << endl;
			continue;
		}
	}
}
