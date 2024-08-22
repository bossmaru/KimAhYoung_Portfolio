#include <iostream>

using namespace std;

// 포인터 ... Pointer (자료형의 일종)
// 가르키는 애
// 주소를 담고있는 변수
// (자료형)*(포인터변수이름) = (초기화 - 해도되고 안해도 됨);
// (자료형) : 포털을 타고 들어갔을 때 해당 자료형이 있을 것이다 라는 힌트

// 크기 : 32비트 운영체제 프로그램에서는 4바이트, 64비트 운영체제 프로그램에서는 8바이트

// 연산자
// &(변수이름) : 주소연산자 -> 그 변수의 주소값을 꺼내줌
// *(포인터변수) : 간접연산자...포탈연산자

// void* : 타고들어가면 무슨 자료형이 있던 상관없다.


// 매개변수로 온 값
// Call by Value
void AddOne(int num)
{
	num++;

	return;
}

// 매개변수로 온 '주소값'
// Call by Address
void AddOne(int* ptr)
{
	(*ptr)++; // aInt + 1

	return;
}



int main()
{
	int aInt = 5; // 

	int* aPtr = &aInt;
	//포털을 타고 가면 int형의 자료가 있을 것이다.

	cout << "aInt의 주소" << &aInt << endl; // 어쩌고
	cout << "aInt 변수가 들고 있는 값" << aInt << endl; // 5
	cout << "aPtr의 주소" << &aPtr << &aPtr << endl; // 새로운 주소
	cout << "aPtr 변수가 들고 있는 값" << aPtr << endl; // 어쩌고랑 같음

	cout << *aPtr << endl; // 간접연산자 ... 포탈연산자 // 5 출력
	*aPtr = 6;

	cout << aInt << endl; // 6 나옴

	float* bPtr = (float*)&aInt; // aInt 자료형을 float으로 바꿔야 에러 안남...그냥 참고


	// void*
	void* vPtr = &aInt;

	aInt = 0;
	AddOne(&aInt);

	cout << aInt << endl;


	return 0;
}