#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// queue : 줄 세우기 (게임에서 큐 돌린다)
// First Input First Out : FIFO

template <typename T, typename Container = list<T>>
class Queue
{
public:
	void push(const T& value)
	{
		q.push_back(value);
	}

	void pop()
	{
		q.pop_front();
	}

	bool empty()
	{
		return q.size() == 0;
	}

	const T& front()
	{
		return q.front();
	}


private:
	Container q;
};

int main()
{
	Queue<int, list<int>> q;

	q.push(51);
	q.push(2);
	q.push(3);
	q.push(23);
	q.push(77);

	while (true)
	{
		if (q.empty() == true)
			break;

		cout << q.front() << endl;

		q.pop();
	}


	return 0;
}