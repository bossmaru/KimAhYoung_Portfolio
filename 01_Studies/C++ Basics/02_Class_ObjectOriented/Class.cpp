#include <iostream>

using namespace std;

#include "Creature.h"

// 클래스
// struct 와 99프로 일치
// -> 설계도
// -> 건물을 지을 수 있다. = 객체를 만들 수 있다.
// 클래스는 객체를 찍어내는 도구일 뿐
// 멤버함수(기능), 멤버변수(속성)

// 객체지향의 3속성
// 1. 은닉성
// 2. 다형성
// 3. 상속성 (언리얼의 핵심 구조)

// 1. 은닉성
// struct와 class의 차이 : 기본접근지정자가 struct는 public으로 자동지정되어있음, class는 private로.
// 접근지정자 public, protected, private



class Car
{
public:

// 도대체 private 영역에 있는 멤버변수들은 초기화조차 못하는 건가?
// -> 생성자
// -> 생성할 때만 호출되는 함수
// -> 생성자에서 멤버 변수를 초기화 한다.
	Car() // 기본생성자 : 정의하지 않아도 암묵적으로 기본적으로 호출되는 생성자(다른 생성자가 하나라도 없을 경우)
	{
		cout << "기본 생성자 호출" << endl;
		_handle = 0;
		_wheels = 4;
		_doors = 4;
		_engine = 1;
	} 

	Car(int doors)
	{
		cout << "타입 변환 생성자 호출" << endl; // 매개변수가 있는 생성자
		_doors = doors;
		_handle = 0;
		_wheels = 4;
		_engine = 1;
	}

	// 소멸자
	~Car()
	{
		cout << "소멸자 호출" << endl;
	}


public: // 외부에서 접근 가능
	int _handle;

private: // 내부에서만 접근 가능
	int _wheels;
	int _doors;

protected: // 내부, 자식에서만 접근 가능
	int _engine;
};

int main()
{
	Car car; // Car car = Car() ->  원형은 이거임

	car._handle = 1;

	Car superCar = Car(2); // Car superCar = 2 와 동일 (타입 변환 가능)



	Creature p = Creature(50, 10, 10);
	p.TakeDamage(5);
	p.PrintCreature();





	return 0; // 리턴 지나야 소멸자 호출
}