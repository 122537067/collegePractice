#include<iostream>
using namespace std;
int main()
{
	int* intpter = new int;
	*intpter = 50;
	float* foatptr = new float;
	*foatptr = 0.5;
	cout << intpter << ":" << *intpter<<endl;
	cout << foatptr << ":" << *foatptr;
	delete intpter;
	delete foatptr;
}