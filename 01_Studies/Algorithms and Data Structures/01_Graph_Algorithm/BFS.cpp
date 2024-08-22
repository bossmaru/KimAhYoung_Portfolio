#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// BFS
// Breadth First Search -> 넓이우선 탐색

vector<vector<bool>> adjacent;
vector<bool> discovered;
vector<int> parent;


void CreateGraph_AdjacentMatrix()
{
	adjacent = vector<vector<bool>>(7, vector<bool>(7, false));
	adjacent[0][0] = true;
	adjacent[0][1] = true;
	adjacent[0][2] = true;
	adjacent[0][4] = true;

	adjacent[1][0] = true;
	adjacent[1][1] = true;

	adjacent[2][0] = true;
	adjacent[2][2] = true;
	adjacent[2][3] = true;
	adjacent[2][4] = true;
	adjacent[2][5] = true;

	adjacent[3][2] = true;
	adjacent[3][3] = true;

	adjacent[4][0] = true;
	adjacent[4][2] = true;
	adjacent[4][4] = true;
	adjacent[4][6] = true;

	adjacent[5][2] = true;
	adjacent[5][5] = true;

	adjacent[6][4] = true;
	adjacent[6][6] = true;
}

void BFS(int start)
{
	int N = adjacent.size();
	discovered[start] = true;
	parent[start] = start;

	cout << start << "방문" << endl;

	queue<int> q;
	q.push(start);

	while (true)
	{
		if (q.empty() == true)
		{
			break;
		}

		int here = q.front();
		q.pop();

		for (int there = 0; there < N; there++)
		{
			if (adjacent[here][there] == false)
			{
				continue;
			}
			if (discovered[there] == true)
			{
				continue;
			}

			q.push(there);
			cout << there << "발견 !!!" << endl;
			discovered[there] = true;
			parent[there] = here;
		}
	}
}

int edgeCount(int start, int dest)
{
	int answer = 0;
	int here = dest;
	while (true)
	{
		answer++;
		if (parent[here] == -1)
		{
			return 0;
		}
		if (parent[here] == start)
		{
			break;
		}
		here = parent[here];
	}
	return answer;
}

int main()
{
	CreateGraph_AdjacentMatrix();
	int size = adjacent.size();
	discovered = vector <bool>(size, false);
	parent = vector<int>(size, -1);

	BFS(0);

	cout << edgeCount(0, 4) << endl;;


	return 0;
}