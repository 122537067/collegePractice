#include<iostream>
#include<string>
#include<fstream>
#include"Student.h"
#include"Lesson.h"
using namespace std;
Lesson::Lesson(string na)
{
	l_name = na;
}
string Lesson::get_l_name()
{
	return l_name;
}