#include <iostream>

using namespace std;


// 객체지향 3속성
// 1. 은닉성
// - public : 어디에서나 접근 가능
// - private : 내부에서만 접근 가능 (멤버함수 or 생성자 통해서 수정)
// - protected : 내부, 자식에서만 접근 가능
// 
// ...함부로 멤버변수를 건드리지 마라.
// -> 프로그래머가 만든 public 멤버함수(인터페이스)로만 멤버변수를 수정해라.
// 
// 2. 다형성
// - 함수 오버로딩
// 
// - 함수 오버라이딩
// 
// 
// 3. 상속성
// Animal ... Cat
// Cat은 Animal인가? (O)
// Animal은 Cat인가? (X)
// 
// (4. 추상화) 




class Vector2
{
public:
	Vector2() { _x = 0; _y = 0; }
	Vector2(int x, int y) { _x = x; _y = y; }
	~Vector2() {}


	void PrintVector2()
	{
		// this 포인터 키워드
		// 이 함수를 호출한 객체를 가리키는 포인터
		cout << "x : " << this->_x << endl;
		cout << "y : " << _y << endl; // this 붙여도 됨 (안붙여도 됨)
	}

	// 연산자 오버로딩
	// a + b : a와 b를 더하고 그 값을 반환한다.
	Vector2 operator+(const Vector2& other)
	{
		Vector2 result;
		result._x = this->_x + other._x; // this 붙여도 됨 (안붙여도 됨)
		result._y = _y + other._y;

		return result;
	}

	Vector2 operator-(const Vector2& other)
	{
		Vector2 result;
		result._x = _x - other._x;
		result._y = _y - other._y;

		return result;
	}

	Vector2 operator*(int num)
	{
		Vector2 result;
		result._x = _x * num;
		result._y = _y * num;

		return result;
	}

	Vector2 operator/(int num)
	{
		Vector2 result;
		result._x = _x / num;
		result._y = _y / num;

		return result;
	}

	// a = b : a에다가 b을 대입하고 a의 원본을 반환한다.
	// 정의하지 않으면 암묵적으로 생성되는 연산자
	Vector2& operator=(const Vector2& other)
	{
		this->_x = other._x;
		this->_y = other._y;

		return (*this);
	}

	// a++
	// 임시로 a의 값을 반환하고 a를 1 더해준다.
	Vector2 operator++(int)
	{
		Vector2 result = *this;
		*this = (*this) + Vector2(1, 1);

		return result;
	}

	// ++a
	// a의 값을 1 더하고, a의 원본을 반환한다.
	Vector2& operator++()
	{
		(*this)++;
		return (*this);

	}


	// 내적
	float Dot(const Vector2& other)
	{
		// cosA * |a| * |b|
		float result = 0.0f;
		result = _x * other._x + _y * other._y;
		return result;
	}

	// 외적
	float Cross(const Vector2& other)
	{
		float result = _x * other._y - _y * other._x;
		return result;
	}

	int _x;
	int _y;
};


// 상속
class Animal
{
public:
	Animal() { _mouth = 1; _leg = 4; }

	void Eat()
	{
		cout << "쩝쩝" << endl;
	}


protected:
	int _mouth;
	int _leg;
};

class Cat : public Animal
{
public:
	Cat()
	{
		// ::  : 범위 지정 연산자 - 써도 되고 안써도 됨
		Animal::_mouth = 1;
		_tail = 1;
	}

	// 함수 오버라이딩 : 시그니처가 완전히 동일하고 실행문을 재정의한다.
	void Eat()
	{
		cout << "냥냥" << endl;
	}

private:
	int _tail;


};





int main()
{
	Vector2 a = Vector2(1, 1);
	Vector2 b = Vector2(3, 4);

	Vector2 c = a + b; // a.operator+(b)  이게 원형
	c = a - b;
	(++a).PrintVector2();
	a.PrintVector2();


	Animal animal = Animal();
	Cat cat = Cat();
	animal.Eat();
	cat.Animal::Eat(); // 반대로는 안됨

	return 0;
}