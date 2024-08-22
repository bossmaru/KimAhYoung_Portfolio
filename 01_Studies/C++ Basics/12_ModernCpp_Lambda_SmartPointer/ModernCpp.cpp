#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>


using namespace std;

// 1. auto
// --> 반드시 초기화
// 
// 2. 중괄호 초기화
// 
// 3. 범위기반 for문
// 
// 4. final, friend
// 
// 5. using
// --> typedef와 다른 장점 ... 템플릿과 호환이 된다.
// 
// 6. enum class
// 
// 7. 람다
// 8. 이동 shift 개념
// 9. 스마트 포인터


class Player
{
public:
	virtual void PrintP() {}

	int _hp = 0;
};

class Knight : public Player
{
public:
	friend class KnightHelper; // 내 친구는 private 쓸 수 있다.

	virtual void PrintP() final override {} // 내 자식부터는 재정의해서 쓸 수 없다.
private:
	int _stamina = 0;
};

class HolyKnight : public Knight
{
public:
	// virtual void PrintP() override {} -> 안됨
};

class KnightHelper
{
public:
	void Prinh(Knight* k) { k->_stamina; }
};

void(*funcPtr)(void);

void Hello()
{
	cout << "Hello" << endl;
}

typedef void(*FuncPtr)(void);
typedef unsigned int UINT;

using UINT2 = unsigned int;
using FuncPtr2 = void(*)(void);


enum class PlayerType
{
	NONE,
	KNIGHT,
	ARCHER,
	MAGE
};

enum class WarriorType
{
	NONE,
	HOLLYKNIGHT,
	WARRIOR,
	KNIGHT
};




int main()
{
	auto aInt = 5;

	// 이렇게는 잘 안씀
	auto aDouble = { 1.4 };

	vector<int> tempV = { 1,2,3,4,5,56,67,88888,23 };

	auto vIter = tempV.begin();

	for (vIter; vIter != tempV.end(); vIter++)
	{

	}

	unordered_map<int, int> temp_uM;
	temp_uM[0] = 1;
	temp_uM[2] = -1;
	temp_uM[4] = 311;
	temp_uM[7] = 100;
	temp_uM[9] = 123;

	auto umIter = temp_uM.begin();

	for (umIter; umIter != temp_uM.end(); umIter++)
	{

	}

	for (int& data : tempV)
	{
		data = 0;
		cout << data << endl;
	}


	// for (pair<const int, int>& p : temp_uM) 이거랑 같음
	for (auto& pair : temp_uM)
	{
		pair.second *= 5;
		cout << "Key : " << pair.first << endl;
		cout << "Value : " << pair.second << endl;
	}

	UINT aUInt = 5;


	funcPtr = &Hello;
	funcPtr();

	FuncPtr FuncPtr;
	FuncPtr = &Hello;
	FuncPtr();

	int type = static_cast<int>(WarriorType::KNIGHT);

	return 0;
}