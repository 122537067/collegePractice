#pragma once
#include<iostream>
#include<string>
#include"Lesson.h"
using namespace std;
class Student
{
private:
	string name;          //学生姓名
	string number;       //学号
	int account;           //所选科目数
	Lesson course[10];         //所选科目
	int my_score;			//所有科目成绩
public:
	friend class Lesson;
	Student(string name = "00000000000000", string number = "Unkonw",int account=0);
	void add_student();				//添加
	friend void find_student();			//查找
	friend void change_student();          //修改
	friend void delete_student();          //删除
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