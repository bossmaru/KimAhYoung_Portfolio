#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// LIS (Longest Increasing Subsequence)
// 최장 증가 부분 수열

vector<int> v = { 3,5,7,1,8,4,9 };
// 증가 부분 수열 : 전점 증가되는 부분수열
// 최장 증가 부분 수열 : 증가 부분 수열 중에 가장 긴 것

vector<int> cache;

int Lis(int pos)
{
	// 기저사항
	if (pos == v.size() - 1)
		return 1;

	// 메모이제이션
	int& ref = cache[pos];
	if (ref != -1)
		return ref;

	ref = 1;
	for (int next = pos + 1; next < v.size(); next++)
	{
		if (v[pos] <= v[next])
		{
			ref = max(ref, Lis(next) + 1);
		}
	}

	return ref;
}


int main()
{
	cache = vector<int>(v.size(), -1);
	int lis = 1;

	for (int i = 0; i < v.size(); i++)
	{
		lis = max(lis, Lis(i));
	}

	cout << lis << endl;

	return 0;
}