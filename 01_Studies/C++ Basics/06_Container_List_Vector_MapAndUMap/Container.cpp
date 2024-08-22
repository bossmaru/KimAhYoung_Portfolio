#include <iostream>
#include <vector>
#include <list>

using namespace std;

#include "Vector.h"
#include "List.h"


void PrintArr(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}

template<typename T>
void PrintVector(Vector<T>* vector)
{
	for (int i = 0; i < vector->Size(); i++)
	{
		cout << (*vector)[i] << endl;
	}
}

template<typename T, typename Container>
void PrintTemp(T t, Container container)
{
	t = container.begin();
	for (t; t != container.end(); t++)
	{
		cout << *t << endl;
	}
}


int main()
{
#pragma region Vector
	int temp = 1;
	
	// 정적배열 -> 배열 크기에 temp 못넣음. 상수값만 넣을 수 있음
	int arr[5] = { 1, 2, 3, 4, 5 };

	// 얘는 크기 지정 안함
	// 동적 배열(가변 배열)
	vector<int> v;
	v.reserve(10);
	// v.resize(1000); /// 0~999는 0으로 초기화

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		// v.push_back(i);
		// cout << v.capacity() << endl;
		// cout << v.size() << endl;
		// cout << "-----------------" << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		v.pop_back();
	}

	v.clear(); // 함수 종료될때까지 capacity 해제 안됨


	// 이름 없음 ->  임시객체 -> 생성자 다음 바로 소멸자 호출 -> 이거를 v랑 바꾸겠다.
	// effective C++
	vector<int>().swap(v); // 이러면 해제됨


	// cout << v.capacity() << endl;
	// cout << v.size() << endl;

	// for (int i = 0; i < v.size(); i++)
	// {
	// 	cout << v[i] << endl;
	// }
#pragma endregion


#pragma region List
	list<int> l;

	for (int i = 0; i < 5; i++)
	{
		l.push_back(i);
		l.push_front(i);
	}

#pragma endregion


#pragma region MyVector
	Vector<int> myV;
	myV.Reserve(100);


	for (int i = 0; i < 10; i++)
	{
		myV.PushBack(i);
		// cout << myV.Capacity() << endl;
		// cout << myV.Size() << endl;
		// cout << "-----------------" << endl;
	}
	// PrintVector(&myV);
	// cout << "-----------------" << endl;


	for (int i = 0; i < 5; i++)
	{
		// myV.PopBack();
		// cout << myV.Capacity() << endl;
		// cout << myV.Size() << endl;
		// cout << "-----------------" << endl;
	}
	// PrintVector(&myV);
	// cout << "-----------------" << endl;


	// myV.Clear();
	// cout << myV.Capacity() << endl;
	// cout << myV.Size() << endl;
	// cout << "-----------------" << endl;
	// PrintVector(&myV);
	// cout << "-----------------" << endl;

#pragma endregion


#pragma region MyList
	List<int> myList;

	myList.PushBack(5);
	myList.PushBack(3);
	myList.PushBack(2);
	myList.PushBack(1);

	for (int i = 0; i < myList.Size(); i++)
	{
		cout << myList[i] << endl;
	}

#pragma endregion


#pragma region Iterator
	cout << "------ Iterator ------" << endl;

	vector<int>::iterator vIter = v.begin();
	list<int>::iterator lIter = l.begin();

	// vector, iterator로 순회하는 방법
	for (vIter; vIter != v.end(); vIter++)
	{
		// cout << *vIter << endl;
	}

	for (lIter; lIter != l.end(); lIter++)
	{
		// cout << *lIter << endl;
	}

	// PrintTemp<vector<int>::iterator, vector<int>>(vIter, v);
	// PrintTemp<list<int>::iterator, list<int>>(lIter, l);

#pragma endregion

	Vector<int>::Iterator myVIter;
	myVIter = myV.begin();
	for (myVIter; myVIter != myV.end(); myVIter++)
	{
		cout << *myVIter << endl;
	}


	List<int>::Iterator myLIter;
	myLIter = myList.begin();
	for (myLIter; myLIter != myList.end(); myLIter++)
	{
		cout << *myLIter << endl;
	}

	PrintTemp<List<int>::Iterator, List<int>>(myLIter, myList);



	return 0;
}