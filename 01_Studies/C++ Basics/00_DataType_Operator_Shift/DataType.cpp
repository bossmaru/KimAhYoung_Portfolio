#include <iostream>

using namespace std;  //standard library

//  bit : 0과 1로 저장되는 최소단위
//  byte : 8bit

// 자료형(DataType)
// 변수 (바구니)
// 변수 선언방법
	// (자료형) (변수이름) = 초기화

// 정수형
	// short -> 2byte = 16bit (-2^15 ~ 2^15-1) (2^16개, 0포함) -> (-32768 ~32767)
	// int  -> 4byte = 32bit (-2^31 ~ 2^31-1) (2^32개) -> (약 -21억 ~ 21억)
	// long long(int64) __int64 -> 8byte (-2^63 ~ 2^63-1) (2^64개)

// 음의 정수 만드는 방법 (2의 보수법)
	// 1. 비트를 모두 뒤바꾼다.
	// 2. +1을 한다.

// 정수의 오버플로우, 언더플로우
	// short aShort = -32768 - 1 -> 32767
	// short aShort = 32767 + 1 -> -32768

// 실수형
	// float ->  4byte = 32bit
	// (부호 1자리) + (지수 8자리) + (유효숫자 23자리)
	// (0.125 = 1 * 2^-3)
	// double -> 8byte
	// 저장되는 방식 : 부동소수점

// 논리형
	// bool -> 1byte (시스템 최소처리단위가 1byte라서 어쩔수 없이..)
	// true 1 / false 0
		// 0을 저장하면 false, 그 외에 모든 것이 다 true

// 문자형
	// char : 1byte
	// 2^8 = 256가지의 알파벳, 문자를 표현할 수 있다. -> 아스키코드
	// 유니코드 (wchar)
	// - UTF-8 : 알파벳, 숫자(1byte) / 한글, 중국어(3byte)
	// - UTF-16 : 알파멧, 숫자, 한글, 중국어(2byte) / 고대문자(4byte)

// Escape Sequence
	// \t : 탭
	// \n : 줄바꿈
	// \" : "
	// \0 : NULL 표시 = 0이라는 뜻

// 부호부가 없는 자료형
unsigned int u_aInt = 5; // 0 ~ 2^32-1
unsigned short u_aShort = 1; // 0 ~ 2^16-1

// 사용자 정의 자료형
struct Pos
{
	int x;
	short y; // 얘도 계속 4byte로 처리
	short padding = 0; // 쓰레기값 0으로..
};




int main() // 메인 함수
{
	// 정수형
	int aInt = 1;
	__int64 aInt64 = 241313;
	short aShort = -32768 - 1; // 32767 나옴 (정수형 오버플로우가 일어난다)

	//실수형
	float aFloat = 1.25f; // f붙여줌
	double aDouble = 1.222;

	// 논리형
	bool aBool = -1; // 출력해보면 1 나옴
	cout << aBool << endl;

	// 문자형
	char aChar = 97; // 출력하면 문자로 나옴 (a)
	cout << aChar << endl;

	// 사용자 정의 자료형
	Pos aPos;
	aPos.x = 1;
	aPos.y = 2;


	Pos bPos;
	bPos.x = 3;
	bPos.y = 3;



	//출력부
	cout << "short의 크기 " << sizeof(aShort) << endl; // endl : 줄바꿈 = \n
	cout << "int의 크기 " << sizeof(aInt) << endl;
	cout << "int64의 크기 " << sizeof(aInt64) << endl;
	cout << "float의 크기 " << sizeof(aFloat) << endl;
	cout << "double의 크기 " << sizeof(aDouble) << endl;
	cout << "bool의 크기 " << sizeof(aBool) << endl;

	cout << "Pos자료형의 크기 " << sizeof(aPos) << endl;

	int sum = aInt + 5;
	// Pos cPos = aPos + bPos; -> 불가능

	return 0;

}