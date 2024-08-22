﻿#include <iostream>

using namespace std;


// Pet 클래스가 추가되고 Player가 펫을 한마리 갖고있다.
class Pet
{
private:
	int arr[100];
};

class Player
{
public:
	Player()
	: _maxHP(150)
	, _hp(0)
	, _hpRef(_hp)
	, _target(nullptr)
	{
		_hp = _maxHP;
		_pet = new Pet();
		cout << "기본생성자 호출" << endl;
	}

	// 기본생성자, 타입변환생성자
	Player(int hp) // 타입변환생성자
	: _maxHP(150)
	, _hp(0)
	, _hpRef(_hp)
	, _target(nullptr)
	{
		_hp = _maxHP;
		_pet = new Pet();
		cout << "타입변환 생성자 호출" << endl;
	}

	// 복사생성자
	// 암시적으로 만들어주는 생성자 -> 제가 명시적으로 만들면 안만들어줌 ... Shallow Copy 얕은 복사
	// 암묵적으로 만들었을 때 모든 멤버변수를 복사한다.
	Player(const Player& other)
	: _maxHP(other._maxHP)
	, _hp(other._hp)
	, _hpRef(other._hpRef)
	, _target(other._target)
	, _pet(nullptr) // 내부에서 생성한걸 내부에서 삭제할때는 이렇게 해야됨
	{
		_pet = new Pet(*other._pet); // DeepCopy...깊은 복사
		cout << "복사생성자 호출" << endl;
	}

	~Player()
	{
		delete _pet;
	}
	 
	void SetTarget(Player* other)
	{
		_target = other;
	}
	void Attack()
	{
		cout << "공격" << endl;
		_target->_hp -= 10;
	}

private:
	int _hp;
	const int _maxHP;
	int& _hpRef;
	Player* _target;
	Pet* _pet; // 4바이트
};

int main()
{
	Player a = Player(); // 기본생성자 호출
	Player b = Player(5); // 타입변환생성자 호출
	// Player b = 5 -> 같은 표현
	Player c = 2; // 타입변환생성자 호출
	Player d = c; // 이것도 복사생성자 호출
	// 원형은 Player d = Player(c)

	// Player* aPlayer = new Player(); // 기본생성자 호출
	// Player* bPlayer = new Player(5); // 타입변환생성자 호출
	// Player* cPlayer = new Player(2); // 타입변환생성자 호출
	// Player* dPlayer = new Player(*cPlayer); // 복사생성자 호출

	Player* a_player = new Player();
	Player* b_player = new Player(*a_player);



	delete b_player;
	delete a_player;

	return 0;
}