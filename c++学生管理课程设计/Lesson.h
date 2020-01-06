#pragma once
#include<iostream>
#include<string>
using namespace std;
class Lesson
{
private:
	string l_name;
	int score;
public:
	friend class Student;
	Lesson(string l_name="Unkonw");
	string get_l_name();
	int get_average();
	int get_max();
	void add_lesson();
	friend void change_lesson();
	friend void delete_lesson();
	void find_lesson();
	friend void read(string name, string number, int account);
	friend void find_studentaccount();
	friend void find_studentname();
	friend void find_studentnumber();
	friend void change_student();
	friend void delete_student();
	friend void number_sort();
	friend void score_sort();
	friend void find_lesson();
	void read();
	friend void caculate();
};