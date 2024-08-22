#include <iostream>

using namespace std;

// 포인터 연산
// *(포인터변수) : 간접연산자
// &(변수) : 주소연산자
// ++ptr : 전위연산자
// 덧셈연산 : +1 하면...자료형의 크기만큼 더해진다. 



// 정적배열
// int arr[상수] = {초기화}

////// 가장 중요한 특성 //////
// 1. 메모리에 일렬로 나열이 되어있다.
// int arr[5] = { 1,2,3,4,5 }; (1에서 4로 가려면 12바이트 더하면 됨...어디로 가든 탐색시간 똑같음)
// 임의 접근하는데 상수의 시간이 걸린다. 

// 2. 배열의 '이름'은 포인터처럼 동작한다.


// 연산자
// [변수] : 임의 접근 연산자... 변수번 째 인덱스(index)(색인)에 접근

// 탐색 : 인덱스
// 순회 : for


void PrintArr(int* arr, int size) // int*arr랑 int arr[]랑 같음
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << endl;
		cout << arr[i] << endl; // 윗줄이랑 같음 (포인터도 임의접근 연산자 사용 가능)
	}
}



int main()
{

	int arr[5] = { 1,2,3,4,5 }; // 전체 크기 : 20바이트

	int* ptr = &arr[0]; // 0x10
	cout << *(ptr + 1) << endl; // 0x14 (자료형의 크기만큼 더해짐) -> 2 나옴
	cout << arr[1] << endl; // 2 나옴


	cout << sizeof(arr) << endl; // 20바이트
	int size = sizeof(arr) / sizeof(int); // 배열 개수
	cout << "Count : " << size << endl;


	PrintArr(arr, size);


	return 0;
}