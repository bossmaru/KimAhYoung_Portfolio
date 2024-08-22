#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// 피보나치 수열
// Fibonacci 수열

int count_my = 0;

// DP 최적화
// 1. 메모이제이션 ... memo
// - 기저사항, 메모이제이션, 구하기
// -> 최적부분구조(최적부분문제)를 알아야 한다... 점화식


vector<int> cache = vector<int>(100, -1);

int Fibonacci(int n)
{
	// 기저사항
	if (n == 0 || n == 1) return 1;

	// 메모이제이션
	int& ref = cache[n];

	if (ref != -1)
		return ref;

	if (n == 2)
		count_my++;

	// 구하기
	ref = Fibonacci(n - 1) + Fibonacci(n - 2);

	return ref;
}

int main()
{
	__int64 start = GetTickCount64();

	cout << Fibonacci(40) << endl;
	cout << "...F(2)연산 : " << count_my << endl;

	__int64 end = GetTickCount64();

	cout << end - start << "ms" << endl;

	return 0;
}