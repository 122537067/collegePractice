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
void Student::add_student()     //新增学生
{
	ofstream out;
	out.open("studentmessage.txt",ios::app);
	my_score = 0;
	cout << "输入新增学生的姓名：";
	cin >>name;
	out << name << '\t';
	cout << "输入新增学生的学号：";
	cin >> number;
	out << number << '\t';
	cout << "输入新增学生总共选了多少门科目：";
	cin >> account;
	out << account << '\t';
	for (int i = 0; account> i; i++)
	{
		cout << "第" << i + 1 << "门科目是：";
		cin >> course[i].l_name;
		out << course[i].l_name << '\t';
		cout << "此门科目的成绩是：";
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
	cout << "查找学生" << endl
		<< "1.输入姓名查找" << endl
		<< "2.输入学号查找" << endl
		<< "3.输入科目数量查找" << endl;
}