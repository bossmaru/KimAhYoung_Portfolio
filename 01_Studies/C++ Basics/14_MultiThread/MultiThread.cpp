#include <iostream>
#include <thread>

using namespace std;

atomic<int> sum = 0;

void Add()
{
	for (int i = 0; i < 100000; i++)
	{
		sum.fetch_add(1);
	}
}

void Sub()
{
	for (int i = 0; i < 100000; i++)
	{
		sum.fetch_sub(1);
	}
}

void HelloThread()
{
	cout << "Hello Thread " << endl;

}

int main()
{
	// std::thread t1(&HelloThread); // HelloThread 라는 일감을 준다.
	// 
	// // t1.detach(); // 스레드 분리
	// if (t1.joinable()) // 스레드가 분리되지 않았다면, 끝나지 않았다면
	// 	t1.join(); // 스레드가 끝날 때까지 대기 후 join

	Add();
	Sub();
	// sum = 0

	std::thread t1(Add); // sum = 10000
	std::thread t2(Sub); // sum = 0

	t1.join();
	t2.join();

	cout << sum << endl;
	
	return 0;
}