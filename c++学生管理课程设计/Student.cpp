#include<iostream>
#include<string>
#include<fstream>
#include"Student.h"
#include"Lesson.h"
using namespace std;
Student::Student(string na, string nu, int ac)
{
	name = na;
	number = nu;
	account = ac;
}
string Student::get_name()
{
	return name;
}
string Student::get_number()
{
	return number;
}
int Student::get_account()
{
	return account;
}
void Student::get_course()
{
	for (int i = 0; account > i; i++)
	{
		cout << course[i].l_name << " ";
	}
}
void Student::add_student()     //����ѧ��
{
	ofstream out;
	out.open("studentmessage.txt",ios::app);
	my_score = 0;
	cout << "��������ѧ����������";
	cin >>name;
	out << name << '\t';
	cout << "��������ѧ����ѧ�ţ�";
	cin >> number;
	out << number << '\t';
	cout << "��������ѧ���ܹ�ѡ�˶����ſ�Ŀ��";
	cin >> account;
	out << account << '\t';
	for (int i = 0; account> i; i++)
	{
		cout << "��" << i + 1 << "�ſ�Ŀ�ǣ�";
		cin >> course[i].l_name;
		out << course[i].l_name << '\t';
		cout << "���ſ�Ŀ�ĳɼ��ǣ�";
		cin >> course[i].score;
		out << course[i].score << '\t';
		my_score = course[i].score + my_score;
	}
	out << my_score << '\t';
	out << endl;
	out.close();
}
void find_student()
{
	cout << "����ѧ��" << endl
		<< "1.������������" << endl
		<< "2.����ѧ�Ų���" << endl
		<< "3.�����Ŀ��������" << endl;
}