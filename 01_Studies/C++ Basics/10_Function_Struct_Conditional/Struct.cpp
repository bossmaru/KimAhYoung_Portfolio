#include <iostream>

using namespace std;

// 사용자 정의 자료형
// 구조체
// 1. 없는 자료형을 내가 만들기 위해서
// 2. 자료형이 여러개 합쳐진 것을 만들기 위해서


// 연산자
// (구조체 변수). : 멤버연산자...해당 멤버에 접근할 수 있게 해준다.
// (구조체 변수)-> : 간접멤버연산자 ... * 



struct Player
{
	//속성 attribute, member
	int hp;
	int mp;
};

// 출력담당
// 얘는 타고 들어간것도 고정 (const 위치 외우기)
// 읽기 전용
void PrintPlayer(Player player) // 구조체의 크기만큼 매개변수 할당
{

}

void PrintPlayer(const Player* const player) // 8바이트의 매개변수 (int 2개)
{
	cout << "플레이어 정보" << endl;
	cout << "Hp : " << player->hp << endl;
	cout << "Mp : " << player->mp << endl;
}




// 세팅담당
void SetPlayer(Player* const player, int hp, int mp) // 얘는 주소 고정 (const 위치 외우기)
{
	cout << "플레이어 세팅" << endl;
	(*player).hp = hp;
	player->mp = mp; // 위랑 같은 표현
}


int main()
{
	Player p;
	p.hp = 0;
	p.mp = 0;

	SetPlayer(&p, 100, 100);
	PrintPlayer(&p);

	return 0;
}