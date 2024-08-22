#include <iostream>

using namespace std;


// Singleton
// 1. 전역으로 접근 가능해야 한다.
// 2. 프로그램에 단 하나만 존재해야 한다.
// 3. 동적할당 되어야 한다.

class SoundManager
{
private:
	SoundManager() {} // 생성자를 private 영역에 두면 외부에서 함부로 생성 못함
	~SoundManager() {}

public:
	// private에 접근할 수 있는 방법 : public 멤버함수
	// 그냥 멤버함수는 외부에서 호출하려면 객체 필요
	// 정적 멤버함수로 변경 -> instance도 정적멤버변수여야 쓸수 있음
	static void Create()
	{
		if (instance == nullptr)
			instance = new SoundManager();
	}

	static void Delete()
	{
		if (instance != nullptr)
			delete instance;
	}

	static SoundManager* GetInstance()
	{
		if (instance != nullptr)
			return instance;
		return nullptr;
	}

	void PrintAllSound()
	{
		cout << _warriorSound << endl;
		cout << _archerSound << endl;
	}

	void PrintWarriorSound()
	{
		cout << _warriorSound << endl;
	}

private:
	static SoundManager* instance;
	string _warriorSound = "워리어 등장!";
	string _archerSound = "아처 등장!";
};

SoundManager* SoundManager::instance = nullptr;

class Warrior
{
public:
	Warrior() { SoundManager::GetInstance()->PrintWarriorSound(); }
};

int main()
{
	SoundManager::Create();
	SoundManager::GetInstance()->PrintAllSound();

	Warrior* warrior = new Warrior();

	delete warrior;
	SoundManager::Delete();


	return 0;
}