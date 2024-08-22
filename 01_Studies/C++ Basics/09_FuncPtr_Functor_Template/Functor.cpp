#include <iostream>

using namespace std;

// 함수객체
// 객체이고, 함수처럼 쓸 수 있는(()함수 연산자를 오버로드해서 쓸수 있다.) 객체
// 콜백개념으로도 쓸 수 있다.
// -> 근데 함수 포인터와 다른 점
// -> 속성(멤버변수)를 가질 수 있다.

struct Functor
{
	Functor()
		: _aInt(0), _bInt(0)
	{
	}

	// 연산자 오버로딩
	void operator()() // () 함수 연산자 : 함수처럼 쓸 수 있다.
	{
		cout << "Hello World" << endl;
		cout << _aInt + _bInt << endl;
	}

	void operator()(int num)
	{
		cout << num << endl;
	}

	int _aInt;
	int _bInt;
};

class Player
{
public:
	void Excute()
	{
		if (_functor != nullptr)
		{
			(*_functor)();
		}
	}

	void SetFunctor(Functor* functor)
	{
		_functor = functor;
	}

private:
	Functor* _functor;
};



int main()
{
	Functor functor; // 객체임 (기본생성자 호출)
	functor._aInt = 1; // 속성을 고칠 수 있음
	functor._bInt = 5;
	functor(); // 함수 객체
	functor(1);

	return 0;
}