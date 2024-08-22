#include "pch.h"
#include "Monster.h"

Monster::Monster(string name, int hp, int mp, int attack)
	: Creature(name, hp, mp, attack)
{
}

Monster::~Monster()
{
}

void Monster::Attack(Creature* other)
{
	if ( IsDead()||other->IsDead() )
	{
	}
	else
	{
		other->TakeDamage(_attack);
	}
}

void Monster::TakeDamage(int amount)
{
	_curHp -= amount;

	if ( _curHp<0 )
	{
		_curHp = 0;
	}
}

void Monster::MonstersAttack(Player* player, vector<Creature*> group)
{
	while ( true )
	{
		cout<<endl;
		cout<<"--------------"<<endl;
		cout<<player->GetName()<<"의 공격!!!"<<endl;
		cout<<endl;

		for ( int i = 0; i<group.size(); i++ )
		{
			// 내가 공격
			int exp = group[ i ]->GetCurHp();
			player->Attack(group[ i ]);
			if ( group[ i ]->IsDead() )
			{
				exp -= group[ i ]->GetCurHp();
				player->GetExp(exp);
			}
			cout<<group[ i ]->GetName()<<"의 HP : "<<group[ i ]->GetCurHp()<<endl;
		}

		// 상대방 죽으면 끝
		if ( AllDead(group) )
		{
			cout<<endl;
			cout<<"이겼습니다!"<<endl;
			cout<<endl;
			break;
		}

		cout<<endl;
		cout<<"--------------"<<endl;
		cout<<"몬스터의 공격!!!"<<endl;
		cout<<endl;
		for ( int i = 0; i<group.size(); i++ )
		{
			// 상대방이 공격
			group[ i ]->Attack(player);
		}
		cout<<player->GetName()<<"의 HP : "<<player->GetCurHp()<<endl;

		// 내가 죽으면 끝
		if ( player->IsDead() )
		{
			cout<<endl;
			cout<<"졌습니다!"<<endl;
			cout<<endl;
			break;
		}
	}
}
