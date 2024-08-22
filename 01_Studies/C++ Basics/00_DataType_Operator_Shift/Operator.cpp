#include <iostream>

#define STURN		(1 << 0) // 보통 대문자로 씀
#define SLEEP		(1 << 1)
#define AIRBONE		(1 << 2)
#define INVINSIBLE  (1 << 3)

using namespace std;

// 연산자
	// 사칙연산
	// + - * / % -> 자료형마다 다를 수 있다.

// 정수형
	// + - * ...
	// / ... 몫을 반환
	// 10 / 3 => 3
	// % ... 나머지를 반환 -> 순환 구조 or 랜덤한 수를 만들 때 중요
	// 10 % 3 => 1

// 실수형
	// + - * 동일
	// / ... 그냥 나눔 -> 순환소수는 중간에 짤림 (부동 소수점의 오차 주의)
	// 숫자 0으로 나누면 컴파일 단계에서 에러 뜸
	// 변수 0으로 넣으면 통과는 함 -> inf로 뜸

// = 대입연산자
	// a = b : a에다가 b를 '대입'하고 a의 원본을 반환한다.
	// +=, -=, *=, /=

// 증감연산자 (실수형도 되긴하는데 거의 int)
	// ++, --
	// aInt++ / aInt-- ... 후위연산자
	// aInt = bInt++;
	// -> aInt에다가 bInt를 먼저 대입하고 bInt를 1 올린다.
	// ++aInt / --aInt ... 전위연산자
	// aInt = ++bInt
	// -> bInt 를 우선 1 올리고 그것을 aInt에다 대입한다.

// 비교연산자
	// 반환자료형이 bool
	// ==, !=, <, >, <=, >=
	// == 같으면 true
	// != 다르면 true

// 논리연산자
	// 반환자료형이 bool
	// !, &&,
	// ! : not
	// a && b : a가 true이고 b가 true이면 true
	// a || b : a, b  둘 중에 하나라도 true 면 true

// 비트연산자 : 부호 없는 정수형과 쓰인다.
	// &, |, ^, >>, <<
	// a & b : 비트의 한자리수 씩 and 연산
	// 1 & 2 : 0001 and 0010 = 0000 = 0
	// 1 & 3 : 0001 and 0011 = 0001 = 1
	// a | b : 비트의 한자리수 씩 or 연산
	// 1 | 3 : 0001 or 0011 = 0011 = 3
	// a ^ b : xor 연산 ... 비트가 서로 같지 않을 때 1, 같으면 0
	// 1 ^ 3 : 0001 xor 0011 = 0010 = 2

	// << : 왼쪽 Shift 연산
	// 특징 : 2배가 된다, 맨오른쪽 비트는 항상 0으로 채워진다
	// 맨 왼쪽 - 되는거 방지 : 부호 없는 정수형 사용
	// >> : 오른쪽 Shift 연산
	// 특징 : 맨 오른쪽 비트는 버려지게 된다. 
	// 부호가 있는 정수형이라면 왼쪽 부호비트는 유지된다. 

// 비트플래그
	// [기절][수면][에어본][무적]
unsigned char state = 0;
const unsigned char sturn = 0b1000; // 1 << 3 
const unsigned char sleep = (1 << 2);
const unsigned char airbone = 2;
const unsigned char invinsible = 1;
//const -> 고정값

enum CC_State
{
	E_STURN = (1 << 0),
	E_SLEEP = (1 << 1),
	E_AIRBONE = (1 << 2),
	E_INVINSIBLE = (1 << 3)
};
// CC_State::E_STURN -> 주로 이 모양으로 씀


// 비트마스크
	// & (보고싶은 비트)




int main()
{
#pragma region 연산자
	int aInt = 10;
	int bInt = 3;
	int cInt = 0;

	cInt = (aInt + bInt) % bInt;
	cout << cInt << endl;

	aInt += 1;

	cout << ++aInt << endl; // 12 출력
	cout << aInt++ << endl; // 12 출력
	cout << aInt << endl; // 13 출력

	aInt = ++bInt;
	aInt = bInt++;
	cout << aInt << endl; // 4 출력

	cout << (aInt == bInt) << endl; // false 0
	cout << ((aInt < bInt) > (aInt == bInt)) << endl; // true 1

	aInt = 2;
	bInt = 3;
	cInt = ++bInt; // 4

	bool check1 = (aInt > bInt); // 0
	bool check2 = (cInt != aInt); // 1
	bool check3 = !check1; // 1
	bool check4 = check3 || check2; // 1
	bool check5 = check2 && (check3 || check4); // 1

	cout << check1 << endl;
	cout << check2 << endl;
	cout << check3 << endl;
	cout << check4 << endl;
	cout << check5 << endl;

	cout << (1 & 3) << endl;
	cout << (1 | 3) << endl;
	// xor...
	// a ^ b ^ b = a ... 암호학에서 쓸 수 있음
	aInt = 1;
	bInt = 3;
	cInt = (aInt ^ bInt);
	cout << (cInt ^ bInt) << endl; // 1 나옴

	unsigned char u_aChar = 3;
	unsigned char u_bChar = (1 << 4); // 16
	unsigned char u_cChar = (u_aChar | u_bChar); // 19
	unsigned char u_dChar = (1 << 3) | (1 << 2); // 12
	unsigned char u_eChar = (u_cChar & u_dChar); // 0

#pragma endregion




#pragma region 비트플래그
	state |= (E_STURN | SLEEP);
	if (state & STURN) // 비트마스크
	{
		cout << "스턴상태입니다" << endl;
	}

	if (state & SLEEP)
	{
		cout << "수면상태입니다" << endl;
	}

	if (state & (STURN | SLEEP))
	{
		cout << "스턴, 수면상태입니다" << endl;
	}
#pragma endregion



	return 0;
}


// 캡쳐 or 쓰기 or 복붙...
// 과제 1
	// 메모리 4 영역 조사

// 과제 2
	// 상수를 선언하는 방법

// 과제 3
	// 복습