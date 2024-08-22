#include "pch.h"
#include "HobGoblin.h"

HobGoblin::HobGoblin(string name, int hp, int mp, int attack)
	: Monster(name, hp, mp, attack)
{
}

HobGoblin::~HobGoblin()
{
}

void HobGoblin::AggroAttack(vector<Creature*> players)
{
	struct PlayerPair
	{
		Creature* _player;
		int _id;
		int _damage;
	};

	vector<PlayerPair*> playerpairs;
	for ( int i = 0; i<players.size(); i++ )
	{
		PlayerPair* playerpair = new PlayerPair();
		playerpair->_player = players[ i ];
		playerpair->_id = i;
		playerpair->_damage = 0;
		playerpairs.push_back(playerpair);
	}

	while ( true )
	{
		// 죽은 플레이어 삭제
		vector<PlayerPair*>::iterator iter = std::remove_if(playerpairs.begin(), playerpairs.end(), [ ] (PlayerPair* p)
		{
			return p->_player->IsDead();
		});
		playerpairs.erase(iter, playerpairs.end());

		// Players의 공격
		std::cout<<endl;
		std::cout<<"--------------"<<endl;
		std::cout<<"Players 의 공격!!!"<<endl;
		std::cout<<endl;

		for ( int i = 0; i<playerpairs.size(); i++ )
		{
			playerpairs[ i ]->_damage += GetCurHp();
			playerpairs[ i ]->_player->Attack(this);
			playerpairs[ i ]->_damage -= GetCurHp();
			std::cout<<playerpairs[ i ]->_player->GetName()<<"의 누적 damage : "<<playerpairs[ i ]->_damage<<endl;
		}

		std::cout<<endl;
		std::cout<<GetName()<<"의 HP : "<<GetCurHp()<<endl;

		// 보스 죽으면 끝
		if ( IsDead() )
		{
			cout<<endl;
			cout<<"보스를 물리쳤습니다!"<<endl;
			cout<<"******* WIN *******"<<endl;
			cout<<endl;
			break;
		}


		// 보스의 공격
		std::cout<<endl;
		std::cout<<"--------------"<<endl;
		std::cout<<GetName()<<" 의 공격!!!"<<endl;
		std::cout<<endl;

		// 공격력 순으로 정렬
		std::sort(playerpairs.begin(), playerpairs.end(), [ ] (PlayerPair* p1, PlayerPair* p2)
		{
			return ( p1->_damage>p2->_damage );
		});

		int count = 0;
		for ( int i = 0; i<playerpairs.size(); i++ )
		{
			int exp = GetCurHp();
			Attack(playerpairs[ i ]->_player);
			exp -= GetCurHp();
			dynamic_cast< Player* >( playerpairs[ i ]->_player )->GetExp(exp);

			// 4명까지만 공격
			count++;
			if ( count==4 )
			{
				break;
			}
		}

		for ( int i = 0; i<playerpairs.size(); i++ )
		{
			std::cout<<playerpairs[ i ]->_player->GetName()<<"의 HP : "<<playerpairs[ i ]->_player->GetCurHp()<<endl;
		}

		// 모두 죽으면 끝
		bool allDead = true;
		for ( int i = 0; i<playerpairs.size(); i++ )
		{
			if ( playerpairs[ i ]->_player->IsDead()==false )
			{
				allDead = false;
				break;
			}
		}
		if ( allDead )
		{
			cout<<endl;
			cout<<"THE END......"<<endl;
			cout<<endl;
			break;
		}
	}
}
