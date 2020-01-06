#include<iostream>
#include<stdlib.h>
#include<string>>
using namespace std;

typedef int Status;
int flag;

//����״̬
enum State
{
	FREE,  //����
	BUSY   //ռ��
};
typedef struct structure   //�����ڴ�ṹ
{
	long size;    //�ڴ������С
	long address; //�ڴ������ַ
	State state;   //�ڴ�����״̬
}PCB;


typedef struct PCB_Part  //ͨ���������Ӹ�������
{
	PCB data;
	struct PCB_Part *pre; //ǰ��ָ��
	struct PCB_Part *next;  //���ָ��
}

PCB_Part, *PCBList;
PCBList head; //ͷ���
PCBList last;  //β���
Status alloc(int);//�ڴ����
Status free(int); //�ڴ����
Status FirstFit(int);//�״���Ӧ�㷨
Status BestFit(int); //�����Ӧ�㷨
void Show();//�鿴����
Status CreatList(int);//�����ռ��

Status CreatList(int max_length)//��ʼ���ڴ�����ṹ
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

//�����ڴ�
Status alloc(int choicec)
{
	int request = 0;
	cout << "������Ҫ������ڴ��С(KB)��";
	cin >> request;
	if (request<0 || request == 0)
	{
		cout << "�����С�����ʣ������ԣ�" << endl;
		return 0;
	}

	//�����Ӧ�㷨
	if (choicec == 2)
	{
		if (BestFit(request) == 1) cout << "����ɹ���" << endl;
		else cout << "�����ڴ治�㣬���䲻�ɹ�" << endl;
		return 1;
	}
	//�״���Ӧ�㷨��Ĭ�ϣ�
	else
	{
		if (FirstFit(request) == 1) cout << "����ɹ���" << endl;
		else cout << "�����ڴ治�㣬���䲻�ɹ�" << endl;
		return 1;
	}
}

//�״���Ӧ�㷨
Status FirstFit(int request)
{
	//Ϊ������ҵ�����¿ռ��ҳ�ʼ��
	PCBList temp = (PCBList)malloc(sizeof(PCB_Part));
	temp->data.size = request;
	temp->data.state = State::BUSY;

	PCB_Part *p = head->next;
	while (p)
	{
		if (p->data.state == State::FREE && p->data.size == request)
		{//�д�Сǡ�ú��ʵĿ��п�
			p->data.state = State::BUSY;
			return 1;
			break;
		}
		if (p->data.state == State::FREE && p->data.size>request)
		{//�п��п�������������Ҫ�ָ�ʣ��
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

//�����Ӧ�㷨
Status BestFit(int request)
{
	int least; //��¼��Сʣ��ռ�
	PCBList temp = (PCBList)malloc(sizeof(PCB_Part));
	temp->data.size = request;
	temp->data.state = State::BUSY;
	PCB_Part *p = head->next;
	PCB_Part *q = NULL; //��¼��Ѳ������λ��

	while (p) //��ʼ����С�ռ�����λ��
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

	if (q == NULL) return 0;//û���ҵ����з���
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


//�ڴ����
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
		cout << endl << "�˷����Ų����ڣ�" << endl;
	}
	else if (p->data.state == State::FREE)
	{
		cout <<endl<< "���ڴ�ռ��Ѵ��ڿ���״̬���������" << endl;
	}
	else
	{

		p->data.state = State::FREE;
		if (p->pre != head && p->pre->data.state == State::FREE)//��ǰ��Ŀ��п�����
		{
			p->pre->data.size += p->data.size;
			p->pre->next = p->next;
			p->next->pre = p->pre;
			p = p->pre;
		}
		if (p->next != last && p->next->data.state == State::FREE)//�����Ŀ��п�����
		{
			p->data.size += p->next->data.size;
			p->next->next->pre = p;
			p->next = p->next->next;
		}
		if (p->next == last && p->next->data.state == State::FREE)//�����Ŀ��п�����
		{
			p->data.size += p->next->data.size;
			p->next = NULL;
		}
	}
	return 1;
}

//��ʾ����������
void Show()
{
	int flag = 0;
	cout << "\n�ڴ�������:\n";
	cout << "===============================================\n\n";
	PCB_Part *p = head->next;
	cout << "������\t��ʼ��ַ\t������С\t״̬\n\n";
	while (p)
	{
		cout << "  " << flag++ << "\t";
		cout << "  " << p->data.address << "\t\t";
		cout << " " << p->data.size << "KB\t\t";
		if (p->data.state == State::FREE) cout << "����\n\n";
		else cout << "�ѷ���" << endl;
		p = p->next;
	}
	cout << "================================================\n\n";
}

//������
void main()
{
	cout << "================================================\n";
	cout << "�������ڴ��С(KB)��";
	int max_length;
	cin >> max_length;   //�����ڴ����ռ�
	while (true)
	{
		if (cin.good() && max_length > 0 && max_length < 100000)
		{
			break;
		}
		else
		{
			cin.clear();   //���cin��
			cin.ignore();
			cout << "��������ڴ��С����1������100000��\n";
			cin >> max_length;
		}
	}
	cout << "================================================\n\n";
	int choicec;//�㷨ѡ����
	cout << "��������ʹ�õ��ڴ�����㷨��\n";
	cout << "1.�״���Ӧ�㷨��First Fit��\n2.�����Ӧ�㷨(Best Fit)\n";

	cin >> choicec;

	while (true)
	{
		if (cin.good() && (choicec==1 > 0 || choicec == 2))
		{
			break;
		}
		else
		{
			cin.clear();   //���cin��
			cin.ignore();
			cout << "����������������룺\n";
			cin >> choicec;
		}
	}

	CreatList(max_length); //�����ռ��
	int choice;  //����ѡ����

	while (1)
	{
		Show();
		cout << "���������Ĳ�����";
		cout << "\n1: �����ڴ�\n2: �����ڴ�\n0: �˳�\n";

		cin >> choice;
		if (choice == 1) alloc(choicec); // �����ڴ�
		else if (choice == 2)  // �ڴ����
		{
			int flag;
			cout << "��������Ҫ�ͷŵķ����ţ�";
			cin >> flag;
			free(flag);
		}
		else if (choice == 0) break; //�˳�
		else //�����������
		{
			cout << "���������������" << endl;
			continue;
		}
	}
}
