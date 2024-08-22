#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool Func(const int& value)
{
	if (value > 15)
		return true;

	return false;
}

int MultiplyThree(int num)
{
	return num * 3;
}

int main()
{
	vector<int> myV;

	myV.push_back(3);
	myV.push_back(5);
	myV.push_back(1);
	myV.push_back(7);
	myV.push_back(1);

	myV.push_back(21);
	myV.push_back(2);
	myV.push_back(4);
	myV.push_back(3);
	myV.push_back(5);


	// 1이 있는지 찾아주세요. 그리고 index나 혹은 iterator 자리를 찾아주세요.
	int index = 0;
	for (int i = 0; i < myV.size(); i++)
	{
		if (myV[i] == 1)
		{
			index = i;
			break;
		}
	}

	vector<int>::iterator Iter = myV.begin();
	for (Iter; Iter != myV.end(); Iter++)
	{
		if (*Iter == 1)
		{
			break;
		}
	}

	cout << myV[index] << endl;
	cout << *Iter << endl;

	Iter = std::find(myV.begin(), myV.end(), 1);
	if (Iter != myV.end())
		cout << *Iter << endl;

	cout << "--------------------------------" << endl;


	// 15보다 큰 수가 있는지 찾아주세요. 그리고 index나 혹은 interator 자리를 찾아주세요.
	int index2 = 0;
	for (int i = 0; i < myV.size(); i++)
	{
		if (myV[i] > 15)
		{
			index = i;
			break;
		}
	}

	vector<int>::iterator Iter2 = myV.begin();
	for (Iter2; Iter2 != myV.end(); Iter2++)
	{
		if (*Iter2 > 15)
		{
			break;
		}
	}

	cout << myV[index] << endl;
	cout << *Iter2 << endl;

	struct Finder_1
	{
		bool operator()(const int& value)
		{
			if (value > compareNum)
				return true;
			return false;
		}

		int compareNum = 0;
	};

	// 전역함수, 정적함수, 함수객체 들어갈 수 있음
	Iter = std::find_if(myV.begin(), myV.end(), &Func);
	cout << *Iter << endl;

	Finder_1 finder_1;
	finder_1.compareNum = 15;
	Iter = std::find_if(myV.begin(), myV.end(), finder_1);
	cout << *Iter << endl;

	cout << "--------------------------------" << endl;



	// 모든 수가 50보다 작은지 bool으로 알려주세요.
	struct Finder_2
	{
		bool operator()(const int& value)
		{
			if (value < compareNum)
				return true;
			return false;
		}

		int compareNum = 0;
	};

	Finder_2 finder_2;
	finder_2.compareNum = 50;
	cout << std::all_of(myV.begin(), myV.end(), finder_2) << endl;

	cout << "--------------------------------" << endl;


	// 하나라도 30보다 큰 수가 있는지 bool으로 알려주세요.
	Finder_1 finder_3;
	finder_3.compareNum = 30;
	cout << std::any_of(myV.begin(), myV.end(), finder_3) << endl;

	cout << "--------------------------------" << endl;


	// 원소가 3인 원소들의 개수를 알려주세요.
	cout << std::count(myV.begin(), myV.end(), 3) << endl;

	cout << "--------------------------------" << endl;


	// 원소가 5보다 큰 원소들의 개수를 알려주세요.
	Finder_1 finder_4;
	finder_4.compareNum = 5;
	cout << std::count_if(myV.begin(), myV.end(), finder_4) << endl;

	cout << "--------------------------------" << endl;


	// 모든 원소에 3을 곱해주세요.

	struct Multiply
	{
		void operator()(int& value)
		{
			value *= _num;
		}

		int _num = 0;
	};

	Multiply multi_three;
	multi_three._num = 3;
	std::for_each(myV.begin(), myV.end(), multi_three);
	for (int i = 0; i < myV.size(); i++)
	{
		cout << myV[i] << endl;
	}

	cout << "--------------------------------" << endl;

	// 중복된 원소들을 '제거'해주세요.


	// 원소가 12인 원소를 지워주세요.

	// 원소가 10보다 작은 원소들을 지워주세요.


	// std::find()


	return 0;
}