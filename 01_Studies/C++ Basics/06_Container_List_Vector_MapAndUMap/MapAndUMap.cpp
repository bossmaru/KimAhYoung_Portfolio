#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

// unordered map;
// 장점 :
// - key 값으로 탐색(접근)시에 상수의 시간이 걸린다.
// 단점 : 
// - 해쉬알고리즘 성능이 좋지 않을 때 -> 체이닝이 길어진다.
// -> 탐색에 시간이 더 오래 걸리 수도 있다.


// map
// 장점 :
// - key 값으로 탐색 시에 N개의 원소가 있을 때... logN 만큼의 시간이 걸린다.



struct UserInfo
{
	UserInfo() {}
	UserInfo(int id) : id(id) {}

	int id;
};


int main()
{

#pragma region UMap
	//            key,  value
	unordered_map<int, UserInfo> um;

	for (int i = 0; i < 1000; i++)
	{
		// 간이적으로 만든 해쉬알고리즘
		// int key = i % 1000;

		UserInfo info;
		info.id = i;

		pair<int, UserInfo> pair = { i, info };
		um.insert(pair);
	}


	// 3가지 사용법
	pair<int, UserInfo> myPair = { 4999, UserInfo(4999) };
	um.insert(myPair);

	um.insert(make_pair<int, UserInfo>(5001, UserInfo(5001)));

	um[5000] = UserInfo(5000);
	cout << um[5000].id << endl;

	// 해시 알고리즘


	//순회
	unordered_map<int, UserInfo>::iterator um_iter;
	for (um_iter = um.begin(); um_iter != um.end(); um_iter++)
	{
		cout << "Key : " << um_iter->first << endl;
		cout << "Value : " << um_iter->second.id << endl;
	}


#pragma endregion

	// 레드블랙 트리
	// 자가균형 이진탐색트리
	map<int, UserInfo> myMap;

	for (int i = 0; i < 1000; i++)
	{
		myMap[i] = UserInfo(i);
		myMap.insert(make_pair<int, UserInfo>(i + 1000, UserInfo(i + 1000)));
	}

	map<int, UserInfo>::iterator m_iter = myMap.begin();
	for (m_iter; m_iter != myMap.end(); m_iter++)
	{
		cout << "Key : " << m_iter->first << endl;
		cout << "Value : " << m_iter->second.id << endl;
	}


	return 0;
}