#pragma once
#include<iostream>
#include<string>
#include"Lesson.h"
using namespace std;
class Student
{
private:
	string name;          //ѧ������
	string number;       //ѧ��
	int account;           //��ѡ��Ŀ��
	Lesson course[10];         //��ѡ��Ŀ
	int my_score;			//���п�Ŀ�ɼ�
public:
	friend class Lesson;
	Student(string name = "00000000000000", string number = "Unkonw",int account=0);
	void add_student();				//���
	friend void find_student();			//����
	friend void change_student();          //�޸�
	friend void delete_student();          //ɾ��
	friend void read(string name, string number, int account);
	string get_name();
	string get_number();
	int get_account();
	void get_course();
	void read();
	friend void find_studentaccount();
	friend void find_studentname();
	friend void find_studentnumber();
	friend void number_sort();
	friend void score_sort();
	friend void change_lesson();
	friend void find_lesson();
	friend void caculate();
};