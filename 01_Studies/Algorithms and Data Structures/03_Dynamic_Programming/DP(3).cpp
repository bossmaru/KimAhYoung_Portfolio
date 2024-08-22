#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// Enchant
// N만큼 강화
// +1, +2, +3

int N = 4; // 100000
// +1 +1 +1
// +1 +2
// +2 +1
// +3
// result = 4

// Enchant(N) = Enchant(N-1) + Enchant(N-2) + Enchant(N-3)

// E(1) = 1
// E(2) = 2
// E(3) = 4
// E(4)

// 1 3
// 1 1 2
// 2 2
// 3 1
// 1 2 1
// 2 1 1
// 1 1 1 1

vector<int> cache = vector<int>(100001, -1);

int Enchant(int num)
{
	if (num == N)
		return 1;
	if (num > N)
		return 0;

	int& ref = cache[num];

	if (ref != -1)
		return ref;

	ref = Enchant(num + 1) + Enchant(num + 2) + Enchant(num + 3);

	return ref;
}


int main()
{
	int result = Enchant(0);
	cout << result << endl;

	return 0;
}