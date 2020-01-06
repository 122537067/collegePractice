#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//进程状态
enum State
{
	ready,   //就绪状态
	run,	 //运行状态
	finish	 //完成状态
};

class PCB
{
public:
	string name; // 进程名
	State state; // 进程状态
	double needTime; // 需要运行时间
	PCB* next; // 链接到下一个PCB
	double priority;  //优先数
	void show()
	{
		cout << "进程名：" << name << ", "
			<< "优先数：" << priority << endl;
		//优先权 = (等待时间 + 需要运行时间)  / 需要运行时间
	}
};

// 就绪队列，队列中每个结点是一个进程项PCB信息。
// 就绪队列按照PCB的优先数排列PCB结点
class PCBList
{
private:
	int count;    // 就绪队列长度
	PCB* head;
	double waitTime;  //等待时间

public:
	PCBList()
	{
		count = 0;
		head = NULL;
		waitTime = 0;
	}
	int getCount()
	{
		return count;
	}
	double getWaitTime()
	{
		return waitTime;
	}
	void setWaitTime(double time)
	{
		waitTime = time;
	}
	// 摘取就绪队列首结点
	PCB* GetFirst()
	{
		PCB* pcb = head;
		head = head->next;
		//pcb->next = NULL;
		count--;
		return pcb;
	}
	void PrintList()
	{
		// 输出就绪队列里所有结点的信息
		PCB* current = head;
		while (current != NULL)
		{
			current->show();
			current = current->next;
		}
	}

	void Insert(PCB* pcb)
	{
		// 如果就绪队列为空，则令头结点指向pcb
		if (head == NULL)
		{
			head = pcb;
			count++;
			return;
		}
		else
		{
			PCB* previous = head;
			PCB* current = head->next;
			if (current == NULL)
			{
				head->next = pcb;
				count++;
				return;
			}
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = pcb;
			count++;
			return;
		}
	}

	//重新排序
	void Resort(PCB* pcb)
	{
		PCB* previous = head;
		PCB* current = pcb->next;
		while (current != NULL)
		{
			PCB* count = pcb->next;
			current->priority = (current->needTime + waitTime) / current->needTime;
			if (head->priority < current->priority)
			{
				PCB* change = current;
				PCB* last = change->next;
				head = current;
				if (previous->next == head)
				{
					head->next = previous;
					current = previous;
					current->next = last;
					pcb->next = current;
					current->next = last;
				}
				else
				{
					head->next = previous->next;
					current = previous;
					current->next = last;
					pcb->next = current;
					current->next = last;
				}
			}
			pcb = count->next;
			if (pcb != NULL)
			{
				current = pcb->next;
			}
			else
			{
				current = pcb;
			}
		}
	}
};
PCBList readyList; //就绪进程队列

// 执行pcb进程一个时间片，执行完后，修改pcb
static void Run(PCB* pcb)
{
	//pcb->priority = (pcb->needTime + pcb->waitTime)/pcb->needTime;   //修改优先数
	//waitTime = pcb->waitTime + pcb->needTime;   //修改等待时间
	//// 修改就绪队列里所有结点的优先数
	//PCB* current = pcb->next;
	//while (current != NULL)
	//{
	//	current->priority = (current->needTime + current->waitTime) / current->needTime;
	//	current = current->next;
	//}
	pcb->state = State::finish;
}

void InputFromFile(string fileName)
{
	ifstream in;
	in.open(fileName);
	if (in.fail())
	{
		cout << "打开文件出错！" << endl;
		exit(1);
	}
	// 读取进程数
	int n;
	in >> n;;
	// 依次读取每个进程
	for (int i = 0; i < n; i++)
	{
		PCB* pcb = new PCB();
		in >> (pcb->name);
		pcb->state = State::ready;
		in >> pcb->needTime;
		pcb->priority = 1;
		pcb->next = NULL;
		// 将新PCB插入就绪队列
		readyList.Insert(pcb);
	}
}

int main()
{
	cout << "2015030403013黄炜轩 c++ 非抢占的高响应比优先调度算法" << endl;
	InputFromFile("pcblist.txt"); // 从pcblist.txt读入待调度进程信息
								 
	double waitTime = readyList.getWaitTime();
	while (readyList.getCount() != 0) // 就绪队列非空
	{
		PCB* currentPCB = readyList.GetFirst();
		waitTime = currentPCB->needTime + waitTime;
		readyList.setWaitTime(waitTime);  //修改等待时间
		readyList.Resort(currentPCB); //重新排序
		cout << "运行时间 " << waitTime << endl;
		// 从就绪队列摘取队首进程（优先数最高）运行
		Run(currentPCB);
		cout << "当前运行进程信息：" << endl;
		currentPCB->show();
		cout << "就绪队列列表：" << endl;
		readyList.PrintList();
		cout << "进程" << (currentPCB->name) << "执行完毕" << endl;
		system("pause"); // 按任意键继续
	}
	cout << "所有进程执行完毕" << endl;
	return 0;
}