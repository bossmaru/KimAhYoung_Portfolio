#include <iostream>

using namespace std;


// 함수
	// 반환형식 함수이름 (매개변수)
	// {
	//		함수 내용
	// 
	//		return (반환값);
	// }


// void : 자료형의 일종 (변수 선언은 못함)

// 함수 호출
// 함수이름(매개변수)

// 호출스택
// 스택 : 팬케이크 굽기, 탑쌓기


// 함수 오버로딩 : 함수의 이름이 같아도, 매개변수의 개수나 데이터타입이 다르면 통과...반환형식이 달라도 통과

// 함수를 쓰는 이유
	// 1. 재사용성
	// 2. 코드 가독성(함수 이름 중요)


void HelloFunc(void)
{

	cout << "Hello Function" << endl; // 그냥 이것만으로는 안뜸. 함수 호출해야함

	return; // 리턴값이 없음
}


void PrintNum(int num)
{
	cout << num << endl;

	return;
}

int AddOne(int num)
{
	// main([반환주소값][aInt(지역변수)][매개변수 없음]) AddOne([반환주소값][지역변수 없음][num(매개변수)]
	num++;

	return num;
}

void SumNum(int num1, int num2)
{
	int sum = num1 + num2;
	cout << sum << endl;

	return;
}


// 함수 오버로딩
void SumNum(int num1, int num2, int num3) // 함수 이름 같음, 매개변수 개수 다름
{
	int sum = num1 + num2 + num3;

	cout << sum << endl;

}


// 함수의 기본 인자
void SumNum(int num1, int num2, int num3, int num4, int num5 = 0)
{
	int sum = num1 + num2 + num3 + num4;

	cout << sum << endl;

}


void Stars(int input)
{
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

// 재귀호출을 하는 함수
// 스택오버플로우에 주의하자
int Factorial(int num)
{
	if (num == 1)
		return 1;

	return num * Factorial(num - 1);
}


int main(void) // void 생략해도 됨
{

	Stars(5);

	int aInt = 1;
	aInt = AddOne(aInt);


	return 0;
}