#include <iostream>

using namespace std;

// 캐스팅

// C스타일 캐스팅
// 기본자료형 캐스팅

// C++ 스타일 캐스팅(4총사)
// 1. static cast
// -> 상식적인 변환만 허용
// -> 컴파일 시간에 캐스팅
// 2. dynamic cast
// -> 상속구조에서 다형성(vftable)이 있어야 사용가능한 cast
// -> 이 때 캐스팅이 실패하면 nullptr을 반환한다.
// -> 런타임에 캐스팅한다.
// 3. const cast (잘 안씀)
// -> 상수객체를 비상수객체로 캐스팅할 수 있다.
// 4. reinterprete_cast (그냥 참고)
// -> 모든 캐스팅 통과
// -> 위험한 캐스팅 (서버에서 많이 씀)




class Player
{
public:
	virtual void PrintPlayer()
	{
		cout << "Player 입니다." << endl;
	}
};

class Knight : public Player
{
public:
	virtual void PrintPlayer() override
	{
		cout << "Knight 입니다." << endl;
	}
};

class Mage : public Player
{
public:
	virtual void PrintPlayer() override
	{
		cout << "Mage 입니다." << endl;
	}
	int _mana;
};

void ManaUp(Player* player)
{
	Mage* mage = dynamic_cast<Mage*>(player);

	if (mage == nullptr)
	{
		cout << "Mage가 아닙니다." << endl;
		return;
	}

	mage->PrintPlayer();
	cout << "최대마나가 증가되었습니다." << endl;
}

// pkt : 17kb/s, fps 140
enum PacketID
{
	NONE = 10,
	LOGIN,
	LOGIN_SUCCESS,
	CREATE_ACCOUNT,
	PLAYER_RUN
};

struct Protocol_test_S // 내가 서버한테 보내는 패키지
{
	PacketID pkt_Id = PacketID::LOGIN;
	int id;
	int password;
};

struct Protocal_test_C // 서버가 클라이언트한테
{
	PacketID pkt_Id = PacketID::LOGIN_SUCCESS;
	bool success;
};

int main()
{
	int aInt = 5;
	float aFloat = static_cast<float>(aInt); // 5.0f : 16진수 -> 부동소수점
	bool aBool = static_cast<bool>(aInt);
	// int* aPtr = (int*)aInt; // ...aPtr = 5 (근데 이런건 쓰면 안됨)

	Player* player1 = new Knight();
	// int* aPtr = (int*)player; -> 이건 통과
	// int* aPtr = static_cast<int*>(player); -> 이건 통과 X

	Player* player2 = new Mage();

	ManaUp(player1);

	// 리터럴 상수
	// Data 영역
	// - bss : 초기화 되지 않은 전역변수
	// - data : 초기화된 전역변수
	// - rodata : 상수
	const char* str1 = "Hello"; // Hello는 rodata 영역에 있음 -> 무조건 읽기 전용이어야 함 -> 무조건 const 붙여야됨
	char* str1 = const_cast<char*>("Hello"); // 통과만 됨. 바꾸지는 못함

	// 클라이언트 로그인 시도
	Protocol_test_S pkt;
	pkt.id = PacketID::LOGIN;
	pkt.id = 12345;
	pkt.password = 12345;

	// 서버에서 로그인 체크 후 성공여부 전달
	// 12바이트...?
	Protocol_test_S* s_pkt = reinterpret_cast<Protocol_test_S*>(&pkt);

	// 클라이언트에서 로그인 성공여부

	return 0;
}
