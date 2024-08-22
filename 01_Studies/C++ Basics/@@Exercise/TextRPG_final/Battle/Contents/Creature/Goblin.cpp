#include "pch.h"
#include "Goblin.h"

Goblin::Goblin(string name, int hp, int mp, int attack)
	: Monster(name, hp, mp, attack)
{
}

Goblin::~Goblin()
{
}

void Goblin::Attack(Player* other)
{
}

void Goblin::Clone(vector<Creature*>& monsters)
{
	srand(time(nullptr));
	for ( int i = 0; i<MonsterNum::GOBLIN; i++ )
	{
		string name = to_string(i+1)+"번 고블린";
		int hp = rand()%20+5;
		int mp = 100;
		int attack = rand()%4+2;
		monsters.push_back(new Goblin(name, hp, mp, attack));
	}
}
