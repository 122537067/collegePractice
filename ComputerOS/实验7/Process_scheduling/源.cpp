#include <iostream>
#include <fstream>
#include <string>
using namespace std;
enum State 	// 进程状态
{
	ready, // 就绪
	run, // 运行
	finish // 完成
};
class PCB
{
public:
	string name; // 进程名
	State state; // 进程状态
	int priority; // 优先数
	int needTime; // 需要运行时间
	int runTime; // 已运行时间
	PCB* next; // 链接到下一个PCB
	void show()
	{
		cout << "进程名：" << name << ", "
			<< "优先数：" << priority << ", "
			<< "已运行时间：" << runTime << ", "
			<< "还需要时间：" << needTime - runTime << endl;
	}
};

// 就绪队列，队列中每个结点是一个进程项PCB信息。
// 就绪队列按照PCB的优先数排列PCB结点
class PCBList
{
private:
	int count;    // 就绪队列长度
	PCB* head;
public:
	PCBList()
	{
		count = 0;
		head = NULL;
	}
	int getCount()
	{
		return count;
	}
	// 将pcb按其优先数大小插入至就绪队列中
	void Insert(PCB* pcb)
	{
		// 如果就绪队列为空，则令头结点指向pcb
		if (head == NULL)
		{
			cout << "head is null" << endl;
			head = pcb;
			cout << "head = " << head << endl;
			cout << head->name << endl;
			count++;
			cout << count << endl;
			return;
		}
		// 比较pcb与队列首结点的优先数
		cout << "head->priority = " <<head->priority << endl;
		cout << "pcb->priority = " << pcb->priority << endl;
		if ((head->priority) < (pcb->priority))
		{
			cout << "(head->priority) < (pcb->priority)" << endl;
			// 如果pcb的优先数比队首的pcb优先数还高
			cout << "pcb->next = " << pcb->next << endl;
			cout << "head = " << head << endl;
			pcb->next = head;
			head = pcb;
			count++;
			cout << count << endl;
			return;
		}
		// pcb插入位置不在队列之首，下面依次查找pcb插入位置
		PCB* previous = head;
		PCB* current = head->next;
		cout << "previous = " << previous <<"----"<<head<< endl;
		cout << "current = " << current << "----" << head->next << endl;
		// 从就绪队列第二个结点开始比较
		while (current != NULL)
		{
			cout << "current->priority = " << current->priority << endl;
			cout << "pcb->priority = " << pcb->priority << endl;
			// 从队列第二个结点开始，
			// 依次遍历队列中每个结点的优先数与pcb的优先数
			// 直到碰到第一个结点的优先数<pcb的优先数为止
			if ((current->priority) < (pcb->priority)) break;
			// 遍历下一个结点
			previous = current;
			current = current->next;
			cout << "previous = " << previous << endl;
			cout << "current = " << current << endl;
		}
		// 跳出循环，应该在previous结点和current结点之间插入pcb
		previous->next = pcb;
		pcb->next = current;
		count++;
		cout << "previous->next = " << previous->next << endl;
		cout << "pcb->next = " << pcb->next << endl;
		cout << count << endl;
	}

	// 摘取就绪队列首结点
	PCB* GetFirst()
	{
		PCB* pcb = head;
		head = head->next;
		pcb->next = NULL;
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
};
PCBList readyList; // 就绪进程队列
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
		in >> (pcb->priority);
		in >> pcb->needTime;
		pcb->runTime = 0;
		pcb->next = NULL;
		// 将新PCB插入就绪队列
		readyList.Insert(pcb);
	}
}

// 执行pcb进程一个时间片，执行完后，修改pcb
static void Run(PCB* pcb)
{
	// 执行完一个时间片后，优先数-1
	pcb->priority--;
	// 已执行时间+1
	pcb->runTime++;
	if (pcb->runTime == pcb->needTime)
	{
		// 如果已执行时间等于进程执行所需时间，进程执行完毕
		pcb->state = State::finish;
	}
	else
	{
		// 还没执行完，需要将pcb重新插入就绪队列
		pcb->state = State::ready;
	}
}
int main()
{
	InputFromFile("pcblist.txt"); // 从pcblist.txt读入待调度进程信息
								  // 模拟调度
	int timeSlice = 0; // 时间片计数
	while (readyList.getCount() != 0) // 就绪队列非空
	{
		timeSlice++; // 轮转下一个时间片
		cout << "运行时间片 " << timeSlice << endl;
		// 从就绪队列摘取队首进程（优先数最高）运行
		PCB* currentPCB = readyList.GetFirst();
		Run(currentPCB);
		cout << "当前运行进程信息：" << endl;
		currentPCB->show();
		cout << "就绪队列列表：" << endl;
		readyList.PrintList();
		if (currentPCB->state == State::finish)
		{
			cout << "进程" << (currentPCB->name) << "执行完毕" << endl;
		}
		else
		{
			readyList.Insert(currentPCB);
		}
		system("pause"); // 按任意键继续
	}
	cout << "所有进程执行完毕" << endl;
	return 0;
}
