#include <iostream>
#include <vector>
#include <list>

using namespace std;

#include "Vector.h"

void PrintVector(Vector* vector)
{
	for (int i = 0; i < vector->Size(); i++)
	{
		cout << (*vector)[i] << endl;
	}
}

int main()
{
	Vector myV;
	myV.Reserve(100);


	for (int i = 0; i < 10; i++)
	{
		myV.PushBack(i);
		cout << myV.Capacity() << endl;
		cout << myV.Size() << endl;
		cout << "-----------------" << endl;
	}
	PrintVector(&myV);
	cout << "-----------------" << endl;


	for (int i = 0; i < 5; i++)
	{
		myV.PopBack();
		cout << myV.Capacity() << endl;
		cout << myV.Size() << endl;
		cout << "-----------------" << endl;
	}
	PrintVector(&myV);
	cout << "-----------------" << endl;


	myV.Clear();
	cout << myV.Capacity() << endl;
	cout << myV.Size() << endl;
	cout << "-----------------" << endl;
	PrintVector(&myV);
	cout << "-----------------" << endl;

	return 0;
}