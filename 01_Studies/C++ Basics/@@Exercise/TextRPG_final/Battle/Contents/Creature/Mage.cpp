#include "pch.h"
#include "Mage.h"

Mage::Mage(string name, int hp, int mp, int attack)
	: Player(name, hp, mp, attack)
{
}

Mage::~Mage()
{
}

void Mage::PreAttack(Creature* other)
{
	cout<<_name<<"(Mage) 가 "<<other->GetName()<<"에게 공격을 시도합니다."<<endl;
}

void Mage::Attack(Creature* other)
{
	if ( other->IsDead() )
	{
	}
	else
	{
		// PreAttack(other);
		if ( _mp<5 )
		{
			_mp = 50;
		}
		else
		{
			_mp -= 5;
			other->TakeDamage(_attack);
		}
	}
}

void Mage::GetExp(int amount)
{
	_curExp += amount;
	if ( _curExp>=_maxExp )
	{
		_curExp -= _maxExp;
		_curHp += _maxExp*3;
		_attack += _maxExp/3;
		_mp += _maxExp/3;
	}
}
