#include <iostream>

using namespace std;


int lotto[45] = {}; // 45개가 0으로 초기화 됨

// 앞에서 함수 선언만 해놓을 수 있음 ->  오류 안남
void Swap(int& a, int& b);
void Shuffle(int arr[], int size, int count);
void SelectionSort(int arr[], int begin, int end);
void PrintArr(int arr[], int size);


void Swap(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}

void Shuffle(int arr[], int size, int count)
{

	for (int i = 0; i < count; i++)
	{
		int a = rand() % 45;
		int b = rand() % 45;

		Swap(arr[a], arr[b]);
	}

}



void SetLotto(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = i + 1;
	}

	Shuffle(arr, size, 10000);
	SelectionSort(arr, 0, 7);
}

void PrintArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}


// 순차정렬
void SequencialSort(int arr[], int begin, int end)
{
	for (int i = begin; i < end - 1; i++)
	{
		for (int j = i + 1; j < end; j++)
		{
			if (arr[i] > arr[j])
			{
				Swap(arr[i], arr[j]);
			}
		}
	}


}


void SelectionSort(int arr[], int begin, int end)
{
	for (int i = begin; i < end - 1; i++)
	{
		int best = i;
		for (int j = i + 1; j < end; j++)
		{
			if (arr[best] > arr[j])
			{
				best = j;
			}
		}

		if (best != i)
		{
			Swap(arr[i], arr[best]);
		}
	}

}

void BubbleSort(int arr[], int begin, int end)
{
	for (int i = end; i > begin; i--)
	{
		for (int j = begin; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// 과제 1
// 객체지향의 3속성
// 은닉성
// 다형성
// 상속

// 가상함수
// VF table
// RTTI



int main()
{
	srand(time(NULL));

	SetLotto(lotto, 45);
	PrintArr(lotto, 7);



	return 0;
}