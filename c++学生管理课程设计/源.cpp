#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include<algorithm>
#include"Student.h"
#include"Lesson.h"
using namespace std;
Student children[50];
Lesson cours[10];
int people;
void show()
{
	char line[50];
	ifstream infile;
	infile.open("studentmessage.txt");
	while (infile.getline(line,50))
	{
		cout << line << endl;
	}
	infile.close();
}
void Student::read()              //读入信息
{
	ifstream fin("studentmessage.txt", ios::in);
	for (int i = 0; 50 > i; i++)
	{
		if (fin.eof()) break;
		fin >> children[i].name >> children[i].number >> children[i].account;
		for (int j = 0; children[i].account > j; j++)
		{
			fin >> children[i].course[j].l_name >> children[i].course[j].score;
		}
		fin >>children[i].my_score;
	}
	fin.close();
}
void Lesson::read()
{
	ifstream fin("lessonmessage.txt", ios::in);
	for (int i = 0; 50 > i; i++)
	{
		if (fin.eof()) break;
		fin >> cours[i].l_name >> cours[i].score;
		
	}
	fin.close();
}
void Lesson::add_lesson()
{
	cout << "输入添加课程名称：";
	ofstream out;
	out.open("lessonmessage.txt", ios::app);
	cin >> l_name;
	score = 0;
	out << l_name << '\t';
	for (int i = 0; people > i; i++)
	{
		for (int j = 0; 10 > j; j++)
		{
			if (l_name == children[i].course[j].l_name)
			{
				score = children[i].course[j].score + score;
			}
		}
	}
	out << score << '\t';
	out.close();
	cout << "添加成功！" << endl;
}
void write_people()
{
	ofstream out;
	out.open("peopleaccount.txt");
	out << people;
	out.close();
}
void menu()
{
	cout << "主菜单" << endl
		<< "1.学生信息" << endl
		<< "2.课程信息" << endl;
}
void menu1()
{
	cout << "学生信息" << endl
		<< "1.添加" << endl
		<< "2.修改" << endl
		<< "3.删除" << endl
		<< "4.查找" << endl
		<< "5.按学号排序" << endl
		<< "6.按成绩排序" << endl;
}
void menu2()
{
	cout << "课程信息" << endl
		<< "1.添加" << endl
		<< "2.修改" << endl
		<< "3.删除" << endl
		<< "4.查找" << endl
		<< "5.统计某门科目的平均分和最高分" << endl;
}
void people_account()                       //读取人数
{
	int j=0;
	ifstream infile;
	char s_people;
	char allpeople[3];
	infile.open("peopleaccount.txt");
	infile.get(s_people);
	while (!infile.eof())            //通过.txt人数读取
	{
		allpeople[j] = s_people;
		j++;
		infile.get(s_people);
	}
	stringstream ss;				//string型转int型
	ss << allpeople;
	ss >> people;
	infile.close();
}
void find_studentname()                  //按照姓名搜索
{
	int find = 0;
	string word;
	cout << "请输入完整学生姓名进行搜索:";
	cin >> word;
	for (int i = 0; i<people; i++)
	{
		if (children[i].get_name() == word)
		{
			cout << "学号	" << "姓名	" << "所选科目数	" << "科目	" << "分数	" << "总分" << endl;
			find++;
			cout << children[i].get_number() << '\t' << children[i].get_name() << '\t' << children[i].get_account() << '\t';
			for (int j = 0; children[i].get_account() > j; j++)
			{
				cout << children[i].course[j].l_name << '\t' << children[i].course[j].score << '\t';
			}
			cout << children[i].my_score;
		}
		if (find == 0 && i == people)
		{
			cout << "找不到你想要的学生哈哈哈哈" << endl;
		}
	}
}
void find_studentnumber()                  //按照学号搜索
{
	int find = 0;
	string word;
	cout << "请输入完整学生学号进行搜索:";
	cin >> word;
	for (int i = 0; i<people; i++)
	{
		if (children[i].get_name() == word)
		{
			cout << "学号	" << "姓名	" << "所选科目数	" << "科目	" << "分数	" << "总分" << endl;
			find++;
			cout << children[i].get_number() << '\t' << children[i].get_name() << '\t' << children[i].get_account() << '\t';
			for (int j = 0; children[i].get_account() > j; j++)
			{
				cout << children[i].course[j].l_name << '\t' << children[i].course[j].score << '\t';
			}
			cout << children[i].my_score;
		}
		if (find == 0 && i == people)
		{
			cout << "Not found!" << endl;
		}
	}
}
void find_studentaccount()                  //按照科目数量搜索
{
	int find = 0;
	int word;
	cout << "请输入完整学生学号进行搜索:";
	cin >> word;
	for (int i = 0; i<people; i++)
	{
		if (children[i].get_account() == word)
		{
			cout << "学号	" << "姓名	" << "所选科目数	" << "科目	" << "分数	" << "总分" << endl;
			find++;
			cout << children[i].get_number() << '\t' << children[i].get_name() << '\t' << children[i].get_account() << '\t';
			for (int j = 0; children[i].get_account() > j; j++)
			{
				cout << children[i].course[j].l_name << '\t' << children[i].course[j].score << '\t';
			}
			cout << children[i].my_score;
		}
		if (find == 0 && i == people)
		{
			cout << "Not found!" << endl;
		}
	}
}
void menu1_4()
{
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:find_studentname(); break;
	case 2:find_studentnumber(); break;
	case 3:find_studentaccount(); break;
	}
}
void delete_student()
{
	char a;
	cout << "请输入需要删除学生的学号：";
	int find = 0;
	string word;
	cin >> word;
	for (int i = 0; i<people; i++)
	{
		if (children[i].get_number() == word)
		{
			find++;
			cout << "此学生信息：" << endl;
			cout << "学号	" << "姓名	" << "所选科目数	" << "科目	" << "分数	" <<"总分"<< endl;
			cout << children[i].get_number() << children[i].get_name() << children[i].get_account();
			for (int j = 0; children[i].get_account() > j; j++)
			{
				cout << children[i].course[j].l_name << children[i].course[j].score;
			}
			cout << children[i].my_score;
			cout << "输入“Y”确定删除" << endl;
			cin >> a;
			if (a == 'Y' || a == 'y')
			{
				ofstream out;
				out.open("studentmessage.txt");
				for (int k = 0; people>k; k++)
				{
					if (i != k)
					{
						out << children[i].get_number() << " " << children[i].get_name() << " " << children[i].get_account() << " ";
						for (int j = 0; children[i].get_account() > j; j++)
						{
							out << children[i].course[j].l_name << " " << children[i].course[j].score << " ";
							children[i].my_score = children[i].my_score + children[i].course[i].score;
						}
						out << children[i].my_score;
					}
				}
				cout << "删除成功" << endl;
				out.close();
			}
		}
		if (find == 0 && i == people)
		{
			cout << "Not found!" << endl;
		}
	}
}
void delete_lesson()
{
	cout << "输入删除课程名称：";
	int find = 0;
	char a;
	string word;
	cin >> word;
	for (int i = 0; i<people; i++)
	{
		if (cours[i].l_name == word)
		{
			find++;
			cout << "此课程信息：" << endl;
			cout << "课程：" << cours[i].l_name << '\t' << "总分：" << cours[i].score << endl;
			cout << "输入“Y”确定删除" << endl;
			cin >> a;
			if (a == 'Y' || a == 'y')
			{
				ofstream out;
				out.open("lessonmessage.txt");
				for (int k = 0; people>k; k++)
				{
					if (i != k)
					{
						out << cours[i].l_name << '\t' << cours[i].score << endl;
					}
				}
				cout << "删除成功" << endl;
				out.close();
			}
		}
		if (find == 0 && i == people)
		{
			cout << "Not found!" << endl;
		}
	}
}
void change_student()
{
	int find = 0;
	string word;
	cout << "请输入需要修改学生的学号：";
	cin >> word;
	char a;
	for (int i = 0; i<people; i++)
	{
		cout << "该学生的信息：" << endl;
		cout << "学号	" << "姓名	" << "所选科目数	" << "科目	" << "分数	" << "总分" << endl;
		if (children[i].get_number() == word)
		{
			find++;
			cout << children[i].get_number() << children[i].get_name() << children[i].get_account();
			for (int j = 0; children[i].get_account() > j; j++)
			{
				cout << children[i].course[j].l_name << children[i].course[j].score;
			}
			cout << "输入Y确定修改：";
			cin >> a;
			if (a == 'Y' || a == 'y')
			{

				ofstream out;
				out.open("studentmessage.txt", ios::app);
				for (int k = 0; people>k; k++)
				{
					if (i != k)
					{
						out << children[i].get_number() << " " << children[i].get_name() << " " << children[i].get_account() << " ";
						for (int j = 0; children[i].get_account() > j; j++)
						{
							out << children[i].course[j].l_name << " " << children[i].course[j].score << " ";
							children[i].my_score = children[i].my_score + children[i].course[i].score;
						}
						out << children[i].my_score;
					}
				}
				cout << "输入修改学生的姓名：";
				cin >> children[i].name;
				out << children[i].name << '\t';
				cout << "输入修改学生的学号：";
				cin >> children[i].number;
				out << children[i].number << '\t';
				cout << "输入修改学生总共选了多少门科目：";
				cin >> children[i].account;
				out << children[i].account << '\t';
				for (int k = 0; children[i].account>k; k++)
				{
					cout << "第" << i + 1 << "门科目是：";
					cin >> children[i].course[k].l_name;
					out << children[i].course[k].l_name << '\t';
					cout << "此门科目的成绩是：";
					cin >> children[i].course[k].score;
					out << children[i].course[k].score << '\t';
					children[i].my_score = children[i].my_score + children[i].course[k].score;
				}
				out << children[i].my_score << '\t'; out.close();
			}
		}
		if (find == 0 && i == people)
		{
			cout << "找不到你修改的学生" << endl;
		}
	}
}
void change_lesson()
{
	int find = 0;
	string word;
	cout << "请输入需要修改课程的名称：";
	cin >> word;
	char a;
	for (int i = 0; i<people; i++)
	{
		cout << "该课程的信息：" << endl;
		if (cours[i].l_name == word)
		{
			cout << "课程：" << cours[i].l_name << '\t' << "总分：" << cours[i].score << endl;
			cout << "输入Y确定修改：";
			cin >> a;
			if (a == 'Y' || a == 'y')
			{

				ofstream out;
				out.open("lessonmessage.txt", ios::app);
				for (int k = 0; 10>k; k++)
				{
					if (i != k)
					{
						out << cours[i].l_name << '\t' << cours[i].score << endl;
					}
				}
				cout << "输入修改课程的名字：";
				cin >> cours[i].l_name;
				out << cours[i].l_name<< '\t';
				cours[i].score = 0;
				for (int i = 0; people > i; i++)
				{
					for (int j = 0; 10 > j; j++)
					{
						if (cours[i].l_name == children[i].course[j].l_name)
						{
							cours[i].score = children[i].course[j].score + cours[i].score;
						}
					}
				}
			}
		}
		if (find == 0 && i == people)
		{
			cout << "找不到你修改的学生" << endl;
		}
	}
}
void number_sort()
{
	cout << "学号	" << "姓名	" << "所选科目数	" << "科目	" << "分数	" << "总分" << endl;
	long long int numb[50];
	long long int num[50];
	for (int i = 0; people > i; i++)
	{
		numb[i]= atoi(children[i].number.c_str());
		num[i] = atoi(children[i].number.c_str());
	}
	sort(numb, numb + people);
	for (int i = 0; people > i; i++)
	{
		for (int j = 0; people > j; j++)
		{
			if (numb[i] == num[j])
			{
				cout << children[j].get_number() << '\t' << children[j].get_name() << '\t' << children[j].get_account() << '\t';
				for (int k = 0; children[j].get_account() > k; k++)
				{
					cout << children[j].course[k].l_name << '\t' << children[j].course[k].score << '\t';
				}
				cout << children[j].my_score << '\t';
			}
		}
		cout << endl;
	}
}
void score_sort()
{
	cout << "学号	" << "姓名	" << "所选科目数	" << "科目	" << "分数	" << "总分" << endl;
	int scoree[50];
	for (int i = 0; people > i; i++)
	{
		scoree[i] = children[i].my_score;
	}
	sort(scoree, scoree + people);
	for (int i = 0; people > i; i++)
	{
		for (int j = 0; people > j; j++)
		{
			if (scoree[i] ==children[j].my_score)
			{
				cout << children[j].get_number() << '\t' << children[j].get_name() << '\t' << children[j].get_account() << '\t';
				for (int k = 0; children[j].get_account() > k; k++)
				{
					cout << children[j].course[k].l_name << '\t' << children[j].course[k].score << '\t';
				}
				cout << children[j].my_score << '\t';
			}
		}
		cout << endl;
	}
}
void find_lesson()
{
	int find = 0;
	string word;
	cout << "请输入完整课程名字进行搜索:";
	cin >> word;
	for (int i = 0; i<10; i++)
	{
		if (cours[i].l_name == word)
		{
			find++;
			cout <<"课程："<< cours[i].l_name << '\t' << "总分："<<cours[i].score << endl;
		}
		if (find == 0 && i == people)
		{
			cout << "找不到你搜索的结果" << endl;
		}
	}
}
void caculate()
{
	int find = 0;
	int max=0;
	string word;
	double aver=0;
	cout << "输入需要统计科目的名称：";
	cin >> word;
	for (int i = 0; i<10; i++)
	{
		if (cours[i].l_name == word)
		{
			cout << cours[i].l_name << '\t' << cours[i].score << endl;
			for (int j = 0; people > j; j++)
			{
				for (int k = 0; 10 > k; k++)
				{
					if (children[j].course[k].l_name == word)
					{
						find++;
						max = children[j].course[k].score > max ? children[j].course[k].score : max;
					}
				}
			}
			aver = cours[i].score / find;
		}
		if (find == 0 && i == people)
		{
			cout << "找不到你搜索的结果" << endl;
		}
	}
	cout <<"最高分："<< max << " " <<"平均分："<< aver << endl;
}
int main()
{
	int choice, choice1,choice2;
	while (1)
	{
		people_account();
		children[people].read();
		cours[10].read();
		menu();
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:menu1();
			cin >> choice1;
			switch (choice1)
			{
			case 1:children[people].add_student(); people++; write_people(); break;
			case 2:change_student(); break;
			case 3:delete_student(); people--; write_people(); break;
			case 4:find_student(); menu1_4(); break;
			case 5:number_sort(); break;
			case 6:score_sort(); break;
			default:cout << "输入有误"; break;
			}
			break;
		case 2:menu2();
			cin>> choice2;
			switch (choice2)
			{
			case 1:cours[10].add_lesson(); break;
			case 2:change_lesson(); break;
			case 3:delete_lesson();break;
			case 4:find_lesson(); break;
			case 5:caculate(); break;
			default:cout << "输入有误"; break;
			}
			break;
		}
		system("pause");
		system("cls");
	}
}