#include <iostream>

using namespace std;

// 조건문
	// if문
	// if(조건절(true / false))
	// {
	//		실행문
	// }
	// else if(조건절)
	// {
	//		실행문
	// }
	// else
	// {
	//		실행문
	// }

	// swtich문
	// switch(양의 정수형)
	// {
	//		case 1: { 실행문 break: }
	//		case 2: { 실행문 break: }
	//		case ...: { 실행문 break: }
	// 
	//		default:
	//		{
	//		}
	// }


// 반복문
	// while문
	// while(조건절)
	// {
	//		if문(제어식)
	//			continue;  실행문이 실행되기 전에 다음 루프 타주세요.
	//		실행문
	//		제어식
	//		break;
	// }

	// for문
	// for(초기식; 조건식; 제어식)
	// {
	//		continue;
	//		실행문;
	//		break;
	// }

int main()
{
	int aInt = 3;
	int bInt = 3;

#pragma region 조건문
	if (aInt > bInt)
	{
		cout << "aInt가 bInt보다 큽니다." << endl;
	}
	else if (aInt = bInt)
	{
		cout << "aInt가 bInt와 동일합니다." << endl;
	}
	else
	{
		cout << "aInt가 bInt보다 작습니다." << endl;
	}


	// 열거형 (자료형)
	enum Test
	{
		ONE = 1,
		TWO,
		THREE
	};

	Test aTest = ONE;

	switch (aTest)
	{
	case ONE:
		break;
	case TWO:
		break;
	case THREE:
		break;
	default:
		break;
	}



	switch (aInt) // 양의정수만 가능해서 enum이랑 같이 잘 쓰임
	{
	case 1:
	{
		cout << "aInt가 1입니다." << endl;
		break;
	}
	case 3:
	{
		cout << "aInt가 3입니다." << endl;
		break; // break 안걸면 디폴트 출력
	}

	default:
	{
		cout << "aInt가 뭔지 잘 모르겠습니다." << endl;
		break;
	}
	}
#pragma endregion



#pragma region 반복문
	aInt = 0;
	while (true)
	{
		if (aInt == 3)
		{
			aInt++;
			continue;
		}


		cout << "반복!" << aInt << endl;

		aInt++; // 제어식
		if (aInt == 5)
			break;
	}


	for (int i = 0; i < 10; i++)
	{
		if (i == 3) continue;
		cout << i << "번 반복!" << endl;
		if (i == 5) break;
	}
#pragma endregion

	// 실습 1
	// 5 입력하면
	// *
	// *
	// *
	// *
	// *

	int input = 0;
	cin >> input;

	cout << input << endl;


	for (int i = 0; i < input; i++)
	{
		cout << "*" << endl;
	}


	// 실습 2
	// 3 입력하면
	// ***
	// ***
	// ***


	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			cout << "*";
		}
		cout << endl;
	}


	// 과제 1 직각삼각형 만들기
	// 5
	// *
	// **
	// ***
	// ****
	// *****


	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}


	// 컴퓨터가 난수를 갖게 하는 방법
	srand(time(NULL)); // 외우기 -> 현재 시간 넣는 것
	int randNum = rand(); // 0 ~ 32767 까지 중에 나옴
	// 1 ~ 3  까지 범위로 하고싶다면
	int randNum_3 = randNum % 3 + 1;
	cout << randNum_3 << endl;


	// 실습 3
	// 가위바위보 게임 만들기
	// 숫자를 1~3 입력받는다.
	// 컴퓨터가 1~3까지 숫자를 랜덤하게 갖고 있습니다.
	// 1 -> 가위, 2 -> 바위, 3 -> 보






	return 0;
}