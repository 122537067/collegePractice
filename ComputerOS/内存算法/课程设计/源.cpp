#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

//�ڴ�ռ�״̬
enum State
{
	Free, //����״̬
	Busy  //ռ��״̬
};

//����ֶδ�����
class FreeStorage
{
public:
	string name;  //��ҵ����
	long size;    //�ռ��С
	long address; //�ռ��ַ
	State state;  //�ռ�״̬
};

//��������ṹ
class PCBList
{
public:
	FreeStorage* data;
	PCBList* front;   //ǰһ������
	PCBList* next;    //��һ������
};

PCBList* head; //ͷ���
PCBList* last; //β���

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
	int flag = 0;  //������
	PCBList *p = head->next;
	cout << endl << "Ŀǰ�������" << endl;
	cout << "==============================================" << endl << endl;
	cout << "������\t��ʼ��ַ\t������С\t״̬\t" << endl;
	while (p)
	{
		cout << "  " << flag++ << "\t"
		     << "  " << p->data->address << "\t\t"
			 << " " << p->data->size << "KB\t\t";
		if (p->data->state == State::Free) cout << "����\n\n";
		else cout << p->data->name << endl << endl;
		p = p->next;
	}
	cout << "==============================================" << endl << endl;
}

int main()
{
	int size = 640;  //��ʼ��״̬�¿��ÿռ�
	//while (1)
	//{
	//	cout << "�������ʼ״̬�¿��õĿռ䣨KB����";
	//	cin >> size;
	//	if (cin.good() && size > 0 && size < 1000)
	//	{
	//		break;
	//	}
	//	else
	//	{
	//		cin.clear();
	//		cin.ignore();  //������Ƿ��ַ�ʱ�����
	//		cout << "�ռ��С����С��0������1000������������!" << endl;
	//	}
	//}

	int choice=1;  //�㷨ѡ����
	cout << "��������ʹ�õ��ڴ�����㷨��"<<endl
		<< "1.�״���Ӧ�㷨" << endl
		<< "2.�����Ӧ�㷨" << endl;
	//cin >> choice;
	if (choice == 2)
	{
		cout << "��ǰѡ�������Ӧ�㷨" << endl;
	}
	else
	{
		choice = 1;
		cout << "��ǰѡ���״���Ӧ�㷨" << endl;
	}

	Start(size);   //��ʼ������
	
	Show();
	//while (true)
	//{
	//	Show();
	//}
}