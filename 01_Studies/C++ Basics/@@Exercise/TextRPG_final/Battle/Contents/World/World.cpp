#include "pch.h"
#include "World.h"
#include "string"

World::World()
	: _player(nullptr)
	, _computer(nullptr)
	, _monster(nullptr)
	, _boss(nullptr)

{
}

World::~World()
{
	if ( _player!=nullptr )
	{
		delete _player;
	}
	if ( _computer!=nullptr )
	{
		delete _computer;
	}
	if ( _monster!=nullptr )
	{
		delete _monster;
	}
	if ( _boss!=nullptr )
	{
		delete _boss;
	}
	_monsters.clear();
	_players.clear();
}

// 홈 화면... 초기화, 플레이 시작
void World::Init()
{
	_player = nullptr;
	_computer = nullptr;
	_monsters = {};

	Start();
	PlayMode();
}

// 이름, 클래스 입력
void World::Start()
{
	int playerNum = 0;
	string name;

	cout<<endl;
	cout<<"------------------------------------------------"<<endl;
	cout<<"이름을 입력해주세요."<<endl;
	cout<<endl;
	cin>>name;
	cout<<endl;
	cout<<"------------------------------------------------"<<endl;
	cout<<"1~3까지의 클래스를 입력해주세요."<<endl;
	cout<<"1 : Knight"<<endl;
	cout<<"2 : Archer"<<endl;
	cout<<"3 : Mage"<<endl;
	cout<<endl;
	cin>>playerNum;

	SelectClass(playerNum, name, &_player);
}

void World::SelectClass(int num, string name, Creature** creature)
{
	switch ( num )
	{
	case PlayerType::KNIGHT:
	{
		if ( name=="Computer" )
		{
			*creature = new Knight(name, KNIGHT_HP*1.5, KNIGHT_MP*1.5, KNIGHT_ATTACK*2);
		}
		else
		{
			*creature = new Knight(name, KNIGHT_HP, KNIGHT_MP, KNIGHT_ATTACK);
		}

		break;
	}
	case PlayerType::ARCHER:
	{
		if ( name=="Computer" )
		{
			*creature = new Archer(name, ARCHER_HP*1.5, ARCHER_MP*1.5, ARCHER_ATTACK*2);
		}
		else
		{
			*creature = new Archer(name, ARCHER_HP, ARCHER_MP, ARCHER_ATTACK);
		}
		break;
	}
	case PlayerType::MAGE:
	{
		if ( name=="Computer" )
		{
			*creature = new Mage(name, MAGE_HP*1.5, MAGE_MP*1.5, MAGE_ATTACK*2);
		}
		else
		{
			*creature = new Mage(name, MAGE_HP, MAGE_MP, MAGE_ATTACK);
		}
		break;
	}
	default:
	{
		cout<<endl;
		cout<<"잘못된 입력입니다."<<endl;
		break;
	}
	}
}

void World::PlayMode()
{
	bool battleWin = false;
	int playMode = 0;

	// 전투 이길 때 까지 반복
	while ( true )
	{
		cout<<endl;
		cout<<"------------------------------------------------"<<endl;
		cout<<"배틀모드를 입력해주세요."<<endl;
		cout<<"1 : 전투"<<endl;
		cout<<"2 : 사냥"<<endl;
		cout<<endl;
		cin>>playMode;

		switch ( playMode )
		{
		case PlayMode::BATTLE:
		{
			int comNum = rand()%3+1;
			SelectClass(comNum, "Computer", &_computer);
			cout<<endl;
			cout<<"------------------------------------------------"<<endl;
			cout<<"전투를 시작합니다!"<<endl;
			cout<<endl;
			battleWin = Battle();
			break;
		}
		case PlayMode::HUNT:
		{
			_monsters = {};
			Hunt();
			cout<<"------------------------------------------------"<<endl;
			cout<<"사냥을 완료하여 경험치를 획득하였습니다!"<<endl;
			cout<<endl;
			cout<<"< 결과 >"<<endl;
			dynamic_cast< Player* >( _player )->PrintInfo();
			break;
		}
		default:
		{
			cout<<endl;
			cout<<"잘못된 입력입니다"<<endl;
			break;
		}
		}

		if ( battleWin==true )
		{
			BattleWin();
			break;
		}
	}
}

bool World::Battle()
{
	bool end = false;
	while ( true )
	{
		_player->PreAttack(_computer);
		_player->Attack(_computer);
		dynamic_cast< Player* >( _computer )->PrintInfo();
		if ( _computer->IsDead() )
		{
			end = true;
			break;
		}

		_computer->PreAttack(_player);
		_computer->Attack(_player);
		dynamic_cast< Player* >( _player )->PrintInfo();
		if ( _player->IsDead() )
		{
			cout<<endl;
			cout<<"전투에서 패배하였습니다!"<<endl;
			cout<<endl;
			break;
		}
	}

	return end;
}

void World::Hunt()
{
	int monsterType = 0;
	cout<<endl;
	cout<<"------------------------------------------------"<<endl;
	cout<<"사냥할 몬스터를 선택해주세요."<<endl;
	cout<<"1 : 고블린"<<endl;
	cout<<endl;
	cin>>monsterType;
	cout<<endl;
	cout<<"------------------------------------------------"<<endl;
	cout<<"사냥을 시작합니다!"<<endl;
	cout<<endl;
	SelectMonster(monsterType);
}

void World::SelectMonster(int monsterType)
{
	switch ( monsterType )
	{
	case MonsterType::GOBLIN:
	{
		dynamic_cast< Goblin* >( _monster )->Clone(_monsters);
		dynamic_cast< Monster* >( _monster )->MonstersAttack(dynamic_cast< Player* >( _player ), _monsters);

		for ( int i = 0; i<MonsterNum::GOBLIN; i++ )
		{
			delete _monsters[ i ];
		}
	}
	}
}

void World::ClonePlayers()
{
	for ( int i = 0; i<10; i++ )
	{
		int classNum = rand()%3+1;
		int random = rand()%30+1;
		string playerName = _player->GetName()+" "+to_string(i+1);

		switch ( classNum )
		{
		case PlayerType::KNIGHT:
		{
			_players.push_back(new Knight(playerName, _player->GetCurHp()+random, _player->GetCurMp()+random, _player->GetCurAtk()+random));
			break;
		}
		case PlayerType::ARCHER:
		{
			_players.push_back(new Archer(playerName, _player->GetCurHp()+random, _player->GetCurMp()+random, _player->GetCurAtk()+random));
			break;
		}
		case PlayerType::MAGE:
		{
			_players.push_back(new Mage(playerName, _player->GetCurHp()+random, _player->GetCurMp()+random, _player->GetCurAtk()+random));
			break;
		}
		}
	}
}

void World::BossBattle()
{
	ClonePlayers();
	_boss = new HobGoblin("Boss", HG_HP, HG_MP, HG_ATTACK/_players.size());
	dynamic_cast< HobGoblin* >( _boss )->AggroAttack(_players);

	for ( int i = 0; i<_players.size(); i++ )
	{
		delete _players[ i ];
	}
}

void World::BattleWin()
{
	cout<<endl;
	cout<<"------------------------------------------------"<<endl;
	cout<<"전투에서 승리하였습니다!!!"<<endl;
	cout<<endl;
	cout<<"보스전을 시작합니다."<<endl;
	cout<<"1 : Y"<<endl;
	cout<<"2 : N"<<endl;
	cout<<endl;
	int start = 0;
	cin>>start;
	cout<<endl;
	cout<<"------------------------------------------------"<<endl;
	switch ( start )
	{
	case( YES ):
	{
		cout<<endl;
		cout<<"최종 보스 등장!!!"<<endl;
		cout<<endl;
		BossBattle();
		End();
	}
	case( NO ):
	{
		cout<<"게임을 종료합니다."<<endl;
		cout<<endl;
		break;
	}
	default:
	{
		cout<<endl;
		cout<<"잘못된 입력입니다"<<endl;
		break;
	}
	}
}

void World::End()
{
	int restart = 0;
	cout<<endl;
	cout<<"게임을 다시 시작하시겠습니까? "<<endl;
	cout<<"1 : Y"<<endl;
	cout<<"2 : N"<<endl;
	cout<<endl;
	cin>>restart;

	switch ( restart )
	{
	case YES:
	{
		Init();
		break;
	}
	case NO:
	{
		cout<<endl;
		cout<<"------------------------------------------------"<<endl;
		cout<<"게임을 종료합니다."<<endl;
		cout<<endl;
		break;
	}
	default:
	{
		cout<<endl;
		cout<<"잘못된 입력입니다"<<endl;
		break;
	}
	}
}
