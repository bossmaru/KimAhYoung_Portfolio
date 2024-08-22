#include <iostream>

// 디자인 패턴
// ... 프로그래밍 하면서 공통된 문제들을 해결하는 패턴을 정형화 해놓은 것


// 1. 싱글톤(Singleton)
// - 객체를 단 하나만. 게임 로직을 담당하는 애들이 주로 포함. 시스템적인 면을 담당하는 애들.
// - SoundManager
// ... 사운드가 출력되어야 할 때마다 동적할당?
// -> SoundManager를 두고, 여기에 전사 10명의 목소리, 도적 10명의 목소리

// static 변수와 static 함수 -> Data 영역


// 메모리 4영역
// - Code
// - Data
// -- 전역변수, 정적변수(static)
// -- 생성주기 : 프로그램이 시작할 때 / 프로그램이 종료될 때
// - Stack
// -- 스택프레임 [반환주소값][지역변수][매개변수]
// -- 생성주기 : 함수 호출시, 지역 시작 / 함수 종료시, 지역 끝
// - Heap
// -- 내가 원하는 데이터 크기만큼
// -- 생성주기 : 프로그래머가 원하는대로



using namespace std;



// 정적변수
static int aInt = 0;
// 전역변수
int bInt = 1;

class Player
{
public:
	int _hp = 0;
	static int _mp; // 얘는 안에서 초기화하려면 const 붙여야됨
};

int Player::_mp = 5; // 밖에서 초기화 해야함

// 정적함수
static void HelloWorld()
{
	cout << "Hello World" << endl;
}



class Marine
{
public:
	void Print()
	{
		cout << _hp << endl;
		cout << atk << endl; // 멤버함수에서 정적멤버변수를 읽기 가능하다.
	}

	// 멤버함수
	void Set(int hp, int atk)
	{
		_hp = hp;
		this->atk = atk; // 멤버함수에서 정적멤버변수 쓰기가 가능하다.
	}

	// 정적멤버함수
	// 멤버함수 호출 조건 : 객체가 무조건 있어야 한다.
	// 정적멤버함수... 전역함수처럼 쓸 수 있다. -> 객체가 없어도 된다.
	static void Print_S()
	{
		// 정적 함수는 멤버변수에 접근할 수 없다.
		// 정적멤버함수는 this를 누군지 특정할 수 없다.
		// cout < this->_hp << endl; -> 안됨 (this가 누군지 모름)

		// 정적멤버함수는 정적멤버변수에 접근할 수 있다.
		cout << atk << endl; // 데이터 영역에 있어서 this 필요 없음 (모두의 것)
	}

	int _hp = 0;
	static int atk; //데이터 영역
};

int Marine::atk = 1;

Marine* marines[100];

void Temp()
{
	Marine::atk = 5; // public에 있다면 어디서든 가져다 쓸 수 있음
}

int main()
{
	cout << aInt << endl;
	HelloWorld();

	Player::_mp = 5; // 이거는 가능

	Player* p = new Player();


	// Marine* marines[100]; // 총 100바이트
	for (int i = 0; i < 100; i++)
	{
		marines[i] = new Marine();
	}

	Marine::atk++;

	marines[0]->Set(100, 50);
	Marine::Print_S();

	cout << marines[5]->atk << endl;



	return 0;
}