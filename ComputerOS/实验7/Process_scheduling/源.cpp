#include <iostream>
#include <fstream>
#include <string>
using namespace std;
enum State 	// ����״̬
{
	ready, // ����
	run, // ����
	finish // ���
};
class PCB
{
public:
	string name; // ������
	State state; // ����״̬
	int priority; // ������
	int needTime; // ��Ҫ����ʱ��
	int runTime; // ������ʱ��
	PCB* next; // ���ӵ���һ��PCB
	void show()
	{
		cout << "��������" << name << ", "
			<< "��������" << priority << ", "
			<< "������ʱ�䣺" << runTime << ", "
			<< "����Ҫʱ�䣺" << needTime - runTime << endl;
	}
};

// �������У�������ÿ�������һ��������PCB��Ϣ��
// �������а���PCB������������PCB���
class PCBList
{
private:
	int count;    // �������г���
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
	// ��pcb������������С����������������
	void Insert(PCB* pcb)
	{
		// �����������Ϊ�գ�����ͷ���ָ��pcb
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
		// �Ƚ�pcb������׽���������
		cout << "head->priority = " <<head->priority << endl;
		cout << "pcb->priority = " << pcb->priority << endl;
		if ((head->priority) < (pcb->priority))
		{
			cout << "(head->priority) < (pcb->priority)" << endl;
			// ���pcb���������ȶ��׵�pcb����������
			cout << "pcb->next = " << pcb->next << endl;
			cout << "head = " << head << endl;
			pcb->next = head;
			head = pcb;
			count++;
			cout << count << endl;
			return;
		}
		// pcb����λ�ò��ڶ���֮�ף��������β���pcb����λ��
		PCB* previous = head;
		PCB* current = head->next;
		cout << "previous = " << previous <<"----"<<head<< endl;
		cout << "current = " << current << "----" << head->next << endl;
		// �Ӿ������еڶ�����㿪ʼ�Ƚ�
		while (current != NULL)
		{
			cout << "current->priority = " << current->priority << endl;
			cout << "pcb->priority = " << pcb->priority << endl;
			// �Ӷ��еڶ�����㿪ʼ��
			// ���α���������ÿ��������������pcb��������
			// ֱ��������һ������������<pcb��������Ϊֹ
			if ((current->priority) < (pcb->priority)) break;
			// ������һ�����
			previous = current;
			current = current->next;
			cout << "previous = " << previous << endl;
			cout << "current = " << current << endl;
		}
		// ����ѭ����Ӧ����previous����current���֮�����pcb
		previous->next = pcb;
		pcb->next = current;
		count++;
		cout << "previous->next = " << previous->next << endl;
		cout << "pcb->next = " << pcb->next << endl;
		cout << count << endl;
	}

	// ժȡ���������׽��
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
		// ����������������н�����Ϣ
		PCB* current = head;
		while (current != NULL)
		{
			current->show();
			current = current->next;
		}
	}
};
PCBList readyList; // �������̶���
void InputFromFile(string fileName)
{
	ifstream in;
	in.open(fileName);
	if (in.fail())
	{
		cout << "���ļ�����" << endl;
		exit(1);
	}
	// ��ȡ������
	int n;
	in >> n;;
	// ���ζ�ȡÿ������
	for (int i = 0; i < n; i++)
	{
		PCB* pcb = new PCB();
		in >> (pcb->name);
		pcb->state = State::ready;
		in >> (pcb->priority);
		in >> pcb->needTime;
		pcb->runTime = 0;
		pcb->next = NULL;
		// ����PCB�����������
		readyList.Insert(pcb);
	}
}

// ִ��pcb����һ��ʱ��Ƭ��ִ������޸�pcb
static void Run(PCB* pcb)
{
	// ִ����һ��ʱ��Ƭ��������-1
	pcb->priority--;
	// ��ִ��ʱ��+1
	pcb->runTime++;
	if (pcb->runTime == pcb->needTime)
	{
		// �����ִ��ʱ����ڽ���ִ������ʱ�䣬����ִ�����
		pcb->state = State::finish;
	}
	else
	{
		// ��ûִ���꣬��Ҫ��pcb���²����������
		pcb->state = State::ready;
	}
}
int main()
{
	InputFromFile("pcblist.txt"); // ��pcblist.txt��������Ƚ�����Ϣ
								  // ģ�����
	int timeSlice = 0; // ʱ��Ƭ����
	while (readyList.getCount() != 0) // �������зǿ�
	{
		timeSlice++; // ��ת��һ��ʱ��Ƭ
		cout << "����ʱ��Ƭ " << timeSlice << endl;
		// �Ӿ�������ժȡ���׽��̣���������ߣ�����
		PCB* currentPCB = readyList.GetFirst();
		Run(currentPCB);
		cout << "��ǰ���н�����Ϣ��" << endl;
		currentPCB->show();
		cout << "���������б�" << endl;
		readyList.PrintList();
		if (currentPCB->state == State::finish)
		{
			cout << "����" << (currentPCB->name) << "ִ�����" << endl;
		}
		else
		{
			readyList.Insert(currentPCB);
		}
		system("pause"); // �����������
	}
	cout << "���н���ִ�����" << endl;
	return 0;
}
