#include "pch.h"
#include "Knight.h"

Knight::Knight(string name, int hp, int mp, int attack)
	: Player(name, hp, mp, attack)
	, _stamina(0)
{
}

Knight::~Knight()
{
}

void Knight::PrintInfo()
{
	cout<<endl;
	cout<<"--------------"<<endl;
	cout<<"이름 : "<<_name<<endl;
	cout<<"HP : "<<_curHp<<endl;
	cout<<"MP : "<<_mp<<endl;
	cout<<"ATTACK : "<<_attack<<endl;
	cout<<"STAMINA : "<<_stamina<<endl;
	cout<<"EXP : "<<_curExp<<endl;
	cout<<"--------------"<<endl;
	cout<<endl;
}

void Knight::PreAttack(Creature* other)
{
	cout<<_name<<"(Knight) 가 "<<other->GetName()<<"에게 공격을 시도합니다."<<endl;
}

void Knight::Attack(Creature* other)
{
	if ( other->IsDead() )
	{
	}
	else
	{
		// PreAttack(other);
		float ratio = ( float ) _curHp/( float ) _maxHp;

		if ( ratio<0.5f )
		{
			// 현재 체력이 50프로 미만
			other->TakeDamage(_attack*2);
		}
		else
		{
			other->TakeDamage(_attack);
		}
	}
}

void Knight::GetExp(int amount)
{
	_curExp += amount;
	if ( _curExp>=_maxExp )
	{
		_curExp -= _maxExp;
		_curHp += _maxExp*3;
		_mp += _maxExp/3;
		_attack += _maxExp/3;
		_stamina += _maxExp/3;
	}
}
