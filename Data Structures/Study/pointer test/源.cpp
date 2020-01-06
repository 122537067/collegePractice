#include<iostream>
using namespace std;
int main()
{
	int arry = 0;
	for(int i=0;i<100;i++)
	{
		arry++;
		cout <<arry<<":"<< &arry<<endl;
	}
}