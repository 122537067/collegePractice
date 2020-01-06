#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//����״̬
enum State
{
	ready,   //����״̬
	run,	 //����״̬
	finish	 //���״̬
};

class PCB
{
public:
	string name; // ������
	State state; // ����״̬
	double needTime; // ��Ҫ����ʱ��
	PCB* next; // ���ӵ���һ��PCB
	double priority;  //������
	void show()
	{
		cout << "��������" << name << ", "
			<< "��������" << priority << endl;
		//����Ȩ = (�ȴ�ʱ�� + ��Ҫ����ʱ��)  / ��Ҫ����ʱ��
	}
};

// �������У�������ÿ�������һ��������PCB��Ϣ��
// �������а���PCB������������PCB���
class PCBList
{
private:
	int count;    // �������г���
	PCB* head;
	double waitTime;  //�ȴ�ʱ��

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
	// ժȡ���������׽��
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
		// ����������������н�����Ϣ
		PCB* current = head;
		while (current != NULL)
		{
			current->show();
			current = current->next;
		}
	}

	void Insert(PCB* pcb)
	{
		// �����������Ϊ�գ�����ͷ���ָ��pcb
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

	//��������
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
PCBList readyList; //�������̶���

// ִ��pcb����һ��ʱ��Ƭ��ִ������޸�pcb
static void Run(PCB* pcb)
{
	//pcb->priority = (pcb->needTime + pcb->waitTime)/pcb->needTime;   //�޸�������
	//waitTime = pcb->waitTime + pcb->needTime;   //�޸ĵȴ�ʱ��
	//// �޸ľ������������н���������
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
		in >> pcb->needTime;
		pcb->priority = 1;
		pcb->next = NULL;
		// ����PCB�����������
		readyList.Insert(pcb);
	}
}

int main()
{
	cout << "2015030403013����� c++ ����ռ�ĸ���Ӧ�����ȵ����㷨" << endl;
	InputFromFile("pcblist.txt"); // ��pcblist.txt��������Ƚ�����Ϣ
								 
	double waitTime = readyList.getWaitTime();
	while (readyList.getCount() != 0) // �������зǿ�
	{
		PCB* currentPCB = readyList.GetFirst();
		waitTime = currentPCB->needTime + waitTime;
		readyList.setWaitTime(waitTime);  //�޸ĵȴ�ʱ��
		readyList.Resort(currentPCB); //��������
		cout << "����ʱ�� " << waitTime << endl;
		// �Ӿ�������ժȡ���׽��̣���������ߣ�����
		Run(currentPCB);
		cout << "��ǰ���н�����Ϣ��" << endl;
		currentPCB->show();
		cout << "���������б�" << endl;
		readyList.PrintList();
		cout << "����" << (currentPCB->name) << "ִ�����" << endl;
		system("pause"); // �����������
	}
	cout << "���н���ִ�����" << endl;
	return 0;
}