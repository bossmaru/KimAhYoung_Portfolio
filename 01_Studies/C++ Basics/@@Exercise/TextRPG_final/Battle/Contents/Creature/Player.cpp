#include "pch.h"
#include "Player.h"

Player::Player(string name, int hp, int mp, int attack)
	: Creature(name, hp, mp, attack)
	, _curExp(0)
	, _maxExp(80)
{
}

Player::~Player()
{
}

void Player::Attack(Creature* other)
{
}

void Player::PrintInfo()
{
	cout<<endl;
	cout<<"--------------"<<endl;
	cout<<"이름 : "<<_name<<endl;
	cout<<"HP : "<<_curHp<<endl;
	cout<<"MP : "<<_mp<<endl;
	cout<<"ATTACK : "<<_attack<<endl;
	cout<<"EXP : "<<_curExp<<endl;
	cout<<"--------------"<<endl;
	cout<<endl;
}
void Player::GetExp(int amount)
{
}
