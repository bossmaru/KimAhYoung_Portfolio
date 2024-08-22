#include <iostream>

using namespace std;

// Data 영역
// - bss 영역 : 초기화되지 않은 전역변수
// - data 영역 : 초기화된 전역변수
// - rodata 영역 : read only data -> 상수

// 문자열의 특징
// 1. 맨 마지막 원소는 0으로 끝난다.


int StrLength(const char* str)
{
	// 문자열의 길이를 반환하는 함수
	// int length = strlen(str);
	int result = 0;

	while (true)
	{
		if (str[result] == '\0')
			return result;

		result++;
	}

}

bool StrCompare(const char* str1, const char* str2)
{
	// 두 문자열이 서로 일치하면 true, 아니면 false 리턴
	int length1 = StrLength(str1);
	int length2 = StrLength(str2);

	bool result = true;

	if (length1 != length2)
	{
		result = false;
	}

	else
	{
		for (int i = 0; i < length1; i++)
		{
			if (str1[i] != str2[i])
			{
				result = false;
			}
		}
	}
	return result;
}


int main()
{
	// 리터럴 상수 "Hello World"
	const char* str = "Hello World";
	cout << str << endl;

	char str2[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	cout << str2 << endl;


	const char* str3 = "Hello World";
	const char* str4 = "Hello   World";

	cout << StrLength(str) << endl;
	cout << StrCompare(str3, str4) << endl;
	cout << strcmp(str2, str3) << endl; // strcmp : str2 == str3 이면 0
										// 길이는 같은데 사전순으로 str2 < str3 이면 -1
										// 길이는 같은데 사전순으로 str2 > str3 이면 1



	return 0;
}