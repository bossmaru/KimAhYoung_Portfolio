#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include < concurrent_priority_queue.h>

using namespace std;

// �켱���� ť
// 1. ��������Ʈ��
// 2. �θ� �׻� �ڽĺ��� ũ��.

class PriotiryQueue
{
public:
	void push(const int& value)
	{
		_container.push_back(value); #include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include < concurrent_priority_queue.h>

			using namespace std;

		// 우선순위 큐
		// 1. 완전이진트리
		// 2. 부모가 항상 자식보다 크다.

		class PriotiryQueue
		{
		public:
			void push(const int& value)
			{
				_container.push_back(value);
				int index = _container.size() - 1;
				int parent_index = 0;

				while (true)
				{
					if (index == 0)
						break;

					if (index % 2 == 1)
					{
						parent_index = (index - 1) / 2;
					}
					if (index % 2 == 0)
					{
						parent_index = (index / 2) - 1;
					}
					if (_container[index] <= _container[parent_index])
					{
						break;
					}
					if (_container[index] > _container[parent_index])
					{
						std::swap(_container[index], _container[parent_index]);
						index = parent_index;
					}
				}
			}

			void pop()
			{
				std::swap(_container[0], _container.back());
				_container.pop_back();
				int left_child_index = 0;
				int right_child_index = 0;
				int max_child_index = 0;
				int index = 0;

				while (true)
				{
					left_child_index = (index * 2) + 1;
					right_child_index = (index * 2) + 2;

					if (left_child_index >= _container.size())
						break;

					if (right_child_index < _container.size())
					{
						if (_container[left_child_index] >= _container[right_child_index])
						{
							max_child_index = left_child_index;
						}
						if (_container[left_child_index] < _container[right_child_index])
						{
							max_child_index = right_child_index;
						}
					}
					if (right_child_index >= _container.size())
					{
						max_child_index = left_child_index;
					}
					if (_container[index] >= _container[max_child_index])
					{
						break;
					}
					if (_container[index] < _container[max_child_index])
					{
						std::swap(_container[index], _container[max_child_index]);
						index = max_child_index;
					}
				}

			}

			const int& top()
			{
				return _container[0];
			}

			bool empty()
			{
				return _container.size() == 0;
			}

		private:
			vector<int> _container;
		};




		int main()
		{
			// priority_queue<int> pq;
			PriotiryQueue pq;

			pq.push(5);
			pq.push(10);
			pq.push(50);
			pq.push(100);
			pq.push(1);
			pq.push(2);
			pq.push(4);


			// N개에서 M개만큼만 정렬하고 싶다.
			// -> partial_sort -> 시간복잡도 : M * logN
			while (true)
			{
				if (pq.empty())
					break;

				int top = pq.top();
				cout << top << endl;

				pq.pop();
			}

			return 0;
		}

		int index = _container.size() - 1;
		int parent_index = 0;

		while (true)
		{
			if (index == 0)
				break;

			if (index % 2 == 1)
			{
				parent_index = (index - 1) / 2;
			}
			if (index % 2 == 0)
			{
				parent_index = (index / 2) - 1;
			}
			if (_container[index] <= _container[parent_index])
			{
				break;
			}
			if (_container[index] > _container[parent_index])
			{
				std::swap(_container[index], _container[parent_index]);
				index = parent_index;
			}
		}
	}

	void pop()
	{
		std::swap(_container[0], _container.back());
		_container.pop_back();
		int left_child_index = 0;
		int right_child_index = 0;
		int max_child_index = 0;
		int index = 0;

		while (true)
		{
			left_child_index = (index * 2) + 1;
			right_child_index = (index * 2) + 2;

			if (left_child_index >= _container.size())
				break;

			if (right_child_index < _container.size())
			{
				if (_container[left_child_index] >= _container[right_child_index])
				{
					max_child_index = left_child_index;
				}
				if (_container[left_child_index] < _container[right_child_index])
				{
					max_child_index = right_child_index;
				}
			}
			if (right_child_index >= _container.size())
			{
				max_child_index = left_child_index;
			}
			if (_container[index] >= _container[max_child_index])
			{
				break;
			}
			if (_container[index] < _container[max_child_index])
			{
				std::swap(_container[index], _container[max_child_index]);
				index = max_child_index;
			}
		}

	}

	const int& top()
	{
		return _container[0];
	}

	bool empty()
	{
		return _container.size() == 0;
	}

private:
	vector<int> _container;
};




int main()
{
	// priority_queue<int> pq;
	PriotiryQueue pq;

	pq.push(5);
	pq.push(10);
	pq.push(50);
	pq.push(100);
	pq.push(1);
	pq.push(2);
	pq.push(4);


	// N������ M����ŭ�� �����ϰ� �ʹ�.
	// -> partial_sort -> �ð����⵵ : M * logN
	while (true)
	{
		if(pq.empty())
			break;

		int top = pq.top();
		cout << top << endl;

		pq.pop();
	}

	return 0;
}
